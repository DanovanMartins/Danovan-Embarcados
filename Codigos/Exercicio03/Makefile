#Makefile

questao11.o: questao11.c num_caracs.h
	gcc $(CFLAGS) -c questao11.c
Num_Caracs.o: Num_Caracs.c num_caracs.h
	gcc $(CFLAGS) -c Num_Caracs.c
questao11: questao11.o Num_Caracs.o
	gcc $(CFLAGS) -o questao11 questao11.o Num_Caracs.o
clean:
	rm -f *.o 

