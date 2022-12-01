fndtest.elf: fndtest.o libMyPeri.a
	arm-linux-gnueabi-gcc -o fndtest.elf fndtest.c -L./

libMyPeri.a: fnd.o
	arm-linux-gnueabi-ar rc libMyPeri.a fnd.o

fnd.o: fnd.c fnd.h
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o

clean:
	@rm -rf *.o libMyPeri.a

