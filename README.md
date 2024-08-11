## Text Compression

Text Compression using Huffman encoding, in huffman encoding we use binary tree to store nodes which represent characters. Each character is assigned a binary code on the basis on how frequently it occurs in the given file.

Priority Queue is used for assigning value for each character.

  

Hufffman Encoding is variable length encoding scheme.

  

## Build

`make`

**Compression**

`./compression input_file compressed_file`

**Decompression**

`./decompression compressed_file output_file`


## Future Scope
- [x] Adding command line utility instead of passing to the source file

- [x] Adding Support for text file compression and decompression where you can specify the files
- [ ] Adding complete ascii support
- [ ] Adding UTF-8 support 
