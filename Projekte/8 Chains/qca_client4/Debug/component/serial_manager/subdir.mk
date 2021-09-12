################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../component/serial_manager/serial_manager.c \
../component/serial_manager/serial_port_uart.c \
../component/serial_manager/serial_port_usb.c 

OBJS += \
./component/serial_manager/serial_manager.o \
./component/serial_manager/serial_port_uart.o \
./component/serial_manager/serial_port_usb.o 

C_DEPS += \
./component/serial_manager/serial_manager.d \
./component/serial_manager/serial_port_uart.d \
./component/serial_manager/serial_port_usb.d 


# Each subdirectory must supply rules for building sources it contributes
component/serial_manager/%.o: ../component/serial_manager/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC54018JET180=1 -DCPU_LPC54018JET180_cm4 -DXIP_IMAGE -DW25Q128JVFM -DCPU_LPC54018 -D__USE_CMSIS -DMXL12835F -DBOARD_USE_VIRTUALCOM -DUSB_STACK_FREERTOS -DUSB_STACK_USE_DEDICATED_RAM=1 -DBOARD_DEBUG_UART_TYPE=kSerialPort_UsbCdc -DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING -DSERIAL_PORT_TYPE_USBCDC=1 -DUSB_DEVICE_CONFIG_CDC_ACM=1 -DA_LITTLE_ENDIAN -DSDK_DEBUGCONSOLE_UART -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -DDEBUG -DSDK_DEBUGCONSOLE=1 -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\board" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\source\Tracealyzer\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\source\Tracealyzer\config" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\source" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\port\boards\lpc54018iotmodule\freertos\gt202" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\drivers" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\component\serial_manager" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\component\lists" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\component\serial_manager\usb_cdc_adapter" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\usb\device\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\usb\device\source" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\component\osa" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\usb\device\source\lpcip3511" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\common_src\hcd" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\common_src\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\common_src\stack_common" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\common_src\wmi" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\custom_src\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\custom_src\stack_custom" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\include\AR6002" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\include\AR6002\hw2.0\hw" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\include\AR6002\hw4.0\hw" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\port" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\device" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\utilities" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\component\uart" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\port\boards\lpc54018iotmodule\freertos" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\port\env\freertos" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\freertos\freertos_kernel\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\wifi_qca\port\drivers\flexcomm_freertos" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\CMSIS" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\usb\device\class\cdc" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\usb\device\class" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_client4\usb\include" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


