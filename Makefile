all:	huff

huff: 	main.o FrequencyCounter.o PriorityQueue.o Node.o HuffmanTree.o
	g++ -Wall -o huff main.o FrequencyCounter.o PriorityQueue.o Node.o HuffmanTree.o

main.o:	main.cpp FrequencyCounter.cpp PriorityQueue.cpp Node.cpp HuffmanTree.cpp
	g++ -c main.cpp

HuffmanTree.o:	HuffmanTree.h HuffmanTree.cpp
	g++ -c HuffmanTree.cpp

PriorityQueue.o:	PriorityQueue.h PriorityQueue.cpp
	g++ -c PriorityQueue.cpp

FrequencyCounter.o:	FrequencyCounter.h FrequencyCounter.cpp
	g++ -c FrequencyCounter.cpp

Node.o:	Node.h Node.cpp
	g++ -c Node.cpp

clean:
	rm -f huff *.o