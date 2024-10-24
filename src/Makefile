OBJS = tokenizer.o history.o uimain.o

CFLAGS = -g -O3

all: myProgram

# Rule to create the executable
myProgram: $(OBJS)
	cc $(CFLAGS) -o myProgram $(OBJS)

# Rule to build object files from the C source files
%.o: %.c
	cc $(CFLAGS) -c $< -o $@

# Dependencies
tokenizer.o: tokenizer.h
history.o: history.h
uimain.o: tokenizer.h history.h

# Clean rule to remove temporary files and the executable
clean:
	rm -f *.o myProgram *.c# *.c~

# Run rule to execute the program
run: myProgram
	./myProgram
