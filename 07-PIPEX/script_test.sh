#!/bin/bash

clear
echo "infile content :"
#echo $'\t' &&
cat -e infile.txt
echo
echo "outfile content :"
if [ -s outfile.txt ]
then
	cat -e outfile.txt
else
	echo "the file is empty"
fi
echo
echo "execute : < infile.txt ls -l | wc -l > outfile.txt"
< infile.txt ls -l | wc -l > outfile.txt
echo
echo "new outfile content :"
if [ -s outfile.txt ]
then
	cat -e outfile.txt
else
	echo "the file is empty"
fi
echo
echo "clear outfile content"
cat /dev/null > outfile.txt
if [ -s outfile.txt ]
then
	cat -e outfile.txt
else
	echo "outfile.txt is empty"
fi
exit