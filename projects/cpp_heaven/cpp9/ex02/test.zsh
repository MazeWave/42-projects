!#bin/zsh

clear;
make re;
valgrind ./PmergeMe `shuf -i 0-10 -n 100 | tr "\n" " "`;
make fclean;