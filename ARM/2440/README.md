# Mini2440

----
# About this folder

> This folder has codes related with mini2440 (s3c2440) in a bare metal level. 
Basically, you can find some assembly code and C code for handling this device. 

# Configure the environment

----
## Install cross-compile

* In the same level of this README, you can find the file 
  arm-linux-gcc-4.3.2.tgz. It is the cross-compile files, you extract the file 
  in /usr/local/ and then add the path to .bashrc. Just execute:
 * tar xvzf arm-linux-gcc-4.3.2.tgz –C /
 * Add to .bashrc: PATH=$PATH:/usr/local/arm/4.3.2/bin
* Now logout, and then execute:
 * arm-linux-gcc --version

## Install usbpush

* In the same level of this README, you can find the file usbpush.tar.gz. You 
  should install the needed package, and compile usbpush.
  * sudo apt-get install libusb-dev
  * tar xvzf usbpush.tar.gz
  * cd usbpush/
  * make

## Install and configure minicom

* Intall minicom:
  * sudo apt-get install minicom
* Configure minicom:
  * minicom -s
  * go to the option "Serial port"
  * Change "Serial Device" to /dev/ttyUSB0 (or ttyUSB1)
  * Change "Bps/Par/Bits" to 115200 8N1
  * Finally Hardware and Software flow control must be "No"
