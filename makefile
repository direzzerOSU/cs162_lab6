
CXX = g++
CXXFLAGS = -std=c++0x
#CXXFLAGS += -Wall
#CXXFLAGS += -pedantic-errors
#CXXFLAGS += -g
#CXXFLAGS += -O3
#LDFLAGS = -lboost_date_time

OBJS = main.o menu.o inputValidation.o doubleLinkedList.o

SRCS = main.cpp menu.cpp inputValidation.cpp doubleLinkedList.cpp

HEADERS = menu.hpp inputValidation.hpp doubleLinkedList.hpp 

#target: dependencies
#	rule to build
#

doubleLinkedList: ${SRCS} ${HEADERS}	
	${CXX} ${CXXFLAGS} ${SRCS} -o doubleLinkedList

#${OBJS}: ${SRCS}
#	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)
