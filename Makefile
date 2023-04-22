#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple makefile for the MSP432 and the native platform
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.dep - Generates <FILE>.dep dependency file for <FILE>.c source file
#      <FILE>.i - Generates <FILE>.i preprocessed file for <FILE>.c source file
#      <FILE>.asm - Generates <FILE>.asm assembly file for <FILE>.c source file
#      <FILE>.o - Generates <FILE>.o object file for <FILE>.c source file
#      build - Builds and links all source files
#      compile-all - Generates all object files
#      clean - removes all generated files
#
# Platform Overrides:
#	   PLATFORM - The target platform you are compiling for (Native-HOST or Cross-MSP432)
#	   CC - Compiler that will perform the build (Native or Cross)
#	   LD - Linker that will perform the linking process (Native or Cross)
#	   SIZE_EXC - Display sies of the compìled sections (Native or Cross)
#	   CFLAGS - C-programming flags for gcc (Native or Cross)
#	   LDFLAGS - Linker Flags (Native or Cross)
#------------------------------------------------------------------------------
include sources.mk

BASENAME = c1final
TARGET = $(BASENAME).out
GEN_FLAGS = -Wall -Werror -g -O0 -std=c99 
ifeq ($(PLATFORM),MSP432)
# Platform Specific Flags
LINKER_FILE = $(CURDIR)/../msp432p401r.lds
# Architecture Specific Flags
CPU = cortex-m4
ARCH = thumb
SPECS = nosys.specs
ARMFLAGS = -mcpu=$(CPU) -m$(ARCH) --specs=$(SPECS) -march=armv7e-m -mfloat-abi=hard -mfpu=fpv4-sp-d16
# Compile Defines
CC = arm-none-eabi-gcc
LD = arm-none-eabi-ld
SIZE_EXC = arm-none-eabi-size
CFLAGS = $(GEN_FLAGS) $(ARMFLAGS) -D$(PLATFORM) -D$(OPTION) -D$(COURSE)
LDFLAGS = -Wl,-Map=$(BASENAME).map -T $(LINKER_FILE)
OBJDUMP = arm-none-eabi-objdump	
else
ifneq ($(PLATFORM),HOST)
$(warning Platform $(PLATFORM) not recognized. Using HOST platform.)
PLATFORM = HOST
endif
# Compile Defines
CC = gcc
LD = ld
SIZE_EXC = size
CFLAGS = -Wall -g -O0 -std=c99 -D$(PLATFORM)
LDFLAGS = -Wl,-Map=$(BASENAME).map
OBJDUMP = objdump
endif

#Compile time switch options
ifdef OPTION
CFLAGS += -D$(OPTION)
endif
ifdef COURSE
CFLAGS +=-D$(COURSE)
endif

DEPS = $(SOURCES:.c=.dep)
PREPS = $(SOURCES:.c=.i)
ASSM = $(SOURCES:.c=.asm)
OBJS = $(SOURCES:.c=.o)

#Dependency files output
%.dep : %.c
	$(CC) -M $< $(CFLAGS) $(INCLUDES) -o $@

#Preprocessed output
%.i : %.c
	$(CC) -E $< $(CFLAGS) $(INCLUDES) -o $@

#Assembly output
%.asm : %.c
	$(CC) -S $< $(CFLAGS) $(INCLUDES) -o $@

#Object output
%.o : %.c
	$(CC) -c $< $(CFLAGS) $(INCLUDES) -o $@

#Executable output
$(TARGET): $(OBJS)
	$(CC) $(OBJS) $(INCLUDES) $(CFLAGS) $(LDFLAGS) -o $@

#Assembly from output
$(BASENAME).asm : $(TARGET)
	$(OBJDUMP) -d $(TARGET) >> $@

.PHONY: build
build: $(TARGET) $(DEPS) 
	$(SIZE_EXC) -Atd $(TARGET)

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: clean
clean: 
	rm -f $(DEPS) $(PREPS) $(ASSM) $(OBJS) $(TARGET) $(BASENAME).map