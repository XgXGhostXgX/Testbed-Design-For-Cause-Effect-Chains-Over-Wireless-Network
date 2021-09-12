/*
 * Copyright (c) 2013 - 2014, Freescale Semiconductor, Inc.
 * Copyright 2016-2017 NXP
 * All rights reserved.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

///////////////////////////////////////////////////////////////////////////////
//  Includes
///////////////////////////////////////////////////////////////////////////////

// SDK Included Files
#include "board.h"
#include "fsl_debug_console.h"
#include "qcom_api.h"
#include "wlan_qcom.h"
#include <time.h>

#include "usb_device_config.h"
#include "usb.h"
#include "usb_device.h"
#include "serial_port_usb.h"
#include "pin_mux.h"
#include <stdbool.h>
#include "fsl_power.h"
#include "fsl_lcdc.h"

#include <math.h>
#include <time.h>
/*******************************************************************************
 * Definitions
 ******************************************************************************/
#define APP_LCD            LCD
#define LCD_PANEL_CLK      9000000
#define LCD_PPL            480
#define LCD_HSW            2
#define LCD_HFP            8
#define LCD_HBP            43
#define LCD_LPP            272
#define LCD_VSW            10
#define LCD_VFP            4
#define LCD_VBP            12
#define LCD_POL_FLAGS      kLCDC_InvertVsyncPolarity | kLCDC_InvertHsyncPolarity
#define IMG_HEIGHT         272
#define IMG_WIDTH          480
#define LCD_INPUT_CLK_FREQ CLOCK_GetLcdClkFreq()
#define APP_LCD_IRQHandler LCD_IRQHandler
#define APP_LCD_IRQn       LCD_IRQn
#define APP_PIXEL_PER_BYTE 8

static uint8_t s_frameBufs[IMG_HEIGHT][IMG_WIDTH / APP_PIXEL_PER_BYTE];

static const uint32_t palette2[] = {0x0000001F};
uint32_t palette[] = {0x00000000};

int chain1_activated = 0;

double USet[3];
int period[3];
int deadline[3];
int execution[3];

int measurement[50];
int pointer = 0;
TickType_t Starting, Ending;


/*******************************************************************************
 * Prototypes
 ******************************************************************************/

void USB_DeviceClockInit(void);

/*******************************************************************************
 * Code
 ******************************************************************************/

void USB_DeviceClockInit(void)
{
#if defined(USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS > 0U)
    /* enable USB IP clock */
    CLOCK_EnableUsbfs0DeviceClock(kCLOCK_UsbSrcFro, CLOCK_GetFroHfFreq());
#if defined(FSL_FEATURE_USB_USB_RAM) && (FSL_FEATURE_USB_USB_RAM)
    for (int i = 0; i < FSL_FEATURE_USB_USB_RAM; i++)
    {
        ((uint8_t *)FSL_FEATURE_USB_USB_RAM_BASE_ADDRESS)[i] = 0x00U;
    }
#endif

#endif
#if defined(USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS > 0U)
    /* enable USB IP clock */
    CLOCK_EnableUsbhs0DeviceClock(kCLOCK_UsbSrcUsbPll, 0U);
#if defined(FSL_FEATURE_USBHSD_USB_RAM) && (FSL_FEATURE_USBHSD_USB_RAM)
    for (int i = 0; i < FSL_FEATURE_USBHSD_USB_RAM; i++)
    {
        ((uint8_t *)FSL_FEATURE_USBHSD_USB_RAM_BASE_ADDRESS)[i] = 0x00U;
    }
#endif
#endif
}


// 0 is the highest priority and priority 15 is the lowest priority
const int TASK_MAIN_PRIO       = configMAX_PRIORITIES - 3;
const int TASK_MAIN_STACK_SIZE = 800;

portSTACK_TYPE *task_main_stack = NULL;
TaskHandle_t task_main_task_handler;
TaskHandle_t task_loop_task_handler;
TaskHandle_t task_chain1_task1_handler;
TaskHandle_t task_chain1_task2_handler;
TaskHandle_t task_chain1_task3_handler;

// Hardwired SSID, passphrase, auth and cipher algo of AP to connect to
// Change this to fit your AP
#define AP_SSID       "nxp"
#define AP_PASSPHRASE "NXP0123456789"

QCOM_SSID g_ssid             = {.ssid = (AP_SSID)};
QCOM_PASSPHRASE g_passphrase = {.passphrase = (AP_PASSPHRASE)};

WLAN_AUTH_MODE g_auth    = WLAN_AUTH_WPA2_PSK;
WLAN_CRYPT_TYPE g_cipher = WLAN_CRYPT_AES_CRYPT;

// ============================================================================
// Menu Handling
// ============================================================================

extern int numIrqs;
extern int initTime;

static void printSeparator(void)
{
    PRINTF("========================================\r\n");
}

static void menuConnectToAP(void)
{
    apConnect(&g_ssid, &g_passphrase, g_auth, g_cipher);
}

static void menuDisconnect(void)
{
    apDisconnect();
}


static void menuUdpServerStart(void)
{
    udpBind(9000);
}

//PING ECUS
//static void menuPingECU1(void){
//	pingHost("192.168.12.18");
//}
//
//static void menuPingECU2(){
//	pingHost("192.168.12.137");
//}
//
//static void menuPingECU3(){
//	pingHost("192.168.12.15");
//}

#if 0
static void menuTraceQcomApi(void)
{
    int was = traceQcomApi(-1);
    PRINTF("QCOM API trace is now %s\r\n", (was ? "DISABLED" : "ENABLED"));
}

static void menuAll(void)
{
    menuConnectToAP();
    state = STATE_CONNECTING;
}
#endif

// ============================================================================
// Main
// ============================================================================

static void print_version(void)
{
    ATH_VERSION_STR verstr;

    int res = qcom_get_versionstr(&verstr);
    if (A_OK == res)
    {
        PRINTF("Host version:      %s\r\n", verstr.host_ver);
        PRINTF("Target version:    %s\r\n", verstr.target_ver);
        PRINTF("Firmware version:  %s\r\n", verstr.wlan_ver);
        PRINTF("Interface version: %s\r\n", verstr.abi_ver);
    }
    else
    {
        PRINTF("ERROR: Failed to get QCA400X version information\r\n");
    }
}



/*******************************************************************************
 * Tasks
 ******************************************************************************/
//3. Task from 1.Chain
//void chain1_task3(void *param){
//	TickType_t xLastWakeTime;
//	const TickType_t xFrequency=period[3];
//
//	// Initialise the xLastWakeTime variable with the current time.
//	xLastWakeTime = xTaskGetTickCount();
//
//	for( ;; )
//	{
//		PRINTF("Chain1 Task3 Entered \r\n");
//		if(chain1_activated == 3){
//			for(int i=0;i<3000;i++){
//
//			}
//			// Wait for the next cycle.
//			PRINTF("Chain_1_3 \r\n");
//			printSeparator();
//			chain1_activated=0;
//			printSeparator();
//			int time = execution[0]+execution[1]+execution[2]+execution[3];
//			PRINTF("EXECUTED TIME: %d \r\n",time);
//			printSeparator();
//		}
//		vTaskDelayUntil( &xLastWakeTime, xFrequency );
//	}
//}


//2. Task from 1.Chain
void chain1_task2(void *param){
	TickType_t xLastWakeTime, xLastCheck;
	const TickType_t xFrequency = period[1];

	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();

	for( ;; )
	{
		TickType_t xRunTime = 0;
		xLastWakeTime = xTaskGetTickCount();
		xLastCheck = xTaskGetTickCount();
		//PRINTF("Chain1 Task2 Entered \r\n");
		while(xRunTime<execution[1]){
			TickType_t delta = xTaskGetTickCount() - xLastCheck;
			if(delta>0){
				xRunTime += delta;
				xLastCheck = xTaskGetTickCount();
			}
		}

		//PRINTF("Chain1 Task2 Entered \r\n");
		if(chain1_activated == 2){
			// Wait for the next cycle.
			PRINTF("Chain_1_2 \r\n");
			printSeparator();
			//chain1_activated=3;
			chain1_activated=0;
			Ending = xTaskGetTickCount();
			PRINTF("MEASUREMENT: %d \r\n",Ending-Starting);
			measurement[pointer]=Ending-Starting;
			pointer++;
			PRINTF("POINTER: %d \r\n",pointer);
		}
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

//1. Task from 1.Chain
void chain1_task1(void *param){

	TickType_t xLastWakeTime, xLastCheck;
	const TickType_t xFrequency = period[2];

	// Initialise the xLastWakeTime variable with the current time.
	xLastWakeTime = xTaskGetTickCount();

	for( ;; )
	{

		TickType_t xRunTime = 0;
		xLastWakeTime = xTaskGetTickCount();
		xLastCheck = xTaskGetTickCount();
		while(xRunTime<execution[2]){
			TickType_t delta = xTaskGetTickCount() - xLastCheck;
			if(delta>0){
				xRunTime += delta;
				xLastCheck = xTaskGetTickCount();
			}
		}

		//PRINTF("Chain1 Task1 Entered \r\n");
		if(chain1_activated == 1){
			Starting = xTaskGetTickCount();
			PRINTF("Chain_1_1 \r\n");
			printSeparator();
			chain1_activated = 2;
			// Wait for the next cycle.

		}
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

//Loop Task to catch input from "Clients"
void task_loop(void *param){

	TickType_t xLastWakeTime;
	const TickType_t xFrequency = period[0];

	// Initialise the xLastWakeTime variable with the current time.


	while(1){
		xLastWakeTime = xTaskGetTickCount();
		PRINTF("Loop Task entered: \r\n");
		if(chain1_activated == 0){
			if(readUdpMessage() != NULL){
				while(1){
					udpPollAndRecv(50);
					if(readUdpMessage() == NULL){
						break;
					}
					PRINTF("CLEAN MESSAGE RECEIVED: %c\r\n",readUdpMessage());
					clearBuffer();
					pointer++;
				}
			}
			if(pointer==50 || GPIO_PinRead(BOARD_SW5_GPIO, BOARD_SW5_GPIO_PORT,BOARD_SW5_GPIO_PIN) == 0){
				printSeparator();
				for(int i=0; i<=pointer;i++){
					PRINTF("%d \r\n",measurement[i]);
				}
				printSeparator();
				vTaskEndScheduler();
			}
			udpPollAndRecv(50);
			if(readUdpMessage() != NULL){
				PRINTF("MESSAGE RECEIVED: %c\r\n",readUdpMessage());
				PRINTF("EXECUTED LOOP \r\n");
				printSeparator();
				chain1_activated = 1;
			}
			clearBuffer();
		}
		else{
			while(1){
				udpPollAndRecv(50);
				if(readUdpMessage() == NULL){
					break;
				}
				PRINTF("CLEAN MESSAGE RECEIVED: %c\r\n",readUdpMessage());
				clearBuffer();
				pointer++;
			}
		}
		vTaskDelayUntil( &xLastWakeTime, xFrequency );
	}
}

void UUniFast(int n, double U_avg){
	float nextSumU = 0.0;
	float sumU=(float)U_avg;
	for(int i=0;i<n;i++){
		float random = ((float)rand()/(float)(RAND_MAX)) * 1.0;
		float pows =(float)pow(random,(float)(1.0/(n-i)));
		nextSumU = (float)sumU*pows;
		USet[i]=sumU-nextSumU;
		sumU = nextSumU;
	}
	USet[2]=sumU;
}



float randomValue(int a, int b){
	float value = 0;
	do{
		value= ((((float)rand()/(float)(RAND_MAX)))* (b-a))+a;
	}while(value == b);
	return value;
}

void CSet_generate(int Pmin, int numLog){
	int j=0;
	int thN,p;
	for(int i=0;i<3;i++){
		thN = j%numLog;
		p = randomValue(Pmin*pow(10,thN+2),Pmin*pow(10,thN+3));
		period[i]=p;
		deadline[i]=p;
		execution[i]=p*USet[i];
		j++;
	}
}

//Main Task, initialise WLAN Module and preset
void task_main(void *param)
{
	srand(100);
    //INIT UUnitFast
	UUniFast(2,0.7);
    CSet_generate(1,2);

    PRINTF("PERIOD 1: %d\r\n",period[0]);
    PRINTF("PERIOD 2: %d\r\n",period[1]);
    PRINTF("PERIOD 3: %d\r\n",period[2]);
    PRINTF("EXECUTION 1: %d\r\n",execution[0]);
    PRINTF("EXECUTION 2: %d\r\n",execution[1]);
    PRINTF("EXECUTION 3: %d\r\n",execution[2]);
    printSeparator();


    int32_t result = 0;
    (void)result;

    TickType_t xLastWakeTime;
    const TickType_t xFrequency = 4000;

    // Initialise the xLastWakeTime variable with the current time.
    xLastWakeTime = xTaskGetTickCount();

    GPIO_PinInit(BOARD_SW5_GPIO, BOARD_SW5_GPIO_PORT, BOARD_SW5_GPIO_PIN, &(gpio_pin_config_t){kGPIO_DigitalOutput, 1U});
        GPIO_PortInit(BOARD_SW5_GPIO, BOARD_SW5_GPIO_PORT);


    printSeparator();
    PRINTF("Initialising starting... \r\n");

    /* Initialize WIFI shield */
    result = WIFISHIELD_Init();
    assert(A_OK == result);
	PRINTF("WLAN shield activated \r\n");

    /* Initialize the WIFI driver (thus starting the driver task) */
    result = wlan_driver_start();
    assert(A_OK == result);
	PRINTF("WLAN driver activated \r\n");

    print_version();

    UBaseType_t numTasks = uxTaskGetNumberOfTasks();
    PRINTF("number of FreeRTOS tasks = %d\r\n", numTasks);
    DbgConsole_Flush();
    PRINTF("Entering main loop\r\n");

    printSeparator();

    //CONNECTING TO NETWORK
    PRINTF("Initialsing Process... \r\n");
    PRINTF("Connecting to local Network \r\n");


    while(1){

    	if(isConnected()){
    		getDhcp();
    		break;
    	}
    	menuConnectToAP();

    	vTaskDelayUntil( &xLastWakeTime, xFrequency );

    }

    PRINTF("Connected to local Network \r\n");

    printSeparator();

    PRINTF("Create UDP Server \r\n");

    menuUdpServerStart();

    PRINTF("Server has been created \r\n");

    printSeparator();

    if(xTaskCreate(task_loop, "Receive", 400, task_main_stack,2,&task_loop_task_handler) != pdPASS){
    	return 1;
    }

    if(xTaskCreate(chain1_task1,"chain1_1",200,task_main_stack,4,&task_chain1_task1_handler) != pdPASS){
    	return 1;
    }

    if(xTaskCreate(chain1_task2,"chain1_2",200,task_main_stack,3,&task_chain1_task2_handler) != pdPASS){
    	return 1;
    }

//    if(xTaskCreate(chain1_task3,"chain1_3",200,task_main_stack,5,&task_chain1_task3_handler) != pdPASS){
//    	return 1;
//    }

    vTaskSuspend(task_main_task_handler);
}

void APP_FillBuffer(void *buffer)
{
    /*
     * Fill the frame buffer, show rectangle in the center.
     */
    uint8_t(*buf)[IMG_WIDTH / APP_PIXEL_PER_BYTE] = buffer;

    uint32_t i, j;

    /* The background color palette index is 0, color is red. */
    for (i = 0; i < IMG_HEIGHT; i++)
    {
        for (j = 0; j < IMG_WIDTH / APP_PIXEL_PER_BYTE; j++)
        {
            buf[i][j] = 0x00U;
        }
    }
}

//main
int main(void)
{
	BaseType_t result = 0;
    (void)result;

    /* attach 12 MHz clock to FLEXCOMM0 (debug console) */
    CLOCK_AttachClk(BOARD_DEBUG_UART_CLK_ATTACH);
    /* LCD */
    lcdc_config_t lcdConfig;
    CLOCK_AttachClk(kMAIN_CLK_to_LCD_CLK);
    CLOCK_SetClkDiv(kCLOCK_DivLcdClk, 1, true);

    /* reset USB0 and USB1 device */
    RESET_PeripheralReset(kUSB0D_RST_SHIFT_RSTn);
    RESET_PeripheralReset(kUSB1D_RST_SHIFT_RSTn);
    RESET_PeripheralReset(kUSB0HMR_RST_SHIFT_RSTn);
    RESET_PeripheralReset(kUSB0HSL_RST_SHIFT_RSTn);
    RESET_PeripheralReset(kUSB1H_RST_SHIFT_RSTn);

    NVIC_ClearPendingIRQ(USB0_IRQn);
    NVIC_ClearPendingIRQ(USB0_NEEDCLK_IRQn);
    NVIC_ClearPendingIRQ(USB1_IRQn);
    NVIC_ClearPendingIRQ(USB1_NEEDCLK_IRQn);

    BOARD_InitBootPins();
    BOARD_InitBootClocks();

    //APP_FillBuffer((void *)(s_frameBufs));

    /* LCD */
    LCDC_GetDefaultConfig(&lcdConfig);

    lcdConfig.panelClock_Hz  = LCD_PANEL_CLK;
    lcdConfig.ppl            = LCD_PPL;
    lcdConfig.hsw            = LCD_HSW;
    lcdConfig.hfp            = LCD_HFP;
    lcdConfig.hbp            = LCD_HBP;
    lcdConfig.lpp            = LCD_LPP;
    lcdConfig.vsw            = LCD_VSW;
    lcdConfig.vfp            = LCD_VFP;
    lcdConfig.vbp            = LCD_VBP;
    lcdConfig.polarityFlags  = LCD_POL_FLAGS;
    lcdConfig.upperPanelAddr = (uint32_t)s_frameBufs;
    lcdConfig.bpp            = kLCDC_1BPP;
    lcdConfig.display        = kLCDC_DisplayTFT;
    lcdConfig.swapRedBlue    = false;

    LCDC_Init(APP_LCD, &lcdConfig, LCD_INPUT_CLK_FREQ);

    LCDC_SetPalette(APP_LCD, palette, ARRAY_SIZE(palette));

    LCDC_Start(APP_LCD);
    LCDC_PowerUp(APP_LCD);

#if (defined USB_DEVICE_CONFIG_LPCIP3511HS) && (USB_DEVICE_CONFIG_LPCIP3511HS)
    POWER_DisablePD(kPDRUNCFG_PD_USB1_PHY);
    /* enable usb1 host clock */
    CLOCK_EnableClock(kCLOCK_Usbh1);
    /*According to reference mannual, device mode setting has to be set by access usb host register */
    *((uint32_t *)(USBHSH_BASE + 0x50)) |= USBHSH_PORTMODE_DEV_ENABLE_MASK;
    /* enable usb1 host clock */
    CLOCK_DisableClock(kCLOCK_Usbh1);
#endif
#if (defined USB_DEVICE_CONFIG_LPCIP3511FS) && (USB_DEVICE_CONFIG_LPCIP3511FS)
    POWER_DisablePD(kPDRUNCFG_PD_USB0_PHY); /*< Turn on USB Phy */
    CLOCK_SetClkDiv(kCLOCK_DivUsb0Clk, 1, false);
    CLOCK_AttachClk(kFRO_HF_to_USB0_CLK);
    /* enable usb0 host clock */
    CLOCK_EnableClock(kCLOCK_Usbhsl0);
    /*According to reference mannual, device mode setting has to be set by access usb host register */
    *((uint32_t *)(USBFSH_BASE + 0x5C)) |= USBFSH_PORTMODE_DEV_ENABLE_MASK;
    /* disable usb0 host clock */
    CLOCK_DisableClock(kCLOCK_Usbhsl0);
#endif

    vTraceEnable(TRC_START);

    USB_DeviceClockInit();
    BOARD_InitDebugConsole();

    result =
        xTaskCreate(task_main, "main", 200, task_main_stack, TASK_MAIN_PRIO, &task_main_task_handler);
    assert(pdPASS == result);

    vTaskStartScheduler();
    for (;;)
        ;
}
