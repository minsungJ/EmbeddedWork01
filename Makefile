final.elf : 1.o 2.o
	gcc -o final.elf 1.o 2.o
   
1.o : 1.c
	gcc -c -o 1.o 1.c
  
2.o : 2.c
	gcc -c -o 2.o 2.c

3.o : 3.c
	gcc -c -o 3.o 3.c
clean:
	rm *.o final.elf
