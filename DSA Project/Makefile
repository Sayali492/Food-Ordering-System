final: Trie.o main.o
	cc Trie.o main.o -o final
Trie.o: Trie.c Trie.h
	cc -c Trie.c
main.o: main.c Trie.h main.h
	cc -c main.c
clean:
	rm *.o



