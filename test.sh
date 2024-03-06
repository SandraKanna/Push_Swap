#!/bin/bash

RED='\033[0;91m'
L_RED='\033[0;31m'
GREEN='\033[1;92m'
L_GREEN='\033[0;32m'
CYAN='\033[0;96m'
BLUE='\033[0;94m'
L_BLUE='\033[0;34m'
YELLOW='\033[0;93m'
L_YELLOW='\033[0;33m'
DEF='\033[0;39m'

if [ "$1" = "stat" ]; then
	./push_swap_tester/complexity 100 100 700 checker_linux
	exit 0
fi

if [ "$1" = "d" ]; then
	echo "\n================================================================================================================"
	echo "Arguments Tests"
	echo "================================================================================================================\n"
else
	echo "\n"
fi

ARG='0 2 1 -5'
if [ "$1" = "d" ]; then
	echo "Arguments : {${ARG}}"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "${CYAN}[Test 1.1 (ok)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.1 (ok)] : ${GREEN}OK${DEF}"
fi

if [ "$1" = "d" ]; then
	echo "\nNo arguments"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -ne 0 ]; then
    echo "${CYAN}[Test 1.2 (no args)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.2 (no args)] : ${GREEN}OK${DEF}"
fi

ARG='0 2 1 e'
if [ "$1" = "d" ]; then
	echo "\nArguments : {${ARG}}"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "${CYAN}[Test 1.3 (error : char)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.3 (error : char)] : ${GREEN}OK${DEF}"
fi

ARG='0 1 2 3.5'
if [ "$1" = "d" ]; then
	echo "\nArguments : {${ARG}}"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "${CYAN}[Test 1.4 (error : float)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.4 (error : float)] : ${GREEN}OK${DEF}"
fi

ARG='0 1 2 2147483648'
if [ "$1" = "d" ]; then
	echo "\nArguments : {${ARG}}"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "${CYAN}[Test 1.5 (error : INT MAX)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.5 (error : INT MAX)] : ${GREEN}OK${DEF}"
fi

ARG='0 1 2 -2147483649'
if [ "$1" = "d" ]; then
	echo "\nArguments : {${ARG}}"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "${CYAN}[Test 1.6 (error : INT MIN)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.6 (error : INT MIN)] : ${GREEN}OK${DEF}"
fi

ARG='0 1 2 3 4 4'
if [ "$1" = "d" ]; then
	echo "\nArguments : {${ARG}}"
fi
./push_swap ${ARG} > /dev/null 2>&1
if [ $? -eq 0 ]; then
    echo "${CYAN}[Test 1.7 (error : double arg)] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 1.7 (error : double arg)] : ${GREEN}OK${DEF}"
fi

if [ "$1" = "d" ]; then
	echo "\n\n================================================================================================================"
	echo "Sort tests"
	echo "================================================================================================================\n"
fi

# TEST 1 (3 ELEMENTS)

iterations=100
min=0
max=0
mid=0
counter=0
checker="OK"

while [ $counter -lt $iterations ]; do
	ARG=$(seq -5 5 | shuf | head -n 3 | tr '\n' ' ')
	result="$(./push_swap ${ARG} | wc -l) "
	if [ $mid -eq 0 ]; then
		min=$result
		max=$result
	fi
	if [ $result -lt $min ]; then
		min=$result
	elif [ $result -gt $max ]; then
		max=$result
	fi
	mid=$((mid + result))
	if [ $(./push_swap ${ARG} | ./checker_linux ${ARG}) = "KO" ]; then
		checker="KO"
		echo "${CYAN}[Test 2.1] : ${RED}NOK${DEF} (iteration : $counter)"
		exit
	fi
	counter=$((counter + 1))
done

mid=$((mid / iterations))

if [ $? -ne 0 ]; then
    echo "${CYAN}[Test 2.1] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 2.1] : ${GREEN}OK${DEF}"
fi
echo "    Argc : ${L_YELLOW}$(echo "${ARG}" | wc -w)${DEF}"
echo "    Checker : ${L_YELLOW}${checker}${DEF}"
echo "    Iterations : ${L_YELLOW}${iterations}${DEF}"
echo "    ${L_GREEN}Min : ${min}${DEF}"
echo "    ${L_BLUE}Mid : ${mid}${DEF}"
echo "    ${L_RED}Max : ${max}${DEF}"



# TEST 2 (5 ELEMENTS)

iterations=100
min=0
max=0
mid=0
counter=0
checker="OK"

while [ $counter -lt $iterations ]; do
	ARG=$(seq -100 100 | shuf | head -n 5 | tr '\n' ' ')
	result="$(./push_swap ${ARG} | wc -l) "
	if [ $mid -eq 0 ]; then
		min=$result
		max=$result
	fi
	if [ $result -lt $min ]; then
		min=$result
	elif [ $result -gt $max ]; then
		max=$result
	fi
	mid=$((mid + result))
	if [ $(./push_swap ${ARG} | ./checker_linux ${ARG}) = "KO" ]; then
		checker="KO"
		echo "${CYAN}[Test 2.2] : ${RED}NOK${DEF} (iteration : $counter)"
		exit
	fi
	counter=$((counter + 1))
done

mid=$((mid / iterations))

if [ $? -ne 0 ]; then
    echo "${CYAN}[Test 2.2] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 2.2] : ${GREEN}OK${DEF}"
fi
echo "    Argc : ${L_YELLOW}$(echo "${ARG}" | wc -w)${DEF}"
echo "    Checker : ${L_YELLOW}${checker}${DEF}"
echo "    Iterations : ${L_YELLOW}${iterations}${DEF}"
echo "    ${L_GREEN}Min : ${min}${DEF}"
echo "    ${L_BLUE}Mid : ${mid}${DEF}"
echo "    ${L_RED}Max : ${max}${DEF}"



# TEST 3 (100 ELEMENTS)

iterations=100
min=0
max=0
mid=0
counter=0
checker="OK"

while [ $counter -lt $iterations ]; do
	ARG=$(seq -100 100 | shuf | head -n 100 | tr '\n' ' ')
	result="$(./push_swap ${ARG} | wc -l) "
	if [ $mid -eq 0 ]; then
		min=$result
		max=$result
	fi
	if [ $result -lt $min ]; then
		min=$result
	elif [ $result -gt $max ]; then
		max=$result
	fi
	if [ $(./push_swap ${ARG} | ./checker_linux ${ARG}) = "KO" ]; then
		checker="KO"
		echo "${CYAN}[Test 2.3] : ${RED}NOK${DEF} (iteration : $counter)"
		exit
	fi
	counter=$((counter + 1))
	mid=$((mid + result))
done

mid=$((mid / iterations))
checker=$(./push_swap ${ARG} | ./checker_linux ${ARG})

if [ $? -ne 0 ]; then
    echo "${CYAN}[Test 2.3] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 2.3] : ${GREEN}OK${DEF}"
fi
echo "    Argc : ${L_YELLOW}$(echo "${ARG}" | wc -w)${DEF}"
echo "    Checker : ${L_YELLOW}${checker}${DEF}"
echo "    Iterations : ${L_YELLOW}${iterations}${DEF}"
echo "    ${L_GREEN}Min : ${min}${DEF}"
echo "    ${L_BLUE}Mid : ${mid}${DEF}"
echo "    ${L_RED}Max : ${max}${DEF}"



# TEST 4 (500 ELEMENTS)

iterations=100
min=0
max=0
mid=0
counter=0
checker="OK"

while [ $counter -lt $iterations ]; do
	ARG=$(seq -500 500 | shuf | head -n 500 | tr '\n' ' ')
	result="$(./push_swap ${ARG} | wc -l) "
	if [ $mid -eq 0 ]; then
		min=$result
		max=$result
	fi
	if [ $result -lt $min ]; then
		min=$result
	elif [ $result -gt $max ]; then
		max=$result
	fi
	if [ $(./push_swap ${ARG} | ./checker_linux ${ARG}) = "KO" ]; then
		checker="KO"
		echo "${CYAN}[Test 2.4] : ${RED}NOK${DEF} (iteration : $counter)"
		exit
	fi
	mid=$((mid + result))
	counter=$((counter + 1))
done

mid=$((mid / iterations))
checker=$(./push_swap ${ARG} | ./checker_linux ${ARG})

if [ $? -ne 0 ]; then
    echo "${CYAN}[Test 2.4] : ${RED}NOK${DEF}"
else
	echo "${CYAN}[Test 2.4] : ${GREEN}OK${DEF}"
fi
echo "    Argc : ${L_YELLOW}$(echo "${ARG}" | wc -w)${DEF}"
echo "    Checker : ${L_YELLOW}${checker}${DEF}"
echo "    Iterations : ${L_YELLOW}${iterations}${DEF}"
echo "    ${L_GREEN}Min : ${min}${DEF}"
echo "    ${L_BLUE}Mid : ${mid}${DEF}"
echo "    ${L_RED}Max : ${max}${DEF}"