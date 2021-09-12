################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../freertos/freertos_kernel/croutine.c \
../freertos/freertos_kernel/event_groups.c \
../freertos/freertos_kernel/list.c \
../freertos/freertos_kernel/queue.c \
../freertos/freertos_kernel/stream_buffer.c \
../freertos/freertos_kernel/tasks.c \
../freertos/freertos_kernel/timers.c 

OBJS += \
./freertos/freertos_kernel/croutine.o \
./freertos/freertos_kernel/event_groups.o \
./freertos/freertos_kernel/list.o \
./freertos/freertos_kernel/queue.o \
./freertos/freertos_kernel/stream_buffer.o \
./freertos/freertos_kernel/tasks.o \
./freertos/freertos_kernel/timers.o 

C_DEPS += \
./freertos/freertos_kernel/croutine.d \
./freertos/freertos_kernel/event_groups.d \
./freertos/freertos_kernel/list.d \
./freertos/freertos_kernel/queue.d \
./freertos/freertos_kernel/stream_buffer.d \
./freertos/freertos_kernel/tasks.d \
./freertos/freertos_kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
freertos/freertos_kernel/%.o: ../freertos/freertos_kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -std=gnu99 -D__REDLIB__ -DCPU_LPC54018JET180=1 -DCPU_LPC54018JET180_cm4 -DXIP_IMAGE -DW25Q128JVFM -DSDK_DEBUGCONSOLE=1 -DCPU_LPC54018 -D__USE_CMSIS -DMXL12835F -DBOARD_USE_VIRTUALCOM -DUSB_STACK_FREERTOS -DUSB_STACK_USE_DEDICATED_RAM=1 -DBOARD_DEBUG_UART_TYPE=kSerialPort_UsbCdc -DDEBUG_CONSOLE_TRANSFER_NON_BLOCKING -DSERIAL_PORT_TYPE_USBCDC=1 -DUSB_DEVICE_CONFIG_CDC_ACM=1 -DA_LITTLE_ENDIAN -DSDK_DEBUGCONSOLE_UART -DSERIAL_PORT_TYPE_UART=1 -DFSL_RTOS_FREE_RTOS -DCR_INTEGER_PRINTF -DPRINTF_FLOAT_ENABLE=0 -D__MCUXPRESSO -DDEBUG -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\board" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\source\Tracealyzer\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\source\Tracealyzer\config" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\source" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\port\boards\lpc54018iotmodule\freertos\gt202" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\drivers" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\component\serial_manager" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\component\lists" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\component\serial_manager\usb_cdc_adapter" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\usb\device\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\usb\device\source" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\component\osa" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\usb\device\source\lpcip3511" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\common_src\hcd" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\common_src\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\common_src\stack_common" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\common_src\wmi" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\custom_src\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\custom_src\stack_custom" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\include\AR6002" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\include\AR6002\hw2.0\hw" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\include\AR6002\hw4.0\hw" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\port" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\device" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\utilities" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\component\uart" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\port\boards\lpc54018iotmodule\freertos" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\port\env\freertos" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\freertos\freertos_kernel\include" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\freertos\freertos_kernel\portable\GCC\ARM_CM4F" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\wifi_qca\port\drivers\flexcomm_freertos" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\CMSIS" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\usb\device\class\cdc" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\usb\device\class" -I"C:\Users\D-Flow\Documents\MCUXpressoIDE_11.3.1_5262\workspace\qca_LCD_server_With_Tracealyzer\usb\include" -O0 -fno-common -g3 -Wall -c  -ffunction-sections  -fdata-sections  -ffreestanding  -fno-builtin -fmerge-constants -fmacro-prefix-map="../$(@D)/"=. -mcpu=cortex-m4 -mfpu=fpv4-sp-d16 -mfloat-abi=hard -mthumb -D__REDLIB__ -fstack-usage -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


