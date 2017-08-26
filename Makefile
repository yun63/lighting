#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

include define.mk

ROOT=$(shell pwd)

BASE_DIR=$(ROOT)/base

## DEBUG开关选项
DEBUG	:= 1

## 头文件搜索路径 
INCPATH ?= -I. -I$(GTEST_DIR)/include -I$(BASE_DIR)

## 源代码子目录
SRCDIRS := sample

## GTest测试框架目录
GTEST_DIR := ../3rd/gtest-1.7.0
GTEST_HEADERS := $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h 
GTEST_SRCS_ := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

## 可执行目标程序
TARGETS = list_sample stack_sample queue_sample \
		  sort_sample algo_sample algo_sample

CPPFLAGS += -isystem $(GTEST_DIR)/include

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2
endif

## 库文件
LIBS = -lm

.PHONY: clean 
.SUFFIXES:

all: $(TARGETS)

list_sample: $(SRCDIRS)/list.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

stack_sample: $(SRCDIRS)/stack.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

queue_sample: $(SRCDIRS)/queue.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

sort_sample: $(SRCDIRS)/sort.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

algo_sample: $(SRCDIRS)/algo.cpp
	$(CXX) -o $@ $^ $(CXXFLAGS) $(MYCFLAGS) $(INCPATH)

#-------------------------------------
clean:
	-rm -f *~ core *.core
	-rm -f $(TARGETS)
	-rm -rf *.dSYM

#############################################################################
