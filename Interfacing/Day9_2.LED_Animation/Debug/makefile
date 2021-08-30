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
Day9_2.LED_Animation.lss \

FLASH_IMAGE += \
Day9_2.LED_Animation.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Day9_2.LED_Animation.elf secondary-outputs

# Tool invocations
Day9_2.LED_Animation.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Day9_2.LED_Animation.map -mmcu=atmega16 -o "Day9_2.LED_Animation.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Day9_2.LED_Animation.lss: Day9_2.LED_Animation.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Day9_2.LED_Animation.elf  >"Day9_2.LED_Animation.lss"
	@echo 'Finished building: $@'
	@echo ' '

Day9_2.LED_Animation.hex: Day9_2.LED_Animation.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Day9_2.LED_Animation.elf  "Day9_2.LED_Animation.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Day9_2.LED_Animation.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 Day9_2.LED_Animation.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Day9_2.LED_Animation.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
