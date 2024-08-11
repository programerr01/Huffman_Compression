#include "Utility.h"
#include <vector>
#include <map> 
#include <iostream>

using namespace std;


Utility::Utility(string file_name){
    this->input_file_name = file_name;   
    this->output_file_name = file_name + ".huff"; 
}

Utility::Utility(string file_name,string output_file){
    this->input_file_name = file_name; 
    this->output_file_name = output_file;   
}

string Utility::read_file(){
    ifstream file(this->input_file_name);
    string s;
    string line;
    while(getline(file,line)){
        s += line;
    }
    file.close();
    return s;
}

void Utility::compress_and_save(){
    string s = this->read_file();
    Huffman* f = new Huffman(s);
    f->buildTree();
    map<char,string> mp = f->getMapping(); 
    string header_info = "";
    for(auto e : mp){
		header_info += e.first;
		header_info += ":";
		header_info += e.second;
		header_info+=",";
	}
    header_info+=",";

    string encoded = f->encode();
    header_info += encoded;
    ofstream file(this->output_file_name);
    file << header_info;
    file.close();
}

string Utility::decode_from_file(string s){
    bool is_char = true;
	map<string,char>mp;
	char last_char = ' ';
	string last_string ="";
	int encoding_st = -1;
	for(int i = 0;i < strlen(s.c_str());i++){
		if(is_char){
			char c = s[i];
			if(c == ','){
				encoding_st = i;
				break;
			}
			last_char = c;
			is_char = false;
		}
		else{
			char c = s[i];
			if(c == ':'){
				is_char = false;
			}
			else{
				if(c == ','){
					mp[last_string] = last_char;
					last_string = "";
					is_char = true;
				}
				else{
					last_string += c;
				}
			}
		}
	}
    
	string curr_str = "";
	string final_out = "";
	for(int i = encoding_st+1;i <= strlen(s.c_str());i++){
		if(i == strlen(s.c_str()) || mp.find(curr_str) != mp.end()){
			final_out += mp[curr_str];
			curr_str = s[i];
		}
		else{
			curr_str += s[i];
		}
	}
	return final_out;
}

void Utility::decompress_and_save(){
    ifstream file(this->input_file_name);
    string s;
    string line;
    while(getline(file,line)){
        s += line;
    }
    file.close();
    string final_out = decode_from_file(s);
    ofstream file2(this->output_file_name);
    file2 << final_out;
    file2.close();
}