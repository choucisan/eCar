################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Drivers/Delay/%.o: ../Drivers/Delay/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ti/ccs2011/ccs/tools/compiler/ti-cgt-armllvm_4.0.2.LTS/bin/tiarmclang.exe" -c @"device.opt"  -march=thumbv6m -mcpu=cortex-m0plus -mfloat-abi=soft -mlittle-endian -mthumb -O0 -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/ADC" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/sensor" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/Delay" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/printf" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/line" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/Encoder" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/OLED_Hardware_I2C" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/MOTOR" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/OLED_Software_I2C" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/OLED_Software_SPI" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/control" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Debug" -I"C:/ti/mspm0_sdk_2_05_00_05/source/third_party/CMSIS/Core/Include" -I"C:/ti/mspm0_sdk_2_05_00_05/source" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/MSPM0" -I"C:/Users/zhangwei/workspace_ccstheia/oled-software-i2c/Drivers/IMU" -DMOTION_DRIVER_TARGET_MSPM0 -DMPU6050 -D__MSPM0G3507__ -gdwarf-3 -MMD -MP -MF"Drivers/Delay/$(basename $(<F)).d_raw" -MT"$(@)"  $(GEN_OPTS__FLAG) -o"$@" "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


