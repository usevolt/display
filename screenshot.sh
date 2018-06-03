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
png=".png"

xxd -p $filename$bin &>"temp.txt" && \
cat "bmp_800x480_template.txt" "temp.txt" &>"temp2.txt" && \
xxd -r -p "temp2.txt" &> $filename$bmp && \
convert $filename$bmp $filename$png && \
rm -rf temp.txt && \
rm -rf temp2.txt && \
rm -rf $filename$bin && \
rm -rf $filename$bmp && \
echo "$filename$bin succesfully converted to PNG"
