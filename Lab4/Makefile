callasm: callasm.o hsvmhr.o
	gcc -m32 -o callasm callasm.o hsvmhr.o

callasm.o: callasm.c
	gcc -m32 -c -o callasm.o callasm.c
	
hsvmhr.o: hsvmhr.asm
	nasm -g -f elf -o hsvmhr.o hsvmhr.asm


