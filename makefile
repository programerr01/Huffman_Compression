main : decompress_file compress_file
	g++ node.o heap.o huffman.o utility.o decompress.o -o decompress
	g++ node.o heap.o huffman.o utility.o compress.o -o compress

decompress_file : decompress.cpp utility.o 
	g++ -c decompress.cpp -Iinclude -o decompress.o

compress_file : compress.cpp utility.o 
	g++ -c compress.cpp -Iinclude -o compress.o

utility.o : include/Utility.h src/Utility.cpp huffman.o
	g++ -c src/Utility.cpp -Iinclude -o utility.o


huffman.o : include/Huffman.h src/Huffman.cpp heap.o 
	g++ -c src/Huffman.cpp -Iinclude -o huffman.o

heap.o : include/Heap.h src/Heap.cpp node.o
	g++ -c src/Heap.cpp -Iinclude -o heap.o 

node.o : include/Node.h src/Node.cpp
	g++ -c src/Node.cpp -Iinclude -o node.o 

test : 
	chmod +x test.sh
	./test.sh
clean : 
	rm -f *.o output
