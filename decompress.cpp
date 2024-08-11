#include <bits/stdc++.h>
#include "Utility.h"
using namespace std; 


int main(int argc, char* argv[]){
    if(argc < 3){
        cout << "Usage: ./decompress <file_name> <output_file>" <<endl;
        return 0;
    }
    string file_name = argv[1];
    string output_file = argv[2];
    Utility* u = new Utility(file_name.c_str(),output_file.c_str());
    u->decompress_and_save();
    return 0;
}