################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/bsp/timer/xscutimer.c \
../source/bsp/timer/xscutimer_g.c \
../source/bsp/timer/xscutimer_sinit.c 

OBJS += \
./source/bsp/timer/xscutimer.o \
./source/bsp/timer/xscutimer_g.o \
./source/bsp/timer/xscutimer_sinit.o 

C_DEPS += \
./source/bsp/timer/xscutimer.d \
./source/bsp/timer/xscutimer_g.d \
./source/bsp/timer/xscutimer_sinit.d 


# Each subdirectory must supply rules for building sources it contributes
source/bsp/timer/%.o: ../source/bsp/timer/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wanshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


