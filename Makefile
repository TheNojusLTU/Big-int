CC = gcc
PROG = program.exe

main: 
	$(CC) main.c bigint.c -o $(PROG)

run:
	$(PROG)

clean:
	del /Q *.o $(PROG) $(TEST)