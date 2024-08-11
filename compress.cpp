#include <bits/stdc++.h>
#include "Utility.h"
using namespace std; 


int main(int argc, char* argv[]){
    // get file from argv 
    if(argc < 2){
        cout << "Usage: ./compress <file_name> <output_file|optional>" <<endl;
        return 0;
    }
    string file_name = argv[1];
    string output_file_name = file_name +".huff";
    if(argc == 3){
        output_file_name = argv[2];
    }
    Utility* u = new Utility(file_name.c_str(),output_file_name.c_str());
    u->compress_and_save();
    return 0;
}