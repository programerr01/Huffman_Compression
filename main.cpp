#include <iostream>
#include "Huffman.h"
using namespace std; 

int main(){
    string  s = "and give you a few other hints about ways you can improve your OOP design";
	Huffman* f = new Huffman(s);
	f->buildTree();
	cout << "this is build tree" <<endl;
	string encoded_msg = f->encode();
	cout << encoded_msg <<endl;
	cout << f->decode(encoded_msg) <<endl;
    return 0;
}
