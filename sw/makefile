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
BUILDDIR := obj


# Name of the produced binary firmware
BINARY := display

# List of include directories
INCLUDEDIRS := 	-I"inc/" \
				-I"hal/include/" \
				-I"hal/uv_hal/inc" \
				-I"hal/CMSIS_CORE_LPC177x_8x/inc"\
				-I"hal/uv_hal/freertos/include" \
				-I"hal/uv_hal/freertos/portable/GCC/ARM_CM3" \
				-I"inc/ui" \
				-I "inc/network" \
				-I "uw_can"


### END OF APP CONFIG ###






CC := arm-none-eabi-gcc
SOURCES := $(shell find $(SOURCEDIR) -name '*.c')
GIT_VERSION := $(shell git describe --abbrev=4 --dirty --always --tags)
APP_NAME := $(shell basename `git rev-parse --show-toplevel`)

CFLAGS := -D$(CORE) $(INCLUDEDIRS) -$(O) -g3 -Wall -fmessage-length=0 -fno-builtin -ffunction-sections -fdata-sections -mcpu=$(MCPU) -mthumb
LDFLAGS := -nostdlib -Xlinker -Map="$(BUILDDIR)/$(APP_NAME).map" -Xlinker --cref -Xlinker --gc-sections -mcpu=$(MCPU) -mthumb -T "$(APP_NAME).ld" -D__UV_APP_VERSION=\"$(GIT_VERSION)\"


# Get list of object files, with paths
OBJECTS := $(addprefix $(BUILDDIR)/,$(SOURCES:%.c=%.o))
# List of object dependencies
DEPS := $(OBJECTS:.o=.d)



default:
	@echo "\n**************************"
	@echo "Error: Target not defined."
	@echo "**************************\n"
	@echo " Please use either 'make fm', 'make lm' or 'make cm'"


fm:	CFLAGS += -DFM -D__UV_PROJECT_NAME=$(APP_NAME)_FM_$(GIT_VERSION)
fm: LDFLAGS += -DFM
fm: $(BINARY)
	$(MAKE) post-build


lm:	CFLAGS += -DLM -D__UV_PROJECT_NAME=$(APP_NAME)_LM_$(GIT_VERSION)
lm: LDFLAGS += -DLM
lm: $(BINARY)
	$(MAKE) post-build
	
cm:	CFLAGS += -DCM -D__UV_PROJECT_NAME=$(APP_NAME)_CM_$(GIT_VERSION)
cm: LDFLAGS += -DCM
cm: $(BINARY)
	$(MAKE) post-build

$(BINARY): $(OBJECTS)
	@echo ""
	@echo "Linking target"
	@echo ""
	$(CC) $(CFLAGS) $(LDFLAGS) $(OBJECTS) -o "$(BINARY).axf"

$(BUILDDIR)/%.o: %.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -I$(HEADERDIR) -I$(dir $<) -MMD -MT $@ -c $< -o $@


post-build:
	-@echo ""
	-@echo 'Performing post-build steps for $(APP_NAME)_$(GIT_VERSION)'
	-@echo ""
	-arm-none-eabi-size "$(BINARY).axf" 
	-arm-none-eabi-objcopy -O ihex "$(BINARY).axf" "$(BINARY).hex"
	-arm-none-eabi-objcopy -v -O binary "$(BINARY).axf" "$(BINARY).bin"
	@chmod +x $(BINARY).hex
	-@echo ' '

clean:
	@rm -rf $(BUILDDIR)
	@rm -rf $(BINARY).axf
	@rm -rf $(BINARY).hex
	@rm -rf $(BINARY).bin

	
-include $(DEPS)

