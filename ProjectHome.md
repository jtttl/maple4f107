# maple for stm32f107 #

本项目的目的是想开发一个基于实时MCU的一个通用无操作系统的应用框架。用于简单应用程序开发。
开发环境可以支持跨平台linux和windows
特点：
  * .移植性好
  * .效率高、简单、通用
  * .编程简单，有一个通用的应用程序框架
  * .有一个统一的设备驱动框架和API
  * .可以采用c和c++来开发应用模块
  * .具有自动加载应用模块、驱动模块、核心模块的功能
开发环境
  * 开发环境: ubuntu 和 window7
  * IDE：　eclipse cdt + arm-plugin + Yagarto(arm-none-eabi-gcc) + zylincdt
  * jtag： jlink(jlink gdbserver windows7) + openocd(ubuntu)
  * 硬件平台 : stm32f107

> ## [查看安装和使用说明](setup.md) ##