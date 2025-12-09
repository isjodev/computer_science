CC=gcc 
CFLAGS=-g -Wall 
BINS=main

all: $(BINS) 

%: %.c 
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	$(RM) -r $(BINS) *.dSYM
