colorledtest.elf: colorledtest.o  libMyPeri.a
	arm-linux-gnueabi-gcc -o cololedtest.elf colorledtest.c -lMyPeri -L.

libMyPeri.a: textlcd.o fnd.o colorled.o
	arm-linux-gnueabi-ar rc libMyPeri.a textlcd.o fnd.o colorled.o

textlcd.o : textlcd.c textlcd.h
	arm-linux-gnueabi-gcc -c textlcd.c -o textlcd.o

fnd.o: fnd.c fnd.h
	arm-linux-gnueabi-gcc -c fnd.c -o fnd.o

colorled.o : colorled.c colorled.h
	arm-linux-gnueabi-gcc -c colorled.c -o colorled.o

clean:
	@rm -rf *.o libMyPeri.a

