all:	huff

huff: 	main.o FrequencyCounter.o
	g++ -Wall -o huff main.o FrequencyCounter.o

main.o:	main.cpp FrequencyCounter.cpp
	g++ -c main.cpp

FrequencyCounter.o:	FrequencyCounter.h FrequencyCounter.cpp
	g++ -c FrequencyCounter.cpp

clean:
	rm -f huff *.o