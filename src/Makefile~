#Compiler flags. -g for debug, -O3 for optimization

CFLAGS=-g -O3

# First target is built by default

all: tokenizer

# Include file dependencies

history.o: history.h
tokenizer.o: tokenizer.h

# Build tokenizer executable

tokenizer: history.o tokenizer.o uimain.o
	cc -o $@ $^ $(CFLAGS)

# Compile uimain.c

uimain.o: uimain.c tokenizer.h
	cc -o $@ -c $< $(CFLAGS)

# Clean up

clean:
	rm -f *.o tokenizer
run:

	./tokenizer
