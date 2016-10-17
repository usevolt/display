################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/uv_hal/src/printf.c \
../hal/uv_hal/src/uv_adc.c \
../hal/uv_hal/src/uv_button.c \
../hal/uv_hal/src/uv_can.c \
../hal/uv_hal/src/uv_canopen.c \
../hal/uv_hal/src/uv_eeprom.c \
../hal/uv_hal/src/uv_emc.c \
../hal/uv_hal/src/uv_errors.c \
../hal/uv_hal/src/uv_filters.c \
../hal/uv_hal/src/uv_gpio.c \
../hal/uv_hal/src/uv_i2c.c \
../hal/uv_hal/src/uv_json.c \
../hal/uv_hal/src/uv_lcd.c \
../hal/uv_hal/src/uv_memory.c \
../hal/uv_hal/src/uv_pwm.c \
../hal/uv_hal/src/uv_reset.c \
../hal/uv_hal/src/uv_rtc.c \
../hal/uv_hal/src/uv_rtos.c \
../hal/uv_hal/src/uv_spi.c \
../hal/uv_hal/src/uv_stdout.c \
../hal/uv_hal/src/uv_terminal.c \
../hal/uv_hal/src/uv_timer.c \
../hal/uv_hal/src/uv_uart.c \
../hal/uv_hal/src/uv_utilities.c \
../hal/uv_hal/src/uv_wdt.c 

OBJS += \
./hal/uv_hal/src/printf.o \
./hal/uv_hal/src/uv_adc.o \
./hal/uv_hal/src/uv_button.o \
./hal/uv_hal/src/uv_can.o \
./hal/uv_hal/src/uv_canopen.o \
./hal/uv_hal/src/uv_eeprom.o \
./hal/uv_hal/src/uv_emc.o \
./hal/uv_hal/src/uv_errors.o \
./hal/uv_hal/src/uv_filters.o \
./hal/uv_hal/src/uv_gpio.o \
./hal/uv_hal/src/uv_i2c.o \
./hal/uv_hal/src/uv_json.o \
./hal/uv_hal/src/uv_lcd.o \
./hal/uv_hal/src/uv_memory.o \
./hal/uv_hal/src/uv_pwm.o \
./hal/uv_hal/src/uv_reset.o \
./hal/uv_hal/src/uv_rtc.o \
./hal/uv_hal/src/uv_rtos.o \
./hal/uv_hal/src/uv_spi.o \
./hal/uv_hal/src/uv_stdout.o \
./hal/uv_hal/src/uv_terminal.o \
./hal/uv_hal/src/uv_timer.o \
./hal/uv_hal/src/uv_uart.o \
./hal/uv_hal/src/uv_utilities.o \
./hal/uv_hal/src/uv_wdt.o 

C_DEPS += \
./hal/uv_hal/src/printf.d \
./hal/uv_hal/src/uv_adc.d \
./hal/uv_hal/src/uv_button.d \
./hal/uv_hal/src/uv_can.d \
./hal/uv_hal/src/uv_canopen.d \
./hal/uv_hal/src/uv_eeprom.d \
./hal/uv_hal/src/uv_emc.d \
./hal/uv_hal/src/uv_errors.d \
./hal/uv_hal/src/uv_filters.d \
./hal/uv_hal/src/uv_gpio.d \
./hal/uv_hal/src/uv_i2c.d \
./hal/uv_hal/src/uv_json.d \
./hal/uv_hal/src/uv_lcd.d \
./hal/uv_hal/src/uv_memory.d \
./hal/uv_hal/src/uv_pwm.d \
./hal/uv_hal/src/uv_reset.d \
./hal/uv_hal/src/uv_rtc.d \
./hal/uv_hal/src/uv_rtos.d \
./hal/uv_hal/src/uv_spi.d \
./hal/uv_hal/src/uv_stdout.d \
./hal/uv_hal/src/uv_terminal.d \
./hal/uv_hal/src/uv_timer.d \
./hal/uv_hal/src/uv_uart.d \
./hal/uv_hal/src/uv_utilities.d \
./hal/uv_hal/src/uv_wdt.d 


# Each subdirectory must supply rules for building sources it contributes
hal/uv_hal/src/%.o: ../hal/uv_hal/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC177x_8x -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC177X_8X__ -DLPC1785=1 -DUW_RTOS=1 -D"__UV_PROJECT_NAME=uw_display_release" -D__NEWLIB__ -I"/home/usevolt/uw/display/sw/inc/ui" -I"/home/usevolt/uw/display/sw/inc" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x/inc" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/include" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/portable/GCC/ARM_CM3" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3" -Og -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -Wno-format -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


