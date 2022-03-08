################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.obj: ../Core/Src/%.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"E:/ti/css1040/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="E:/Project/TexasInstruments_TIVAC/Ejemplo2_Gpio_Input" --include_path="E:/Project/TexasInstruments_TIVAC/Ejemplo2_Gpio_Input/CMSIS/Include" --include_path="E:/Project/TexasInstruments_TIVAC/Ejemplo2_Gpio_Input/Core/Inc" --include_path="E:/ti/css1040/ccs/tools/compiler/ti-cgt-arm_20.2.6.LTS/include" --define=ccs="ccs" --define=PART_TM4C123GH6PM -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="Core/Src/$(basename $(<F)).d_raw" --obj_directory="Core/Src" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


