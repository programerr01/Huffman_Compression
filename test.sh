#!/bin/bash 

F1="inp.txt"
F2="com.huff"
F3="out.txt"

CONTENT="Hello This is the content of the file."

echo "$CONTENT" > "$F1"

./compress $F1 $F2
./decompress $F2 $F3

if cmp -s "$F1" "$F3"; then
    echo "Test Passed"
    exit 0;
else
    echo "Test Failed."
    exit 1;
fi

