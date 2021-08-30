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
Day14_05_GIE.lss \

SIZEDUMMY += \
sizedummy \


# All Target
all: Day14_05_GIE.elf secondary-outputs

# Tool invocations
Day14_05_GIE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Day14_05_GIE.map -mmcu=atmega32 -o "Day14_05_GIE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Day14_05_GIE.lss: Day14_05_GIE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Day14_05_GIE.elf  >"Day14_05_GIE.lss"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Day14_05_GIE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Day14_05_GIE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Day14_05_GIE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
