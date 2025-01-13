# Makefile for this shit
all:
	gcc -D__linux__ -CC timer.c -o timer
	
exec:
	./timer
	
clean:
	rm timer
