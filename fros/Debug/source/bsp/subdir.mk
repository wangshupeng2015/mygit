################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/bsp/vectors.c \
../source/bsp/xgpiops.c \
../source/bsp/xil_assert.c \
../source/bsp/xil_exception.c \
../source/bsp/xplatform_info.c \
../source/bsp/xscuwdt.c \
../source/bsp/xscuwdt_g.c \
../source/bsp/xscuwdt_sinit.c 

OBJS += \
./source/bsp/vectors.o \
./source/bsp/xgpiops.o \
./source/bsp/xil_assert.o \
./source/bsp/xil_exception.o \
./source/bsp/xplatform_info.o \
./source/bsp/xscuwdt.o \
./source/bsp/xscuwdt_g.o \
./source/bsp/xscuwdt_sinit.o 

C_DEPS += \
./source/bsp/vectors.d \
./source/bsp/xgpiops.d \
./source/bsp/xil_assert.d \
./source/bsp/xil_exception.d \
./source/bsp/xplatform_info.d \
./source/bsp/xscuwdt.d \
./source/bsp/xscuwdt_g.d \
./source/bsp/xscuwdt_sinit.d 


# Each subdirectory must supply rules for building sources it contributes
source/bsp/%.o: ../source/bsp/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wanshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


