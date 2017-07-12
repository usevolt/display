#!/bin/bash


if [ "$#" -ne 1 ]; then
    echo "Give source binary file as argument, without file extension"
fi

filename=$(basename "$1")
dirname=$(dirname "$1")
extension="${filename##*.}"
filename="${dirname}/${filename%.*}"
bin=".bin"
bmp=".bmp"

xxd -p $filename$bin &>"temp.txt" && \
cat "bmp_800x480_template.txt" "temp.txt" &>"temp2.txt" && \
xxd -r -p "temp2.txt" &> $filename$bmp && \
rm -rf temp.txt && \
rm -rf temp2.txt && \
rm -rf $filename$bin && \
echo "$filename$bin succesfully converted to bitmap"
