################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/ui/subdir.mk
-include src/subdir.mk
-include hal/uv_hal/src/ui/subdir.mk
-include hal/uv_hal/src/subdir.mk
-include hal/uv_hal/freertos/portable/GCC/ARM_CM4F/subdir.mk
-include hal/uv_hal/freertos/portable/GCC/ARM_CM3/subdir.mk
-include hal/uv_hal/freertos/portable/GCC/ARM_CM0/subdir.mk
-include hal/uv_hal/freertos/subdir.mk
-include CMSIS_CORE_LPC177x_8x/src/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: uw_display.axf

# Tool invocations
uw_display.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: MCU Linker'
	arm-none-eabi-gcc -nostdlib -Xlinker -Map="uw_display.map" -Xlinker --gc-sections -mcpu=cortex-m3 -mthumb -T "uw_display_release.ld" -o "uw_display.axf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '
	$(MAKE) --no-print-directory post-build

# Other Targets
clean:
	-$(RM) $(OBJS)$(C_DEPS)$(EXECUTABLES) uw_display.axf
	-@echo ' '

post-build:
	-@echo 'Performing post-build steps'
	-arm-none-eabi-size "uw_display.axf" ; arm-none-eabi-objcopy -O ihex "uw_display.axf" "uw_display.hex" ; arm-none-eabi-objcopy -v -O binary "uw_display.axf" "uw_display.bin" ; # checksum -p LPC1785 -d "uw_display.bin"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY: post-build

-include ../makefile.targets
