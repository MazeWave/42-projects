!#bin/zsh

clear;
make re;
valgrind ./PmergeMe `shuf -i 0-19 -n 100 | tr "\n" " "`;
make fclean;