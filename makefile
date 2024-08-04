
run : main 
	g++ node.o heap.o  huffman.o main.o  -o output

main : main.cpp huffman.o 
	g++ -c main.cpp -Iinclude -o main.o 
	
huffman.o : include/Huffman.h src/Huffman.cpp heap.o 
	g++ -c src/Huffman.cpp -Iinclude -o huffman.o

heap.o : include/Heap.h src/Heap.cpp node.o
	g++ -c src/Heap.cpp -Iinclude -o heap.o 

node.o : include/Node.h src/Node.cpp
	g++ -c src/Node.cpp -Iinclude -o node.o 

clean : 
	rm -f *.o output
