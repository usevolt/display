#############################################
#
#	USEVOLT MAKEFILE
# Builds a project adding a git hash to preprocessor symbols
# 
# * Project name is taken from the name of the git repository
# 
##############################################



### APP CONFIG ###


# Specify the CPU used. Depends on the used compiler
MCPU := cortex-m3
# Additional CPU define symbol, used for FreeRTOS comiple
CORE := CORE_M3

#Sepcify the optimizations used. Os == optimize for size, Og = optimize for debug, O3, O2, O1
O := Og

# Name of the directory where build files will be saved
BUILDDIR := release

# Name of the produced binary firmware
BINARY := display

# name of the CMSIS directory. Should be in the same directory as this makefile
CMSIS := CMSIS_CORE_LPC177x_8x

# List of include directories
INCLUDEDIRS := 	-I"inc/" \
				-I"CMSIS_CORE_LPC177x_8x/inc/" \
				-I"hal/uv_hal/inc" \
				-I"hal/uv_hal/freertos/include" \
				-I"hal/uv_hal/freertos/portable/GCC/ARM_CM3" \
				-I"inc/ui"


### END OF APP CONFIG ###






CC := arm-none-eabi-gcc
SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags)
APP_NAME := $(shell basename `git rev-parse --show-toplevel`)
FULL_NAME := $(APP_NAME)_$(GIT_VERSION)


CFLAGS := -DDEBUG -D__CODE_RED -D$(CORE) -D__USE_CMSIS=$(CMSIS) -D__UV_PROJECT_NAME=$(FULL_NAME) -D__NEWLIB__ $(INCLUDEDIRS) -$(O) -g3 -Wall -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=$(MCPU) -mthumb


LDFLAGS := -nostdlib -Xlinker -Map="$(BUILDDIR)/$(APP_NAME).map" -Xlinker --cref -Xlinker --gc-sections -mcpu=$(MCPU) -mthumb -T "$(APP_NAME).ld" -D__UV_APP_VERSION=\"$(GIT_VERSION)\"


# Get list of object files, with paths
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))
# List of object dependencies
DEPS := $(OBJECTS:.o=.d)




all: $(BINARY)
	$(MAKE) post-build

$(BINARY): $(OBJECTS)
	@echo ""
	@echo "Linking target"
	@echo ""
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o "$(BUILDDIR)/$(BINARY).axf"

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -I$(dir $<) -MMD -MT $@ -c $< -o $@


post-build:
	-@echo ""
	-@echo 'Performing post-build steps'
	-@echo ""
	-arm-none-eabi-size "$(BUILDDIR)/$(APP_NAME).axf" 
	-arm-none-eabi-objcopy -O ihex "$(BUILDDIR)/$(APP_NAME).axf" "$(BUILDDIR)/$(APP_NAME).hex"
	-arm-none-eabi-objcopy -v -O binary "$(BUILDDIR)/$(APP_NAME).axf" "$(BUILDDIR)/$(APP_NAME).bin"
	@chmod +x $(BUILDDIR)/$(APP_NAME).hex
	-@echo ' '

clean:
	@rm -rf $(BUILDDIR)

	
-include $(DEPS)
