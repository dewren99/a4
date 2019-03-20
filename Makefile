all:	huff

huff: 	main.o FrequencyCounter.o PriorityQueue.o Node.o HuffmanTree.o BitStream.o
	g++ -Wall -o huff main.o FrequencyCounter.o PriorityQueue.o Node.o HuffmanTree.o BitStream.o

main.o:	main.cpp FrequencyCounter.cpp PriorityQueue.cpp Node.cpp HuffmanTree.cpp BitStream.cpp
	g++ -c main.cpp

HuffmanTree.o:	HuffmanTree.h HuffmanTree.cpp
	g++ -c HuffmanTree.cpp

PriorityQueue.o:	PriorityQueue.h PriorityQueue.cpp
	g++ -c PriorityQueue.cpp

FrequencyCounter.o:	FrequencyCounter.h FrequencyCounter.cpp
	g++ -c FrequencyCounter.cpp

Node.o:	Node.h Node.cpp
	g++ -c Node.cpp

BitStream.o: BitStream.h BitStream.cpp
	g++ -c BitStream.cpp

clean:
	rm -f huff *.o