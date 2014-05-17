1 - About file organization
	* bin: Keep the binary file for execution
	* inc: Keep all the headers used in the module
	* module: Keep all the files related with the module, include the .ko
	* obj: Keep object files
	* others: Keep other information about the code, but not directly related
	* src: Implementation of the header and another source code.
	* Makefile
	* load.sh: Script responsable for insert the module in the kernel. Run it as root.
	* unload.sh: Remove the device of the memory.

2 - How to use the Makefile
	* make :=> It will compile the only the module. After that you can execute load.sh
	* make test :=> Compile the test file that use the module, for work correctly the 
			step abot must to be execute first.
	* make clean :=> Remove all the files previouly generate.
	* make executeTest :=> Execute the binary file, you must to execute it as a root.

3 - Documentation
	* This code has a Doxygen documentation.
	* You can check a previously documentation in the folder others/DoxygenHTML/index.html

============== IMPORTANT ============
4 - How to use it.
	a) Firstly insert the module:
		-> ex.: insmod cacheFake.ko
	b) Secondly of all we need to create a fake device (for safetly), following the steps below:
		I) Create an empty file:
			-> dd if=/dev/zero of=/tmp/store1 bs=1024 seek=2047 count=1
		II) Make the file previouly created into a block device:
			-> losetup /dev/loop1 /tmp/store1
	c) Create the device with you new module
		I) Create the new device target: 
			-> echo 0 $(blockdev --getsize /dev/loop1) cacheFake /dev/loop1 0 | dmsetup create myCache
		II) Create a filesystem: 
			-> mke2fs /dev/mapper/myCache
		III) Mount the file system:
			-> mkdir /mnt/deviceMappeTest
			-> mount /dev/mapper/myCache /mnt/deviceMappeTest



