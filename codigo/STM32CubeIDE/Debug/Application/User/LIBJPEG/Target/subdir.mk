################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (10.3-2021.10)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
D:/TouchGFXProjects/ECG_SDCard_Display/LIBJPEG/Target/jdata_conf.c 

C_DEPS += \
./Application/User/LIBJPEG/Target/jdata_conf.d 

OBJS += \
./Application/User/LIBJPEG/Target/jdata_conf.o 


# Each subdirectory must supply rules for building sources it contributes
Application/User/LIBJPEG/Target/jdata_conf.o: D:/TouchGFXProjects/ECG_SDCard_Display/LIBJPEG/Target/jdata_conf.c Application/User/LIBJPEG/Target/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m7 -std=gnu11 -g3 -DUSE_HAL_DRIVER -DSTM32F769xx -DDEBUG -c -I../../Core/Inc -I../../Drivers/CMSIS/Include -I../../TouchGFX/target -I../../Drivers/STM32F7xx_HAL_Driver/Inc -I../../Drivers/CMSIS/Device/ST/STM32F7xx/Include -I../../TouchGFX/App -I../../Middlewares/Third_Party/FreeRTOS/Source/CMSIS_RTOS_V2 -I../../TouchGFX/target/generated -I../../Middlewares/Third_Party/FreeRTOS/Source/portable/GCC/ARM_CM7/r0p1 -I../../Drivers/BSP/Components/Common -I../../Drivers/STM32F7xx_HAL_Driver/Inc/Legacy -I../../Middlewares/Third_Party/FreeRTOS/Source/include -I../../LIBJPEG/App -I../../LIBJPEG/Target -I../../Utilities/JPEG -I../../Middlewares/Third_Party/LibJPEG/include -I../../Middlewares/ST/touchgfx/framework/include -I../../TouchGFX/generated/fonts/include -I../../TouchGFX/generated/gui_generated/include -I../../TouchGFX/generated/images/include -I../../TouchGFX/generated/texts/include -I../../TouchGFX/generated/videos/include -I../../TouchGFX/gui/include -I../../FATFS/Target -I../../FATFS/App -I../../Middlewares/Third_Party/FatFs/src -Os -ffunction-sections -fdata-sections -Wall -fstack-usage -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfpu=fpv5-d16 -mfloat-abi=hard -mthumb -o "$@"

clean: clean-Application-2f-User-2f-LIBJPEG-2f-Target

clean-Application-2f-User-2f-LIBJPEG-2f-Target:
	-$(RM) ./Application/User/LIBJPEG/Target/jdata_conf.d ./Application/User/LIBJPEG/Target/jdata_conf.o ./Application/User/LIBJPEG/Target/jdata_conf.su

.PHONY: clean-Application-2f-User-2f-LIBJPEG-2f-Target

