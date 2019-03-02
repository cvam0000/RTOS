# RTOS (REAL TIME OPERATING SYSTEM) 
###### When it Matters, it Runs on RTOS

# What RTOS needs to be Deterministic
* Interrupt & Context switch

* Preemption

* Latency

* Jitter

* Faster

* Linux mainline kernel was not designed as RTOS

# Distributions 

* <a href="https://www.freertos.org/about-RTOS.html">FreeRTOS </a>:  FreeRTOS is a class of RTOS that is designed to be small enough to run on a microcontroller - although its use is not limited to microcontroller applications.

 
* <a href="http://blackberry.qnx.com/en/sdp7">QNX</a> : QNX is real time RTOS, which support ARM, MIPS, PowerPC, SH and X86 Processor family.
* <a href="https://www.windriver.com/products/vxworks">Vxworks</a> :Vxworks is also real time rtos, it support wide range of processor architectures like ARM, PowerPC, ColdFire, MIPS etc.

* <a href="http://www.rtlinux.org/">RTlinux</a> :RTLinux is a hard realtime real-time operating system (RTOS) microkernel that runs the entire Linux operating system as a fully preemptive process. The hard real-time property makes it possible to control robots, data acquisition systems, manufacturing plants, and other time-sensitive instruments and machines from RTLinux applications. Even with a similar name it is not related the Real-Time Linux project of the Linux Foundation.

* <a href="http://www.chibios.org/dokuwiki/doku.php">ChibiOS/RT</a>: is designed for embedded applications on 8, 16 and 32 bit microcontrollers; size and execution efficiency are the main project goals.[2] As reference, the kernel size can range from a minimum of 1.2 Kib up to a maximum of 5.5 KiB with all the subsystems activated on a STM32 Cortex-M3 processor. The kernel is capable of over 220,000 created/terminated threads per second and is able to perform a context switch in 1.2 microseconds on an STM32 @ 72 MHz. Similar metrics for all the supported platforms are included in the source distribution as test reports. 
github :https://github.com/ChibiOS/

# projects
1. Arduino UNO (ATmega328P 8-bit μc)
   OS: FreeRTOS
   lib:https://github.com/feilipu/Arduino_FreeRTOS_Library
   * Example 1 [blink AnalogRead]
2. Raspberry Pi 3 Model B+ 

   OS :RTlinux
   ## cross compile the RTlinux on any linux distro
   ###### Step 1. Download the Raspberrypi tool , Kernel sources. 
   > #https://github.com/raspberrypi/tools.git
   
   > #git clone -b rpi-3.18.9-rt5 https://github.com/emlid/linux-rt-rpi.gi
   
   **# cd Linux-rt-rpi** 
   ###### step 2. Export the following variables to specify cross-compilation 
   **# export ARCH=arm**
   
   **# export CROSS_COMPILE=~/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf-**
   
   
   **For Raspberry Pi 3:**

   #make bcm2709_rt_defconfig

   
   
   
