ledtest.elf : led.o libMyPeri.a
	arm-linux-gnueabi-gcc -o ledtest.elf led.c -L./

led.o : led.c led.h
	arm-linux-gnueabi-gcc -c led.c -o led.o

libMyPeri.a : led.o
	arm-linux-gnueabi-ar rc libMyPeri.a led.o

clean :
	@rm -rf *.o libMyPeri.a
