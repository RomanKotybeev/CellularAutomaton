CC = gcc
SRCMODULES = ca.c table_fill.c viewca.c
OBJMODULES = $(SRCMODULES:.c=.o)

%.o: %.c %.h
	$(CC) $(CFLAGS) -c $< -o $@

ca: main.c $(OBJMODULES)
	$(CC) $(CFLAGS) $^ -lm -o $@
	rm -f *.o

run: ca
	./ca

clean:
	rm ca
