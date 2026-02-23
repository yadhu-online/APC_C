a.out:  main.o add.o mul.o div.o sub.o fun.o head.o 
	gcc -o main.o add.o mul.o div.o sub.o fun.o head.o 
main.o : main.c
	gcc -c main.c
add.o : add.c
	gcc -c add.c
div.o : div.c
	gcc -c div.c
sub.o : sub.c
	gcc -c sub.c	
fun.o : fun.c
	gcc -c fun.c
head.o : head.c
	gcc -c head.c
clean:
	rm *.exe *.o