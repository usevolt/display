################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../hal/uv_hal/src/ui/ugui.c \
../hal/uv_hal/src/ui/uv_ui_styles.c \
../hal/uv_hal/src/ui/uv_uibutton.c \
../hal/uv_hal/src/ui/uv_uidisplay.c \
../hal/uv_hal/src/ui/uv_uifonts.c \
../hal/uv_hal/src/ui/uv_uilabel.c \
../hal/uv_hal/src/ui/uv_uislider.c \
../hal/uv_hal/src/ui/uv_uiwindow.c 

OBJS += \
./hal/uv_hal/src/ui/ugui.o \
./hal/uv_hal/src/ui/uv_ui_styles.o \
./hal/uv_hal/src/ui/uv_uibutton.o \
./hal/uv_hal/src/ui/uv_uidisplay.o \
./hal/uv_hal/src/ui/uv_uifonts.o \
./hal/uv_hal/src/ui/uv_uilabel.o \
./hal/uv_hal/src/ui/uv_uislider.o \
./hal/uv_hal/src/ui/uv_uiwindow.o 

C_DEPS += \
./hal/uv_hal/src/ui/ugui.d \
./hal/uv_hal/src/ui/uv_ui_styles.d \
./hal/uv_hal/src/ui/uv_uibutton.d \
./hal/uv_hal/src/ui/uv_uidisplay.d \
./hal/uv_hal/src/ui/uv_uifonts.d \
./hal/uv_hal/src/ui/uv_uilabel.d \
./hal/uv_hal/src/ui/uv_uislider.d \
./hal/uv_hal/src/ui/uv_uiwindow.d 


# Each subdirectory must supply rules for building sources it contributes
hal/uv_hal/src/ui/%.o: ../hal/uv_hal/src/ui/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: MCU C Compiler'
	arm-none-eabi-gcc -DDEBUG -D__CODE_RED -DCORE_M3 -D__USE_CMSIS=CMSIS_CORE_LPC177x_8x -D__USE_CMSIS_DSPLIB=CMSIS_DSPLIB_CM3 -D__LPC177X_8X__ -DLPC1785=1 -DUW_RTOS=1 -D"__UV_PROJECT_NAME=uw_display_release" -D__NEWLIB__ -I"/home/usevolt/uw/display/sw/inc/ui" -I"/home/usevolt/uw/display/sw/inc" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x/inc" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/inc" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/include" -I"/home/usevolt/uw/display/sw/hal/uv_hal/freertos/portable/GCC/ARM_CM3" -I"/home/usevolt/uw/display/sw/CMSIS_CORE_LPC177x_8x" -I"/home/usevolt/uw/display/sw/CMSIS_DSPLIB_CM3" -Og -g -Wall -c -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -Wno-format -mcpu=cortex-m3 -mthumb -D__NEWLIB__ -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.o)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


