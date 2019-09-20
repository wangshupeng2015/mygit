################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/platform/macuart.c 

OBJS += \
./source/platform/macuart.o 

C_DEPS += \
./source/platform/macuart.d 


# Each subdirectory must supply rules for building sources it contributes
source/platform/%.o: ../source/platform/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wanshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


