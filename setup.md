# Introduction #

---

这篇文章讲解了开发环境的搭建步骤，以及相关工具的下载地址和配置方法,最后给出了工程的编译方法和步骤

Sections:


---


# 环境搭建和安装 #
## 1、下载必备的工具 ##
  1. elipse 和 c++开发插件 [下载地址](http://www.eclipse.org/downloads/download.php?file=/technology/epp/downloads/release/juno/R/eclipse-cpp-juno-win32.zip)
  1. [eclipse 的arm开发插件](http://sourceforge.net/projects/gnuarmeclipse/)
  1. [Yagarto(arm-none-eabi-gcc) arm的开发工具链](http://www.yagarto.de/)
  1. [zylincdt gdb调试插件](http://opensource.zylin.com/embeddedcdt.html)

---

## 2、eclipse cdt的安装和配置 ##
> eclipse cdt下载后，无需安装，解压后运行根目录下的eclipse.exe即可,为了支持arm的开发还需要做一些针对性的设置。请点击这里查看详细说明 [eclipse cdt详细配置说明](eclipsesetup.md)

---

## 3、arm插件的安装和配置 ##
  1. [GNU ARM Eclipse Plug-in的安装方法](http://gnuarmeclipse.livius.net/wiki/Plug-in_installation)
  1. 看看[第二版的功能](http://gnuarmeclipse.livius.net/wiki/Second_edition_roadmap)，挺期待的。


---

## 4、交叉工具链的安装和配置 ##

> ## 交叉工具链有很多种可以供选择 ##
  * [可供支持的交叉工具链](http://gnuarmeclipse.livius.net/wiki/Main_Page#Supported_toolchains)，这里还有一个[gcc-arm-embedded](https://launchpad.net/gcc-arm-embedded)

  * linux下选择 Sourcery CodeBench Lite ARM,但是下载起来挺麻烦的，这里有个下载地址是[leaflabs维护的分支](http://static.leaflabs.com/pub/codesourcery/)可以选择windows和linux下的版本。
  * windows下选择 [yagarto](http://www.yagarto.de/index.html)，因为yagaro现在不提供linux的版本了，你也可以自己去下载源代码编译。yagarto在windows下安装的时候，特别注意:安装目录中不用包含空格或中文。

  * 安装好了以后还需要设置环境变量，否则可能会出现找不到工具链的情况.
    * **[windows下设置环境变量](http://gnuarmeclipse.livius.net/wiki/Toolchain_installation_on_Windows)
    *** [linux下设置环境变量](http://gnuarmeclipse.livius.net/wiki/Toolchain_installation_on_Linux)

---

## 5、gdb调试插件zylicdt的安装和配置 ##

---

## 6、使用jlink进行调试 ##
    1. 这里详细的讲解了如何[使用jlink gdbserver进行调试](http://gnuarmeclipse.livius.net/wiki/How_to_use_the_J-Link_probe_with_the_GDB_Server)
    1. [使用openocd进行调试](http://gnuarmeclipse.livius.net/wiki/How_to_use_the_J-Link_probe_with_OpenOCD)

---

# 编译工程 #

---

# 调试工程 #