cmake_minimum_required(VERSION 3.16)
project(LinearCoherentGeneratorExperiment)

set(CMAKE_CXX_STANDARD 20)

add_executable(LinearCoherentGeneratorExperiment src/config.h src/experiment.cpp src/experiments.h src/generator.cpp src/generator.h
        src/num_threads.cpp src/num_threads.h main.cpp)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -fopenmp")