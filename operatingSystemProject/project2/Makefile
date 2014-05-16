INCPACK	:= inc/
SRCPACK	:= src/
OBJPACK	:= obj/
MODULEPACK := module/

DEBFLAG	:=	-O2
CFLAG	+= $(DEBFLAG) -I$(LDDINCDIR)

cacheFake-objs := src/cacheTarget.o src/manageDevice.o
obj-m	:= cacheFake.o 

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

install:
	$(shell `awk '{if ($$2 == "cacheFake") print ($$1)}' /proc/devices`)

uninstall:
	rm -r /dev/cacheFake
	rmmod cacheFake

clean:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
	rm -rf .[A-Za-z]*
	rm -rf module/*
	rm -rf bin/*
