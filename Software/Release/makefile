################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(CC_DEPS)),)
-include $(CC_DEPS)
endif
ifneq ($(strip $(C++_DEPS)),)
-include $(C++_DEPS)
endif
ifneq ($(strip $(C_UPPER_DEPS)),)
-include $(C_UPPER_DEPS)
endif
ifneq ($(strip $(CXX_DEPS)),)
-include $(CXX_DEPS)
endif
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
ifneq ($(strip $(CPP_DEPS)),)
-include $(CPP_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
i-greenhouse.lss \

FLASH_IMAGE += \
i-greenhouse.hex \

EEPROM_IMAGE += \
i-greenhouse.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: i-greenhouse.elf secondary-outputs

# Tool invocations
i-greenhouse.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C++ Linker'
	avr-g++ -Wl,-Map,i-greenhouse.map,--cref -mrelax -Wl,--gc-sections -mmcu=atmega32 -o "i-greenhouse.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

i-greenhouse.lss: i-greenhouse.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S i-greenhouse.elf  >"i-greenhouse.lss"
	@echo 'Finished building: $@'
	@echo ' '

i-greenhouse.hex: i-greenhouse.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex i-greenhouse.elf  "i-greenhouse.hex"
	@echo 'Finished building: $@'
	@echo ' '

i-greenhouse.eep: i-greenhouse.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex i-greenhouse.elf  "i-greenhouse.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: i-greenhouse.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 i-greenhouse.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(C_UPPER_DEPS)$(S_DEPS)$(LSS)$(C_DEPS)$(FLASH_IMAGE)$(CC_DEPS)$(ELFS)$(C++_DEPS)$(OBJS)$(CXX_DEPS)$(ASM_DEPS)$(EEPROM_IMAGE)$(SIZEDUMMY)$(S_UPPER_DEPS)$(CPP_DEPS) i-greenhouse.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents

-include ../makefile.targets
