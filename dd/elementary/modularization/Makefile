INC := inc/
SRC := src/
OBJ := obj/
BIN := bin/
PWD := $(shell pwd)

obj-m := $(SRC)hello.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod.c *.order *.symvers
	rm -rf .*.*.cmd
	rm -rf .tmp_versions

