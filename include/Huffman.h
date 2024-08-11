#ifndef HUFFMAN_H
#define HUFFMAN_H 

#include "Node.h"
#include "Heap.h"
#include <vector>
#include <string> 
#include <map>


class Huffman{
    private:
      Heap* hp = new Heap();
      std::string message ="";
      std::vector<std::pair<int,char>> freq_map;
      Node* final_tree;
      std::map<char,std::string> mapping;
      std::map<std::string,char> rev_mapping;

    public:
        Huffman(std::string s);
        void buildTree(); 
        void traverse(Node* n,std::string code_);
        std::string encode();
        std::string decode(std::string message);
        void frequency_map(std::string words,std::vector<std::pair<int,char>>& freq_map);
        std::map<char,std::string> getMapping();
};


#endif 