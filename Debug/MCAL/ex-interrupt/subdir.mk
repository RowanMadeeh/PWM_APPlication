################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ex-interrupt/GIE.c \
../MCAL/ex-interrupt/interrupt.c 

OBJS += \
./MCAL/ex-interrupt/GIE.o \
./MCAL/ex-interrupt/interrupt.o 

C_DEPS += \
./MCAL/ex-interrupt/GIE.d \
./MCAL/ex-interrupt/interrupt.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/ex-interrupt/%.o: ../MCAL/ex-interrupt/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


