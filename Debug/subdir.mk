################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
OBJ_SRCS += \
../teapot.obj 

CPP_SRCS += \
../Color.cpp \
../Matrix.cpp \
../Model.cpp \
../Raster.cpp \
../Triangle2D.cpp \
../Vector2.cpp \
../main.cpp \
../test.cpp 

OBJS += \
./Color.o \
./Matrix.o \
./Model.o \
./Raster.o \
./Triangle2D.o \
./Vector2.o \
./main.o \
./test.o 

CPP_DEPS += \
./Color.d \
./Matrix.d \
./Model.d \
./Raster.d \
./Triangle2D.d \
./Vector2.d \
./main.d \
./test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: Cygwin C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


