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
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
Day9_5.Traffic.lss \

FLASH_IMAGE += \
Day9_5.Traffic.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Day9_5.Traffic.elf secondary-outputs

# Tool invocations
Day9_5.Traffic.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Day9_5.Traffic.map -mmcu=atmega32 -o "Day9_5.Traffic.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Day9_5.Traffic.lss: Day9_5.Traffic.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Day9_5.Traffic.elf  >"Day9_5.Traffic.lss"
	@echo 'Finished building: $@'
	@echo ' '

Day9_5.Traffic.hex: Day9_5.Traffic.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Day9_5.Traffic.elf  "Day9_5.Traffic.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Day9_5.Traffic.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Day9_5.Traffic.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Day9_5.Traffic.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
