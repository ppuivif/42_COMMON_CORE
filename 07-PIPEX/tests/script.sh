#!/bin/bash

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

function create_files_and_set_permissions() {
#	local file1="$1"
#	local file2="$2"
    
#	echo > "$file1"
#	chmod 644 "$file1"
#	echo > "$file2"
#	chmod 644 "$file2"
	echo -e "ceci est\nun test\n" > infile.txt
	echo > outfile_bash.txt
	chmod 644 outfile_bash.txt
	echo > outfile_pipex.txt
	chmod 644 outfile_pipex.txt
	echo > stdout_bash.txt
	chmod 644 stdout_bash.txt
	echo > stderr1_bash.txt
	chmod 644 stderr1_bash.txt
	echo > stderr2_bash.txt
	chmod 644 stderr2_bash.txt
	echo > stdout_pipex.txt
	chmod 644 stdout_pipex.txt
	echo > stderr1_pipex.txt
	chmod 644 stderr1_pipex.txt
	echo > stderr2_pipex.txt
	chmod 644 stderr2_pipex.txt
}

function delete_files() {
	if [ -f "infile.txt" ] # to check if the given path exists and is a regular file
	then
		chmod 644 infile.txt
		rm infile.txt
	fi
	if [ -f "outfile_bash.txt" ]
	then
		chmod 644 outfile_bash.txt
		rm outfile_bash.txt
	fi
	if [ -f "outfile_pipex.txt" ]
	then
		chmod 644 outfile_pipex.txt
		rm outfile_pipex.txt
	fi
	if [ -f "stdout_bash.txt" ]
	then
		chmod 644 stdout_bash.txt
		rm stdout_bash.txt
	fi
	if [ -f "stderr1_bash.txt" ]
	then
		chmod 644 stderr1_bash.txt
		rm stderr1_bash.txt
	fi
	if [ -f "stderr2_bash.txt" ]
	then
		chmod 644 stderr2_bash.txt
		rm stderr2_bash.txt
	fi
		if [ -f "stdout_pipex.txt" ]
	then
		chmod 644 stdout_pipex.txt
		rm stdout_pipex.txt
	fi
	if [ -f "stderr1_pipex.txt" ]
	then
		chmod 644 stderr1_pipex.txt
		rm stderr1_pipex.txt
	fi
	if [ -f "stderr2_pipex.txt" ]
	then
		chmod 644 stderr2_pipex.txt
		rm stderr2_pipex.txt
	fi
}

function error() {
	stderr1_bash="$1"
	stdout_bash="$2"
	stderr2_bash="$3"
	stderr1_pipex="$4"
	outfile_pipex="$5"
	stdout_pipex="$6"
	stderr2_pipex="$7"
	diff -q $stdout_bash $outfile_pipex
	diff_stdout=$?
	diff -q $stderr1_bash $stderr1_pipex
	diff_stderr1=$?
	diff -q $stderr2_bash $stderr2_pipex
	diff_stderr2=$?
#	if diff $stdout_bash $outfile_pipex > /dev/null
	if [ "$diff_stdout" -ne 0 ]
	then
		flag=1
		error+="stdout_bash :\n"
		error+=$(awk '{print "\t"$0}' $stdout_bash)
		error+="\noutfile_pipex :\n"
		error+=$(awk '{print "\t"$0}' $outfile_pipex)
		error+="\n\n"
	#	echo "stdout_bash :"
	#	awk '{print "\t"$0}' $stdout_bash
	#	echo "outfile_pipex :"
	#	awk '{print "\t"$0}' $outfile_pipex
	fi
	if [ "$diff_stderr1" -ne 0 ]
	then
		flag=1
		error+="stderr1_bash :\n"
		error+=$(awk '{print "\t"$0}' $stderr1_bash)
		error+="stderr1_pipex :\n"
		error+=$(awk '{print "\t"$0}' $stderr1_pipex)
		error+="\n"
	fi
	if [ "$diff_stderr2" -ne 0 ]
	then
		flag=1
		error+="stderr2_bash :\n"
		error+=$(awk '{print "\t"$0}' $stderr2_bash)
		error+="stderr2_pipex :\n"
		error+=$(awk '{print "\t"$0}' $stderr2_pipex)
		error+="\n"
	fi
	if [ "$8" != "$9" ]
	then
		flag=1
		error+="status_exit_bash : "
		error+=$(echo $8)
		error+="\nstatus_exit_pipex : "
		error+=$(echo $9)
		error+="\n"
	#	echo "status_output_bash : "
	#	printf "\t" && echo $6
	#	echo "status_output_pipex :"
	#	printf "\t" && echo $7
	#	echo -e
	fi
	if [ "$flag" == 1 ]
	then
		message+="${RED} KO${NC}"
		flag=0
	else
		message+="${GREEN} OK${NC}"
		flag=0
	fi
}

function display_files_content() {
	stderr1_bash="$1"
	stdout_bash="$2"
	stderr2_bash="$3"
	stderr1_pipex="$4"
	outfile_pipex="$5"
	stdout_pipex="$6"
	stderr2_pipex="$7"

	echo "stderr1_bash :"
	awk '{print "\t"$0}' $stderr1_bash
	echo "stdout_bash :"
#	printf "\t" && cat stdout_bash.txt
	awk '{print "\t"$0}' $stdout_bash
	echo "stderr2_bash :"
#	cat $stderr_bash
	awk '{print "\t"$0}' $stderr2_bash
#	echo -n "status_output_bash : " && cat $status_output_bash
#	echo -n "status_output_bash : " && awk '{print $0}' <<< "$status_output_bash"
#	awk -v var="$status_output_bash" 'BEGIN {print var}'
	printf "status_output_bash : " && echo $8
	echo -e
	echo "stderr1_pipex :"
	awk '{print "\t"$0}' $stderr1_pipex
	echo "outfile_pipex :"
	awk '{print "\t"$0}' $outfile_pipex
	echo "stderr2_pipex :"
	awk '{print "\t"$0}' $stderr2_pipex
	printf "status_output_pipex : " && echo $9
	echo -e
}

clear
echo > test.txt
chmod 644 test.txt
delete_files

#test1 : all inputs are valid
test="test1\tall inputs are valid\t\t"
message=$test
create_files_and_set_permissions
< infile.txt cat -e 2>stderr1_bash.txt | cat -e > outfile_bash.txt >stdout_bash.txt 2>stderr2_bash.txt
status_output_bash=$?
# 2>&1 standard error (stderr : fd 2) is combined with standard output (stdout : fd 1)
# so both standard error and standard output are captured and stored in the variable output and are not displayed on the terminal
# to capture only standard error : output=$(./pipex infile.txt "cat -e" "cat -e" outfile2.txt 2>&1 >/dev/null) because standard output is redirect to /dev/null 
# Save original stderr file descriptor
#exec 3>&2
# Redirect stderr to /dev/null
#./script.sh >/dev/null 3>&2
#./script.sh 2>error.log
# Restore stderr to its original state
#exec 2>&3
# Close the temporary file descriptor
#exec 3>&-
./pipex infile.txt "cat -e" 2>stderr1_pipex "cat -e" outfile_pipex.txt >stdout_pipex.txt 2>stderr2_pipex.txt
status_output_pipex=$?
#display_files_content stderr1_bash.txt stdout_bash.txt stderr2_bash.txt stderr1_pipex.txt outfile_pipex.txt stdout_pipex.txt stderr2_pipex.txt "$status_output_bash" "$status_output_pipex"
error stderr1_bash.txt stdout_bash.txt stderr2_bash.txt stderr1_pipex.txt outfile_pipex.txt stdout_pipex.txt stderr2_pipex.txt "$status_output_bash" "$status_output_pipex"
if [ $status_output_bash == $status_output_pipex ] &&
	diff $stdout_bash $outfile_pipex > /dev/null &&
	[ $(wc -c < "$stdout_pipex") -eq 0 ] &&
	diff $stderr1_bash $stderr2_pipex > /dev/null &&
	diff $stderr2_bash $stderr2_pipex > /dev/null
#	diff outfile_bash.txt outfile_pipex.txt > /dev/null#echo "stdout_bash :"
#	diff stdout_bash.txt stdout_pipex.txt > /dev/null

: <<BLOCK_COMMENT
	echo "stdout_bash :"
	awk '{print "\t"$0}' stdout_bash.txt
	echo "stderr_bash :"
	awk '{print "\t"$0}' stderr_bash.txt
	echo "status_output_bash :"
	printf "\t" && cat $status_output_bash
	echo -e
	echo "outfile_pipex :"
	awk '{print "\t"$0}' outfile_pipex.txt
	echo "stderr_pipex :"
	awk '{print "\t"$0}' stderr_pipex.txt
	echo "status_output_pipex :"
	printf "\t" && cat $status_output_pipex
	echo -e
BLOCK_COMMENT

then
	echo -e "${GREEN}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt 
else
	echo -e "${RED}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt 
fi
delete_files
echo -e "$message"
echo -e "$error"
message=""
error=""

#test2 : outfile doesn't exist
test="test2\toutfile doesn't exist\t\t"
message=$test
create_files_and_set_permissions
rm outfile_bash.txt
rm outfile_pipex.txt
< infile.txt cat -e 2>stderr1_bash.txt | cat -e > outfile_bash.txt >stdout_bash.txt 2>stderr2_bash.txt
status_output_bash=$?
./pipex infile.txt "cat -e" 2>stderr1_pipex "cat -e" outfile_pipex.txt >stdout_pipex.txt 2>stderr2_pipex.txt
status_output_pipex=$?
#display_files_content stderr1_bash.txt stdout_bash.txt stderr2_bash.txt stderr1_pipex.txt outfile_pipex.txt stdout_pipex.txt stderr2_pipex.txt "$status_output_bash" "$status_output_pipex"
error stderr1_bash.txt stdout_bash.txt stderr2_bash.txt stderr1_pipex.txt outfile_pipex.txt stdout_pipex.txt stderr2_pipex.txt "$status_output_bash" "$status_output_pipex"
if [ $status_output_bash == $status_output_pipex ] &&
	diff stdout_bash.txt outfile_pipex.txt > /dev/null &&
	[ $(wc -c < "stdout_pipex.txt") -eq 0 ] &&
	diff stderr1_bash.txt stderr1_pipex.txt > /dev/null &&
	diff stderr2_bash.txt stderr2_pipex.txt > /dev/null
then
	echo -e "${GREEN}$test : \n\tinfile exists\n\toutfile doesn't exist\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt
else
	echo -e "${RED}$test : \n\tinfile exists\n\toutfile doesn't exist\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt 
fi
delete_files
echo -e "$message"
echo -e "$error"
message=""
error=""

#test3 : no permission on outfile
test="test3\tno permission on outfile\t"
message=$test
create_files_and_set_permissions
chmod 044 outfile_bash.txt
chmod 044 outfile_pipex.txt
substring="Permission denied"
#< infile.txt cat -e 2>stderr1_bash.txt | cat -e > outfile_bash.txt >stdout_bash.txt 2>stderr2_bash.txt
#status_output_bash=$?
./pipex infile.txt "cat -e" 2>stderr1_pipex.txt "cat -e" outfile_pipex.txt >stdout_pipex.txt 2>stderr2_pipex.txt
#display_files_content stderr1_bash.txt stdout_bash.txt stderr2_bash.txt stderr1_pipex.txt outfile_pipex.txt stdout_pipex.txt stderr2_pipex.txt "$status_output_bash" "$status_output_pipex"
status_output_pipex=$?
if grep "$substring" stderr2_pipex.txt >/dev/null &&
	[ $status_output_pipex == 1 ]
# && diff stdout_bash.txt outfile_pipex.txt > /dev/null to verify result of cmd2
then
	message+="${GREEN} OK${NC}"
	echo -e "${GREEN}$test : \n\tinfile exists\n\toutfile exists without any permissions\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt
else
	message+="${RED} KO${NC}"
	echo -e "${RED}$test : \n\tinfile exists\n\toutfile exists without any permissions\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"cat -e\"\n${NC}" >> test.txt
fi
delete_files
echo -e "$message"
message=""


#test4 : infile doesn't exist
test="test4\tinfile doesn't exist\t\t"
message=$test
create_files_and_set_permissions
rm infile.txt
substring="No such file or directory"
#< infile.txt cat -e 2>stderr1_bash.txt | cat -e > outfile_bash.txt >stdout_bash.txt 2>stderr2_bash.txt
./pipex infile.txt "cat -e" 2>stderr1_pipex.txt "cat -e" outfile_pipex.txt >stdout_pipex.txt 2>stderr2_pipex.txt
if grep "$substring" stderr2_pipex.txt >/dev/null &&
	[ $status_output_pipex == 0 ]
# && diff stdout_bash.txt outfile_pipex.txt > /dev/null to verify result of cmd2
then
	message+="${GREEN} OK${NC}"
	echo -e "${GREEN}$test : \n\tinfile doesn't exist\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"wc -l\"\n${NC}" >> test.txt
else
	message+="${RED} KO${NC}"
	echo -e "${RED}$test : \n\tinfile doesn't exist\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"wc -l\"\n${NC}" >> test.txt
fi
delete_files
echo -e "$message"
message=""

: <<BLOCK_COMMENT

#test5 : no permission on infile
test="test5"
message=$test
create_files_and_set_permissions
chmod 044 infile.txt
output_bash=$(< infile.txt ls -l | wc -l > outfile_bash.txt 2>&1 >/dev/null)
output_pipex=$(./pipex infile.txt "ls -l" "wc -l" outfile_pipex.txt 2>&1)
#if grep "$substring" stderr_pipex.txt >/dev/null # && diff stdout_bash.txt outfile_pipex.txt > /dev/null to verify result of cmd2
if diff outfile_bash.txt outfile_pipex.txt > /dev/null && [ $result_executing_bash == $result_executing_pipex ]
then
	message+="${RED} KO${NC}"
	echo -e "${RED}$test : \n\tinfile exists\n\tinfile exists without any permissions\n\tcmd1 : \"ls -l\"\n\tcmd2 : \"wc -l\"\n${NC}" >> test.txt
else
	message+="${GREEN} OK${NC}"
	echo -e "${GREEN}$test : \n\tinfile exists\n\tinfile exists without any permissions\n\tcmd1 : \"ls -l\"\n\tcmd2 : \"wc -l\"\n${NC}" >> test.txt
fi
delete_files
echo -e "$message"
message=""

#test6 : cmd1 invalid
test="test6"
message=$test
create_files_and_set_permissions
< infile.txt invalid | wc -l > outfile_bash.txt
error_output_bash=$?
./pipex infile.txt "invalid" "wc -l" outfile_pipex.txt
error_output_pipex=$?
if diff outfile_bash.txt outfile_pipex.txt > /dev/null && [ $error_output_bash == $error_output_pipex ]
then
	message+="${GREEN} OK${NC}"
	echo -e "${GREEN}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"invalid\"\n\tcmd2 : \"wc -l\"\n${NC}" >> test.txt
else
	message+="${RED} KO${NC}"
	echo -e "${RED}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"invalid\"\n\tcmd2 : \"wc -l\"\n${NC}" >> test.txt
fi
delete_files
echo -e "$message"
message=""

#test7 : cmd2 invalid
test="test7"
message=$test
create_files_and_set_permissions
< infile.txt cat -e | invalid > outfile_bash.txt
error_output_bash=$?
#echo $error_output_bash
./pipex infile.txt "cat -e" "invalid" outfile_pipex.txt
error_output_pipex=$?
#echo $error_output_pipex
if diff outfile_bash.txt outfile_pipex.txt > /dev/null && [ $error_output_bash == $error_output_pipex ]
then
	message+="${GREEN} OK${NC}"
	echo -e "${GREEN}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"invalid\"\n${NC}" >> test.txt
else
	message+="${RED} KO${NC}"
	echo -e "${RED}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"invalid\"\n${NC}" >> test.txt
fi
delete_files
echo -e "$message"
message=""

#test8 : to build
test="test8"
message=$test
create_files_and_set_permissions
< infile.txt cat -e | invalid > outfile_bash.txt
error_output_bash=$?
#echo $error_output_bash
./pipex infile.txt "cat -e" "invalid" outfile_pipex.txt
error_output_pipex=$?
#echo $error_output_pipex
if diff outfile_bash.txt outfile_pipex.txt > /dev/null && [ $error_output_bash == $error_output_pipex ]
then
	message+="${GREEN} OK${NC}"
	echo -e "${GREEN}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"invalid\"\n${NC}" >> test.txt
else
	message+="${RED} KO${NC}"
	echo -e "${RED}$test : \n\tinfile exists\n\toutfile exists\n\tcmd1 : \"cat -e\"\n\tcmd2 : \"invalid\"\n${NC}" >> test.txt
fi
delete_files
echo -e "$message"
message=""

BLOCK_COMMENT

exit