################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../source/kernel/FreeRTOS_tick_config.c \
../source/kernel/ParTest.c \
../source/kernel/croutine.c \
../source/kernel/heap_5.c \
../source/kernel/init.c \
../source/kernel/list.c \
../source/kernel/queue.c \
../source/kernel/tasks.c \
../source/kernel/timers.c 

S_UPPER_SRCS += \
../source/kernel/head.S \
../source/kernel/hyp_entry.S \
../source/kernel/svc_entry.S 

OBJS += \
./source/kernel/FreeRTOS_tick_config.o \
./source/kernel/ParTest.o \
./source/kernel/croutine.o \
./source/kernel/head.o \
./source/kernel/heap_5.o \
./source/kernel/hyp_entry.o \
./source/kernel/init.o \
./source/kernel/list.o \
./source/kernel/queue.o \
./source/kernel/svc_entry.o \
./source/kernel/tasks.o \
./source/kernel/timers.o 

S_UPPER_DEPS += \
./source/kernel/head.d \
./source/kernel/hyp_entry.d \
./source/kernel/svc_entry.d 

C_DEPS += \
./source/kernel/FreeRTOS_tick_config.d \
./source/kernel/ParTest.d \
./source/kernel/croutine.d \
./source/kernel/heap_5.d \
./source/kernel/init.d \
./source/kernel/list.d \
./source/kernel/queue.d \
./source/kernel/tasks.d \
./source/kernel/timers.d 


# Each subdirectory must supply rules for building sources it contributes
source/kernel/%.o: ../source/kernel/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross C Compiler'
<<<<<<< HEAD
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wanshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
=======
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -I"/home/wangshupeng/workspace/fros/include" -std=gnu11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
>>>>>>> 5dc63b0d5d606ffd3190c90c150681be878cfbac
	@echo 'Finished building: $<'
	@echo ' '

source/kernel/%.o: ../source/kernel/%.S
	@echo 'Building file: $<'
	@echo 'Invoking: GNU ARM Cross Assembler'
<<<<<<< HEAD
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I"/home/wanshupeng/workspace/fros/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
=======
	arm-none-eabi-gcc -mcpu=cortex-a7 -march=armv7-a -marm -mlittle-endian -mfloat-abi=hard -mfpu=vfpv4 -O0 -fmessage-length=0 -fsigned-char -ffunction-sections -fdata-sections  -g3 -x assembler-with-cpp -I"/home/wangshupeng/workspace/fros/include" -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
>>>>>>> 5dc63b0d5d606ffd3190c90c150681be878cfbac
	@echo 'Finished building: $<'
	@echo ' '


