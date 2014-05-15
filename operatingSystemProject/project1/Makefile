INCPACK	= inc/
SRCPACK	= src/
OBJPACK	= obj/
MODULEPACK	= module/

DEBFLAG	=	-O2
CFLAG		+= $(DEBFLAG) -I$(LDDINCDIR)

fakeMemory-objs := src/memoryOperation.o src/virtualMemoryOperation.o
obj-m	:= fakeMemory.o 

all: makeStuffs cleanResult

makeStuffs:
	make -C $(INCFLAG) /lib/modules/$(shell uname -r)/build M=$(PWD) modules

cleanResult:
	mv *.ko module/
	mv *.mod* module/
	mv src/*.o module/
	mv *.o module/
	mv modules.order module/
	mv Module.symvers module/

test: 
	gcc src/testMem.c -o bin/test

executeTest:
	bin/test

install:
	$(shell `awk '{if ($$2 == "fakeMemory") print ($$1)}' /proc/devices`)

#	insmod module/fakeMemory.ko
#	mknod /dev/fakeMemory0 c `awk '{if($$2=="fakeMemory") {print $$1}}' /proc/devices` 0
#	mknod /dev/fakeMemory1 c `awk '{if($$2=="fakeMemory") {print $$1}}' /proc/devices` 1
				
uninstall:
	rm -r /dev/fakeMemory0
	rm -r /dev/fakeMemory1
	rmmod fakeMemory

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf module/*
	rm -rf bin/*
