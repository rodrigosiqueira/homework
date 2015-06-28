PWD := $(shell pwd)

obj-m := jiffies.o

all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules

clean:
	rm -rf *.ko *.o *.mod.c *.order *.symvers
	rm -rf .*.*.cmd
	rm -rf .tmp_versions

