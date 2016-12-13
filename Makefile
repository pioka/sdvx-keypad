XC = "/opt/microchip/xc8/v1.37/bin/xc8"

TARGET_DEVICE = 18F14K50
TARGET_DIR = bin
TARGET_NAME = target
TARGET = $(TARGET_DIR)/$(TARGET_NAME).elf

SRC_DIR = src
SRC = $(wildcard $(SRC_DIR)/*.c)

INCLUDE_DIR = inc
INCLUDE = $(wildcard $(INCLUDE_DIR)/*.h)

OBJ_DIR = obj
OBJ = $(addprefix $(OBJ_DIR)/,$(notdir $(SRC:%.c=%.p1)))

XC_COMPILE_OPTIONS = --pass1 --chip=$(TARGET_DEVICE) -Q -G  --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N100 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"

XC_LINK_OPTIONS = --chip=$(TARGET_DEVICE) -G --double=24 --float=24 --emi=wordwrite --opt=default,+asm,-asmfile,+speed,-space,-debug --addrqual=ignore --mode=pro -P -N100 --warn=0 --asmlist --summary=default,-psect,-class,+mem,-hex,-file --output=default,-inhx032 --runtime=default,+clear,+init,-keep,-no_startup,-download,+config,+clib,-plib --output=-mcof,+elf:multilocs --stack=compiled:auto:auto:auto "--errformat=%f:%l: error: (%n) %s" "--warnformat=%f:%l: warning: (%n) %s" "--msgformat=%f:%l: advisory: (%n) %s"

.PHONY:					all clean

all:					$(TARGET)

clean:	
	rm -rf $(OBJ_DIR)
	rm -rf $(TARGET_DIR)
	
# Build step: Compile
$(OBJ_DIR)/%.p1:		$(SRC_DIR)/%.c $(INCLUDE)
	mkdir -p $(OBJ_DIR)
	$(XC) $(XC_COMPILE_OPTIONS) -o$@ $<

# Build step: Link
$(TARGET):				$(OBJ)
	mkdir -p $(TARGET_DIR)
	$(XC) $(XC_LINK_OPTIONS) -o$@ $^
