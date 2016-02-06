cmake_minimum_required(VERSION 2.8)
project(CentaurEngine)

include_directories(/home/sebastien/Downloads/naoqi-sdk-2.4.2.26-linux64/include)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        centaurtest.cpp
        Intelligence.cpp
        Include/Intelligence.h
        Decision.cpp
        Include/Decision.h
        Consideration.cpp
        Include/Consideration.h
        Context.cpp
        Include/Context.h
        External/tinyxml2.cpp
        External/tinyxml2.h
        IntelligenceLoader.cpp Include/IntelligenceLoader.h ModuleInterface.cpp Include/ModuleInterface.h Modules/DemoInputModule.cpp Modules/DemoInputModule.h Modules/DemoOutputModule.cpp Modules/DemoOutputModule.h)

add_executable(CentaurEngine ${SOURCE_FILES})