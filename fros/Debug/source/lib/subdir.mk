################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/lib/print.c \
../source/lib/printformat.c 

OBJS += \
./source/lib/print.o \
./source/lib/printformat.o 

C_DEPS += \
./source/lib/print.d \
./source/lib/printformat.d 


# Each subdirectory must supply rules for building sources it contributes
source/lib/%.o: ../source/lib/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wangshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


