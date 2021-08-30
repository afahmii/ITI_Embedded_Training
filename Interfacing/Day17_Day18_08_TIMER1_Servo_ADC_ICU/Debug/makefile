################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include MCAL/Timer/subdir.mk
-include MCAL/GIE/subdir.mk
-include MCAL/DIO/subdir.mk
-include MCAL/ADC/subdir.mk
-include HAL/LCD/subdir.mk
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
Day17_Day18_08_TIMER1_Servo_ADC_ICU.lss \

FLASH_IMAGE += \
Day17_Day18_08_TIMER1_Servo_ADC_ICU.hex \

SIZEDUMMY += \
sizedummy \


# All Target
all: Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf secondary-outputs

# Tool invocations
Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,Day17_Day18_08_TIMER1_Servo_ADC_ICU.map -mmcu=atmega32 -o "Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

Day17_Day18_08_TIMER1_Servo_ADC_ICU.lss: Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf  >"Day17_Day18_08_TIMER1_Servo_ADC_ICU.lss"
	@echo 'Finished building: $@'
	@echo ' '

Day17_Day18_08_TIMER1_Servo_ADC_ICU.hex: Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf  "Day17_Day18_08_TIMER1_Servo_ADC_ICU.hex"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) Day17_Day18_08_TIMER1_Servo_ADC_ICU.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
