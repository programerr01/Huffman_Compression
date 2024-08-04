#include <bits/stdc++.h>
#include <algorithm>
#include "Heap.h"
#include <iostream>


Heap::Heap(){
}
void Heap::heapify(int indx){
    int curr_min_indx = indx;
    Node* curr_min = this->hp[indx];

    int left_p = (indx*2)+1;
    int right_p = (indx*2)+2;

    if(left_p < this->hp.size() && *this->hp[indx] >  *this->hp[left_p]){
        curr_min_indx = left_p;
        curr_min = this->hp[left_p];
    }
    if(right_p < this->hp.size() && *this->hp[curr_min_indx] > *this->hp[right_p]){
        curr_min_indx = right_p;
        curr_min = this->hp[right_p];
    }
    if(curr_min_indx != indx){
        std::swap(this->hp[indx], this->hp[curr_min_indx]);
        this->heapify(curr_min_indx);
    }
}

void Heap::handle_rm_min(int indx){
    for(int i = this->hp.size()/2;i >= 0 ;i--){
        this->heapify(i);
    }
    return;
}

void Heap::add(Node* curr_){

    this->hp.push_back(curr_);
    for(int i = this->hp.size()/2;i >=0;i--){
        this->heapify(i);
    }
}
void Heap::remove_min(){
    if(this->hp.size() == 0){
        return;
    }

    if(this->hp.size() == 1){
        this->hp.pop_back();
        return;
    }
    std::swap(this->hp[0],this->hp[this->hp.size()-1]);
    this->hp.pop_back();
    this->handle_rm_min(0);
}
Node* Heap::get_min(){
    return this->hp[0];
}

int Heap::size(){
    return this->hp.size();
}

std::vector<Node*> Heap::print(){
    return this->hp;
}