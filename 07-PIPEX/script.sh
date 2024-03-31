#!/bin/bash

clear
echo "test1"
echo > outfile1.txt
chmod 644 outfile1.txt
echo > outfile2.txt
chmod 644 outfile2.txt
< infile.txt ls -l | wc -l > outfile1.txt
< infile.txt ls -l | wc -l > outfile2.txt
#./pipex infile.txt "ls -l" "wc -l" outfile2.txt
if diff outfile1.txt outfile2.txt > /dev/null
then
	echo "OK"
else
	echo "KO"
fi
exit