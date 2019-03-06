# RTOS (REAL TIME OPERATING SYSTEM) 
### When it Matters, it Runs on RTOS

###### Realtime computing Myth V/S Truth
Myth : RTC (Real Time computing) is fast computing with higher performance 

Truth : RTC is predictable computing , timeliness is more important than perfomance.
- RTOS deals with gurantees , not with raw speed . having more processor , more RAM ,faster BUS interfaces does't make a system real time , it deals with GUARANTEES

<p align="center">
  <img src="https://raw.githubusercontent.com/cvam0000/RTOS/master/extra/rtos.png" width="450" title="">
  
</p>


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


   - Efficient and portable preemptive kernel.
   - Best in class context switch performance.
   - Many supported architectures and platforms.
   - Static architecture, everything is statically allocated at compile time.
   - Dynamic extensions, dynamic objects are supported by an optional layer built on top of the static core.
    -Rich set of primitives: threads, virtual timers, semaphores, mutexes, condition variables, messages, mailboxes, event flags, queues.
   - Support for priority inheritance algorithm on mutexes.
    - Hardware Abstraction Layer (HAL) component supporting a variety of abstract device drivers: Port, Serial, ADC, CAN, EXT, GPT, I2C, ICU, MAC, MMC, PWM, RTC, SDC, SPI, UART, USB, USB-CDC.
    Support for external components uIP, lwIP, FatFs.
    Extensive test suite with benchmarks.
    Support for C++ applications.

github :https://github.com/ChibiOS/

# projects
1. Arduino UNO (ATmega328P 8-bit μc)
   OS: FreeRTOS
   lib:https://github.com/feilipu/Arduino_FreeRTOS_Library
   * Example 1 [blink AnalogRead]
   * Example 2 [ultrasonic sensor response at Real time]
2. Raspberry Pi 3 Model B+ 

   OS :RTlinux
   ## cross compile the RTlinux on any linux distro
   ###### Step 1. Download the Raspberrypi tool , Kernel sources. 
   ```$ https://github.com/raspberrypi/tools.git```
   
   ```$ git clone -b rpi-3.18.9-rt5 https://github.com/emlid/linux-rt-rpi.git```
   
    ```$ cd Linux-rt-rpi```
   ###### step 2. Export the following variables to specify cross-compilation 
    ```$ export ARCH=arm```
   
    ```$ export CROSS_COMPILE=~/tools/arm-bcm2708/gcc-linaro-arm-linux-gnueabihf-raspbian-x64/bin/arm-linux-gnueabihf```
   
   
   ###### For Raspberry Pi 3:

    ```$ make bcm2709_rt_defconfig```
   ###### compile the kernel
     ```$ make -j5```
   ###### Install modules, will result in "lib" folder with modules and firmware:
    ```$ mkdir kernel-rt```
  
    ```$ INSTALL_MOD_PATH=kernel-rt make modules_install```
   ###### Testing real-time capabilites using cyclictest utility
    ``` git clone git://git.kernel.org/pub/scm/linux/kernel/git/clrkwllms/rt-tests.git```
  
    ``` cd rt-tests```
 
    ```make all```

    ```sudo cp ./cyclictest /usr/bin/```

    ```cd ~```

    ```sudo cyclictest -l1000000 -m -n -a0 -t1 -p99 -i400 -h400 -q```
