################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include source/portable/subdir.mk
-include source/platform/subdir.mk
-include source/lib/subdir.mk
-include source/kernel/subdir.mk
-include source/bsp/timer/subdir.mk
-include source/bsp/gic/subdir.mk
-include source/bsp/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
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
SECONDARY_FLASH += \
fros.bin \

SECONDARY_SIZE += \
fros.siz \


# All Target
all: fros.elf secondary-outputs

# Tool invocations
fros.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM Cross C Linker'
<<<<<<< HEAD
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "/home/wanshupeng/workspace/fros/source/kernel/ld.lds" -Xlinker --gc-sections -Wl,-Map,"fros.map" -o "fros.elf" $(OBJS) $(USER_OBJS) $(LIBS)
=======
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -T "/home/wangshupeng/workspace/fros/source/kernel/ld.lds" -Xlinker --gc-sections -Wl,-Map,"fros.map" -o "fros.elf" $(OBJS) $(USER_OBJS) $(LIBS)
>>>>>>> 5dc63b0d5d606ffd3190c90c150681be878cfbac
	@echo 'Finished building target: $@'
	@echo ' '

fros.bin: fros.elf
	@echo 'Invoking: GNU ARM Cross Create Flash Image'
	arm-none-eabi-objcopy -O binary "fros.elf"  "fros.bin"
	@echo 'Finished building: $@'
	@echo ' '

fros.siz: fros.elf
	@echo 'Invoking: GNU ARM Cross Print Size'
	arm-none-eabi-size --format=berkeley "fros.elf"
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(OBJS)$(SECONDARY_FLASH)$(SECONDARY_SIZE)$(ASM_DEPS)$(S_UPPER_DEPS)$(C_DEPS) fros.elf
	-@echo ' '

secondary-outputs: $(SECONDARY_FLASH) $(SECONDARY_SIZE)

.PHONY: all clean dependents

-include ../makefile.targets
