################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/portable/port.c 

S_UPPER_SRCS += \
../source/portable/portASM.S 

OBJS += \
./source/portable/port.o \
./source/portable/portASM.o 

S_UPPER_DEPS += \
./source/portable/portASM.d 

C_DEPS += \
./source/portable/port.d 


# Each subdirectory must supply rules for building sources it contributes
source/portable/%.o: ../source/portable/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wangshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '

source/portable/%.o: ../source/portable/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I"/home/wangshupeng/workspace/fros/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


