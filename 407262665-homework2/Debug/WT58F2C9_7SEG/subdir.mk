################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../WT58F2C9_7SEG/init-default.c \
../WT58F2C9_7SEG/init-soc.c \
../WT58F2C9_7SEG/interrupt-c-ext.c \
../WT58F2C9_7SEG/main.c 

OBJS += \
./WT58F2C9_7SEG/init-default.o \
./WT58F2C9_7SEG/init-soc.o \
./WT58F2C9_7SEG/interrupt-c-ext.o \
./WT58F2C9_7SEG/main.o 

C_DEPS += \
./WT58F2C9_7SEG/init-default.d \
./WT58F2C9_7SEG/init-soc.d \
./WT58F2C9_7SEG/interrupt-c-ext.d \
./WT58F2C9_7SEG/main.d 


# Each subdirectory must supply rules for building sources it contributes
WT58F2C9_7SEG/%.o: ../WT58F2C9_7SEG/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: Andes C Compiler'
	$(CROSS_COMPILE)gcc -DREMAP -DUSE_C_EXT -O0 -mcmodel=medium -g3 -Wall -mcpu=n801 -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


