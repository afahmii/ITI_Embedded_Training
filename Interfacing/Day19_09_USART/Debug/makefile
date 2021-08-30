################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/UART/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
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
Day19_09_USART.lss \

FLASH_IMAGE += \
Day19_09_USART.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Day19_09_USART.elf secondary-outputs

# Tool invocations
Day19_09_USART.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Day19_09_USART.map -mmcu=atmega32 -o "Day19_09_USART.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Day19_09_USART.lss: Day19_09_USART.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Day19_09_USART.elf  >"Day19_09_USART.lss"
	@echo 'Finished building: $@'
	@echo ' '

Day19_09_USART.hex: Day19_09_USART.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Day19_09_USART.elf  "Day19_09_USART.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Day19_09_USART.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Day19_09_USART.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Day19_09_USART.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
