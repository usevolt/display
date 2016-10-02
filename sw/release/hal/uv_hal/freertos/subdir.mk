################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/uv_hal/freertos/croutine.c \
../hal/uv_hal/freertos/event_groups.c \
../hal/uv_hal/freertos/heap_2.c \
../hal/uv_hal/freertos/list.c \
../hal/uv_hal/freertos/queue.c \
../hal/uv_hal/freertos/tasks.c \
../hal/uv_hal/freertos/timers.c 

OBJS += \
./hal/uv_hal/freertos/croutine.o \
./hal/uv_hal/freertos/event_groups.o \
./hal/uv_hal/freertos/heap_2.o \
./hal/uv_hal/freertos/list.o \
./hal/uv_hal/freertos/queue.o \
./hal/uv_hal/freertos/tasks.o \
./hal/uv_hal/freertos/timers.o 

C_DEPS += \
./hal/uv_hal/freertos/croutine.d \
./hal/uv_hal/freertos/event_groups.d \
./hal/uv_hal/freertos/heap_2.d \
./hal/uv_hal/freertos/list.d \
./hal/uv_hal/freertos/queue.d \
./hal/uv_hal/freertos/tasks.d \
./hal/uv_hal/freertos/timers.d 


# Each subdirectory must supply rules for building sources it contributes
hal/uv_hal/freertos/%.o: ../hal/uv_hal/freertos/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC177x_8x -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC177X_8X__ -DLPC1785=1 -DUW_RTOS=1 -D"__UV_PROJECT_NAME=uw_display_release" -D__NEWLIB__ -I"/home/usevolt/uw/display/sw/inc/ui" -I"/home/usevolt/uw/display/sw/inc" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x/inc" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/include" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/portable/GCC/ARM_CM3" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3" -Og -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -Wno-format -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


