CC=gcc 
CFLAGS=-g -Wall 
BIN=trie_example 

all: $(BINS) 

%: %.c 
	$(CC) $(CFLAGS) $^ -o $@

clean: 
	$(RM) -r $(BINS) main *.dSYM
