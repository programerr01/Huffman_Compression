#ifndef  HEAP_H 
#define HEAP_H 

#include "Node.h"
#include <bits/stdc++.h>


class Heap{
    private:
        std::vector<Node*>hp;
        
		int last_pos;
        
        void heapify(int indx);

        void handle_rm_min(int indx);
    
    public:
        Heap();
        void add(Node* curr_);
        void remove_min();
        Node* get_min();
        int size();
        std::vector<Node*> print();

};

#endif