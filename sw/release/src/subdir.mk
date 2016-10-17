################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/alert.c \
../src/canopen.c \
../src/commands.c \
../src/cr_startup_lpc177x_8x.c \
../src/crp.c \
../src/gui.c \
../src/log.c \
../src/main.c \
../src/network.c 

OBJS += \
./src/alert.o \
./src/canopen.o \
./src/commands.o \
./src/cr_startup_lpc177x_8x.o \
./src/crp.o \
./src/gui.o \
./src/log.o \
./src/main.o \
./src/network.o 

C_DEPS += \
./src/alert.d \
./src/canopen.d \
./src/commands.d \
./src/cr_startup_lpc177x_8x.d \
./src/crp.d \
./src/gui.d \
./src/log.d \
./src/main.d \
./src/network.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC177x_8x -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC177X_8X__ -DLPC1785=1 -DUW_RTOS=1 -D"__UV_PROJECT_NAME=uw_display_release" -D__NEWLIB__ -I"/home/usevolt/uw/display/sw/inc/ui" -I"/home/usevolt/uw/display/sw/inc" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x/inc" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/include" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/portable/GCC/ARM_CM3" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3" -Og -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -Wno-format -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


