# Usage with Vitis IDE:
# In Vitis IDE create a Single Application Debug launch configuration,
# change the debug type to 'Attach to running target' and provide this 
# tcl script in 'Execute Script' option.
# Path of this script: D:\vivado_first\20260427_Microblaze_GPIO_4\vitis_workspace\Microblaze_fnd_upcount_system\_ide\scripts\debugger_microblaze_fnd_upcount-default.tcl
# 
# 
# Usage with xsct:
# To debug using xsct, launch xsct and run below command
# source D:\vivado_first\20260427_Microblaze_GPIO_4\vitis_workspace\Microblaze_fnd_upcount_system\_ide\scripts\debugger_microblaze_fnd_upcount-default.tcl
# 
connect -url tcp:127.0.0.1:3121
targets -set -filter {jtag_cable_name =~ "Digilent Basys3 210183BB7A20A" && level==0 && jtag_device_ctx=="jsn-Basys3-210183BB7A20A-0362d093-0"}
fpga -file D:/vivado_first/20260427_Microblaze_GPIO_4/vitis_workspace/Microblaze_fnd_upcount/_ide/bitstream/design_1_wrapper.bit
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
loadhw -hw D:/vivado_first/20260427_Microblaze_GPIO_4/vitis_workspace/design_1_wrapper/export/design_1_wrapper/hw/design_1_wrapper.xsa -regs
configparams mdm-detect-bscan-mask 2
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
rst -system
after 3000
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
dow D:/vivado_first/20260427_Microblaze_GPIO_4/vitis_workspace/Microblaze_fnd_upcount/Debug/Microblaze_fnd_upcount.elf
targets -set -nocase -filter {name =~ "*microblaze*#0" && bscan=="USER2" }
con
