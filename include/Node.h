#ifndef NODE_H

#define NODE_H 

class Node{
    public:
        char ch;
        int val;
        bool isT;
        Node* left;
        Node* right;

        Node(char c,int v);
        Node();
        bool operator>(const Node& other) const;
        bool operator>=(const Node& other) const; 

};
#endif

