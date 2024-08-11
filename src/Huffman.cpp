#include "Huffman.h"
#include <vector>
#include <map> 
#include <iostream>
#include <algorithm>

using namespace std; 


Huffman::Huffman(string s){
    this->message = s;
    this->frequency_map(this->message,this->freq_map);
}

void Huffman::buildTree(){

    for(auto e  : this->freq_map){
        Node* n = new Node(e.second,e.first);
        this->hp->add(n);
    }
    while(this->hp->size()){
        Node* pp = new Node(this->hp->get_min()->ch,this->hp->get_min()->val);
        pp->left = this->hp->get_min()->left;
        pp->right = this->hp->get_min()->right;
        this->hp->remove_min(); // remove only after assignment is done

        if(this->hp->size() ==0){
            this->final_tree = pp; // root is found
            break;
        }
        Node* q = this->hp->get_min();
        Node* qq  = new Node(this->hp->get_min()->ch,this->hp->get_min()->val);
        qq->left = this->hp->get_min()->left;
        qq->right = this->hp->get_min()->right;
        this->hp->remove_min();
        Node *t = new Node('\0',pp->val+qq->val);
        t->left = pp;
        t->right = qq;
        hp->add(t);

    }
    this->traverse(this->final_tree,"");

}

void Huffman::traverse(Node* n,string code_=""){
    if(!n){
        return;
    }
    if(n->ch != '\0'){
        // cout << n->ch << "=> " << code_ <<endl;
        this->mapping[n->ch] = code_;
        this->rev_mapping[code_] = n->ch;

    }
    this->traverse(n->left,code_+'0');
    this->traverse(n->right,code_+'1');    
}

string Huffman::encode(){
    string final_ = "";
    for(auto e : message){
        final_ += this->mapping[e];
    }
    return final_;
}

map<char,string> Huffman::getMapping(){
	return this->mapping;
}

string Huffman::decode(string encoded_msg){
    string buffer = "";
    string final_ = "";
    for(auto e : encoded_msg){
        buffer +=e;
        if(this->rev_mapping.find(buffer) != this->rev_mapping.end()){
            final_ += this->rev_mapping[buffer];
            buffer = "";
        }
    }
    final_ += this->rev_mapping[buffer];
    return final_;
}

void Huffman::frequency_map(string words,vector<pair<int,char>>& freq_map){
	sort(words.begin(),words.end());
	char last_='\0';
	int last_count = 0;
	for(auto e : words){
		if(e == last_){
			last_count++;
		}
		else{
			if(last_  == '\0'){
				last_ = e;
				continue;
			}
			pair<int,char> p = {++last_count,last_};
			freq_map.push_back(p);
			last_count = 0;
			last_ = e;
		}
	}
	if(last_ != '\0'){
		pair<int,char> p = {++last_count,last_};
		freq_map.push_back(p);
	}
	
	return;
}