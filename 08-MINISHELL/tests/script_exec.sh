#!/bin/bash

# Define global variables for index range
start_index=0
end_index=0

RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

function create_temp_directory() {
	mkdir temp
	chmod 777 temp
	flag=0
	clear
}

function create_files_and_set_permissions() {
	test_index=$1
	test_definition=$2
	if [ "$test_definition" == "execution" ]
	then
		echo > "temp/$test_index-bash_stdout.txt"
		chmod 644 "temp/$test_index-bash_stdout.txt"
#		exec 200> "temp/bash_stdout$test_index.txt"
		echo > "temp/$test_index-bash_stderr.txt"
		chmod 644 "temp/$test_index-bash_stderr.txt"
#		exec 201> "temp/bash_stderr$test_index.txt"
		echo > "temp/tmp_to_execute_valgrind.txt"
    	chmod 644 "temp/tmp_to_execute_valgrind.txt"
		exec 101< "temp/tmp_to_execute_valgrind.txt"
	fi
	echo -e "ceci est\nun test1\n" > temp/infile1.txt
	echo -e "ceci est\nun test2\n" > temp/infile2.txt
	echo -e "ceci est\nun test3\n" > temp/infile3.txt
	echo > temp/outfile1.txt
	chmod 644 temp/outfile1.txt
	echo > temp/outfile2.txt
	chmod 644 temp/outfile2.txt
	echo > temp/outfile3.txt
	chmod 644 temp/outfile3.txt
	echo > "temp/$test_index-minishell_stdout.txt"
    chmod 644 "temp/$test_index-minishell_stdout.txt"
#	exec 100> "temp/minishell_stdout$test_index.txt"
	echo > "temp/$test_index-minishell_stderr.txt"
    chmod 644 "temp/$test_index-minishell_stderr.txt"
#	exec 101> "temp/minishell_stderr$test_index.txt"
	echo > "temp/tmp_to_read_command.txt"
    chmod 644 "temp/tmp_to_read_command.txt"
	exec 100< "temp/tmp_to_read_command.txt"
}

function delete_infiles() {
	if [ -f "temp/infile1.txt" ] # to check if the given path exists and is a regular file
	then
		chmod 644 temp/infile1.txt
		rm temp/infile1.txt
	fi
	if [ -f "temp/infile2.txt" ]
	then
		chmod 644 temp/infile2.txt
		rm temp/infile2.txt
	fi
	if [ -f "temp/infile3.txt" ]
	then
		chmod 644 temp/infile3.txt
		rm temp/infile3.txt
	fi
}

function delete_outfiles() {
	if [ -f "temp/outfile1.txt" ]
	then
		chmod 644 temp/outfile1.txt
		rm temp/outfile1.txt
	fi
	if [ -f "temp/outfile2.txt" ]
	then
		chmod 644 temp/outfile2.txt
		rm temp/outfile2.txt
	fi
	if [ -f "temp/outfile3.txt" ]
	then
		chmod 644 temp/outfile3.txt
		rm temp/outfile3.txt
	fi
}

function delete_test_files() {
#	if [ -f "temp/minishell_test1.txt" ]
#	then
#		chmod 644 temp/minishell_test1.txt
#		rm temp/minishell_test1.txt
#	fi
	if [ -d "temp" ]
	then
		chmod 777 temp
		rm -r temp
	fi
}

function delete_file() {
	file="$1"

	if [ -f $file ]
	then
		chmod 644 $file
		rm $file
	fi
}

execute_parsing_test() {
    test_index=$2
    command=$3
	file_test=$4
    exit_code_expected=$5
    test="test$test_index\t$command\t"
    message=$test
 	substring=$6

	create_files_and_set_permissions $test_index "parsing"
	echo "$command" >"temp/tmp_to_read_command.txt"

#	echo "$command" | ./minishell 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/stderr_minishell$test_index.txt"
	./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
	exit_code_minishell=$?

	delete_file "temp/tmp_to_read_command.txt"
	exec 100>&-

	diff_stdout=$(diff "temp/$test_index-minishell_stdout.txt" "Tests/$file_test-test_n.txt" > /dev/null)
	diff_exit_stdout=$?

	empty_substring=""
	if [ "$exit_code_expected" -eq 2 ]
	then
		if [ "$substring" = "$empty_substring" ] && [ ! -s "temp/$test_index-minishell_stderr.txt" ]
		then
			diff_empty_substring=0
		else
			diff_empty_substring=1
		fi
	else
			diff_empty_substring=0
	fi
 	diff_stderr=$(grep "$substring" temp/$test_index-minishell_stderr.txt >/dev/null)
	diff_exit_stderr=$?

	if [ $diff_exit_stdout -eq 1 ]
	then
		status3="KO"
		error_detail3="${RED}std_output ${NC}"
		flag=$((flag + 1))
	else
		status3="OK"
		error_detail3=""
		delete_file "temp/$test_index-minishell_stdout.txt"
	fi
	
	if [ $diff_exit_stderr -eq 0 ] || [ $diff_empty_substring -eq 0 ]
#	if	grep "$substring" temp/minishell_stderr$test_index.txt >/dev/null
	then
		status4="OK"
		error_detail4=""
		delete_file "temp/$test_index-minishell_stderr.txt"
	else	
#		echo "$substring"
		status4="KO"
		error_detail4="${RED}stderr_output ${NC}"
		flag=$((flag + 1))
    fi

	if [ "$exit_code_minishell" -ne "$exit_code_expected" ]
	then
		status5="KO"
		error_detail5="${RED}exit_code ${NC}"
		flag=$((flag + 1))
	else
		status5="OK"
		echo "$heredoc1_content" | ./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
		error_detail5=""
		status_message="${GREEN} OK${NC}"
    fi

	if [ "$display" == "wrong_only" ]
	then
		if [ "$status3" == "KO" ] || [ "$status4" == "KO" ] || [ "$status5" == "KO" ]
		then
			status_message="${RED} KO : ${NC}"
			echo -e "${message}${spaces}${test_index}${status_message}${error_detail3}${error_detail4}${error_detail5}"
		fi
	else
		if [ "$status3" == "KO" ] || [ "$status4" == "KO" ] || [ "$status5" == "KO" ]
		then
			status_message="${RED} KO : ${NC}"
			echo -e "${message}${spaces}${test_index}${status_message}${error_detail3}${error_detail4}${error_detail5}"
		else
			status_message="${GREEN} OK${NC}"
			echo -e "${message}${spaces}${status_message}"
		fi
	fi
	substring=""
}


execute_test() {
	test_type=$1
    test_index=$2
    command=$3
	file_test=$4
    exit_code_expected=$5
 	substring=$6
 	invalid_test=$7
 	limiter1=$8
 	limiter2=$9
 	limiter3=${10}
	test="test$test_index\t$command\t"
    message=$test
    
	create_files_and_set_permissions $test_index "execution"

	heredoc1_content="line1
line2
"$limiter1""

	heredoc2_content="line1
line2
"$limiter1"
line3
line4
"$limiter2""

	heredoc3_content="line1
line2
"$limiter1"
line3
line4
"$limiter2"
line5
line6
"$limiter3""

# if more lines with heredoc4 dont forget to modify tail on line 406

	heredoc4_content="line1
"$TEST1"
"$limiter1""

: << BLOCK_COMMENT

"$TEST1""$TEST2"
"$TEST1"" ""$TEST2"
"$TEST1""$TEST2""$TEST3"
"$TEST1"" ""$TEST2"" ""$TEST3"
"$TEST4"
"$TEST5"
"$TEST1""$TEST4"
"$TEST1"" ""$TEST4"
"$limiter1""

BLOCK_COMMENT

	if [ "$test_type" != "oneheredoc" ] && [ "$test_type" != "twoheredoc" ] && [ "$test_type" != "threeheredoc" ] && [ "$test_type" != "heredoc_with_expand" ]
	then
		full_command="$command" 
	elif [ "$test_type" == "oneheredoc" ]
	then
		full_command="${command}
${heredoc1_content}"
	elif [ "$test_type" == "twoheredoc" ]
	then
		full_command="${command}
${heredoc2_content}"
	elif [ "$test_type" == "threeheredoc" ]
	then
		full_command="${command}
${heredoc3_content}"
	elif [ "$test_type" == "heredoc_with_expand" ]
	then
		full_command="${command}
${heredoc4_content}"
	fi

	echo "$full_command" >"temp/tmp_to_read_command.txt"

	eval "$full_command" 1>"temp/$test_index-bash_stdout.txt" 2>"temp/$test_index-bash_stderr.txt"
	exit_code_bash=$?
#	echo "exit_code_bash"
#	echo "$exit_code_bash"
	cat "temp/outfile1.txt" >"temp/$test_index-bash_outfile1.txt"
	cat "temp/outfile2.txt" >"temp/$test_index-bash_outfile2.txt"
	
	echo > temp/outfile1.txt
	echo > temp/outfile2.txt


	echo "$command" >"temp/tmp_to_read_command.txt"
	if [ "$test_type" != "oneheredoc" ] && [ "$test_type" != "twoheredoc" ] && [ "$test_type" != "threeheredoc" ] && [ "$test_type" != "heredoc_with_expand" ]
	then
		./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
	elif [ "$test_type" == "oneheredoc" ];
	then
		echo "$heredoc1_content" | ./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
	elif [ "$test_type" == "twoheredoc" ];
	then
		echo "$heredoc2_content" | ./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
	elif [ "$test_type" == "threeheredoc" ];
	then
		echo "$heredoc3_content" | ./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
	elif [ "$test_type" == "heredoc_with_expand" ];
	then
		echo "$heredoc4_content" | ./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"



: << BLOCK_COMMENT
		echo -e "line1\nline2\nlimiter1\nerror\n" | ./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt"
BLOCK_COMMENT

: << BLOCK_COMMENT
		./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt" <<< "line1
	line2
	limiter1"
BLOCK_COMMENT

: << BLOCK_COMMENT
		./minishell 100 1>"temp/$test_index-minishell_stdout.txt" 2>"temp/$test_index-minishell_stderr.txt" << EOF
	line1
	line2
	limiter1
EOF
BLOCK_COMMENT

	fi

	exit_code_minishell=$?
#	echo "exit_code_minishell"
#	echo "$exit_code_minishell"
	cat "temp/outfile1.txt" >"temp/$test_index-minishell_outfile1.txt"
	cat "temp/outfile2.txt" >"temp/$test_index-minishell_outfile2.txt"
	delete_file "temp/tmp_to_read_command.txt"
	exec 100>&-

	echo "$full_command" >"temp/tmp_to_execute_valgrind.txt"
	echo "exit" >>"temp/tmp_to_execute_valgrind.txt"


	if [ "$run_valgrind" == "yes" ]
	then
		if [ "$test_type" != "oneheredoc" ] && [ "$test_type" != "twoheredoc" ] && [ "$test_type" != "threeheredoc" ] && [ "$test_type" != "heredoc_with_expand" ]
		then
#		 	valgrind --suppressions=readline.supp --leak-check=full --track-fds=yes --trace-children=yes --error-exitcode=1 ./minishell 101
 			valgrind --suppressions=readline.supp --leak-check=full --trace-children=yes --error-exitcode=10 ./minishell 101 1>/dev/null 2>&1
#			beware : if minishell exit_code is 10, script will consider it as a valgrind_error	
			exit_code_valgrind=$?
#			echo "exit_code_valgrind"
#			echo "$exit_code_valgrind"
		elif [ "$test_type" == "oneheredoc" ];
		then
 			echo "$heredoc1_content" | valgrind --suppressions=readline.supp --leak-check=full --trace-children=yes --error-exitcode=10 ./minishell 101 1>/dev/null 2>&1
			exit_code_valgrind=$?
		elif [ "$test_type" == "twoheredoc" ];
		then
 			echo "$heredoc2_content" | valgrind --suppressions=readline.supp --leak-check=full --trace-children=yes --error-exitcode=10 ./minishell 101 1>/dev/null 2>&1
			exit_code_valgrind=$?
		elif [ "$test_type" == "threeheredoc" ];
		then
 			echo "$heredoc3_content" | valgrind --suppressions=readline.supp --leak-check=full --trace-children=yes --error-exitcode=10 ./minishell 101 1>/dev/null 2>&1
			exit_code_valgrind=$?
		elif [ "$test_type" == "heredoc_with_expand" ];
		then
 			echo "$heredoc4_content" | valgrind --suppressions=readline.supp --leak-check=full --trace-children=yes --error-exitcode=10 ./minishell 101 1>/dev/null 2>&1
			exit_code_valgrind=$?
		fi
	else
		exit_code_valgrind=0
	fi


	diff_outfile1=$(diff "temp/$test_index-minishell_outfile1.txt" "temp/$test_index-bash_outfile1.txt" > /dev/null)
	diff_exit_outfile1=$?
	diff_outfile2=$(diff "temp/$test_index-minishell_outfile2.txt" "temp/$test_index-bash_outfile2.txt" > /dev/null)
	diff_exit_outfile2=$?
	
	if [ "$test_type" != "oneheredoc" ] && [ "$test_type" != "twoheredoc" ] && [ "$test_type" != "threeheredoc" ] && [ "$test_type" != "heredoc_with_expand" ]
	then
		diff_stdout=$(diff "temp/$test_index-minishell_stdout.txt" "temp/$test_index-bash_stdout.txt" > /dev/null)
		diff_exit_stdout=$?
	elif [ "$test_type" == "oneheredoc" ];
	then
#		<(sed '3d' filename) is use to skip only the third line
#		<(tail -n +4 filename) is use to skip the first, the two and third line
		diff_stdout=$(diff <(tail -n +4 "temp/$test_index-minishell_stdout.txt") "temp/$test_index-bash_stdout.txt" > /dev/null)
		diff_exit_stdout=$?
	elif [ "$test_type" == "twoheredoc" ];
	then
		diff_stdout=$(diff <(tail -n +7 "temp/$test_index-minishell_stdout.txt") "temp/$test_index-bash_stdout.txt" > /dev/null)
		diff_exit_stdout=$?
	elif [ "$test_type" == "threeheredoc" ];
	then
		diff_stdout=$(diff <(tail -n +10 "temp/$test_index-minishell_stdout.txt") "temp/$test_index-bash_stdout.txt" > /dev/null)
		diff_exit_stdout=$?
	elif [ "$test_type" == "heredoc_with_expand" ];
	then
		diff_stdout=$(diff <(tail -n +4 "temp/$test_index-minishell_stdout.txt") "temp/$test_index-bash_stdout.txt" > /dev/null)
		diff_exit_stdout=$?
	fi

	
	empty_substring=""
	if [ "$substring" = "$empty_substring" ] && [ ! -s "temp/$test_index-minishell_stderr.txt" ]
	then
		diff_empty_substring=0
	else
		diff_empty_substring=1
	fi
 	diff_stderr=$(grep "$substring" temp/$test_index-minishell_stderr.txt >/dev/null)
	diff_exit_stderr=$?
	
	if [ $diff_exit_outfile1 -eq 1 ]
	then
		status1="KO"
		error_detail1="${RED}outfile1.txt ${NC}"
		flag=$((flag + 1))
	else
		status1="OK"
		error_detail1=""
		delete_file "temp/$test_index-minishell_outfile1.txt"
		delete_file "temp/$test_index-bash_outfile1.txt"
	fi
	
	if [ $diff_exit_outfile2 -eq 1 ]
	then
		status2="KO"
		error_detail2="${RED}outfile2.txt ${NC}"
		flag=$((flag + 1))
	else
		status2="OK"
		error_detail2=""
		delete_file "temp/$test_index-minishell_outfile2.txt"
		delete_file "temp/$test_index-bash_outfile2.txt"
	fi
	
	if [ $diff_exit_stdout -eq 1 ]
	then
		status3="KO"
		error_detail3="${RED}std_output ${NC}"
		flag=$((flag + 1))
	else
		status3="OK"
		error_detail3=""
		delete_file "temp/$test_index-minishell_stdout.txt"
		delete_file "temp/$test_index-bash_stdout.txt"
	fi
	
	if [ $diff_exit_stderr -eq 0 ] || [ $diff_empty_substring -eq 0 ]
#	if	grep "$substring" temp/minishell_stderr$test_index.txt >/dev/null
	then
		status4="OK"
		error_detail4=""
		delete_file "temp/$test_index-minishell_stderr.txt"
		delete_file "temp/$test_index-bash_stderr.txt"
	else	
#		echo "$substring"
		status4="KO"
		error_detail4="${RED}stderr_output ${NC}"
		flag=$((flag + 1))
    fi

	if [ "$exit_code_minishell" -ne "$exit_code_bash" ]
	then
		status5="KO"
		error_detail5="${RED}exit_code ${NC}"
		flag=$((flag + 1))
	else
		status5="OK"
		error_detail5=""
		status_message="${GREEN} OK${NC}"
    fi

	if [ $exit_code_valgrind -eq 10 ]
	then
		status6="KO"
		error_detail6="${RED}valgrind_error ${NC}"
		flag=$((flag + 1))
	else
		status6="OK"
		error_detail6=""
		status_message="${GREEN} OK${NC}"
    fi

	# Calculate the length of the message
    message_length=${#message}
    # Calculate the number of spaces needed for alignment
    num_spaces=$((60 - message_length))
    #num_tabs=$((25 - message_length))
    # Create a string of spaces
	#tabs=$(printf "%${num_tabs}s" "" | tr ' ' '\t')
  #  spaces=$(printf "%-${num_spaces}s" "")
    spaces=$(printf "%-30s" "")
    # Print the message with aligned status

	if [ "$display" == "wrong_only" ]
	then
		if [ "$status1" == "KO" ] || [ "$status2" == "KO" ] || [ "$status3" == "KO" ] || [ "$status4" == "KO" ] || [ "$status5" == "KO" ] || [ "$status6" == "KO" ]
		then
			status_message="${RED} KO : ${NC}"
			echo -e "${message}${spaces}${test_index}${status_message}${error_detail1}${error_detail2}${error_detail3}${error_detail4}${error_detail5}${error_detail6}${invalid_test}"
		fi
	else
		if [ "$status1" == "KO" ] || [ "$status2" == "KO" ] || [ "$status3" == "KO" ] || [ "$status4" == "KO" ] || [ "$status5" == "KO" ] || [ "$status6" == "KO" ]
		then
			status_message="${RED} KO : ${NC}"
			echo -e "${message}${spaces}${test_index}${status_message}${error_detail1}${error_detail2}${error_detail3}${error_detail4}${error_detail5}${error_detail6}${invalid_test}"
		else
			status_message="${GREEN} OK${NC}"
			echo -e "${message}${spaces}${status_message}"
		fi
	fi
	substring=""
	delete_file "temp/tmp_to_execute_valgrind.txt"
	exec 101>&-
#fi
	delete_infiles
	delete_outfiles
}

create_temp_directory

choice_one() {
	execute="all"
	start_index=1
	end_index=20000
}

choice_two() {
	execute="parsing"
	start_index=1
	end_index=4999
}

choice_three() {
	execute="expansion"
	start_index=1
	end_index=4999
}

choice_four() {
	execute="execution"
	start_index=5000
	end_index=20000
}

choice_five() {
	execute="free_choice"
	read -p "Enter the start of the range: " start_index
    read -p "Enter the end of the range: " end_index
	echo ""
#	if [ start_index < 0 ] || [ end_index > 10000 ]
#	then
#		echo "Invalid range. Please enter valid numbers and ensure start is less than or equal to end."
#    fi
}

#: << BLOCK_COMMENT
echo "To execute all tests choice 1"
echo "To execute only parsing tests choice 2"
echo "To execute only expansion tests choice 3"
echo "To execute only execution tests choice 4"
echo "To execute specific tests on execution choice 5"
read -p "Enter your choice : " choice
echo ""

# Handle the user's choice
case $choice in
    1)
        choice_one
        ;;
    2)
        choice_two
        ;;
    3)
        choice_three
        ;;
    4)
        choice_four
        ;;
    5)
        choice_five
        ;;
	#do not work    
	*)
        echo -e "${RED}Invalid choice. Please enter 1 or 2.${NC}"
        ;;
esac


if [ "$execute" == "all" ] || [ "$execute" == "execution" ] || [ "$execute" == "free_choice" ]
then
	choice_one() {
		run_valgrind="yes"
	}

	choice_two() {
		run_valgrind="no"
	}

	echo "To run valgrind_test choice 1"
	echo "Not to run valgrind_test choice 2"
	echo "Warning : running tests with valgrind will execute the script slower"  
	read -p "Enter your choice (1 or 2): " choice
	echo ""

	# Handle the user's choice
	case $choice in
		1)
        	choice_one
        	;;
		2)
			choice_two
			;;
		#do not work    
		*)
			echo -e "${RED}Invalid choice. Please enter 1 or 2.${NC}"
			;;
	esac
else
	run_valgrind="no"
fi


# Function to handle the first choice
choice_one() {
	display="all"
}

# Function to handle the second choice
choice_two() {
    display="wrong_only"
}

echo "To display all tests choice 1"
echo "To display only wrong tests choice 2"
read -p "Enter your choice (1 or 2): " choice
echo ""

# Handle the user's choice
case $choice in
    1)
        choice_one
        ;;
    2)
        choice_two
        ;;
#do not work    
	*)
        echo -e "${RED}Invalid choice. Please enter 1 or 2.${NC}"
        ;;
esac

run_test() {
	index=$2
	if (( index >= "$start_index" && index <= "$end_index" ))
	then
		if [ "$execute" == "parsing" ] || [ "$execute" == "expansion" ]
		then
			execute_parsing_test "$@"
		else
			execute_test "$@"
		fi		
	fi
}

run_test "simple" 1 "< temp/infile1.txt cat | cat > temp/outfile1.txt" 1 0
run_test "simple" 2 "<temp/infile1.txt cat | cat > temp/outfile1.txt" 1 0
run_test "simple" 3 "< temp/infile1.txt cat| cat > temp/outfile1.txt" 1 0
run_test "simple" 4 "< temp/infile1.txt cat |cat > temp/outfile1.txt" 1 0
run_test "simple" 5 "< temp/infile1.txt cat | cat >temp/outfile1.txt" 1 0
run_test "simple" 6 "<temp/infile1.txt cat|cat >temp/outfile1.txt" 1 0
run_test "simple" 7 "<	temp/infile1.txt cat | cat > temp/outfile1.txt" 1 0
run_test "simple" 8 "<		temp/infile1.txt cat | cat > temp/outfile1.txt" 1 0
run_test "simple" 9 "< temp/infile1.txt cat	| cat > temp/outfile1.txt" 1 0
run_test "simple" 10 "< temp/infile1.txt cat		| cat > temp/outfile1.txt" 1 0
run_test "simple" 11 "< temp/infile1.txt cat |	cat > temp/outfile1.txt" 1 0
run_test "simple" 12 "< temp/infile1.txt cat |		cat > temp/outfile1.txt" 1 0
run_test "simple" 13 "< temp/infile1.txt cat |	cat > temp/outfile1.txt" 1 0
run_test "simple" 14 "< temp/infile1.txt cat |		cat > temp/outfile1.txt" 1 0
run_test "simple" 15 "< temp/infile1.txt cat | cat	> temp/outfile1.txt" 1 0
run_test "simple" 16 "< temp/infile1.txt cat | cat		> temp/outfile1.txt" 1 0
run_test "simple" 17 "< temp/infile1.txt cat | cat >	temp/outfile1.txt" 1 0
run_test "simple" 18 "< temp/infile1.txt cat | cat >		temp/outfile1.txt" 1 0
run_test "simple" 19 "< temp/infile1.txt cat | cat > temp/outfile1.txt	" 1 0
run_test "simple" 20 "< temp/infile1.txt cat | cat > temp/outfile1.txt		" 1 0


run_test "oneheredoc" 21 "<< limiter1 cat | cat > temp/outfile1.txt" 21 0 "" "" "limiter1"
run_test "oneheredoc" 22 "<<limiter1 cat | cat > temp/outfile1.txt" 21 0 "" "" "limiter1"
run_test "oneheredoc" 36 "<< limiter1 cat | cat		> temp/outfile1.txt" 21 0 "" "" "limiter1"
run_test "oneheredoc" 37 "<< limiter1 cat | cat >	temp/outfile1.txt" 21 0 "" "" "limiter1"
run_test "oneheredoc" 38 "<< limiter1 cat | cat >		temp/outfile1.txt" 21 0 "" "" "limiter1"
run_test "oneheredoc" 39 "<< limiter1 cat | cat > temp/outfile1.txt	" 21 0 "" "" "limiter1"
run_test "oneheredoc" 40 "<< limiter1 cat | cat > temp/outfile1.txt		" 21 0 "" "" "limiter1"

run_test "simple" 41 "< temp/infile1.txt cat | cat >> temp/outfile1.txt" 41 0
run_test "simple" 42 "<temp/infile1.txt cat | cat >> temp/outfile1.txt" 41 0
run_test "simple" 43 "< temp/infile1.txt cat| cat >> temp/outfile1.txt" 41 0
run_test "simple" 44 "< temp/infile1.txt cat |cat >> temp/outfile1.txt" 41 0
run_test "simple" 45 "< temp/infile1.txt cat | cat>> temp/outfile1.txt" 41 0
run_test "simple" 46 "< temp/infile1.txt cat | cat >>temp/outfile1.txt" 41 0
run_test "simple" 47 "<temp/infile1.txt cat|cat >>temp/outfile1.txt" 41 0
run_test "simple" 48 "< temp/infile1.txt cat | cat >> temp/outfile1.txt" 41 0
run_test "simple" 49 "<	temp/infile1.txt cat | cat >> temp/outfile1.txt" 41 0
run_test "simple" 50 "<		temp/infile1.txt cat | cat >> temp/outfile1.txt" 41 0
run_test "simple" 51 "< temp/infile1.txt cat	| cat >> temp/outfile1.txt" 41 0
run_test "simple" 52 "< temp/infile1.txt cat		| cat >> temp/outfile1.txt" 41 0
run_test "simple" 53 "< temp/infile1.txt cat |	cat >> temp/outfile1.txt" 41 0
run_test "simple" 54 "< temp/infile1.txt cat |		cat >> temp/outfile1.txt" 41 0
run_test "simple" 55 "< temp/infile1.txt cat | cat	>> temp/outfile1.txt" 41 0
run_test "simple" 56 "< temp/infile1.txt cat | cat		>> temp/outfile1.txt" 41 0
run_test "simple" 57 "< temp/infile1.txt cat | cat >>	temp/outfile1.txt" 41 0
run_test "simple" 58 "< temp/infile1.txt cat | cat >>		temp/outfile1.txt" 41 0
run_test "simple" 59 "< temp/infile1.txt cat | cat >> temp/outfile1.txt	" 41 0
run_test "simple" 60 "< temp/infile1.txt cat | cat >> temp/outfile1.txt		" 41 0

if (( "$start_index" >= 1 && "$start_index" <= 60 && "$end_index" >= 1 && "$end_index" <= 60 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 1 to 60\n"
	else
		echo -e "end of test serie from 1 to 60"
	fi
fi

#: <<BLOCK_COMMENT


run_test "oneheredoc" 61 "<< limiter1 cat | cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 62 "<<limiter1 cat | cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 63 "<< limiter1 cat| cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 64 "<< limiter1 cat |cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 65 "<< limiter1 cat | cat>> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 66 "<< limiter1 cat | cat >>temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 67 "<<limiter1 cat|cat >>temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 68 "<< limiter1 cat | cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 69 "<<	limiter1 cat | cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 70 "<<		limiter1 cat | cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 71 "<< limiter1 cat	| cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 72 "<< limiter1 cat		| cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 73 "<< limiter1 cat |	cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 74 "<< limiter1 cat |		cat >> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 75 "<< limiter1 cat | cat	>> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 76 "<< limiter1 cat | cat		>> temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 77 "<< limiter1 cat | cat >>	temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 78 "<< limiter1 cat | cat >>		temp/outfile1.txt" 61 0 "" "" "limiter1"
run_test "oneheredoc" 79 "<< limiter1 cat | cat >> temp/outfile1.txt	" 61 0 "" "" "limiter1"
run_test "oneheredoc" 80 "<< limiter1 cat | cat >> temp/outfile1.txt		" 61 0 "" "" "limiter1"

if (( "$start_index" >= 61  && "$start_index" <= 80 && "$end_index" >= 61 && "$end_index" <= 80 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 61 to 80\n"
	else
		echo -e "end of test serie from 61 to 80"
	fi
fi

#BLOCK_COMMENT

run_test "simple" 81 "< temp/infile1.txt < temp/infile2.txt" 81 0
run_test "simple" 82 "<temp/infile1.txt < temp/infile2.txt" 81 0
run_test "simple" 83 "< temp/infile1.txt <temp/infile2.txt" 81 0
run_test "simple" 84 "<temp/infile1.txt <temp/infile2.txt" 81 0
run_test "simple" 85 "<temp/infile1.txt<temp/infile2.txt" 81 0
run_test "simple" 86 "<temp/infile1.txt<temp/infile2.txt" 81 0
run_test "simple" 87 " <	temp/infile1.txt < temp/infile2.txt" 81 0
run_test "simple" 88 " < temp/infile1.txt	< temp/infile2.txt" 81 0
run_test "simple" 89 " < temp/infile1.txt <	temp/infile2.txt" 81 0
run_test "simple" 90 " < temp/infile1.txt < temp/infile2.txt	" 81 0
run_test "simple" 91 "< temp/infile1.txt < temp/infile2.txt < temp/infile3.txt" 91 0
run_test "simple" 92 "<temp/infile1.txt < temp/infile2.txt < temp/infile3.txt" 91 0
run_test "simple" 93 "< temp/infile1.txt <temp/infile2.txt < temp/infile3.txt" 91 0
run_test "simple" 94 "< temp/infile1.txt < temp/infile2.txt <temp/infile3.txt" 91 0
run_test "simple" 95 "< temp/infile1.txt < temp/infile2.txt < temp/infile3.txt" 91 0
run_test "simple" 96 "<temp/infile1.txt <temp/infile2.txt < temp/infile3.txt" 91 0
run_test "simple" 97 "<temp/infile1.txt <temp/infile2.txt <temp/infile3.txt" 91 0
run_test "simple" 98 "<temp/infile1.txt<temp/infile2.txt <temp/infile3.txt" 91 0
run_test "simple" 99 "<temp/infile1.txt<temp/infile2.txt<temp/infile3.txt" 91 0

if (( "$start_index" >= 81 && "$start_index" <= 99 && "$end_index" >= 81 && "$end_index" <= 99 ))
#if [ "$execution" == "all" ] || [ "$execution" == "parsing" ]
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 81 to 99\n"
	else
		echo -e "end of test serie from 81 to 99"
	fi
fi

run_test "simple" 100 "> temp/outfile1.txt > temp/outfile2.txt" 100 0
run_test "simple" 101 ">temp/outfile1.txt > temp/outfile2.txt" 100 0
run_test "simple" 102 "> temp/outfile1.txt >temp/outfile2.txt" 100 0
run_test "simple" 103 ">temp/outfile1.txt >temp/outfile2.txt" 100 0
run_test "simple" 104 ">temp/outfile1.txt>temp/outfile2.txt" 100 0
run_test "simple" 105 ">temp/outfile1.txt>temp/outfile2.txt" 100 0
run_test "simple" 106 " >	temp/outfile1.txt > temp/outfile2.txt" 100 0
run_test "simple" 107 " > temp/outfile1.txt	> temp/outfile2.txt" 100 0
run_test "simple" 108 " > temp/outfile1.txt >	temp/outfile2.txt" 100 0
run_test "simple" 109 " > temp/outfile1.txt > temp/outfile2.txt	" 100 0
run_test "simple" 110 "> temp/outfile1.txt > temp/outfile2.txt > temp/outfile3.txt" 110 0
run_test "simple" 111 ">temp/outfile1.txt > temp/outfile2.txt > temp/outfile3.txt" 110 0
run_test "simple" 112 "> temp/outfile1.txt >temp/outfile2.txt > temp/outfile3.txt" 110 0
run_test "simple" 113 "> temp/outfile1.txt > temp/outfile2.txt >temp/outfile3.txt" 110 0
run_test "simple" 114 "> temp/outfile1.txt > temp/outfile2.txt > temp/outfile3.txt" 110 0
run_test "simple" 115 ">temp/outfile1.txt >temp/outfile2.txt > temp/outfile3.txt" 110 0
run_test "simple" 116 ">temp/outfile1.txt >temp/outfile2.txt >temp/outfile3.txt" 110 0
run_test "simple" 117 ">temp/outfile1.txt>temp/outfile2.txt >temp/outfile3.txt" 110 0
run_test "simple" 118 ">temp/outfile1.txt>temp/outfile2.txt>temp/outfile3.txt" 110 0

if (( "$start_index" >= 100 && "$start_index" <= 118 && "$end_index" >= 100 && "$end_index" <= 118 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 100 to 118\n"
	else
		echo -e "end of test serie from 100 to 118"
	fi
fi


run_test "twoheredoc" 120 "<< limiter1 << limiter2 cat" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 121 "<<limiter1 << limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 122 "<< limiter1 <<limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 123 "<<limiter1 <<limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 124 "<<limiter1<<limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 125 "<<limiter1<<limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 126 " <<	limiter1 << limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 127 " << limiter1	<< limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 128 " << limiter1 <<	limiter2" 120 0 "" "" "limiter1" "limiter2"
run_test "twoheredoc" 129 " << limiter1 << limiter2	" 120 0 "" "" "limiter1" "limiter2"
run_test "threeheredoc" 130 "<< limiter1 << limiter2 << limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 131 "<<limiter1 << limiter2 << limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 132 "<< limiter1 <<limiter2 << limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 133 "<< limiter1 << limiter2 <<limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 134 "<< limiter1 << limiter2 << limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 135 "<<limiter1 <<limiter2 << limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 136 "<<limiter1 <<limiter2 <<limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 137 "<<limiter1<<limiter2 <<limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"
run_test "threeheredoc" 138 "<<limiter1<<limiter2<<limiter3" 130 0 "" "" "limiter1" "limiter2" "limiter3"

if (( "$start_index" >= 120 && "$start_index" <= 138 && "$end_index" >= 120 && "$end_index" <= 138 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 120 to 138\n"
	else
		echo -e "end of test serie from 120 to 138"
	fi
fi

run_test "simple" 140 ">> temp/outfile1.txt >> temp/outfile2.txt" 140 0
run_test "simple" 141 ">>temp/outfile1.txt >> temp/outfile2.txt" 140 0
run_test "simple" 142 ">> temp/outfile1.txt >>temp/outfile2.txt" 140 0
run_test "simple" 143 ">>temp/outfile1.txt >>temp/outfile2.txt" 140 0
run_test "simple" 144 ">>temp/outfile1.txt>>temp/outfile2.txt" 140 0
run_test "simple" 145 ">>temp/outfile1.txt>>temp/outfile2.txt" 140 0
run_test "simple" 146 " >>	temp/outfile1.txt >> temp/outfile2.txt" 140 0
run_test "simple" 147 " >> temp/outfile1.txt	>> temp/outfile2.txt" 140 0
run_test "simple" 148 " >> temp/outfile1.txt >>	temp/outfile2.txt" 140 0
run_test "simple" 149 " >> temp/outfile1.txt >> temp/outfile2.txt	" 140 0
run_test "simple" 150 ">> temp/outfile1.txt >> temp/outfile2.txt >> temp/outfile3.txt" 150 0
run_test "simple" 151 ">>temp/outfile1.txt >> temp/outfile2.txt >> temp/outfile3.txt" 150 0
run_test "simple" 152 ">> temp/outfile1.txt >>temp/outfile2.txt >> temp/outfile3.txt" 150 0
run_test "simple" 153 ">> temp/outfile1.txt >> temp/outfile2.txt >>temp/outfile3.txt" 150 0
run_test "simple" 154 ">> temp/outfile1.txt >> temp/outfile2.txt >> temp/outfile3.txt" 150 0
run_test "simple" 155 ">>temp/outfile1.txt >>temp/outfile2.txt >> temp/outfile3.txt" 150 0
run_test "simple" 156 ">>temp/outfile1.txt >>temp/outfile2.txt >>temp/outfile3.txt" 150 0
run_test "simple" 157 ">>temp/outfile1.txt>>temp/outfile2.txt >>temp/outfile3.txt" 150 0
run_test "simple" 158 ">>temp/outfile1.txt>>temp/outfile2.txt>>temp/outfile3.txt" 150 0

if (( "$start_index" >= 140 && "$start_index" <= 158 && "$end_index" >= 140 && "$end_index" <= 158 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 140 to 158\n"
	else
		echo -e "end of test serie from 140 to 158"
	fi
fi


run_test "simple" 160 "< 'temp/infile1.txt'" 160 0
run_test "simple" 161 "< \"temp/infile1.txt\"" 161 0
run_test "simple" 162 "< '\"temp/infile1.txt\"'" 162 1 "\"temp/infile1.txt\": No such file or directory"
run_test "simple" 163 "< \"'temp/infile1.txt'\"" 163 1 "'temp/infile1.txt': No such file or directory"
run_test "simple" 164 "< '\"'temp/infile1.txt'\"'" 164 1 "\"temp/infile1.txt\": No such file or directory"
run_test "simple" 165 "< \"'\"temp/infile1.txt\"'\"" 165 1 "'temp/infile1.txt': No such file or directory"
run_test "simple" 166 "> 'temp/outfile1.txt'" 166 0
run_test "simple" 167 "> \"temp/outfile1.txt\"" 167 0
run_test "simple" 168 "> '\"temp/outfile1.txt\"'" 168 1 "\"temp/outfile1.txt\": No such file or directory"
run_test "simple" 169 "> \"'temp/outfile1.txt'\"" 169 1 "'temp/outfile1.txt': No such file or directory"
run_test "simple" 170 "> '\"'temp/outfile1.txt'\"'" 170 1 "\"temp/outfile1.txt\": No such file or directory"
run_test "simple" 171 "> \"'\"temp/outfile1.txt\"'\"" 171 1 "'temp/outfile1.txt': No such file or directory"
run_test "oneheredoc" 172 "<< 'limiter1'" 172 0 "" "" "limiter1"
run_test "oneheredoc" 173 "<< \"limiter1\"" 173 0 "" "" "limiter1"
run_test "oneheredoc" 174 "<< '\"limiter1\"'" 174 0 "" "" "\"limiter1\""
run_test "oneheredoc" 175 "<< \"'limiter1'\"" 175 0 "" "" "'limiter1'"
run_test "oneheredoc" 176 "<< '\"'limiter1'\"'" 176 0 "" "" "\"limiter1\""
run_test "oneheredoc" 177 "<< \"'\"limiter1\"'\"" 177 0 "" "" "'limiter1'"
run_test "oneheredoc" 178 "<< '<limiter1'" 178 0 "" "" "<limiter1"
run_test "oneheredoc" 179 "<< \"<limiter1\"" 179 0 "" "" "<limiter1"

run_test "simple" 190 ">> 'temp/outfile1.txt'" 190 0
run_test "simple" 191 ">> \"temp/outfile1.txt\"" 191 0
run_test "simple" 192 ">> '\"temp/outfile1.txt\"'" 192 1 "\"temp/outfile1.txt\": No such file or directory"
run_test "simple" 193 ">> \"'temp/outfile1.txt'\"" 193 1 "'temp/outfile1.txt': No such file or directory"
run_test "simple" 194 ">> '\"'temp/outfile1.txt'\"'" 194 1 "\"temp/outfile1.txt\": No such file or directory"
run_test "simple" 195 ">> \"'\"temp/outfile1.txt\"'\"" 195 1 "'temp/outfile1.txt': No such file or directory"

if (( "$start_index" >= 160 && "$start_index" <= 195 && "$end_index" >= 160 && "$end_index" <= 195 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 160 to 195\n"
	else
		echo -e "end of test serie from 160 to 195"
	fi
fi


run_test "simple" 200 "\"< temp/infile1.txt\"" 200 127 "< temp/infile1.txt: No such file or directory"
run_test "simple" 210 "\"<< limiter1\"" 210 127 "<< limiter1: command not found"
run_test "simple" 220 "\"> temp/outfile1.txt\"" 220 127 "> temp/outfile1.txt: No such file or directory"
run_test "simple" 230 "\">> temp/outfile1.txt\"" 230 127 ">> temp/outfile1.txt: No such file or directory"

run_test "simple" 240 "< temp/\"i\"nfile1.txt" 240 0
run_test "simple" 241 "< temp/\"i\"n\"f\"ile1.txt" 241 0
run_test "simple" 242 "< temp/\"i\"n\"f\"i\"l\"e1.txt" 242 0
run_test "simple" 243 "< temp/\"i\"n\"f\"i\"l\"e\"1\".txt" 243 0
run_test "simple" 244 "< temp/'i'nfile1.txt" 244 0
run_test "simple" 245 "< temp/'i'n'f'ile1.txt" 245 0
run_test "simple" 246 "< temp/'i'n'f'i'l'e1.txt" 246 0
run_test "simple" 247 "< temp/'i'n'f'i'l'e'1'.txt" 247 0
run_test "simple" 248 "< temp/\"i\"''n\"f\"i\"l\"e\"1\".txt" 248 0
run_test "simple" 249 "< temp/\"i\"''n''\"f\"i\"l\"e\"1\".txt" 249 0
run_test "simple" 250 "< temp/\"i\"''n''\"f\"''i\"l\"e\"1\".txt" 250 0
run_test "simple" 251 "< temp/\"i\"''n''\"f\"''i''\"l\"e\"1\".txt" 251 0
run_test "simple" 252 "< temp/\"i\"''n''\"f\"''i''\"l\"''e\"1\".txt" 252 0
run_test "simple" 253 "< temp/\"i\"''n''\"f\"''i''\"l\"''e''\"1\".txt" 253 0
run_test "simple" 254 "< temp/'i'\"\"n'f'i'l'e'1'.txt" 254 0
run_test "simple" 255 "< temp/'i'\"\"n\"\"'f'i'l'e'1'.txt" 255 0
run_test "simple" 256 "< temp/'i'\"\"n\"\"'f'\"\"i'l'e'1'.txt" 256 0
run_test "simple" 257 "< temp/'i'\"\"n\"\"'f'\"\"i\"\"'l'e'1'.txt" 257 0
run_test "simple" 258 "< temp/'i'\"\"n\"\"'f'\"\"i\"\"'l'\"\"e'1'.txt" 258 0
run_test "simple" 259 "< temp/'i'\"\"n\"\"'f'\"\"i\"\"'l'\"\"e\"\"'1'.txt" 259 0
run_test "simple" 260 "< temp/\"i\"\"\"\"n\"\"\"\"f\"\"\"\"i\"\"\"\"l\"\"\"\"e\"\"\"\"1\".txt" 260 0
run_test "simple" 261 "< temp/\"i\"\" \"\"n\"\" \"\"f\"\" \"\"i\"\" \"\"l\"\" \"\"e\"\" \"\"1\".txt" 261 127 "temp/i n f i l e 1.txt: No such file or directory"
run_test "simple" 262 "< temp/\"i\"'\"'n'\"'\"f\"'\"'i'\"'\"l\"'\"'e'\"'\"1\".txt" 262 127 "temp/i\"n\"f\"i\"l\"e\"1.txt: No such file or directory"
run_test "simple" 263 "< temp/'i''\"'n'\"''f''\"'i'\"''l''\"'e'\"''1'.txt" 263 127 "temp/i\"n\"f\"i\"l\"e\"1.txt: No such file or directory"
run_test "simple" 264 "< temp/'i'\"'\"n\"'\"'f'\"'\"i\"'\"'l'\"'\"e\"'\"'1'.txt" 264 127 "temp/i'n'f'i'l'e'1.txt: No such file or directory"

if (( "$start_index" >= 200 && "$start_index" <= 300 && "$end_index" >= 200 && "$end_index" <= 300 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 200 to 300\n"
	else
		echo -e "end of test serie from 200 to 300"
	fi
fi








run_test "simple" 500 "'ls' -l" 500 0
run_test "simple" 501 "'ls' '-l'" 501 0
run_test "simple" 502 "\"ls\" -l" 502 0
run_test "simple" 503 "\"ls\" \"-l\"" 503 0
run_test "simple" 504 "\"ls\" '-l'" 504 0
run_test "simple" 505 "'ls' \"-l\"" 505 0

run_test "simple" 550 "ls -l | cat -e" 550 0
run_test "simple" 551 "ls '-l' | cat -e" 551 0
run_test "simple" 552 "ls -l | 'cat' -e" 552 0
run_test "simple" 553 "ls -l | cat '-e'" 553 0
run_test "simple" 554 "'ls' '-l' | cat -e" 554 0
run_test "simple" 555 "'ls' '-l' | 'cat' -e" 555 0
run_test "simple" 556 "'ls' '-l' | cat '-e'" 556 0
run_test "simple" 557 "'ls' '-l' | 'cat' '-e'" 557 0
run_test "simple" 558 "ls -l | 'cat' '-e'" 558 0
run_test "simple" 559 "ls -l | cat '-e'" 559 0
run_test "simple" 560 "ls '-l' | 'cat' -e" 560 0
run_test "simple" 561 "ls '-l' | cat '-e'" 561 0
run_test "simple" 562 "ls '-l' | 'cat' '-e'" 562 0
run_test "simple" 563 "ls -l | 'cat' '-e'" 563 0 

run_test "simple" 564 "\"ls\" -l | cat -e" 550 0
run_test "simple" 565 "ls \"-l\" | cat -e" 550 0
run_test "simple" 566 "ls -l | \"cat\" -e" 550 0
run_test "simple" 567 "ls -l | cat \"-e\"" 550 0
run_test "simple" 568 "\"ls\" \"-l\" | cat -e" 550 0
run_test "simple" 569 "\"ls\" \"-l\" | \"cat\" -e" 550 0
run_test "simple" 570 "\"ls\" \"-l\" | cat \"-e\"" 550 0
run_test "simple" 571 "\"ls\" \"-l\" | \"cat\" \"-e\"" 550 0
run_test "simple" 572 "\"ls\" -l | \"cat\" \"-e\"" 550 0
run_test "simple" 573 "\"ls\" -l | cat \"-e\"" 550 0
run_test "simple" 574 "ls \"-l\" | \"cat\" -e" 550 0
run_test "simple" 575 "ls \"-l\" | cat \"-e\"" 550 0
run_test "simple" 576 "ls \"-l\" | \"cat\" \"-e\"" 550 0
run_test "simple" 577 "ls -l | \"cat\" \"-e\"" 550 0

run_test "simple" 578 "\"ls\" '-l' | cat -e" 550 0
run_test "simple" 579 "\"ls\" -l | 'cat' -e" 550 0
run_test "simple" 580 "\"ls\" -l | cat '-e'" 550 0
run_test "simple" 581 "\"ls\" '-l' | 'cat' -e" 550 0
run_test "simple" 582 "\"ls\" '-l' | cat '-e'" 550 0
run_test "simple" 583 "\"ls\" '-l' | 'cat' '-e'" 550 0
run_test "simple" 584 "\"ls\" -l | 'cat' '-e'" 550 0

run_test "simple" 585 "'ls' \"-l\" | cat -e" 550 0
run_test "simple" 586 "ls \"-l\" | 'cat' -e" 550 0
run_test "simple" 587 "ls \"-l\" | cat '-e'" 550 0
run_test "simple" 588 "'ls' \"-l\" | 'cat' -e" 550 0
run_test "simple" 589 "'ls' \"-l\" | cat '-e'" 550 0
run_test "simple" 590 "'ls' \"-l\" | 'cat' '-e'" 550 0
run_test "simple" 591 "ls -l | \"cat\" '-e'" 550 0
run_test "simple" 592 "'ls' -l | \"cat\" -e" 550 0
run_test "simple" 593 "ls '-l' | \"cat\" -e" 550 0
run_test "simple" 594 "'ls' '-l' | \"cat\" -e" 550 0
run_test "simple" 595 "'ls' '-l' | \"cat\" '-e'" 550 0
run_test "simple" 596 "ls '-l' | \"cat\" '-e'" 550 0
run_test "simple" 597 "'ls' -l | \"cat\" '-e'" 550 0
run_test "simple" 598 "'ls' -l | cat \"-e\"" 550 0
run_test "simple" 599 "ls '-l' | cat \"-e\"" 550 0
run_test "simple" 600 "ls -l | 'cat' \"-e\"" 550 0
run_test "simple" 601 "'ls' '-l' | cat \"-e\"" 550 0
run_test "simple" 602 "'ls' '-l' | 'cat' \"-e\"" 550 0
run_test "simple" 603 "ls '-l' | 'cat' \"-e\"" 550 0

run_test "simple" 604 "\"ls\" \"-l\" | cat -e" 550 0
run_test "simple" 605 "\"ls\" \"-l\" | 'cat' -e" 550 0
run_test "simple" 606 "\"ls\" \"-l\" | cat '-e'" 550 0
run_test "simple" 607 "\"ls\" \"-l\" | 'cat' '-e'" 550 0

run_test "simple" 608 "\"ls\" -l | \"cat\" -e" 550 0
run_test "simple" 609 "\"ls\" '-l' | \"cat\" -e" 550 0
run_test "simple" 610 "\"ls\" -l | \"cat\" '-e'" 550 0
run_test "simple" 611 "\"ls\" '-l' | \"cat\" '-e'" 550 0

run_test "simple" 612 "\"ls\" -l | cat \"-e\"" 550 0
run_test "simple" 613 "\"ls\" '-l' | cat \"-e\"" 550 0
run_test "simple" 614 "\"ls\" '-l' | 'cat' \"-e\"" 550 0
run_test "simple" 615 "\"ls\" -l | 'cat' \"-e\"" 550 0

run_test "simple" 616 "ls \"-l\" | \"cat\" -e" 550 0
run_test "simple" 617 "'ls' \"-l\" | \"cat\" -e" 550 0
run_test "simple" 618 "ls \"-l\" | \"cat\" '-e'" 550 0
run_test "simple" 619 "'ls' \"-l\" | \"cat\" '-e'" 550 0

run_test "simple" 620 "ls -l | \"cat\" \"-e\"" 550 0
run_test "simple" 621 "'ls' -l | \"cat\" \"-e\"" 550 0
run_test "simple" 622 "ls '-l' | \"cat\" \"-e\"" 550 0
run_test "simple" 623 "'ls' '-l' | \"cat\" \"-e\"" 550 0

run_test "simple" 624 "\"ls\" \"-l\" | \"cat\" -e" 550 0
run_test "simple" 625 "\"ls\" \"-l\" | \"cat\" '-e'" 550 0

run_test "simple" 626 "\"ls\" \"-l\" | cat \"-e\"" 550 0
run_test "simple" 627 "\"ls\" \"-l\" | 'cat' \"-e\"" 550 0

run_test "simple" 628 "\"ls\" -l | \"cat\" \"-e\"" 550 0
run_test "simple" 629 "\"ls\" '-l' | \"cat\" \"-e\"" 550 0

run_test "simple" 630 "ls \"-l\" | \"cat\" \"-e\"" 550 0
run_test "simple" 631 "'ls' \"-l\" | \"cat\" \"-e\"" 550 0

run_test "simple" 632 "\"ls\" \"-l\" | \"cat\" \"-e\"" 550 0

if (( "$start_index" >= 500 && "$start_index" <= 632 && "$end_index" >= 500 && "$end_index" <= 632 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 500 to 632\n"
	else
		echo -e "end of test serie from 500 to 632"
	fi
fi

run_test "simple" 650 "'ls -l'" 650 127 "ls -l: command not found"
run_test "simple" 651 "\"ls -l\"" 651 127 "ls -l: command not found"
run_test "simple" 652 "'\"ls -l\"'" 652 127 "\"ls -l\": command not found"
run_test "simple" 653 "\"'ls -l'\"" 653 127 "'ls -l': command not found"

run_test "simple" 654 "'ls'-l" 654 127 "ls-l: command not found"
run_test "simple" 655 "ls'-l'" 655 127 "ls-l: command not found"
run_test "simple" 656 "\"ls\"-l" 656 127 "ls-l: command not found"
run_test "simple" 657 "ls\"-l\"" 657 127 "ls-l: command not found"

run_test "simple" 658 "\"ls\"''-l" 658 127 "ls-l: command not found"
run_test "simple" 659 "\"ls\"''\"-l\"" 659 127 "ls-l: command not found"
run_test "simple" 660 "\"ls\"\"\"-l" 660 127 "ls-l: command not found"
run_test "simple" 661 "\"ls\"\"\"\"-l\"" 661 127 "ls-l: command not found"

run_test "simple" 662 "'ls'\"\"-l" 662 127 "ls-l: command not found"
run_test "simple" 663 "'ls'\"\"'-l'" 663 127 "ls-l: command not found"
run_test "simple" 664 "'ls'''-l" 664 127 "ls-l: command not found"
run_test "simple" 665 "'ls''''-l'" 665 127 "ls-l: command not found"

run_test "simple" 666 "\"ls\"'\"'-l" 666 127 "ls\"-l: command not found"
run_test "simple" 667 "\"ls\"'\"'\"-l\"" 667 127 "ls\"-l: command not found"
run_test "simple" 668 "\"ls\"\"'\"-l" 668 127 "ls'-l: command not found"
run_test "simple" 669 "\"ls\"\"'\"\"-l\"" 669 127 "ls'-l: command not found"

run_test "simple" 670 "'ls'\"'\"-l" 670 127 "ls'-l: command not found"
run_test "simple" 671 "'ls'\"'\"'-l'" 671 127 "ls'-l: command not found"
run_test "simple" 672 "'ls''\"'-l" 672 127 "ls\"-l: command not found"
run_test "simple" 673 "'ls''\"''-l'" 673 127 "ls\"-l: command not found"

if (( "$start_index" >= 650 && "$start_index" <= 657 && "$end_index" >= 650 && "$end_index" <= 657 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 650 to 657\n"
	else
		echo -e "end of test serie from 650 to 657"
	fi
fi

run_test "simple" 700 "'ls -l cat -e'" 700 127 "ls -l cat -e: command not found"
run_test "simple" 701 "\"ls -l cat -e\"" 700 127 "ls -l cat -e: command not found"
run_test "simple" 702 "'\"ls -l cat -e\"'" 702 127 "\"ls -l cat -e\": command not found"
run_test "simple" 703 "\"'ls -l cat -e'\"" 703 127 "'ls -l cat -e': command not found"

run_test "simple" 704 "'ls'-l cat -e" 704 127 "ls-l: command not found"
run_test "simple" 705 "ls'-l' cat -e" 704 127 "ls-l: command not found"
run_test "simple" 706 "\"ls\"-l cat -e" 704 127 "ls-l: command not found"
run_test "simple" 707 "ls\"-l\" cat -e" 704 127 "ls-l: command not found"

run_test "simple" 708 "'ls -l' cat -e" 708 127 "ls -l: command not found"
run_test "simple" 710 "'\"ls -l\"' cat -e" 710 127 "\"ls -l\": command not found"
run_test "simple" 711 "\"'ls -l'\" cat -e" 711 127 "'ls -l': command not found"

run_test "simple" 712 "'ls -l'cat -e" 712 127 "ls -lcat: command not found"
run_test "simple" 713 "\"ls -l\"cat -e" 712 127 "ls -lcat: command not found"
run_test "simple" 714 "'\"ls -l\"'cat -e" 714 127 "\"ls -l\"cat: command not found"
run_test "simple" 715 "\"'ls -l'\"cat -e" 715 127 "'ls -l'cat: command not found"

run_test "simple" 716 "'ls -l' 'cat' -e" 716 127 "ls -l: command not found"
run_test "simple" 717 "\"ls -l\" 'cat' -e" 716 127  "ls -l: command not found"
run_test "simple" 718 "'\"ls -l\"' 'cat' -e" 718 127 "\"ls -l\": command not found"
run_test "simple" 719 "\"'ls -l'\" 'cat' -e" 719 127 "'ls -l': command not found"

run_test "simple" 720 "'ls -l' cat '-e'" 720 127 "ls -l: command not found"
run_test "simple" 721 "\"ls -l\" cat '-e'" 720 127 "ls -l: command not found"
run_test "simple" 722 "'\"ls -l\"' cat '-e'" 722 127 "\"ls -l\": command not found"
run_test "simple" 723 "\"'ls -l'\" cat '-e'" 723 127 "'ls -l': command not found"
run_test "simple" 724 "'ls -l' 'cat' '-e'" 724 127 "ls -l: command not found"
run_test "simple" 725 "\"ls -l\" 'cat' '-e'" 724 127 "ls -l: command not found"
run_test "simple" 726 "'\"ls -l\"' 'cat' '-e'" 726 127 "\"ls -l\": command not found"
run_test "simple" 727 "\"'ls -l'\" 'cat' '-e'" 727 127 "'ls -l': command not found"
run_test "simple" 728 "'ls -l' \"cat\" '-e'" 728 127 "ls -l: command not found"
run_test "simple" 729 "\"ls -l\" \"cat\" '-e'" 729 127 "ls -l: command not found"
run_test "simple" 730 "'\"ls -l\"' \"cat\" '-e'" 730 127 "\"ls -l\": command not found"

run_test "simple" 731 "\"'ls -l'\" \"cat\" '-e'" 731 127 "'ls -l': command not found"
run_test "simple" 732 "'ls -l' \"cat\" \"-e\"" 732 127 "ls -l: command not found"
run_test "simple" 733 "\"ls -l\" \"cat\" \"-e\"" 733 127 "ls -l: command not found"
run_test "simple" 734 "'\"ls -l\"' \"cat\" \"-e\"" 734 127 "\"ls -l\": command not found"
run_test "simple" 735 "\"'ls -l'\" \"cat\" \"-e\"" 735 127 "'ls -l': command not found"

if (( "$start_index" >= 700 && "$start_index" <= 735 && "$end_index" >= 700 && "$end_index" <= 735 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 700 to 735\n"
	else
		echo -e "end of test serie from 700 to 735"
	fi
fi

run_test "simple" 736 "'ls -l'cat '-e'" 736 127 "ls -lcat: command not found"
run_test "simple" 737 "\"ls -l\"cat '-e'" 737 127 "ls -lcat: command not found"
run_test "simple" 738 "'\"ls -l\"'cat '-e'" 738 127 "\"ls -l\"cat: command not found"
run_test "simple" 739 "\"'ls -l'\"cat '-e'" 739 127 "'ls -l'cat: command not found"
run_test "simple" 740 "'ls -l'cat \"-e\"" 740 127 "ls -lcat: command not found"
run_test "simple" 741 "\"ls -l\"cat \"-e\"" 741 127 "ls -lcat: command not found"
run_test "simple" 742 "'\"ls -l\"'cat \"-e\"" 742 127 "\"ls -l\"cat: command not found"
run_test "simple" 743 "\"'ls -l'\"cat \"-e\"" 743 127 "'ls -l'cat: command not found"
run_test "simple" 744 "'ls -l''cat' '-e'" 744 127 "ls -lcat: command not found"
run_test "simple" 745 "\"ls -l\"'cat' '-e'" 745 127 "ls -lcat: command not found"
run_test "simple" 746 "'\"ls -l\"''cat' '-e'" 746 127 "\"ls -l\"cat: command not found"
run_test "simple" 747 "\"'ls -l'\"'cat' '-e'" 747 127 "'ls -l'cat: command not found"
run_test "simple" 748 "'ls -l''cat' \"-e\"" 748 127 "ls -lcat: command not found"
run_test "simple" 749 "\"ls -l\"'cat' \"-e\"" 749 127 "ls -lcat: command not found"
run_test "simple" 750 "'\"ls -l\"''cat' \"-e\"" 750 127 "\"ls -l\"cat: command not found"
run_test "simple" 751 "\"'ls -l'\"'cat' \"-e\"" 751 127 "'ls -l'cat: command not found"
run_test "simple" 752 "'ls -l'\"cat\" '-e'" 752 127 "ls -lcat: command not found"
run_test "simple" 753 "\"ls -l\"\"cat\" '-e'" 753 127 "ls -lcat: command not found"
run_test "simple" 754 "'\"ls -l\"'\"cat\" '-e'" 754 127 "\"ls -l\"cat: command not found"
run_test "simple" 755 "\"'ls -l'\"\"cat\" '-e'" 755 127 "'ls -l'cat: command not found"
run_test "simple" 756 "'ls -l'\"cat\" \"-e\"" 756 127 "ls -lcat: command not found"
run_test "simple" 757 "\"ls -l\"\"cat\" \"-e\"" 757 127 "ls -lcat: command not found"
run_test "simple" 758 "'\"ls -l\"'\"cat\" \"-e\"" 758 127 "\"ls -l\"cat: command not found"
run_test "simple" 759 "\"'ls -l'\"\"cat\" \"-e\"" 759 127 "'ls -l'cat: command not found"

if (( "$start_index" >= 735 && "$start_index" <= 759 && "$end_index" >= 735 && "$end_index" <= 759 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 735 to 759\n"
	else
		echo -e "end of test serie from 735 to 759"
	fi
fi

run_test "simple" 760 "'ls -l' cat'-e'" 760 127 "ls -l: command not found"
run_test "simple" 761 "\"ls -l\" cat'-e'" 761 127 "ls -l: command not found"
run_test "simple" 762 "'\"ls -l\"' cat'-e'" 762 127 "\"ls -l\": command not found"
run_test "simple" 763 "\"'ls -l'\" cat'-e'" 763 127 "'ls -l': command not found"
run_test "simple" 764 "'ls -l' 'cat''-e'" 764 127 "ls -l: command not found"
run_test "simple" 765 "\"ls -l\" 'cat''-e'" 765 127 "ls -l: command not found"
run_test "simple" 766 "'\"ls -l\"' 'cat''-e'" 766 127 "\"ls -l\": command not found"
run_test "simple" 767 "\"'ls -l'\" 'cat''-e'" 767 127 "'ls -l': command not found"
run_test "simple" 768 "'ls -l' \"cat\"'-e'" 768 127 "ls -l: command not found"
run_test "simple" 769 "\"ls -l\" \"cat\"'-e'" 769 127 "ls -l: command not found"
run_test "simple" 770 "'\"ls -l\"' \"cat\"'-e'" 770 127 "\"ls -l\": command not found"
run_test "simple" 771 "\"'ls -l'\" \"cat\"'-e'" 771 127 "'ls -l': command not found"
run_test "simple" 772 "'ls -l' \"cat\"\"-e\"" 772 127 "ls -l: command not found"
run_test "simple" 773 "\"ls -l\" \"cat\"\"-e\"" 773 127 "ls -l: command not found"
run_test "simple" 774 "'\"ls -l\"' \"cat\"\"-e\"" 774 127 "\"ls -l\": command not found"
run_test "simple" 775 "\"'ls -l'\" \"cat\"\"-e\"" 775 127 "'ls -l': command not found"

if (( "$start_index" >= 760 && "$start_index" <= 775 && "$end_index" >= 760 && "$end_index" <= 775 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 760 to 775\n"
	else
		echo -e "end of test serie from 760 to 775"
	fi
fi

run_test "simple" 800 "\"ls\"\" \"-l | cat -e" 800 0
run_test "simple" 801 "\"ls\"\" \"\"-l\" | cat -e" 801 0
run_test "simple" 802 "\"ls\"\" \"\"-l\"\" \"| cat -e" 802 0
run_test "simple" 803 "\"ls\"\" \"\"-l\"\" \"|\" \"cat -e" 803 0
run_test "simple" 804 "\"ls\"\" \"\"-l\"\" \"|\" \"\"cat\" -e" 804 0
run_test "simple" 805 "\"ls\"\" \"\"-l\"\" \"|\" \"\"cat\"\" \"-e" 805 0
run_test "simple" 806 "\"ls\"\" \"\"-l\"\" \"|\" \"\"cat\"\" \"\"-e\"" 806 0

run_test "simple" 810 "'ls'' '-l | cat -e" 810 0
run_test "simple" 811 "'ls'' ''-l' | cat -e" 811 0
run_test "simple" 812 "'ls'' ''-l'' '| cat -e" 812 0
run_test "simple" 813 "'ls'' ''-l'' '|' 'cat -e" 813 0
run_test "simple" 814 "'ls'' ''-l'' '|' ''cat' -e" 814 0
run_test "simple" 815 "'ls'' ''-l'' '|' ''cat'' '-e" 815 0
run_test "simple" 816 "'ls'' ''-l'' '|' ''cat'' ''-e'" 816 0

run_test "simple" 820 "\"ls\"' '-l | cat -e" 820 0
run_test "simple" 821 "\"ls\"' '\"-l\" | cat -e" 821 0
run_test "simple" 822 "\"ls\"' '\"-l\"' '| cat -e" 822 0
run_test "simple" 823 "\"ls\"' '\"-l\"' '|' 'cat -e" 823 0
run_test "simple" 824 "\"ls\"' '\"-l\"' '|' '\"cat\" -e" 824 0
run_test "simple" 825 "\"ls\"' '\"-l\"' '|' '\"cat\"' '-e" 825 0
run_test "simple" 826 "\"ls\"' '\"-l\"' '|' '\"cat\"' '\"-e\"" 826 0

run_test "simple" 830 "'ls'\" \"-l | cat -e" 830 0
run_test "simple" 831 "'ls'\" \"'-l' | cat -e" 831 0
run_test "simple" 832 "'ls'\" \"'-l'\" \"| cat -e" 832 0
run_test "simple" 833 "'ls'\" \"'-l'\" \"|\" \"cat -e" 833 0
run_test "simple" 834 "'ls'\" \"'-l'\" \"|\" \"'cat' -e" 834 0
run_test "simple" 835 "'ls'\" \"'-l'\" \"|\" \"'cat'\" \"-e" 835 0
run_test "simple" 836 "'ls'\" \"'-l'\" \"|\" \"'cat'\" \"'-e'" 836 0


run_test "simple" 840 "\"ls\"\"'\"-l | cat -e" 840 127 "ls'-l: command not found"
run_test "simple" 841 "'ls''\"'-l | cat -e" 841 127 "ls\"-l: command not found"
run_test "simple" 842 "ls -l | \"cat\"\"'\"-e" 842 127 "cat'-e: command not found"
run_test "simple" 843 "ls -l | 'cat''\"'-e" 843 127 "cat\"-e: command not found"

if (( "$start_index" >= 800 && "$start_index" <= 850 && "$end_index" >= 800 && "$end_index" <= 850 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 800 to 850\n"
	else
		echo -e "end of test serie from 800 to 850"
	fi
fi




run_test "simple" 1000 "'ls'-l'cat -e'" 1000 127 "ls-lcat -e: command not found"
run_test "simple" 1001 "'ls'-l'cat  -e'" 1001 127 "ls-lcat  -e: command not found"
run_test "simple" 1010 "\"ls\"'-l'cat\"-e\"" 1010 127 "ls-lcat-e: command not found"

if (( "$start_index" >= 1000 && "$start_index" <= 1001 && "$end_index" >= 1000 && "$end_index" <= 1001 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 1000 to 1001\n"
	else
		echo -e "end of test serie from 1000 to 1001"
	fi
fi


run_test "simple" 1100 "\\" 1100 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1101 "\"\\\"" 1100 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1102 "\"\\ls\"" 1102 127 "\ls: command not found"
run_test "simple" 1103 "'\'" 1103 127 "\: command not found"
run_test "simple" 1104 "'\ls'" 1104 127 "\ls: command not found"
run_test "simple" 1105 "(" 1105 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1106 ")" 1106 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1107 "()" 1107 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1108 ";" 1108 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1109 ":" 1109 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1110 "!" 1110 127 "" "invalid test because bash has a special behaviour"
run_test "simple" 1111 "-" 1111 127 "\-: command not found"

run_test "simple" 1120 "\"'\"" 1111 127 "': command not found"
run_test "simple" 1121 "@" 1112 127 "@: command not found"
run_test "simple" 1122 "\"@\"" 1113 127 "@: command not found"
run_test "simple" 1123 "*" 1114 127
run_test "simple" 1124 "\"*\"" 1115 127

run_test "simple" 1130 "&" 1130 2 "syntax error" "invalid test because bash has a special behaviour"
run_test "simple" 1131 "&&" 1131 2 "syntax error" "invalid test because bash has a special behaviour"
run_test "simple" 1132 "&&&" 1132 2 "syntax error" "invalid test because bash has a special behaviour"
run_test "simple" 1133 "&&&&" 1133 2 "syntax error" "invalid test because bash has a special behaviour"
run_test "simple" 1134 "&&&&&" 1134 2 "syntax error" "invalid test because bash has a special behaviour"

if (( "$start_index" >= 1100 && "$start_index" <= 1200 && "$end_index" >= 1100 && "$end_index" <= 1200 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 1100 to 1200\n"
	else
		echo -e "end of test serie from 1100 to 1200"
	fi
fi


export TEST="test_minishell"

if (( "$start_index" >= 1500 && "$start_index" <= 1570 && "$end_index" >= 1500 && "$end_index" <= 1570 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo -e echo "\$TEST = \"test_minishell\"\n"
	fi
fi

run_test "simple" 1500 "\$TEST" 1500 0
run_test "simple" 1501 "\$DO_NOT_EXIST" 1501 0
run_test "simple" 1502 "'\$TEST'" 1502 0
run_test "simple" 1503 "\"\$TEST\"" 1503 127 ": command not found"
run_test "simple" 1504 "'\"\$TEST\"'" 1504 127
run_test "simple" 1505 "\"'\"\$TEST\"'\"" 1505 0
run_test "simple" 1506 "\"'\$TEST'\"" 1506 0
run_test "simple" 1507 "'\"'\$TEST'\"'" 1507 0
run_test "simple" 1508 "\"\$TEST \$TEST\"" 1508 0
run_test "simple" 1509 "\" \$TEST\"" 1509 0
run_test "simple" 1510 "\"  \$TEST\"" 1510 0
run_test "simple" 1511 "\"\$TEST \"" 1511 0
run_test "simple" 1512 "\"\$TEST  \"" 1512 0
run_test "simple" 1513 "\" \$TEST \"" 1513 0
run_test "simple" 1514 "\"  \$TEST  \"" 1514 0
run_test "simple" 1515 "\"	\$TEST\"" 1515 0
run_test "simple" 1516 "\"\t\t\$TEST\"" 1516 0
run_test "simple" 1517 "\"\$TEST	\"" 1517 127 "test_minishell	: command not found"
run_test "simple" 1518 "\"\$TEST		\"" 1518 127 "test_minishell		: command not found"
run_test "simple" 1519 "\"	\$TEST	\"" 1519 127 "	test_minishell	: command not found"
run_test "simple" 1520 "\"		\$TEST		\"" 1520 127 "		test_minishell		: command not found"
run_test "simple" 1521 "\" \$TEST	\"" 1521 127 " test_minishell	: command not found"
run_test "simple" 1522 "\"	\$TEST \"" 1522 127 "	test_minishell : command not found"

run_test "simple" 1523 "\$\"TEST\"" 1523 127 "TEST: command not found"
run_test "simple" 1524 "\$'TEST'" 1524 0
run_test "simple" 1525 "\"\$ \"TEST\"\"" 1525 0
run_test "simple" 1526 "\"\$ 'TEST'\"" 1526 0

run_test "simple" 1530 "\" \$TEST \$TEST\"" 1530 0
run_test "simple" 1531 "\"  \$TEST \$TEST\"" 1531 0
run_test "simple" 1532 "\"\$TEST  \$TEST\"" 1532 0
run_test "simple" 1533 "\"\$TEST \$TEST \"" 1533 0
run_test "simple" 1534 "\"\$TEST \$TEST  \"" 1534 0
run_test "simple" 1535 "\" \$TEST  \$TEST\"" 1535 0
run_test "simple" 1536 "\" \$TEST  \$TEST \"" 1536 0
run_test "simple" 1537 "\"\t\$TEST\t\$TEST\"" 1537 0
run_test "simple" 1538 "\"\t\$TEST\t\$TEST\t\"" 1538 0
run_test "simple" 1539 "\"\t\t\$TEST\t\t\$TEST\t\t\"" 1539 0
run_test "simple" 1540 "\$TEST\$TEST" 1540 0
run_test "simple" 1541 "\" \$TEST\$TEST\"" 1541 0
run_test "simple" 1542 "\"\$TEST\$TEST \"" 1542 0
run_test "simple" 1543 "\" \$TEST\$TEST \"" 1543 0
run_test "simple" 1544 "\"	\$TEST\$TEST\"" 1544 0
run_test "simple" 1545 "\"\$TEST\$TEST	\"" 1545 0
run_test "simple" 1546 "\"	\$TEST\$TEST	\"" 1546 0

run_test "simple" 1550 "\"text\$TEST\"" 1550 0
run_test "simple" 1551 "\"text \$TEST\"" 1551 0
run_test "simple" 1552 "\" text \$TEST\"" 1552 0
run_test "simple" 1553 "\"text \$TEST \"" 1553 0
run_test "simple" 1554 "\"text \$TEST text\"" 1554 0
run_test "simple" 1555 "'text \$TEST text'" 1555 0
run_test "simple" 1556 "\"'text \$TEST text'\"" 1556 0
run_test "simple" 1557 "'\"text \$TEST text\"'" 1557 0
run_test "simple" 1558 "\"\$TEST text \$TEST\"" 1558 0

run_test "simple" 1559 "\"\$TEST cat\"" 1559 0
run_test "simple" 1560 "\"\$TEST cat \"" 1560 0
run_test "simple" 1561 "\"\$TEST cat	\"" 1561 0

run_test "simple" 1562 "\$" 1562 0
run_test "simple" 1563 "\"\$ TEST\"" 1563 0
run_test "simple" 1564 "\$\"\"" 1564 127 ": command not found"
run_test "simple" 1565 "\$''" 1565 127 ": command not found"
run_test "simple" 1566 "\"\$\"\"\"" 1566 0
run_test "simple" 1567 "\"\$''\"" 1567 0
run_test "simple" 1568 "\"\$\" \"\"" 1568 0
run_test "simple" 1569 "\"\$' '\"" 1569 0
run_test "simple" 1570 "'\$'''" 1570 0
unset TEST

if (( "$start_index" >= 1500 && "$start_index" <= 1570 && "$end_index" >= 1500 && "$end_index" <= 1570 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 1500 to 1570\n"
	else
		echo -e "end of test serie from 1500 to 1570"
	fi
fi

export TEST1="test1"
export TEST2="test2"
export TEST3="salut     les     amis"

#export TEST3="     salut     les     amis     "
#export TEST3="	salut	les	amis	"

export TEST4='echo    "     salut'
#export TEST5='echo    "     salut     les     amis'

if (( "$start_index" >= 1600 && "$start_index" <= 1699 && "$end_index" >= 1600 && "$end_index" <= 1699 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo "\$TEST1 = \"test1\""
		echo "\$TEST2 = \"test2\""
		echo "\$TEST3 = 'salut     les     amis'"
		echo "\$TEST4 = 'echo    \"     salut'"
		echo "\$TEST5 = 'echo    \"     salut     les     amis'\n"
	fi
fi

run_test "simple" 1600 "echo \$TEST1\$TEST2" 1600 0
run_test "simple" 1601 "echo \$TEST1\"\"\$TEST2" 1601 0
run_test "simple" 1602 "echo \$TEST1"text"\$TEST2" 1602 0
run_test "simple" 1603 "echo \$TEST1"text"\$TEST2$" 1603 0
run_test "simple" 1604 "echo \$\"\"\$TEST1"text"\$TEST2$" 1604 0
run_test "simple" 1605 "echo \$DO_NOT_EXIST\$TEST1"text"\$TEST2$" 1605 0
run_test "simple" 1606 "echo    \$TEST1   \$TEST2   " 1610 0

run_test "simple" 1610 "echo \$TEST3" 1610 0
run_test "simple" 1611 "echo \$TEST3'text'" 1611 0
run_test "simple" 1612 "echo '\$TEST3'" 1612 0
run_test "simple" 1613 "echo '\$TEST3''text'" 1613 0
run_test "simple" 1614 "echo \"\$TEST3\"" 1614 0
run_test "simple" 1615 "echo \"\$TEST3\"'text'" 1615 0
run_test "simple" 1616 "\$TEST4" 1616 0

run_test "simple" 1620 "\$TEST1=\$TEST1" 1620 0

unset TEST1
unset TEST2
unset TEST3

if (( "$start_index" >= 1600 && "$start_index" <= 1699 && "$end_index" >= 1600 && "$end_index" <= 1699 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 1600 to 1699\n"
	else
		echo -e "end of test serie from 1600 to 1699"
	fi
fi

export INFILE="temp/infile1.txt"

if (( "$start_index" >= 1700 && "$start_index" <= 1719 && "$end_index" >= 1700 && "$end_index" <= 1719 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo "\$INFILE = \"temp/infile1.txt\""
		echo ""
	fi
fi

run_test "simple" 1700 "< \$INFILE" 1700 0
run_test "simple" 1701 "< \$DO_NOT_EXIST" 1701 0
run_test "simple" 1702 "< '\$INFILE'" 1702 0
run_test "simple" 1703 "< \"\$INFILE\"" 1703 0
run_test "simple" 1704 "< '\"\$INFILE\"'" 1704 0
run_test "simple" 1705 "< \"'\"\$INFILE\"'\"" 1705 0
run_test "simple" 1706 "< \"\$INFILE \$INFILE\"" 1706 0
run_test "simple" 1707 "< \" \$INFILE\"" 1707 0
run_test "simple" 1708 "< \"  \$INFILE\"" 1708 0
run_test "simple" 1709 "< \"\$INFILE \"" 1709 0
run_test "simple" 1710 "< \"\$INFILE  \"" 1710 0
run_test "simple" 1711 "< \" \$INFILE \"" 1711 0
run_test "simple" 1712 "< \"  \$INFILE  \"" 1712 0
run_test "simple" 1713 "< \"	\$INFILE\"" 1713 0
run_test "simple" 1714 "< \"\$INFILE	\"" 1714 0
run_test "simple" 1715 "< \"		\$INFILE\"" 1715 0
run_test "simple" 1716 "< \"\$INFILE		\"" 1716 0
run_test "simple" 1717 "< \"	\$INFILE	\"" 1717 0
run_test "simple" 1718 "< \"		\$INFILE		\"" 1718 0
run_test "simple" 1719 "< \"INFILE \$INFILE\"" 1719 0
unset INFILE

export OUTFILE="temp/outfile1.txt"

if (( "$start_index" >= 1700 && "$start_index" <= 1759 && "$end_index" >= 1700 && "$end_index" <= 1759 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo "\$OUTFILE = \"temp/outfile.txt\""
		echo ""
	fi
fi

run_test "simple" 1740 "> \$OUTFILE" 1740 0
run_test "simple" 1741 "> \$DO_NOT_EXIST" 1741 0
run_test "simple" 1742 "> '\$OUTFILE'" 1742 0
run_test "simple" 1743 "> \"\$OUTFILE\"" 1743 0
run_test "simple" 1744 "> '\"\$OUTFILE\"'" 1744 0
run_test "simple" 1745 "> \"'\"\$OUTFILE\"'\"" 1745 0
run_test "simple" 1746 "> \"\$OUTFILE \$OUTFILE\"" 1746 0
run_test "simple" 1747 "> \" \$OUTFILE\"" 1747 0
run_test "simple" 1748 "> \"  \$OUTFILE\"" 1748 0
run_test "simple" 1749 "> \"\$OUTFILE \"" 1749 0
run_test "simple" 1750 "> \"\$OUTFILE  \"" 1750 0
run_test "simple" 1751 "> \" \$OUTFILE \"" 1751 0
run_test "simple" 1752 "> \"  \$OUTFILE  \"" 1752 0
run_test "simple" 1753 "> \"	\$OUTFILE\"" 1753 0
run_test "simple" 1754 "> \"\$OUTFILE	\"" 1754 0
run_test "simple" 1755 "> \"		\$OUTFILE\"" 1755 0
run_test "simple" 1756 "> \"\$OUTFILE		\"" 1756 0
run_test "simple" 1757 "> \"	\$OUTFILE	\"" 1757 0
run_test "simple" 1758 "> \"		\$OUTFILE		\"" 1758 0
run_test "simple" 1759 "> \"OUTFILE \$OUTFILE\"" 1759 0
unset OUTFILE

#: <<BLOCK_COMMENT

export LIMITER="limiter1"
export TEST1="salut"
export TEST2="les"
export TEST3="amis"
export TEST4="     salut     les     amis     "
export TEST5="     salut     les     amis"

if (( "$start_index" >= 1770 && "$start_index" <= 1810 && "$end_index" >= 1770 && "$end_index" <= 1810 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo "\$LIMITER = \"limiter1\""
		echo ""
	fi
fi

run_test "oneheredoc" 1770 "<< \$LIMITER" 1770 0 "" "" "\$LIMITER"
run_test "oneheredoc" 1771 "<< \$DO_NOT_EXIST" 1771 0 "" "" "\$DO_NOT_EXIST"
run_test "oneheredoc" 1772 "<< '\$LIMITER'" 1772 0 "" "" "\$LIMITER"
run_test "oneheredoc" 1773 "<< \"\$LIMITER\"" 1772 0 "" "" "\$LIMITER"
run_test "oneheredoc" 1774 "<< '\"\$LIMITER\"'" 1774 0 "" "" "\"\$LIMITER\""
run_test "oneheredoc" 1775 "<< \"'\"\$LIMITER\"'\"" 1775 0 "" "" "'\$LIMITER'"
run_test "oneheredoc" 1776 "<< \"\$LIMITER \$LIMITER\"" 1776 0 "" "" "\$LIMITER \$LIMITER"
run_test "oneheredoc" 1777 "<< \" \$LIMITER\"" 1777 0 "" "" " \$LIMITER"
run_test "oneheredoc" 1778 "<< \"  \$LIMITER\"" 1778 0 "" "" "  \$LIMITER"
run_test "oneheredoc" 1779 "<< \"\$LIMITER \"" 1779 0 "" "" "\$LIMITER "
run_test "oneheredoc" 1780 "<< \"\$LIMITER  \"" 1780 0 "" "" "\$LIMITER  "
run_test "oneheredoc" 1781 "<< \" \$LIMITER \"" 1781 0 "" "" " \$LIMITER "
run_test "oneheredoc" 1782 "<< \"  \$LIMITER  \"" 1782 0 "" "" "  \$LIMITER  "
run_test "oneheredoc" 1783 "<< \"	\$LIMITER\"" 1783 0 "" "" "	\$LIMITER"
run_test "oneheredoc" 1784 "<< \"\$LIMITER	\"" 1784 0 "" "" "\$LIMITER	"
run_test "oneheredoc" 1785 "<< \"		\$LIMITER\"" 1785 0 "" "" "		\$LIMITER"
run_test "oneheredoc" 1786 "<< \"\$LIMITER		\"" 1786 0 "" "" "\$LIMITER		"
run_test "oneheredoc" 1787 "<< \"	\$LIMITER	\"" 1787 0 "" "" "	\$LIMITER	"
run_test "oneheredoc" 1788 "<< \"		\$LIMITER		\"" 1788 0 "" "" "		\$LIMITER		"
run_test "oneheredoc" 1789 "<< \"LIMITER \$LIMITER\"" 1789 0 "" "" "LIMITER \$LIMITER"

run_test "heredoc_with_expand" 1790 "<< limiter1 cat" 1790 0 "" "" "limiter1"


unset LIMITER
unset TEST1
unset TEST2
unset TEST3
unset TEST4
unset TEST5


export OUTFILE="temp/outfile1.txt"

if (( "$start_index" >= 1820 && "$start_index" <= 1838 && "$end_index" >= 1820 && "$end_index" <= 1838 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo "\$OUTFILE = \"temp/outfile.txt\""
		echo ""
	fi
fi

run_test "simple" 1820 ">> \$OUTFILE" 1820 0
run_test "simple" 1821 ">> \$DO_NOT_EXIST" 1821 0
run_test "simple" 1822 ">> '\$OUTFILE'" 1822 0
run_test "simple" 1823 ">> \"\$OUTFILE\"" 1823 0
run_test "simple" 1824 ">> '\"\$OUTFILE\"'" 1824 0
run_test "simple" 1825 ">> \"'\"\$OUTFILE\"'\"" 1825 0
run_test "simple" 1826 ">> \"\$OUTFILE \$OUTFILE\"" 1826 0
run_test "simple" 1827 ">> \" \$OUTFILE\"" 1827 0
run_test "simple" 1828 ">> \"  \$OUTFILE\"" 1828 0
run_test "simple" 1829 ">> \"\$OUTFILE \"" 1829 0
run_test "simple" 1830 ">> \"\$OUTFILE  \"" 1830 0
run_test "simple" 1831 ">> \" \$OUTFILE \"" 1831 0
run_test "simple" 1832 ">> \"  \$OUTFILE  \"" 1832 0
run_test "simple" 1833 ">> \"	\$OUTFILE\"" 1833 0
run_test "simple" 1834 ">> \"\$OUTFILE	\"" 1834 0
run_test "simple" 1835 ">> \"		\$OUTFILE\"" 1835 0
run_test "simple" 1836 ">> \"\$OUTFILE		\"" 1836 0
run_test "simple" 1837 ">> \"	\$OUTFILE	\"" 1837 0
run_test "simple" 1838 ">> \"		\$OUTFILE		\"" 1838 0
unset OUTFILE

if (( "$start_index" >= 1700 && "$start_index" <= 1850 && "$end_index" >= 1700 && "$end_index" <= 1850 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 1700 to 1850\n"
	else
		echo -e "end of test serie from 1700 to 1850"
	fi
fi

export TEST1
export TEST2=
export TEST3=""
export TEST4=" "
export TEST5="	"

if (( "$start_index" >= 1900 && "$start_index" <= 1950 && "$end_index" >= 1900 && "$end_index" <= 1950 ))
then
	if [ "$display" == "all" ]
	then
		echo ""
		echo "\$TEST1"
		echo "\$TEST2 ="
		echo "\$TEST3 = \"\""
		echo "\$TEST4 = \" \""
		echo "\$TEST5 = \"	\""
		echo ""
	fi
fi

run_test "simple" 1900 "< \$TEST1 cat" 1900 1 "\$TEST1: ambiguous redirect"
run_test "simple" 1901 "< \$TEST1 ls" 1901 1 "\$TEST1: ambiguous redirect"
run_test "simple" 1902 "< \$TEST1 cat | cat" 1902 0 "\$TEST1: ambiguous redirect"
run_test "simple" 1903 "< \$TEST1 cat | ls" 1903 0 "\$TEST1: ambiguous redirect"
run_test "simple" 1904 "< \$TEST1 < temp/infile1.txt cat" 1904 1 "\$TEST1: ambiguous redirect"
run_test "simple" 1905 "< temp/infile1.txt < \$TEST1 cat" 1905 1 "\$TEST1: ambiguous redirect"
run_test "simple" 1906 "< \$TEST1 < do_not_exist cat" 1906 1 "\$TEST1: ambiguous redirect"
run_test "simple" 1907 "< do_not_exist < \$TEST1 cat" 1907 1 "do_not_exist: No such file or directory"

run_test "simple" 1910 "< \$TEST2 cat" 1910 1 "\$TEST2: ambiguous redirect"
run_test "simple" 1911 "< \$TEST2 ls" 1911 1 "\$TEST2: ambiguous redirect"
run_test "simple" 1912 "< \$TEST2 cat | cat" 1912 0 "\$TEST2: ambiguous redirect"
run_test "simple" 1913 "< \$TEST2 cat | ls" 1913 0 "\$TEST2: ambiguous redirect"
run_test "simple" 1914 "< \$TEST2 < temp/infile1.txt cat" 1914 1 "\$TEST2: ambiguous redirect"
run_test "simple" 1915 "< temp/infile1.txt < \$TEST2 cat" 1915 1 "\$TEST2: ambiguous redirect"
run_test "simple" 1916 "< \$TEST2 < do_not_exist cat" 1916 1 "\$TEST2: ambiguous redirect"
run_test "simple" 1917 "< do_not_exist < \$TEST2 cat" 1917 1 "do_not_exist: No such file or directory"

run_test "simple" 1920 "< \$TEST3 cat" 1920 1 "\$TEST3: ambiguous redirect"
run_test "simple" 1921 "< \$TEST3 ls" 1921 1 "\$TEST3: ambiguous redirect"
run_test "simple" 1922 "< \$TEST3 cat | cat" 1922 0 "\$TEST3: ambiguous redirect"
run_test "simple" 1923 "< \$TEST3 cat | ls" 1923 0 "\$TEST3: ambiguous redirect"
run_test "simple" 1924 "< \$TEST3 < temp/infile1.txt cat" 1924 1 "\$TEST3: ambiguous redirect"
run_test "simple" 1925 "< temp/infile1.txt < \$TEST3 cat" 1925 1 "\$TEST3: ambiguous redirect"
run_test "simple" 1926 "< \$TEST3 < do_not_exist cat" 1926 1 "\$TEST3: ambiguous redirect"
run_test "simple" 1927 "< do_not_exist < \$TEST3 cat" 1927 1 "do_not_exist: No such file or directory"

run_test "simple" 1930 "< \$TEST4 cat" 1930 1 "\$TEST4: ambiguous redirect"
run_test "simple" 1931 "< \$TEST4 ls" 1931 1 "\$TEST4: ambiguous redirect"
run_test "simple" 1932 "< \$TEST4 cat | cat" 1932 0 "\$TEST4: ambiguous redirect"
run_test "simple" 1933 "< \$TEST4 cat | ls" 1933 0 "\$TEST4: ambiguous redirect"
run_test "simple" 1934 "< \$TEST4 < temp/infile1.txt cat" 1934 1 "\$TEST4: ambiguous redirect"
run_test "simple" 1935 "< temp/infile1.txt < \$TEST4 cat" 1935 1 "\$TEST4: ambiguous redirect"
run_test "simple" 1936 "< \$TEST4 < do_not_exist cat" 1936 1 "\$TEST4: ambiguous redirect"
run_test "simple" 1937 "< do_not_exist < \$TEST4 cat" 1937 1 "do_not_exist: No such file or directory"

run_test "simple" 1940 "< \$TEST5 cat" 1940 1 "\$TEST5: ambiguous redirect"
run_test "simple" 1941 "< \$TEST5 ls" 1941 1 "\$TEST5: ambiguous redirect"
run_test "simple" 1942 "< \$TEST5 cat | cat" 1942 0 "\$TEST5: ambiguous redirect"
run_test "simple" 1943 "< \$TEST5 cat | ls" 1943 0 "\$TEST5: ambiguous redirect"
run_test "simple" 1944 "< \$TEST5 < temp/infile1.txt cat" 1944 1 "\$TEST5: ambiguous redirect"
run_test "simple" 1945 "< temp/infile1.txt < \$TEST5 cat" 1945 1 "\$TEST5: ambiguous redirect"
run_test "simple" 1946 "< \$TEST5 < do_not_exist cat" 1946 1 "\$TEST5: ambiguous redirect"
run_test "simple" 1947 "< do_not_exist < \$TEST5 cat" 1947 1 "do_not_exist: No such file or directory"

unset TEST1
unset TEST2
unset TEST3
unset TEST4
unset TEST5



run_test "simple" 2000 "<" 2000 2 "syntax error"
run_test "simple" 2001 "< <" 2001 2 "syntax error"
run_test "simple" 2002 "< < <" 2002 2 "syntax error"
run_test "simple" 2003 "< < < <" 2003 2 "syntax error"

run_test "simple" 2005 "<<" 2005 2 "syntax error"
run_test "simple" 2006 "<< <<" 2006 2 "syntax error"
run_test "simple" 2007 "<< << <<" 2007 2 "syntax error"
run_test "simple" 2007 "<< << << <<" 2007 2 "syntax error"

run_test "simple" 2010 "<<<" 2010 2 "syntax error"
run_test "simple" 2011 "<<< <<<" 2011 2 "syntax error"
run_test "simple" 2012 "<<< <<< <<<" 2012 2 "syntax error"
run_test "simple" 2013 "<<< <<< <<< <<<" 2013 2 "syntax error"

run_test "simple" 2015 "<<<<" 2015 2 "syntax error"
run_test "simple" 2016 "<<<< <<<<" 2016 2 "syntax error"
run_test "simple" 2017 "<<<< <<<< <<<<" 2017 2 "syntax error"
run_test "simple" 2018 "<<<< <<<< <<<< <<<<" 2018 2 "syntax error"
run_test "simple" 2019 "<<<<<<<<<<<<<<<<" 2019 2 "syntax error"

run_test "simple" 2020 ">" 2020 2 "syntax error"
run_test "simple" 2021 "> >" 2021 2 "syntax error"
run_test "simple" 2022 "> > >" 2022 2 "syntax error"
run_test "simple" 2023 "> > > >" 2023 2 "syntax error"

run_test "simple" 2025 ">>" 2025 2 "syntax error"
run_test "simple" 2026 ">> >>" 2026 2 "syntax error"
run_test "simple" 2027 ">> >> >>" 2027 2 "syntax error"
run_test "simple" 2028 ">> >> >> >>" 2028 2 "syntax error"

run_test "simple" 2030 ">>>" 2030 2 "syntax error"
run_test "simple" 2031 ">>> >>>" 2031 2 "syntax error"
run_test "simple" 2032 ">>> >>> >>>" 2032 2 "syntax error"
run_test "simple" 2033 ">>> >>> >>> >>>" 2033 2 "syntax error"

run_test "simple" 2035 ">>>>" 2035 2 "syntax error"
run_test "simple" 2036 ">>>> >>>>" 2036 2 "syntax error"
run_test "simple" 2037 ">>>> >>>> >>>>" 2037 2 "syntax error"
run_test "simple" 2038 ">>>> >>>> >>>> >>>>" 2038 2 "syntax error"
run_test "simple" 2039 ">>>>>>>>>>>>>>>>" 2039 2 "syntax error"

run_test "simple" 2040 "< << <<< <<<<" 2040 2 "syntax error"
run_test "simple" 2041 "<<<< <<< << <" 2041 2 "syntax error"
run_test "simple" 2042 "> >> >>> >>>>" 2042 2 "syntax error"
run_test "simple" 2043 ">>>> >>> >> >" 2043 2 "syntax error"

run_test "simple" 2050 "<>" 2050 2 "syntax error"
run_test "simple" 2051 "><" 2051 2 "syntax error"
run_test "simple" 2052 "<><>" 2052 2 "syntax error"
run_test "simple" 2053 "><><" 2053 2 "syntax error"
run_test "simple" 2054 "<<>" 2054 2 "syntax error"
run_test "simple" 2055 "<<>>" 2055 2 "syntax error"
run_test "simple" 2056 "<<<>>>" 2056 2 "syntax error"
run_test "simple" 2057 "<<<<>>>>" 2057 2 "syntax error"
run_test "simple" 2058 ">><" 2058 2 "syntax error"
run_test "simple" 2059 ">><<" 2059 2 "syntax error"
run_test "simple" 2060 ">>><<<" 2060 2 "syntax error"
run_test "simple" 2061 ">>>><<<<" 2061 2 "syntax error"

run_test "simple" 2070 "ls <" 2070 2 "syntax error"
run_test "simple" 2071 "ls <<" 2071 2 "syntax error"
run_test "simple" 2072 "ls >" 2072 2 "syntax error"
run_test "simple" 2073 "ls >>" 2073 2 "syntax error"
run_test "simple" 2074 "ls<" 2074 2 "syntax error"
run_test "simple" 2075 "ls<<" 2075 2 "syntax error"
run_test "simple" 2076 "ls>" 2076 2 "syntax error"
run_test "simple" 2077 "ls>>" 2077 2 "syntax error"

run_test "simple" 2080 "|" 2080 2 "syntax error"
run_test "simple" 2081 " |" 2081 2 "syntax error"
run_test "simple" 2082 "  |" 2082 2 "syntax error"
run_test "simple" 2083 "| " 2083 2 "syntax error"
run_test "simple" 2084 "|  " 2084 2 "syntax error"
run_test "simple" 2085 " | " 2085 2 "syntax error"
run_test "simple" 2086 "  | " 2086 2 "syntax error"
run_test "simple" 2087 "  |  " 2087 2 "syntax error"
run_test "simple" 2088 "	|" 2088 2 "syntax error"
run_test "simple" 2089 "		|" 2089 2 "syntax error"
run_test "simple" 2090 "|	" 2090 2 "syntax error"
run_test "simple" 2091 "|		" 2091 2 "syntax error"
run_test "simple" 2092 "	|	" 2092 2 "syntax error"
run_test "simple" 2093 "		|		" 2093 2 "syntax error"

run_test "simple" 2100 "| ls" 2100 2 "syntax error"
run_test "simple" 2101 "|ls" 2101 2 "syntax error"
run_test "simple" 2102 " |ls" 2102 2 "syntax error"
run_test "simple" 2103 "ls |" 2103 2 "syntax error"
run_test "simple" 2104 "ls|" 2104 2 "syntax error"
run_test "simple" 2105 "ls| " 2105 2 "syntax error"

run_test "simple" 2110 "||" 2110 2 "syntax error"
run_test "simple" 2111 "| |" 2111 2 "syntax error"
run_test "simple" 2112 "|	|" 2112 2 "syntax error"
run_test "simple" 2113 "|||" 2113 2 "syntax error"
run_test "simple" 2114 "| | |" 2114 2 "syntax error"
run_test "simple" 2115 "|	|	|" 2115 2 "syntax error"
run_test "simple" 2116 "||||" 2116 2 "syntax error"
run_test "simple" 2117 "|||||" 2117 2 "syntax error"
run_test "simple" 2118 "| | | |" 2118 2 "syntax error"
run_test "simple" 2119 "| | | | |" 2119 2 "syntax error"
run_test "simple" 2120 "|	|	|	|" 2120 2 "syntax error"
run_test "simple" 2121 "|	|	|	|	|" 2121 2 "syntax error"

run_test "simple" 2130 ">|" 2130 2 "syntax error"
run_test "simple" 2131 "<|" 2131 2 "syntax error"
run_test "simple" 2132 "|>" 2132 2 "syntax error"
run_test "simple" 2133 "|<" 2133 2 "syntax error"
run_test "simple" 2134 ">>|" 2134 2 "syntax error"
run_test "simple" 2135 "<<|" 2135 2 "syntax error"
run_test "simple" 2136 "|>>" 2136 2 "syntax error"
run_test "simple" 2137 "|<<" 2137 2 "syntax error"

run_test "simple" 2150 ">|>" 2150 2 "syntax error"
run_test "simple" 2151 "<|<" 2151 2 "syntax error"
run_test "simple" 2152 "<|>" 2152 2 "syntax error"
run_test "simple" 2153 ">|<" 2153 2 "syntax error"
run_test "simple" 2154 ">>|<<" 2154 2 "syntax error"
run_test "simple" 2155 "<<|>>" 2155 2 "syntax error"
run_test "simple" 2156 "<<|>>" 2156 2 "syntax error"
run_test "simple" 2157 ">>|<<" 2157 2 "syntax error"

run_test "simple" 2170 "|| ls" 2170 2 "syntax error"
run_test "simple" 2171 "||ls" 2171 2 "syntax error"
run_test "simple" 2172 "ls ||" 2172 2 "syntax error"
run_test "simple" 2173 "ls||" 2173 2 "syntax error"
run_test "simple" 2174 "||| ls" 2174 2 "syntax error"
run_test "simple" 2175 "|||ls" 2175 2 "syntax error"
run_test "simple" 2176 "ls |||" 2176 2 "syntax error"
run_test "simple" 2177 "ls|||" 2177 2 "syntax error"

#run_test "simple" 2200 "ls || cat" 2200 2 "syntax error"//invalid test because bash has a special behaviour
run_test "simple" 2201 "ls | | cat" 2201 2 "syntax error"
run_test "simple" 2202 "ls | cat |" 2202 2 "syntax error"
run_test "simple" 2203 "ls || cat |" 2203 2 "syntax error"


if (( "$start_index" >= 2000 && "$start_index" <= 2150 && "$end_index" >= 2000 && "$end_index" <= 2150 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 2000 to 2150\n"
	else
		echo -e "end of test serie from 2000 to 2150"
	fi
fi


run_test "simple" 2300 "/" 2300 126 "/: Is a directory"
run_test "simple" 2301 "//" 2301 126 "//: Is a directory"
run_test "simple" 2302 "///" 2302 126 "///: Is a directory"
run_test "simple" 2303 "////" 2303 126 "////: Is a directory"

run_test "simple" 2305 "/." 2305 126 "/.: Is a directory"
run_test "simple" 2306 "/./." 2306 126 "/./.: Is a directory"
run_test "simple" 2307 "/././." 2307 126 "/././.: Is a directory"
run_test "simple" 2308 "/./././." 2308 126 "/./././.: Is a directory"

run_test "simple" 2310 "/.." 2310 126 "/..: Is a directory"
run_test "simple" 2311 "/../.." 2311 126 "/../..: Is a directory"
run_test "simple" 2312 "/../../.." 2312 126 "/../../..: Is a directory"
run_test "simple" 2313 "/../../../.." 2313 126 "/../../../..: Is a directory"

run_test "simple" 2315 "./" 2315 126 "./: Is a directory"
run_test "simple" 2316 "././" 2316 126 "././: Is a directory"
run_test "simple" 2317 "./././" 2317 126 "./././: Is a directory"
run_test "simple" 2318 "././././" 2318 126 "././././: Is a directory"

run_test "simple" 2320 ".//" 2320 126 ".//: Is a directory"
run_test "simple" 2321 ".//." 2321 126 ".//.: Is a directory"
run_test "simple" 2322 ".//.." 2322 126 ".//..: Is a directory"
run_test "simple" 2323 "/./" 2323 126 "/./: Is a directory"
run_test "simple" 2324 "./../" 2324 126 "./../: Is a directory"
run_test "simple" 2325 "/./.." 2325 126 "/./..: Is a directory"
run_test "simple" 2326 "/./../" 2326 126 "/./../: Is a directory"
run_test "simple" 2327 "/../." 2327 126 "/../.: Is a directory"
run_test "simple" 2328 "/.././" 2328 126 "/.././: Is a directory"
run_test "simple" 2329 "././.." 2329 126 "././..: Is a directory"
run_test "simple" 2330 "./../." 2330 126 "./../.: Is a directory"
run_test "simple" 2331 ".././.." 2331 126 ".././..: Is a directory"
run_test "simple" 2332 "/./../../../../../.." 2332 126 "/./../../../../../..: Is a directory"
run_test "simple" 2333 "././../../../../../.." 2333 126 "././../../../../../..: Is a directory"

run_test "simple" 2340 "." 2340 2 ".: filename argument required"
run_test "simple" 2345 ".." 2345 127 "..: command not found"



run_test "simple" 3000 "<<< infile1.txt" 3000 2 "syntax error" "invalid test because bash has a special behaviour"
run_test "simple" 3001 "<<<< infile1.txt" 3001 2 "syntax error"
run_test "simple" 3002 "<<<<< infile1.txt" 3002 2 "syntax error"
run_test "simple" 3003 "<<> infile1.txt" 3003 2 "syntax error"
run_test "simple" 3004 "<<>> infile1.txt" 3004 2 "syntax error"
run_test "simple" 3005 "<<>>> infile1.txt" 3005 2 "syntax error"
run_test "simple" 3006 "<<>>>> infile1.txt" 3006 2 "syntax error"
run_test "simple" 3007 "<<>< infile1.txt" 3007 2 "syntax error"
run_test "simple" 3008 "<<><< infile1.txt" 3008 2 "syntax error"
run_test "simple" 3009 "<<><<< infile1.txt" 3009 2 "syntax error"
run_test "simple" 3010 "<<><<<< infile1.txt" 3010 2 "syntax error"
run_test "simple" 3011 "<<><> infile1.txt" 3011 2 "syntax error"
run_test "simple" 3012 "<<><>> infile1.txt" 3012 2 "syntax error"
run_test "simple" 3013 "<<><>>> infile1.txt" 3013 2 "syntax error"
run_test "simple" 3014 "<<><>>>> infile1.txt" 3014 2 "syntax error"
run_test "simple" 3015 "<> infile1.txt" 3015 2 "syntax error" "invalid test because bash has a special behaviour"
run_test "simple" 3016 "<>> infile1.txt" 3016 2 "syntax error"
run_test "simple" 3017 "<>>> infile1.txt" 3017 2 "syntax error"
run_test "simple" 3018 "<>>>> infile1.txt" 3018 2 "syntax error"
run_test "simple" 3019 "<>>>>> infile1.txt" 3019 2 "syntax error"
run_test "simple" 3020 "<>< infile1.txt" 3020 2 "syntax error"
run_test "simple" 3021 "<><< infile1.txt" 3021 2 "syntax error"
run_test "simple" 3022 "<><<< infile1.txt" 3022 2 "syntax error"
run_test "simple" 3023 "<><<<< infile1.txt" 3023 2 "syntax error"
run_test "simple" 3024 "<><> infile1.txt" 3024 2 "syntax error"
run_test "simple" 3025 "<><>> infile1.txt" 3025 2 "syntax error"
run_test "simple" 3026 "<><>>> infile1.txt" 3026 2 "syntax error"
run_test "simple" 3027 "<><>>>> infile1.txt" 3027 2 "syntax error"
run_test "simple" 3028 "<><>>>>> infile1.txt" 3028 2 "syntax error"
run_test "simple" 3029 ">>> outfile1.txt" 3029 2 "syntax error"
run_test "simple" 3030 ">>>> outfile1.txt" 3030 2 "syntax error"
run_test "simple" 3031 ">>>>> outfile1.txt" 3031 2 "syntax error"
run_test "simple" 3032 ">>>>>> outfile1.txt" 3032 2 "syntax error"
run_test "simple" 3033 ">>< outfile1.txt" 3033 2 "syntax error"
run_test "simple" 3034 ">><< outfile1.txt" 3034 2 "syntax error"
run_test "simple" 3035 ">><<< outfile1.txt" 3035 2 "syntax error"
run_test "simple" 3036 ">><<<< outfile1.txt" 3036 2 "syntax error"
run_test "simple" 3037 ">><<<<< outfile1.txt" 3037 2 "syntax error"
run_test "simple" 3038 ">><> outfile1.txt" 3038 2 "syntax error"
run_test "simple" 3039 ">><>> outfile1.txt" 3039 2 "syntax error"
run_test "simple" 3040 ">><>>> outfile1.txt" 3040 2 "syntax error"
run_test "simple" 3041 ">><>>>> outfile1.txt" 3041 2 "syntax error"
run_test "simple" 3042 ">><>>>>> outfile1.txt" 3042 2 "syntax error"

if (( "$start_index" >= 3000 && "$start_index" <= 3050 && "$end_index" >= 3000 && "$end_index" <= 3050 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 3000 to 3050\n"
	else
		echo -e "end of test serie from 3000 to 3050"
	fi
fi

run_test "simple" 3300 "< 'infile1.txt" 3300 2  "syntax error"
run_test "simple" 3301 "< infile1.txt'" 3301 2 "syntax error"
run_test "simple" 3302 "< \"infile1.txt" 3302 2 "syntax error"
run_test "simple" 3303 "< infile1.txt\"" 3303 2 "syntax error"
run_test "simple" 3304 "< 'infile1.txt\"" 3304 2 "syntax error"
run_test "simple" 3305 "< 'infile1.txt'\"" 3305 2 "syntax error"
#run_test "simple" 3306 "< \"infile1.txt'\"" 3306 2 "syntax error"
run_test "simple" 3307 "< \"infile1.txt\"'" 3307 2 "syntax error"
run_test "simple" 3308 "<< 'infile1.txt" 3308 2 "syntax error"
run_test "simple" 3309 "<< infile1.txt'" 3309 2 "syntax error"
run_test "simple" 3310 "<< \"infile1.txt" 3310 2 "syntax error"
run_test "simple" 3311 "<< infile1.txt\"" 3311 2 "syntax error"
run_test "simple" 3312 "<< 'infile1.txt\"" 3312 2 "syntax error"
run_test "simple" 3313 "<< 'infile1.txt'\"" 3313 2 "syntax error"
#run_test "simple" 3314 "<< \"infile1.txt'\"" 3314 2 "syntax error"
run_test "simple" 3315 "<< \"infile1.txt\"'" 3315 2 "syntax error"

run_test "simple" 3400 "> 'outfile1.txt" 3400 2 "syntax error"
run_test "simple" 3401 "> outfile1.txt'" 3401 2 "syntax error"
run_test "simple" 3402 "> \"outfile1.txt" 3402 2 "syntax error"
run_test "simple" 3403 "> outfile1.txt\"" 3403 2 "syntax error"
run_test "simple" 3404 "> 'outfile1.txt\"" 3404 2 "syntax error"
run_test "simple" 3405 "> 'outfile1.txt'\"" 3405 2 "syntax error"
#run_test "simple" 3406 "> \"outfile1.txt'\"" 3406 2 "syntax error"
run_test "simple" 3407 "> \"outfile1.txt\"'" 3407 2 "syntax error"
run_test "simple" 3408 ">> 'outfile1.txt" 3408 2 "syntax error"
run_test "simple" 3409 ">> outfile1.txt'" 3409 2 "syntax error"
run_test "simple" 3410 ">> \"outfile1.txt" 3410 2 "syntax error"
run_test "simple" 3411 ">> outfile1.txt\"" 3411 2 "syntax error"
run_test "simple" 3412 ">> 'outfile1.txt\"" 3412 2 "syntax error"
run_test "simple" 3413 ">> 'outfile1.txt'\"" 3413 2 "syntax error"
#run_test "simple" 3414 ">> \"outfile1.txt'\"" 3414 2 "syntax error"
run_test "simple" 3415 ">> \"outfile1.txt\"'" 3415 2 "syntax error"

if (( "$start_index" >= 3300 && "$start_index" <= 3415 && "$end_index" >= 3300 && "$end_index" <= 3415 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 3300 to 3415\n"
	else
		echo -e "end of test serie from 3300 to 3415"
	fi
fi

run_test "simple" 4000 "'ls" 4000 2 "syntax error"
run_test "simple" 4001 "ls'" 4001 2 "syntax error"
run_test "simple" 4002 "\"ls" 4002 2 "syntax error"
run_test "simple" 4003 "ls\"" 4003 2 "syntax error"
run_test "simple" 4004 "'ls\"" 4004 2 "syntax error"
run_test "simple" 4005 "'ls'\"" 4005 2 "syntax error"
run_test "simple" 4006 "\"ls'" 4006 2 "syntax error"
run_test "simple" 4007 "\"ls\"'" 4007 2 "syntax error"
#run_test "simple" 4008 "''ls" 4008 2 "syntax error"
run_test "simple" 4009 "''ls'" 4009 2 "syntax error"
run_test "simple" 4010 "'''ls" 4010 2 "syntax error"
#run_test "simple" 4011 "'''ls'" 4011 2 "syntax error"
run_test "simple" 4012 "'''ls''" 4012 2 "syntax error"
#run_test "simple" 4013 "\"\"ls" 4013 2 "syntax error"
run_test "simple" 4014 "\"\"ls\"" 4014 2 "syntax error"
run_test "simple" 4015 "\"\"\"ls" 4015 2 "syntax error"
#run_test "simple" 4016 "\"\"\"ls\"" 4016 2 "syntax error"
run_test "simple" 4017 "\"\"\"ls\"\"" 4017 2 "syntax error"
#to continue


if (( "$start_index" >= 4000 && "$start_index" <= 4020 && "$end_index" >= 4000 && "$end_index" <= 4020 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4000 to 4020\n"
	else
		echo -e "end of test serie from 4000 to 4020"
	fi
fi



run_test "simple" 4100 "cat 'ls" 4100 2 "syntax error"
run_test "simple" 4101 "cat ls'" 4101 2 "syntax error"
run_test "simple" 4102 "cat \"ls" 4102 2 "syntax error"
run_test "simple" 4103 "cat ls\"" 4103 2 "syntax error"
run_test "simple" 4104 "'cat' 'ls" 4104 2 "syntax error"
run_test "simple" 4105 "'cat' ls'" 4105 2 "syntax error"
run_test "simple" 4106 "'cat' ls'" 4106 2 "syntax error"
run_test "simple" 4107 "'cat' \"ls" 4107 2 "syntax error"
run_test "simple" 4108 "'cat' ls\"" 4108 2 "syntax error"
run_test "simple" 4109 ""cat" 'ls" 4109 2 "syntax error"
run_test "simple" 4110 ""cat" ls'" 4110 2 "syntax error"
run_test "simple" 4111 ""cat" ls'" 4111 2 "syntax error"
run_test "simple" 4112 ""cat" \"ls" 4112 2 "syntax error"
run_test "simple" 4113 ""cat" ls\"" 4113 2 "syntax error"
run_test "simple" 4114 "cat 'ls " 4114 2 "syntax error"
run_test "simple" 4115 "cat ls' " 4115 2 "syntax error"
run_test "simple" 4116 "cat \"ls " 4116 2 "syntax error"
run_test "simple" 4117 "cat ls\" " 4117 2 "syntax error"
run_test "simple" 4118 "cat 'ls  " 4118 2 "syntax error"
run_test "simple" 4119 "cat ls'  " 4119 2 "syntax error"
run_test "simple" 4120 "cat \"ls  " 4120 2 "syntax error"
run_test "simple" 4121 "cat ls\"  " 4121 2 "syntax error"
run_test "simple" 4122 "cat ' ls" 4122 2 "syntax error"
run_test "simple" 4123 "cat  ls'" 4123 2 "syntax error"
run_test "simple" 4124 "cat \" ls" 4124 2 "syntax error"
run_test "simple" 4125 "cat ls \"" 4125 2 "syntax error"

if (( "$start_index" >= 4100 && "$start_index" <= 4125 && "$end_index" >= 4100 && "$end_index" <= 4125 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4100 to 4125\n"
	else
		echo -e "end of test serie from 4100 to 4125"
	fi
fi

run_test "simple" 4300 "'" 4300 2 #exit_status to confirm
run_test "simple" 4301 "\"" 4301 2 #exit_status to confirm
run_test "simple" 4302 "\"\"\"" 4302 2 #exit_status to confirm

if (( "$start_index" >= 4300 && "$start_index" <= 4350 && "$end_index" >= 4300 && "$end_index" <= 4350 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4300 to 4350\n"
	else
		echo -e "end of test serie from 4300 to 4350"
	fi
fi


run_test "simple" 4429 "\"ls -l\" \"cat\" '-e'" 4429 127
run_test "simple" 4430 "'\"ls -l\"' \"cat\" '-e'" 4430 127
run_test "simple" 4431 "\"'ls -l'\" \"cat\" '-e'" 4431 127
run_test "simple" 4432 "'ls -l' \"cat\" \"-e\"" 4432 127
run_test "simple" 4433 "\"ls -l\" \"cat\" \"-e\"" 4433 127
run_test "simple" 4434 "'\"ls -l\"' \"cat\" \"-e\"" 4434 127
run_test "simple" 4435 "\"'ls -l'\" \"cat\" \"-e\"" 4435 127

run_test "simple" 4436 "'ls -l'cat '-e'" 4436 127
run_test "simple" 4437 "\"ls -l\"cat '-e'" 4437 127
run_test "simple" 4438 "'\"ls -l\"'cat '-e'" 4438 127
run_test "simple" 4439 "\"'ls -l'\"cat '-e'" 4439 127
run_test "simple" 4440 "'ls -l'cat \"-e\"" 4470 127
run_test "simple" 4441 "\"ls -l\"cat \"-e\"" 4441 127
run_test "simple" 4442 "'\"ls -l\"'cat \"-e\"" 4472 127
run_test "simple" 4443 "\"'ls -l'\"cat \"-e\"" 4443 127
run_test "simple" 4444 "'ls -l''cat' '-e'" 4444 127
run_test "simple" 4445 "\"ls -l\"'cat' '-e'" 4445 127
run_test "simple" 4446 "'\"ls -l\"''cat' '-e'" 4446 127
run_test "simple" 4447 "\"'ls -l'\"'cat' '-e'" 4447 127
run_test "simple" 4448 "'ls -l''cat' \"-e\"" 4448 127
run_test "simple" 4449 "\"ls -l\"'cat' \"-e\"" 4449 127
run_test "simple" 4450 "'\"ls -l\"''cat' \"-e\"" 4450 127
run_test "simple" 4451 "\"'ls -l'\"'cat' \"-e\"" 4451 127
run_test "simple" 4452 "'ls -l'\"cat\" '-e'" 4452 127
run_test "simple" 4453 "\"ls -l\"\"cat\" '-e'" 4453 127
run_test "simple" 4454 "'\"ls -l\"'\"cat\" '-e'" 4454 127
run_test "simple" 4455 "\"'ls -l'\"\"cat\" '-e'" 4455 127
run_test "simple" 4456 "'ls -l'\"cat\" \"-e\"" 4456 127
run_test "simple" 4457 "\"ls -l\"\"cat\" \"-e\"" 4457 127
run_test "simple" 4458 "'\"ls -l\"'\"cat\" \"-e\"" 4458 127
run_test "simple" 4459 "\"'ls -l'\"\"cat\" \"-e\"" 4459 127

run_test "simple" 4460 "'ls -l' cat'-e'" 4460 127
run_test "simple" 4461 "\"ls -l\" cat'-e'" 4461 127
run_test "simple" 4462 "'\"ls -l\"' cat'-e'" 4462 127
run_test "simple" 4463 "\"'ls -l'\" cat'-e'" 4463 127
run_test "simple" 4464 "'ls -l' 'cat''-e'" 4464 127
run_test "simple" 4465 "\"ls -l\" 'cat''-e'" 4465 127
run_test "simple" 4466 "'\"ls -l\"' 'cat''-e'" 4466 127
run_test "simple" 4467 "\"'ls -l'\" 'cat''-e'" 4467 127
run_test "simple" 4468 "'ls -l' \"cat\"'-e'" 4468 127
run_test "simple" 4469 "\"ls -l\" \"cat\"'-e'" 4469 127
run_test "simple" 4470 "'\"ls -l\"' \"cat\"'-e'" 4470 127
run_test "simple" 4471 "\"'ls -l'\" \"cat\"'-e'" 4471 127
run_test "simple" 4472 "'ls -l' \"cat\"\"-e\"" 4472 127
run_test "simple" 4473 "\"ls -l\" \"cat\"\"-e\"" 4473 127
run_test "simple" 4474 "'\"ls -l\"' \"cat\"\"-e\"" 4474 127
run_test "simple" 4475 "\"'ls -l'\" \"cat\"\"-e\"" 4475 127

if (( "$start_index" >= 4400 && "$start_index" <= 4475 && "$end_index" >= 4400 && "$end_index" <= 4475 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4400 to 4475\n"
	else
		echo -e "end of test serie from 4400 to 4475"
	fi
fi



run_test "simple" 4500 "ls|ls" 4500 0
run_test "simple" 4501 "ls | ls" 4500 0
run_test "simple" 4502 " ls | ls " 4500 0
run_test "simple" 4503 "	ls | ls " 4500 0
run_test "simple" 4504 "	ls	| ls " 4500 0
run_test "simple" 4505 "	ls	|	ls " 4500 0
run_test "simple" 4506 "	ls	|	ls	" 4500 0
run_test "simple" 4507 "		ls | ls " 4500 0
run_test "simple" 4508 "		ls		| ls " 4500 0
run_test "simple" 4509 "		ls		|		ls" 4500 0
run_test "simple" 4510 "		ls		|		ls		" 4500 0
run_test "simple" 4511 " 		ls		|		ls		" 4500 0
run_test "simple" 4512 " 		ls 		|		ls		" 4500 0
run_test "simple" 4513 " 		ls 		| 		ls		" 4500 0
run_test "simple" 4514 " 		ls 		| 		ls 		" 4500 0
run_test "simple" 4515 "  		ls 		| 		ls 		" 4500 0
run_test "simple" 4516 "  		ls  		| 		ls 		" 4500 0
run_test "simple" 4517 "  		ls  		|  		ls 		" 4500 0
run_test "simple" 4518 "  		ls  		|  		ls  		" 4500 0


if (( "$start_index" >= 4500 && "$start_index" <= 4600 && "$end_index" >= 4500 && "$end_index" <= 4600 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4500 to 4600\n"
	else
		echo -e "end of test serie from 4500 to 4600"
	fi
fi


run_test "simple" 4700 "echo" 4700 0
run_test "simple" 4701 "echo -n" 4701 0
run_test "simple" 4702 "echo hello" 4702 0
run_test "simple" 4703 "echo -hello" 4702 0

run_test "simple" 4705 "echohello" 4705 127 "echohello: command not found"
run_test "simple" 4706 "echo -n hello" 4706 0
run_test "simple" 4707 "echo-n hello" 4707 127 "echo-n: command not found"
run_test "simple" 4708 "echo -nhello" 4708 0
run_test "simple" 4709 "echo-nhello" 4709 127 "echo-nhello: command not found"
run_test "simple" 4710 "echo "-n" hello" 4710 0
run_test "simple" 4711 "echo hello -n" 4711 0
run_test "simple" 4712 "echo \n hello" 4712 0

run_test "simple" 4715 "echo | cat -e" 4715 0
run_test "simple" 4716 "echo \"     \" | cat -e" 4716 0

run_test "simple" 4720 "echo -n -n" 4720 0
run_test "simple" 4721 "echo -n -n -n" 4721 0
run_test "simple" 4722 "echo -n -n -n -n" 4722 0
run_test "simple" 4723 "echo -n -n -n -n -n" 4723 0
run_test "simple" 4724 "echo -n -n Hello" 4724 0
run_test "simple" 4725 "echo -n -n -n Hello" 4725 0
run_test "simple" 4726 "echo -n -n -n -n Hello" 4726 0
run_test "simple" 4727 "echo -n -n -n -n -n Hello" 4727 0

run_test "simple" 4730 "echo -nn -nn" 4730 0
run_test "simple" 4731 "echo -nn -nn -nn" 4731 0
run_test "simple" 4732 "echo -nn -nn -nn -nn" 4732 0
run_test "simple" 4733 "echo -nn -nn -nn -nn -nn" 4733 0
run_test "simple" 4734 "echo -nn -nn Hello" 4734 0
run_test "simple" 4735 "echo -nn -nn -nn Hello" 4735 0
run_test "simple" 4736 "echo -nn -nn -nn -nn Hello" 4736 0
run_test "simple" 4737 "echo -nn -nn -nn -nn -nn Hello" 4737 0

run_test "simple" 4740 "echo -nnn -nnn" 4720 0
run_test "simple" 4741 "echo -nnn -nnn -nnn" 4741 0
run_test "simple" 4742 "echo -nnn -nnn -nnn -nnn" 4742 0
run_test "simple" 4743 "echo -nnn -nnn -nnn -nnn -nnn" 4743 0
run_test "simple" 4744 "echo -nnn -nnn Hello" 4744 0
run_test "simple" 4745 "echo -nnn -nnn -nnn Hello" 4745 0
run_test "simple" 4746 "echo -nnn -nnn -nnn -nnn Hello" 4746 0
run_test "simple" 4747 "echo -nnn -nnn -nnn -nnn -nnn Hello" 4747 0

run_test "simple" 4750 "echo -nn" 4750 0
run_test "simple" 4751 "echo -nnn" 4751 0
run_test "simple" 4752 "echo -nnnn" 4752 0
run_test "simple" 4753 "echo -nnnnn" 4753 0
run_test "simple" 4754 "echo -nnnnnn" 4754 0
run_test "simple" 4755 "echo -nnnnnnn" 4755 0
run_test "simple" 4756 "echo -nnnnnnnn" 4756 0
run_test "simple" 4757 "echo -nn Hello" 4757 0
run_test "simple" 4758 "echo -nnn Hello" 4758 0
run_test "simple" 4759 "echo -nnnn Hello" 4759 0
run_test "simple" 4760 "echo -nnnnn Hello" 4760 0
run_test "simple" 4761 "echo -nnnnnn Hello" 4761 0
run_test "simple" 4762 "echo -nnnnnnn Hello" 4762 0
run_test "simple" 4763 "echo -nnnnnnnn Hello" 4763 0

run_test "simple" 4770 "echo -n -nn" 4770 0
run_test "simple" 4771 "echo -n -nn -nnn" 4771 0
run_test "simple" 4772 "echo -n -nn -nnn -nnnn" 4772 0
run_test "simple" 4773 "echo -n -nn -nnn -nnnn -nnnnn" 4773 0
run_test "simple" 4774 "echo -n -nn Hello" 4774 0
run_test "simple" 4775 "echo -n -nn -nnn Hello" 4775 0
run_test "simple" 4776 "echo -n -nn -nnn -nnnn Hello" 4776 0
run_test "simple" 4777 "echo -n -nn -nnn -nnnn -nnnn Hello" 4777 0

run_test "simple" 4780 "echo -n Hello-nn" 4780 0
run_test "simple" 4781 "echo -n -nn Hello -nnn" 4781 0
run_test "simple" 4782 "echo -n -nn -nnn Hello -nnnn" 4782 0
run_test "simple" 4783 "echo -n -nn -nnn -nnnn Hello -nnnnn" 4783 0

run_test "simple" 4785 "echo -n -nn-nnn" 4785 0
run_test "simple" 4786 "echo -n -nn -nnn-nnnn" 4786 0
run_test "simple" 4787 "echo -n -nn -nnn -nnnn-nnnnn" 4787 0

run_test "simple" 4790 "echo --n" 4790 0
run_test "simple" 4791 "echo ---n" 4791 0
run_test "simple" 4792 "echo ----n" 4792 0
run_test "simple" 4793 "echo -----n" 4793 0
run_test "simple" 4794 "echo -n --n" 4794 0
run_test "simple" 4795 "echo -n ---n" 4795 0
run_test "simple" 4796 "echo -n ----n" 4796 0
run_test "simple" 4797 "echo -n --nn" 4797 0
run_test "simple" 4798 "echo -n ---nn" 4798 0
run_test "simple" 4799 "echo -n ----nn" 4799 0

if (( "$start_index" >= 4700 && "$start_index" <= 4800 && "$end_index" >= 4700 && "$end_index" <= 4800 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4700 to 4800\n"
	else
		echo -e "end of test serie from 4700 to 4800"
	fi
fi


if (( "$start_index" >= 4800 && "$start_index" <= 4999 && "$end_index" >= 4800 && "$end_index" <= 4999 ))
then
	echo -e "lucas tests implementation, and more\n"
fi


run_test "simple" 4801 "echo hello world" 4801 0
run_test "simple" 4802 "echo \"hello world\"" 4802 0
run_test "simple" 4803 "echo 'hello world'" 4803 0
run_test "simple" 4804 "echo hello'world'" 4804 0
run_test "simple" 4805 "echo hello\"\"world" 4805 0
run_test "simple" 4806 "echo ''" 4806 0
run_test "simple" 4807 "echo \"\$PWD\"" 4807 0
run_test "simple" 4808 "echo '\$PWD'" 4808 0
run_test "simple" 4809 "echo \"aspas ->'\"" 4809 0
run_test "simple" 4810 "echo \"aspas -> ' \"" 4810 0
run_test "simple" 4811 "echo 'aspas ->\"'" 4811 0
run_test "simple" 4812 "echo 'aspas -> \" '" 4812 0
run_test "simple" 4813 "echo \"> >> < * ? [ ] | ; [ ] || && ( ) & # $  <<\"" 4813 0


run_test "simple" 4857 "grep est <./temp/infile1.txt" 4857 0 "" "(consider leaks of grep)"
run_test "simple" 4858 "grep est \"<infile1.txt\" <         ./temp/infile1.txt" 4858 0 "" "(consider leaks of grep)"


run_test "simple" 4873 "cat <\"./temp/infile1.txt\" | echo hi" 4873 0
run_test "simple" 4874 "cat <\"./test_files/infile1\" | grep hello\" | echo hi" 4874 0
run_test "simple" 4875 "cat <\"./temp/infile_big.txt\" | echo hi" 4875 0


#366
run_test "simple" 4933 "\$PWD" 4933 126 ": Is a directory"

mkdir ./temp/no_permission_dir
chmod 000 ./temp/no_permission_dir
run_test "simple" 4935 "./temp/no_permission_dir" 4935 126 "./temp/no_permission_dir: Is a directory"
run_test "simple" 4936 "cd ./temp/no_permission_dir" 4936 1 "cd: ./temp/no_permission_dir: Permission denied"

chmod 744 ./temp/no_permission_dir
rmdir ./temp/no_permission_dir

run_test "simple" 4937 "./missing.out" 4937 127 "./missing.out: No such file or directory"
#run_test "simple" 4938 "./minishell" 4938 0

run_test "simple" 4941 "./temp" 4941 126 "./temp: Is a directory"
run_test "simple" 4942 "temp/" 4942 126 "temp/: Is a directory"
run_test "simple" 4943 "/temp" 4943 127 "/temp: No such file or directory"
run_test "simple" 4944 "./missing" 4944 127 "./missing: No such file or directory"
run_test "simple" 4945 "/missing" 4945 127 "/missing: No such file or directory"
run_test "simple" 4946 "missing/" 4946 127 "missing/: No such file or directory"
run_test "simple" 4947 "/missing/" 4947 127 "/missing/: No such file or directory"
run_test "simple" 4948 "./missing/" 4948 127 "./missing/: No such file or directory"
run_test "simple" 4949 "./missing/missing" 4949 127 "./missing/missing: No such file or directory"
run_test "simple" 4950 "/missing/missing" 4950 127 "/missing/missing: No such file or directory"
run_test "simple" 4951 "missing/missing" 4951 127 "missing/missing: No such file or directory"
run_test "simple" 4952 "missing/missing/" 4952 127 "missing/missing/: No such file or directory"
run_test "simple" 4953 "/missing/missing/" 4953 127 "/missing/missing/: No such file or directory"
run_test "simple" 4954 "./missing/missing/" 4954 127 "./missing/missing/: No such file or directory"

run_test "simple" 4960 "/nfs" 4960 126 "/nfs: Is a directory"
run_test "simple" 4961 "/nfs/homes" 4961 126 "/nfs/homes: Is a directory"
run_test "simple" 4962 "/nix" 4962 126 "/nix: Is a directory"

run_test "simple" 4970 "temp" 4970 127 "temp: command not found"

#444
run_test "simple" 4980 "echo \$\"42\$'HOME'" 4980 0


if (( "$start_index" >= 4800 && "$start_index" <= 4999 && "$end_index" >= 4800 && "$end_index" <= 4999 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 4800 to 4999\n"
	else
		echo -e "end of test serie from 4800 to 4999"
	fi
fi





run_test "simple" 5000 "< temp/infile1.txt cat" 5000 0
run_test "simple" 5001 "cat < temp/infile1.txt" 5000 0
run_test "simple" 5002 "< temp/infile1.txt cat -e" 5002 0
run_test "simple" 5003 "cat -e < temp/infile1.txt" 5002 0
run_test "simple" 5004 "cat temp/infile1.txt" 5004 0

run_test "simple" 5010 "< temp/infile1.txt wc" 5010 0
run_test "simple" 5011 "wc < temp/infile1.txt" 5010 0
run_test "simple" 5012 "< temp/infile1.txt wc -l" 5012 0
run_test "simple" 5013 "wc -l < temp/infile1.txt" 5012 0
run_test "simple" 5014 "wc -l temp/infile1.txt" 5014 0

run_test "simple" 5020 "ls > temp/outfile1.txt" 5020 0
run_test "simple" 5021 "> temp/outfile1.txt ls" 5020 0

run_test "simple" 5030 "< temp/infile1.txt cat > temp/outfile1.txt" 5030 0
run_test "simple" 5031 "< temp/infile1.txt > temp/outfile1.txt cat" 5030 0
run_test "simple" 5032 "> temp/outfile1.txt < temp/infile1.txt cat" 5030 0

run_test "simple" 5035 "< temp/infile1.txt wc -l > temp/outfile1.txt" 5035 0
run_test "simple" 5036 "< temp/infile1.txt > temp/outfile1.txt wc -l" 5035 0
run_test "simple" 5037 "> temp/outfile1.txt < temp/infile1.txt wc -l" 5035 0

run_test "simple" 5040 "< temp/infile1.txt ls > temp/outfile1.txt" 5040 0
run_test "simple" 5041 "< temp/infile1.txt > temp/outfile1.txt ls" 5040 0
run_test "simple" 5042 "> temp/outfile1.txt < temp/infile1.txt ls" 5040 0

run_test "simple" 5045 "< temp/infile1.txt < temp/infile2.txt cat" 5045 0
run_test "simple" 5046 "< temp/infile1.txt cat < temp/infile2.txt" 5045 0
run_test "simple" 5047 "cat < temp/infile1.txt < temp/infile2.txt" 5045 0

run_test "simple" 5050 "< temp/infile1.txt < temp/infile2.txt wc -l" 5050 0
run_test "simple" 5051 "< temp/infile1.txt wc -l < temp/infile2.txt" 5050 0
run_test "simple" 5052 "wc -l < temp/infile1.txt < temp/infile2.txt" 5050 0

run_test "simple" 5055 "< temp/infile1.txt < temp/infile2.txt ls" 5055 0
run_test "simple" 5056 "< temp/infile1.txt ls < temp/infile2.txt" 5055 0
run_test "simple" 5057 "ls < temp/infile1.txt < temp/infile2.txt" 5055 0

#run_test "simple" 5060 "> temp/outfile1.txt > temp/outfile2.txt cat" 5060 0
#run_test "simple" 5061 "> temp/outfile1.txt cat > temp/outfile2.txt" 5060 0
#run_test "simple" 5062 "cat > temp/outfile1.txt > temp/outfile2.txt" 5060 0

#run_test "simple" 5065 "> temp/outfile1.txt > temp/outfile2.txt wc -l" 5065 0
#run_test "simple" 5066 "> temp/outfile1.txt wc -l > temp/outfile2.txt" 5065 0
#run_test "simple" 5067 "wc -l > temp/outfile1.txt > temp/outfile2.txt" 5065 0

run_test "simple" 5070 "> temp/outfile1.txt > temp/outfile2.txt ls" 5070 0
run_test "simple" 5071 "> temp/outfile1.txt ls > temp/outfile2.txt" 5070 0
run_test "simple" 5072 "ls > temp/outfile1.txt > temp/outfile2.txt" 5070 0

run_test "simple" 5080 "cat < temp/infile1.txt < temp/infile2.txt > temp/outfile1.txt" 5080 0
run_test "simple" 5081 "< temp/infile1.txt cat < temp/infile2.txt > temp/outfile1.txt" 5080 0
run_test "simple" 5082 "< temp/infile1.txt < temp/infile2.txt cat > temp/outfile1.txt" 5080 0
run_test "simple" 5083 "< temp/infile1.txt < temp/infile2.txt > temp/outfile1.txt cat" 5080 0
run_test "simple" 5084 "> temp/outfile1.txt < temp/infile1.txt < temp/infile2.txt cat" 5080 0
run_test "simple" 5085 "< temp/infile1.txt > temp/outfile1.txt < temp/infile2.txt cat" 5080 0

run_test "simple" 5090 "wc -l < temp/infile1.txt < temp/infile2.txt > temp/outfile1.txt" 5090 0
run_test "simple" 5091 "< temp/infile1.txt wc -l < temp/infile2.txt > temp/outfile1.txt" 5090 0
run_test "simple" 5092 "< temp/infile1.txt < temp/infile2.txt wc -l > temp/outfile1.txt" 5090 0
run_test "simple" 5093 "< temp/infile1.txt < temp/infile2.txt > temp/outfile1.txt wc -l" 5090 0
run_test "simple" 5094 "> temp/outfile1.txt < temp/infile1.txt < temp/infile2.txt wc -l" 5090 0
run_test "simple" 5095 "< temp/infile1.txt > temp/outfile1.txt < temp/infile2.txt wc -l" 5090 0

run_test "simple" 5100 "ls < temp/infile1.txt < temp/infile2.txt > temp/outfile1.txt" 5100 0
run_test "simple" 5101 "< temp/infile1.txt ls < temp/infile2.txt > temp/outfile1.txt" 5100 0
run_test "simple" 5102 "< temp/infile1.txt < temp/infile2.txt ls > temp/outfile1.txt" 5100 0
run_test "simple" 5103 "< temp/infile1.txt < temp/infile2.txt > temp/outfile1.txt ls" 5100 0
run_test "simple" 5104 "> temp/outfile1.txt < temp/infile1.txt < temp/infile2.txt ls" 5100 0
run_test "simple" 5105 "< temp/infile1.txt > temp/outfile1.txt < temp/infile2.txt ls" 5100 0

run_test "simple" 5110 "cat < temp/infile1.txt > temp/outfile1.txt > temp/outfile2.txt" 5110 0
run_test "simple" 5111 "< temp/infile1.txt cat > temp/outfile1.txt > temp/outfile2.txt" 5110 0
run_test "simple" 5112 "< temp/infile1.txt > temp/outfile1.txt cat > temp/outfile2.txt" 5110 0
run_test "simple" 5113 "< temp/infile1.txt > temp/outfile1.txt > temp/outfile2.txt cat" 5110 0
run_test "simple" 5114 "> temp/outfile1.txt < temp/infile1.txt > temp/outfile2.txt cat" 5110 0
run_test "simple" 5115 "> temp/outfile1.txt > temp/outfile2.txt < temp/infile1.txt cat" 5110 0

run_test "simple" 5120 "wc -l < temp/infile1.txt > temp/outfile1.txt > temp/outfile2.txt" 5120 0
run_test "simple" 5121 "< temp/infile1.txt wc -l > temp/outfile1.txt > temp/outfile2.txt" 5120 0
run_test "simple" 5122 "< temp/infile1.txt > temp/outfile1.txt wc -l > temp/outfile2.txt" 5120 0
run_test "simple" 5123 "< temp/infile1.txt > temp/outfile1.txt > temp/outfile2.txt wc -l" 5120 0
run_test "simple" 5124 "> temp/outfile1.txt < temp/infile1.txt > temp/outfile2.txt wc -l" 5120 0
run_test "simple" 5125 "> temp/outfile1.txt > temp/outfile2.txt < temp/infile1.txt wc -l" 5120 0

run_test "simple" 5130 "ls < temp/infile1.txt > temp/outfile1.txt > temp/outfile2.txt" 5130 0
run_test "simple" 5131 "< temp/infile1.txt ls > temp/outfile1.txt > temp/outfile2.txt" 5130 0
run_test "simple" 5132 "< temp/infile1.txt > temp/outfile1.txt ls > temp/outfile2.txt" 5130 0
run_test "simple" 5133 "< temp/infile1.txt > temp/outfile1.txt > temp/outfile2.txt ls" 5130 0
run_test "simple" 5134 "> temp/outfile1.txt < temp/infile1.txt > temp/outfile2.txt ls" 5130 0
run_test "simple" 5135 "> temp/outfile1.txt > temp/outfile2.txt < temp/infile1.txt ls" 5130 0

run_test "simple" 5150 "< temp/infile1.txt < temp/infile2.txt cat > temp/outfile1.txt > temp/outfile2.txt" 5150 0
run_test "simple" 5151 "< temp/infile1.txt > temp/outfile1.txt < temp/infile2.txt > temp/outfile2.txt cat" 5150 0
run_test "simple" 5152 "> temp/outfile1.txt < temp/infile1.txt < temp/infile2.txt > temp/outfile2.txt cat" 5150 0
run_test "simple" 5153 "> temp/outfile1.txt < temp/infile1.txt > temp/outfile2.txt < temp/infile2.txt cat" 5150 0
run_test "simple" 5154 "> temp/outfile1.txt > temp/outfile2.txt < temp/infile1.txt < temp/infile2.txt cat" 5150 0

run_test "simple" 5155 "< temp/infile1.txt < temp/infile2.txt wc -l > temp/outfile1.txt > temp/outfile2.txt" 5155 0
run_test "simple" 5156 "< temp/infile1.txt > temp/outfile1.txt < temp/infile2.txt > temp/outfile2.txt wc -l" 5155 0
run_test "simple" 5157 "> temp/outfile1.txt < temp/infile1.txt < temp/infile2.txt > temp/outfile2.txt wc -l" 5155 0
run_test "simple" 5158 "> temp/outfile1.txt < temp/infile1.txt > temp/outfile2.txt < temp/infile2.txt wc -l" 5155 0
run_test "simple" 5159 "> temp/outfile1.txt > temp/outfile2.txt < temp/infile1.txt < temp/infile2.txt wc -l" 5155 0

run_test "simple" 5165 "< temp/infile1.txt < temp/infile2.txt ls > temp/outfile1.txt > temp/outfile2.txt" 5165 0
run_test "simple" 5166 "< temp/infile1.txt > temp/outfile1.txt < temp/infile2.txt > temp/outfile2.txt ls" 5165 0
run_test "simple" 5167 "> temp/outfile1.txt < temp/infile1.txt < temp/infile2.txt > temp/outfile2.txt ls" 5165 0
run_test "simple" 5168 "> temp/outfile1.txt < temp/infile1.txt > temp/outfile2.txt < temp/infile2.txt ls" 5165 0
run_test "simple" 5169 "> temp/outfile1.txt > temp/outfile2.txt < temp/infile1.txt < temp/infile2.txt ls" 5165 0

if (( "$start_index" >= 5000 && "$start_index" <= 5170 && "$end_index" >= 5000 && "$end_index" <= 5170 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 5000 to 5170\n"
	else
		echo -e "end of test serie from 5000 to 5170"
	fi
fi

run_test "simple" 5200 "grep un < temp/infile1.txt" 5200 0 "" "(consider leaks of grep)"
run_test "simple" 5201 "echo < temp/infile1.txt added_word" 5201 0
run_test "simple" 5202 "echo < temp/infile1.txt added_word" 5202 0
run_test "simple" 5203 "echo added_word1 < temp/infile1.txt added_word2" 5203 0


#run_test "simple" 5250 "cat | cat | ls" 5250 0 "" "needs 2 entries"


if (( "$start_index" >= 5200 && "$start_index" <= 5300 && "$end_index" >= 5200 && "$end_index" <= 5300 ))
then
	if [ "$display" == "all" ]
	then
		echo -e "end of test serie from 5200 to 5300\n"
	else
		echo -e "end of test serie from 5200 to 5300"
	fi
fi


run_test "simple" 7000 "temp/infile1.txt cat" 7000 126 "temp/infile1.txt: Permission denied"
run_test "simple" 7001 "temp/infile1.txt wc" 7001 126 "temp/infile1.txt: Permission denied"
run_test "simple" 7002 "./temp/infile1.txt cat" 7002 126 "temp/infile1.txt: Permission denied"
run_test "simple" 7003 "./temp/infile1.txt wc" 7003 126 "temp/infile1.txt: Permission denied"
run_test "simple" 7004 "Makefile cat" 7004 127 "Makefile: command not found"
run_test "simple" 7005 "Makefile wc" 7005 127 "Makefile: command not found"

echo "ceci est un test" > temp/full_permission_file.txt
chmod 777 temp/full_permission_file.txt
run_test "simple" 7010 "./temp/full_permission_file.txt" 7010 127 "./temp/full_permission_file.txt: line 1: ceci: command not found"
run_test "simple" 7011 "./temp/full_permission_file.txt cat" 7011 127 "./temp/full_permission_file.txt: line 1: ceci: command not found"

echo "ls" > temp/full_permission_file.txt
run_test "simple" 7015 "./temp/full_permission_file.txt" 7015 0


run_test "simple" 7020 "< temp/infile1.txt cat wc" 7020 1 "cat: wc: No such file or directory"

run_test "simple" 7100 "< missing_file cat -e" 7100 1 "missing_file: No such file or directory"
run_test "simple" 7101 "< missing_file invalid_command" 7101 1 "missing_file: No such file or directory"
run_test "simple" 7102 "invalid_command < missing_file" 7102 1 "missing_file: No such file or directory"

run_test "simple" 7200 "< missing_file cat > outfile1.txt" 7200 1 "missing_file: No such file or directory"
run_test "simple" 7201 "> temp/outfile1.txt < missing_file cat" 7201 1 "missing_file: No such file or directory"

echo > temp/outfile_without_permission
chmod 000 temp/outfile_without_permission
run_test "simple" 7300 "> temp/outfile_without_permission < missing_file cat -e" 7300 1 "temp/outfile_without_permission: Permission denied"
run_test "simple" 7301 "< missing_file > temp/outfile_without_permission cat -e" 7301 1 "missing_file: No such file or directory"
run_test "simple" 7302 "> temp/outfile_without_permission < temp/infile1.txt cat -e" 7302 1 "temp/outfile_without_permission: Permission denied"
run_test "simple" 7303 "< temp/infile1.txt > temp/outfile_without_permission cat -e" 7303 1 "temp/outfile_without_permission: Permission denied"
run_test "simple" 7304 "> temp/outfile_without_permission < missing_file invalid_command" 7304 1 "temp/outfile_without_permission: Permission denied"
run_test "simple" 7305 " invalid_command > temp/outfile_without_permission < missing_file" 7305 1 "temp/outfile_without_permission: Permission denied"

echo > temp/infile_without_permission
chmod 000 temp/infile_without_permission
run_test "simple" 7306 "temp/infile_without_permission" 7300 1 "temp/infile_without_permission: Permission denied"
run_test "simple" 7307 "./temp/infile_without_permission" 7300 1 "temp/infile_without_permission: Permission denied"


run_test "simple" 7310 "< temp/infile_without_permission > temp/outfile1.txt cat -e" 7310 1 "temp/infile_without_permission: Permission denied"
run_test "simple" 7311 "> temp/outfile_without_permission < temp/infile_without_permission cat -e" 7311 1 "temp/outfile_without_permission: Permission denied"
run_test "simple" 7312 "< temp/infile_without_permission > temp/outfile_without_permission cat -e" 7312 1 "temp/infile_without_permission: Permission denied"
run_test "simple" 7313 "< temp/infile_without_permission > temp/outfile1.txt cat -e" 7313 1 "temp/infile_without_permission: Permission denied"
run_test "simple" 7314 "> temp/outfile1.txt < temp/infile_without_permission cat -e" 7314 1 "temp/infile_without_permission: Permission denied"
run_test "simple" 7315 "< temp/infile_without_permission > temp/outfile1.txt invalid_command" 7315 1 "temp/infile_without_permission: Permission denied"
run_test "simple" 7316 "invalid_command < temp/infile_without_permission > temp/outfile1.txt" 7316 1 "temp/infile_without_permission: Permission denied"

run_test "simple" 7318 "Tests/executable_no_permission" 7318 126 "Tests/executable_no_permission: Permission denied"
run_test "simple" 7319 "Tests/file_whith_segfault" 7319 139 "segmentation fault  ./file_with_segfault"


chmod 644 temp/outfile_without_permission
delete_file temp/outfile_without_permission
chmod 644 temp/infile_without_permission
delete_file temp/infile_without_permission

#unset PATH
#run_test "simple" 8000 "echo \$PATH" 8000 0
#run_test "simple" 8001 "ls" 8001 127 "ls: No such file or directory"

run_test "simple" 9000 "sleep 100 & pid=$! && kill -SIGINT $pid" 9000 130
run_test "simple" 9001 "sleep 100 & pid=$! && kill -SIGQUIT $pid" 9001 131



# -g for greater than and -ge for greater than or equal to
if [ $flag -gt 0 ]
then
	echo -e "${RED}$flag errors were detected${NC}"
else
	echo -e "${GREEN}no error detected${NC}"
fi

delete_file "\$OUTFILE"
delete_file "\"\$OUTFILE\""

#delete_files

exit
