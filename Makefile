a.out: main.o permut.o
	$(CC) main.o permut.o
.PYONY: clean
clean:
	$(RM) *.o a.out
