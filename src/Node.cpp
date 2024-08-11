#include <bits/stdc++.h>
#include "Node.h"



 Node::Node(){
    this->ch = '\0';
    this->val = 0;
    this->left = nullptr;
    this->right = nullptr;
};

 Node::Node(char c,int v){
    this->ch = c;
    this->val = v;
    this->left = nullptr;
    this->right = nullptr;
};

bool Node::operator>(const Node& other)const {
    return this->val > other.val;
}

bool Node::operator>=(const Node& other) const {
    return this->val >= other.val;
}