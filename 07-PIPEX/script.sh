#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

clear
echo > test.txt
chmod 644 test.txt
message1="test1"
echo -e "ceci est\nun test\n" > infile.txt
#chmod 644 infile.txt
echo > outfile1.txt

chmod 644 outfile1.txt
echo > outfile2.txt
chmod 644 outfile2.txt
< infile.txt cat -e | cat -e > outfile1.txt
./pipex infile.txt "cat -e" "cat -e" outfile2.txt
if diff outfile1.txt outfile2.txt > /dev/null
then
	message1+="${GREEN} OK${NC}"
	echo -e "${GREEN}test 1 : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt 
else
	message1+="${RED} KO${NC}"
	echo -e "${RED}test 1 : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt 
fi
rm infile.txt
rm outfile1.txt
rm outfile2.txt
echo -e "$message1"

message2="test2"
echo -e "ceci est\nun test\n" > infile.txt
#chmod 644 infile.txt
< infile.txt cat -e | cat -e > outfile1.txt
./pipex infile.txt "cat -e" "cat -e" outfile2.txt
if diff outfile1.txt outfile2.txt > /dev/null
then
	message2+="${GREEN} OK${NC}"
	echo -e "${GREEN}test 2 : \n\tinfile exists\n\toutfile doesn't exist\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt
else
	message2+="${RED} KO${NC}"
	echo -e "${RED}test 2 : \n\tinfile exists\n\toutfile doesn't exist\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt 
fi
rm infile.txt
rm outfile1.txt
rm outfile2.txt
echo -e "$message2"

message3="test3"
echo -e "ceci est\nun test\n" > infile.txt
#chmod 644 infile.txt
#echo > outfile1.txt
#chmod 044 outfile1.txt
echo > outfile2.txt
chmod 044 outfile2.txt
#< infile.txt cat -e | cat -e > outfile1.txt
substring="Error"
output=$(./pipex infile.txt "cat -e" "cat -e" outfile2.txt 2>&1)
#if diff outfile1.txt outfile2.txt > /dev/null
if [ $? -eq 0 ] && [ "$output" == *"$substring"* ]
then
	message3+="${RED} KO${NC}"
	echo -e "${RED}test 3 : \n\tinfile exists\n\toutfile exists without any permissions\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt
else
	message3+="${GREEN} OK${NC}"
	echo -e "${GREEN}test 3 : \n\tinfile exists\n\toutfile exists without any permissions\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt
fi
rm infile.txt
#chmod 644 outfile1.txt
#rm outfile1.txt
chmod 644 outfile2.txt
rm outfile2.txt
echo -e "$message3"
exit