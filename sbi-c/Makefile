CROSS_COMPILE:=riscv64-linux-
CC:=$(CROSS_COMPILE)gcc
LD:=$(CROSS_COMPILE)ld
NM:=$(CROSS_COMPILE)nm
OBJDUMP:=$(CROSS_COMPILE)objdump 
OBJCOPY:=$(CROSS_COMPILE)objcopy

SRC:=./src
BUILD:=./build
INCLUDE_FILES:=$(shell find $(SRC) -name "*.h")
TARGET_NAME:=main

INCLUDE_PATH:=$(foreach it,$(INCLUDE_FILES),-I$(dir ${it}))
INCLUDE_PATH:=$(sort $(INCLUDE_PATH))


SRC_FILES:= $(shell find $(SRC) -name "*.s")
SRC_FILES+= $(shell find $(SRC) -name "*.c")
OBJECTS:= $(foreach it,$(SRC_FILES),$(patsubst $(SRC)/%.c, $(BUILD)/%.o,$(it)))
OBJECTS:= $(foreach it,$(OBJECTS),$(patsubst $(SRC)/%.s, $(BUILD)/%.o,$(it)))


CCFLAGS:= -g $(INCLUDE_PATH) 

LDFLAGS:= -g 

compile: $(OBJECTS) kernel.ld
	@mkdir -p $(dir $@)
	$(LD) $(LDFLAGS) ${OBJECTS} -T kernel.ld -o $(BUILD)/$(TARGET_NAME)

$(BUILD)/%.o:$(SRC)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

$(BUILD)/%.o:${SRC}/%.s
	@mkdir -p $(dir $@)
	$(CC) $(CCFLAGS) -c $< -o $@

test:
	@echo ${INCLUDE_PATH}
	@echo $(OBJECTS)
clean:
	rm -rf $(BUILD)

.PHONY: compile clean test
