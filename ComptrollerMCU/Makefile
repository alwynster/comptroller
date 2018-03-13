
##########------------------------------------------------------##########
##########              Project-specific Details                ##########
##########    Check these every time you start a new project    ##########
##########------------------------------------------------------##########

MCU   = atmega328p
F_CPU = 16000000UL
BAUD = 9600 
## Also try BAUD = 19200 or 38400 if you're feeling lucky.

## A directory for common include files and the simple USART library.
## If you move either the current folder or the Library folder, you'll
##  need to change this path to match.
# LIBDIR = ../../AVR-Programming-Library

##########------------------------------------------------------##########
##########                 Programmer Defaults                  ##########
##########          Set up once, then forget about it           ##########
##########        (Can override.  See bottom of file.)          ##########
##########------------------------------------------------------##########

PROGRAMMER_TYPE_ISP = avrisp2
PROGRAMMER_TYPE_STK = stk500v2
PROGRAMMER_ARGS_STK = -P $(wildcard /dev/tty.usbmodem*)
PROGRAMMER_ARGS = -P COM3
# PROGRAMMER_ARGS_STK = -P /dev/tty.usbmodem323131

ELASTIC_NODE_SERIAL = $(wildcard /dev/tty.usbserial-23*)
ELASTIC_NODE_DEBUG_SERIAL = $(wildcard /dev/tty.usbserial-A*)
# ELASTIC_NODE_DEBUG_SERIAL = /dev/tty.usbserial-AI02KF0V
# extra arguments to avrdude: baud rate, chip type, -F flag, etc.

##########------------------------------------------------------##########
##########                  Program Locations                   ##########
##########     Won't need to change if they're in your PATH     ##########
##########------------------------------------------------------##########

# AVR_PATH = /usr/local/CrossPack-AVR-20131216/bin
# CC = $(AVR_PATH)/avr-gcc
# OBJCOPY = $(AVR_PATH)/avr-objcopy
# OBJDUMP = $(AVR_PATH)/avr-objdump
# AVRSIZE = $(AVR_PATH)/avr-size
# AVRDUDE = $(AVR_PATH)/avrdude
CC = avr-gcc
OBJCOPY = avr-objcopy
OBJDUMP = avr-objdump
AVRSIZE = avr-size
AVRDUDE = avrdude

##########------------------------------------------------------##########
##########                   Makefile Magic!                    ##########
##########         Summary:                                     ##########
##########             We want a .hex file                      ##########
##########        Compile source files into .elf                ##########
##########        Convert .elf file into .hex                   ##########
##########        You shouldn't need to edit below.             ##########
##########------------------------------------------------------##########

## The name of your project (without the .c)
# TARGET = blinkLED
## Or name it automatically after the enclosing directory
TARGET = $(lastword $(subst /, ,$(CURDIR)))

# Object files: will find all .c/.h files in current directory
#  and in LIBDIR.  If you have any other (sub-)directories with code,
#  you can add them in to SOURCES below in the wildcard statement.
SOURCES=$(wildcard *.c lib/*/*.c lib/*/*/*.c)

# $(LIBDIR)/*.c)
LIBDIR=$(CURDIR)/lib
OBJECTS=$(SOURCES:.c=.o)
HEADERS=$(SOURCES:.c=.h)

## Compilation options, type man avr-gcc if you're curious.
CPPFLAGS = -DF_CPU=$(F_CPU) -DBAUD=$(BAUD)
# -I$(LIBDIR)
CFLAGS = -O1 -g2 -gstabs -std=gnu99 -Wall
CFLAGS += -I$(LIBDIR)
## Use short (8-bit) data types
CFLAGS += -funsigned-char -funsigned-bitfields -fpack-struct -fshort-enums
## copied from eclipse avr:
CFLAGS += -MMD -MP
## Splits up object files per function
CFLAGS += -ffunction-sections -fdata-sections -std=gnu99 -MT"$@" -MF"$(@:.o=.d)"
LDFLAGS = -Wl,-Map,$(TARGET).map
## Optional, but often ends up with smaller code
# LDFLAGS += -Wl,--gc-sections
## Relax shrinks code even more, but makes disassembly messy
## LDFLAGS += -Wl,--relax
LDFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm
## LDFLAGS += -Wl,-u,vfprintf -lprintf_min      ## for smaller printf
TARGET_ARCH = -mmcu=$(MCU)

all: clean flash_arduino # $(TARGET).hex

## Explicit pattern rules:
##  To make .o files from .c files
%.o: %.c $(HEADERS) Makefile squeaky_clean
	$(CC) $(CFLAGS) $(CPPFLAGS) $(TARGET_ARCH) ASDF -c -o $@ $<;

$(TARGET).elf: $(OBJECTS)
	$(CC) $(LDFLAGS) $(TARGET_ARCH) $^ $(LDLIBS) -o $@

%.hex: %.elf
	 # $(OBJCOPY) -j .text -j .data -O ihex $< $@
	$(OBJCOPY) -R .eeprom -R .fuse -R .lock -R .signature -O ihex $< $@
	# $(OBJCOPY) -j .text -j .data -O ihex $< $@

%.eeprom: %.elf
	$(OBJCOPY) -j .eeprom --change-section-lma .eeprom=0 -O ihex $< $@

%.lst: %.elf
	$(OBJDUMP) -h -S $< > $@

## These targets don't have files named after them
.PHONY: flash_stk all  disassemble disasm eeprom size clean squeaky_clean flash debug flash_arduino # ann #  fuses



# debug:
# 	@echo
# 	@echo "Source files:"   $(SOURCES)
# 	@echo "MCU, F_CPU, BAUD:"  $(MCU), $(F_CPU), $(BAUD)
# 	@echo

# Optionally create listing file from .elf
# This creates approximate assembly-language equivalent of your code.
# Useful for debugging time-sensitive bits,
# or making sure the compiler does what you want.
disassemble: $(TARGET).lst

disasm: disassemble

# Optionally show how big the resulting program is
size:  $(TARGET).elf
	$(AVRSIZE) -C --mcu=$(MCU) $(TARGET).elf 

clean:
	echo $(SOURCES)

	rm -f *.elf *.hex *.obj $(OBJECTS) *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom

squeaky_clean:
	rm -f *.elf *.hex *.obj $(OBJECTS) *.o *.d *.eep *.lst *.lss *.sym *.map *~ *.eeprom

##########------------------------------------------------------##########
##########              Programmer-specific details             ##########
##########           Flashing code to AVR using avrdude         ##########
##########------------------------------------------------------##########

flash_isp: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER_TYPE_ISP) -p $(MCU) -V -U flash:w:$<

flash_stk: $(TARGET).hex
	$(AVRDUDE) -c $(PROGRAMMER_TYPE_STK) -p $(MCU) -V $(PROGRAMMER_ARGS_STK) -U flash:w:$<

## An alias
program: flash

flash_eeprom: $(TARGET).eeprom
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -U eeprom:w:$<

avrdude_terminal:
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nt

## If you've got multiple programmers that you use,
## you can define them here so that it's easy to switch.
## To invoke, use something like `make flash_arduinoISP`
flash_usbtiny: PROGRAMMER_TYPE = usbtiny
flash_usbtiny: PROGRAMMER_ARGS =  # USBTiny works with no further arguments
flash_usbtiny: flash

flash_usbasp: PROGRAMMER_TYPE = usbasp
flash_usbasp: PROGRAMMER_ARGS =  # USBasp works with no further arguments
flash_usbasp: flash

flash_arduinoISP: PROGRAMMER_TYPE = avrisp
flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P /dev/ttyACM0
## (for windows) flash_arduinoISP: PROGRAMMER_ARGS = -b 19200 -P com5
flash_arduinoISP: flash

flash_109: PROGRAMMER_TYPE = avr109
flash_109: PROGRAMMER_ARGS = -b 9600 -P /dev/ttyUSB0
flash_109: flash

flash_arduino: PROGRAMMER_TYPE = arduino
# flash_arduino: PROGRAMMER_ARGS = $(PROGRAMMER_ARGS)
flash_arduino: $(TARGET).hex
	echo $(SOURCES)
	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) -V $(PROGRAMMER_ARGS) -U flash:w:$<


##########------------------------------------------------------##########
##########       Fuse settings and suitable defaults            ##########
##########------------------------------------------------------##########

# ## Mega 48, 88, 168, 328 default values
# LFUSE = 0x62
# HFUSE = 0xdf
# EFUSE = 0x00

# ## Generic
# FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m

# fuses:
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) \
# 	           $(PROGRAMMER_ARGS) $(FUSE_STRING)
# show_fuses:
# 	$(AVRDUDE) -c $(PROGRAMMER_TYPE) -p $(MCU) $(PROGRAMMER_ARGS) -nv

# ## Called with no extra definitions, sets to defaults
# set_default_fuses:  FUSE_STRING = -U lfuse:w:$(LFUSE):m -U hfuse:w:$(HFUSE):m -U efuse:w:$(EFUSE):m
# set_default_fuses:  fuses

# ## Set the fuse byte for full-speed mode
# ## Note: can also be set in firmware for modern chips
# set_fast_fuse: LFUSE = 0xE2
# set_fast_fuse: FUSE_STRING = -U lfuse:w:$(LFUSE):m
# set_fast_fuse: fuses

# ## Set the EESAVE fuse byte to preserve EEPROM across flashes
# set_eeprom_save_fuse: HFUSE = 0xD7
# set_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
# set_eeprom_save_fuse: fuses

# ## Clear the EESAVE fuse byte
# clear_eeprom_save_fuse: FUSE_STRING = -U hfuse:w:$(HFUSE):m
# clear_eeprom_save_fuse: fuses

debug:
	@echo "Debug"
	python scripts/serial_echo.py $(ELASTIC_NODE_DEBUG_SERIAL) $(BAUD) 

bitfile:
	@echo "Fetching bitfile"
	./scripts/remote-program.sh

test: bitfile serial

serial:
	@echo "Initiating communication"
	python scripts/serial_test.py

# ann:
# 	# @echo caught target $@
# 	python scripts/serial_test.py ann

# send any other targets to the python script
.DEFAULT:
	# @echo caught target $@
	python scripts/serial_test.py $@
