################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/subdir.mk
-include HAL/LCD/subdir.mk
-include HAL/Keypad/subdir.mk
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
Day12_03_KeypadDriver.lss \

FLASH_IMAGE += \
Day12_03_KeypadDriver.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Day12_03_KeypadDriver.elf secondary-outputs

# Tool invocations
Day12_03_KeypadDriver.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Day12_03_KeypadDriver.map -mmcu=atmega32 -o "Day12_03_KeypadDriver.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Day12_03_KeypadDriver.lss: Day12_03_KeypadDriver.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Day12_03_KeypadDriver.elf  >"Day12_03_KeypadDriver.lss"
	@echo 'Finished building: $@'
	@echo ' '

Day12_03_KeypadDriver.hex: Day12_03_KeypadDriver.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Day12_03_KeypadDriver.elf  "Day12_03_KeypadDriver.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Day12_03_KeypadDriver.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Day12_03_KeypadDriver.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Day12_03_KeypadDriver.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
