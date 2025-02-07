!#bin/zsh

clear;
make re;
valgrind ./PmergeMe `shuf -i 0-30000 -n 30000 | tr "\n" " "` > logs.txt;

make fclean;