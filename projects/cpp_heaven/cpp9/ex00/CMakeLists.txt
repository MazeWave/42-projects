cmake_minimum_required(VERSION 3.22)
project(btc VERSION 1.0 LANGUAGES CXX)

include_directories(include)
add_executable(btc main.cpp BitcoinExchange.cpp)