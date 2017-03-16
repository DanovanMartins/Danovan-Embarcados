# Makefile

reciprocal: exemplo2.o reciprocal.o
	g++ $(CFLAGS) -o teste_exemplo2 exemplo2.o reciprocal.o
main.o: exemplo2.c reciprocal.hpp
	gcc $(CFLAGS) -c exemplo2.c
reciprocal.o: reciprocal.cpp reciprocal.hpp
	g++ $(CFLAGS) -c reciprocal.cpp
clean:
	rm -f *.o reciprocal
