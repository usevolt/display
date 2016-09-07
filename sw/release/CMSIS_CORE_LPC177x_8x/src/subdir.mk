################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CMSIS_CORE_LPC177x_8x/src/system_LPC177x_8x.c 

OBJS += \
./CMSIS_CORE_LPC177x_8x/src/system_LPC177x_8x.o 

C_DEPS += \
./CMSIS_CORE_LPC177x_8x/src/system_LPC177x_8x.d 


# Each subdirectory must supply rules for building sources it contributes
CMSIS_CORE_LPC177x_8x/src/%.o: ../CMSIS_CORE_LPC177x_8x/src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC177x_8x -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC177X_8X__ -D__REDLIB__ -DLPC1785=1 -DUW_RTOS=1 -D"__UV_PROJECT_NAME=uw_display_release" -I"/home/usevolt/uw/display/sw/inc" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x/inc" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/include" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/portable/GCC/ARM_CM3" -O0 -g3 -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=cortex-m3 -mthumb -D__REDLIB__ -specs=redlib.specs -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


