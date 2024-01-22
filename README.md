# celosia 
celosia is an Open-source operating system built on top of a microkernel. 
It is written in C++


## building
You'll first want to obtain the limine bootloader. 
You can do so by running:
```
git clone https://github.com/limine-bootloader/limine.git --branch=binary --depth=1
make -C limine/
```

Now, run `make all` to build the kernel, drivers and userspace utilities.
