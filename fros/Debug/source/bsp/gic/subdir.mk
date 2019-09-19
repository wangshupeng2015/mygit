################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/bsp/gic/xscugic.c \
../source/bsp/gic/xscugic_g.c \
../source/bsp/gic/xscugic_sinit.c 

OBJS += \
./source/bsp/gic/xscugic.o \
./source/bsp/gic/xscugic_g.o \
./source/bsp/gic/xscugic_sinit.o 

C_DEPS += \
./source/bsp/gic/xscugic.d \
./source/bsp/gic/xscugic_g.d \
./source/bsp/gic/xscugic_sinit.d 


# Each subdirectory must supply rules for building sources it contributes
source/bsp/gic/%.o: ../source/bsp/gic/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wangshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


