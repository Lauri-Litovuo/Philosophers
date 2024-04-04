# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    error_check.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: llitovuo <llitovuo@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/03 15:26:00 by llitovuo          #+#    #+#              #
#    Updated: 2024/04/04 14:08:32 by llitovuo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

R="\033[0;31m" # Red
G="\033[0;32m" # Green
Y="\033[0;33m" # yellow
B="\033[0;34m" # Blue
P="\033[0;35m" # Purple
C="\033[0;36m" # Cyan

RB="\033[1;31m" # Bold
GB="\033[1;32m"
YB="\033[1;33m"
BB="\033[1;34m"
PB="\033[1;35m"
CB="\033[1;36m"

RC="\033[0m" # Reset Color
FLL="**************"

!#bin/bash

input_errors()
{
	printf "${GB}Testing:${RC} ./philo $1 $2 $3 $4 $5\n"
	#cat $1
	#printf "\n\n"
	printf "${BB}Output: ${RC}"
	./philo "$1" "$2" "$3" "$4" "$5"
	printf "${RC}${RB}Exit Code: ${RC}$?\n"
	#leaks --atExit -- ./philo "$1"
	#sleep 1	
	printf "================================\n\n"
}

a1="-123"
a2="0"
a3="1"
a4="\t"
a5="2147483648"
a6="-2147483647"
a7="-2147483648"
a8="asdg"
a9="\0	!@#&SF*)"
aok="5"
empty=""


printf "\n${P}${FLL}****************${P}${FLL}${RC}\n"
printf "${P}${FLL}${RC}${RB}Philo errors${P}${FLL}${RC}\n"
printf "${P}${FLL}****************${P}${FLL}${RC}\n\n"

./philo
./philo 5
./philo 5 5
./philo 5 5 5
./philo 5 5 5 5
./philo 5 5 5 5 5 5 5

input_errors ${a1} ${aok} ${aok} ${aok} ${aok}
input_errors ${a2} ${aok} ${aok} ${aok} ${aok}
input_errors ${a3} ${aok} ${aok} ${aok} ${aok}
input_errors ${a4} ${aok} ${aok} ${aok} ${aok}
input_errors ${a5} ${aok} ${aok} ${aok} ${aok}
input_errors ${a6} ${aok} ${aok} ${aok} ${aok}
input_errors ${a7} ${aok} ${aok} ${aok} ${aok}
input_errors ${a8} ${aok} ${aok} ${aok} ${aok}
input_errors ${a9} ${aok} ${aok} ${aok} ${aok}

input_errors ${aok} ${a1} ${aok} ${aok} ${aok}
input_errors ${aok} ${a2} ${aok} ${aok} ${aok}
input_errors ${aok} ${a3} ${aok} ${aok} ${aok}
input_errors ${aok} ${a4} ${aok} ${aok} ${aok}
input_errors ${aok} ${a5} ${aok} ${aok} ${aok}
input_errors ${aok} ${a6} ${aok} ${aok} ${aok}
input_errors ${aok} ${a7} ${aok} ${aok} ${aok}
input_errors ${aok} ${a8} ${aok} ${aok} ${aok}
input_errors ${aok} ${a9} ${aok} ${aok} ${aok}
input_errors ${aok} ${a1} ${aok} ${aok} ${aok}

input_errors ${aok} ${aok} ${a1} ${aok} ${aok}
input_errors ${aok} ${aok} ${a2} ${aok} ${aok}
input_errors ${aok} ${aok} ${a3} ${aok} ${aok}
input_errors ${aok} ${aok} ${a4} ${aok} ${aok}
input_errors ${aok} ${aok} ${a5} ${aok} ${aok}
input_errors ${aok} ${aok} ${a6} ${aok} ${aok}
input_errors ${aok} ${aok} ${a7} ${aok} ${aok}
input_errors ${aok} ${aok} ${a8} ${aok} ${aok}
input_errors ${aok} ${aok} ${a9} ${aok} ${aok}

input_errors ${aok} ${aok} ${aok} ${a1} ${aok}
input_errors ${aok} ${aok} ${aok} ${a2} ${aok}
input_errors ${aok} ${aok} ${aok} ${a3} ${aok}
input_errors ${aok} ${aok} ${aok} ${a4} ${aok}
input_errors ${aok} ${aok} ${aok} ${a5} ${aok}
input_errors ${aok} ${aok} ${aok} ${a6} ${aok}
input_errors ${aok} ${aok} ${aok} ${a7} ${aok}
input_errors ${aok} ${aok} ${aok} ${a8} ${aok}
input_errors ${aok} ${aok} ${aok} ${a9} ${aok}

input_errors ${aok} ${aok} ${aok} ${aok} ${a1}
input_errors ${aok} ${aok} ${aok} ${aok} ${a2}
input_errors ${aok} ${aok} ${aok} ${aok} ${a3}
input_errors ${aok} ${aok} ${aok} ${aok} ${a4}
input_errors ${aok} ${aok} ${aok} ${aok} ${a5}
input_errors ${aok} ${aok} ${aok} ${aok} ${a6}
input_errors ${aok} ${aok} ${aok} ${aok} ${a7}
input_errors ${aok} ${aok} ${aok} ${aok} ${a8}
input_errors ${aok} ${aok} ${aok} ${aok} ${a9}