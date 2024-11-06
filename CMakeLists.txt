
# CMakeLists.txt

cmake_minimum_required(VERSION 3.10)
project(TextBookSimilarity)

set(CMAKE_CXX_STANDARD 17)

add_executable(TextBookSimilarity main.cpp TextProcessor.cpp SimilarityCalculator.cpp)
