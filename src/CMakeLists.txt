cmake_minimum_required(VERSION 3.23)
project(SmartCalc)

set(CMAKE_CXX_STANDARD 17)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOUIC_SEARCH_PATHS sources/ui)

find_package(Qt6 REQUIRED COMPONENTS Core Widgets PrintSupport)

include_directories(include)

qt_add_executable(SmartCalc
        sources/CalcModel.cc
        include/CalcModel.h
        sources/main.cc
        sources/Controller.cc
        include/Controller.h
        sources/CalcView.cc
        include/CalcView.h
        sources/ui/calc.ui
        sources/GraphView.cc
        include/GraphView.h
        include/qcustomplot.h
        sources/qcustomplot.cpp)

target_link_libraries(SmartCalc PRIVATE Qt6::Core Qt6::Widgets Qt6::PrintSupport)