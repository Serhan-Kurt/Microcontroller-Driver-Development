################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (12.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../myDrivers/Src/GPIO.c \
../myDrivers/Src/RCC.c 

OBJS += \
./myDrivers/Src/GPIO.o \
./myDrivers/Src/RCC.o 

C_DEPS += \
./myDrivers/Src/GPIO.d \
./myDrivers/Src/RCC.d 


# Each subdirectory must supply rules for building sources it contributes
myDrivers/Src/%.o myDrivers/Src/%.su myDrivers/Src/%.cyclo: ../myDrivers/Src/%.c myDrivers/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m4 -std=gnu11 -g3 -DDEBUG -DSTM32 -DNUCLEO_F446ZE -DSTM32F4 -DSTM32F446ZETx -c -I../Inc -I"C:/Users/serha/STM32CubeIDE/workspace_1.15.1/new/Erhan.N/myDrivers/Inc" -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-myDrivers-2f-Src

clean-myDrivers-2f-Src:
	-$(RM) ./myDrivers/Src/GPIO.cyclo ./myDrivers/Src/GPIO.d ./myDrivers/Src/GPIO.o ./myDrivers/Src/GPIO.su ./myDrivers/Src/RCC.cyclo ./myDrivers/Src/RCC.d ./myDrivers/Src/RCC.o ./myDrivers/Src/RCC.su

.PHONY: clean-myDrivers-2f-Src

