#ifndef UTILITY_H
#define UTILITY_H 

#include "Huffman.h"
#include <vector>


class Utility{
    private:
        std::string input_file_name;
        std::string output_file_name;
        std::string decode_from_file(std::string s);
    public:
        Utility(std::string file_name );
        Utility(std::string file_name ,std::string output_file);
        std::string read_file();
        void compress_and_save();
        void decompress_and_save();
};

#endif