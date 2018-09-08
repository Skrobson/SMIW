################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../ADC.cpp \
../DistanceSensor.cpp \
../HumiditySensor.cpp \
../ICPTimer.cpp \
../SH1106.cpp \
../SPI.cpp \
../ScreenController.cpp \
../WaterPump.cpp \
../button.cpp \
../dht.cpp \
../main.cpp 

OBJS += \
./ADC.o \
./DistanceSensor.o \
./HumiditySensor.o \
./ICPTimer.o \
./SH1106.o \
./SPI.o \
./ScreenController.o \
./WaterPump.o \
./button.o \
./dht.o \
./main.o 

CPP_DEPS += \
./ADC.d \
./DistanceSensor.d \
./HumiditySensor.d \
./ICPTimer.d \
./SH1106.d \
./SPI.d \
./ScreenController.d \
./WaterPump.d \
./button.d \
./dht.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: AVR C++ Compiler'
	avr-g++ -Wall -Os -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -funsigned-char -funsigned-bitfields -fno-exceptions -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


