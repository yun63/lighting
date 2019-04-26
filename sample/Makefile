#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################


include ../define.mk

BASE_DIR = ..

LIBS_PATH ?= $(BASE_DIR)/lib

## DEBUG开关选项
DEBUG := 1

## 头文件搜索路径 
INCPATHS = -I$(GTEST_DIR)/include -I$(BASE_DIR)/src#$(addprefix -I, $(HDRS)) 

## 库文件搜索路径及库
LIBS := $(addprefix -L, $(LIBPATHS)) -L$(LIBS_PATH) -lm -lpthread

## 源代码子目录
SRCDIRS := .

## 目标目录
SAMPLES_PATH := .

## GTest测试框架目录
GTEST_DIR := ../3rd/gtest-1.7.0
GTEST_HEADERS := $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h 
GTEST_SRCS_ := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

## 可执行目标程序
SAMPLES = list_sample stack_sample queue_sample \
		  sort_sample algo_sample

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2
endif

.SUFFIXES:

COMMON_SOURCES := \
	$(foreach e, $(addprefix *, $(SRCEXTS)), $(wildcard $(BASE_PATH)/$(e))) \
	$(foreach e, $(addprefix *, $(SRCEXTS)), $(wildcard $(CORE_PATH)/$(e)))

SAMPLES_TARGETS := $(foreach v, $(SAMPLES), $(SAMPLES_PATH)/$(v))

all: $(SAMPLES_TARGETS)

$(LIBS_PATH):
	@mkdir $(LIBS_PATH)

$(SAMPLES_PATH)/list_sample:
	@echo "-- Generating $@"
	$(CXX) -g -std=c++11 -Wall -I../src list.cpp -o $@

$(SAMPLES_PATH)/stack_sample: $(SRCDIRS)/stack.cpp
	@echo "-- Generating $@"
	$(CXX) $(CXXFLAGS) $(INCPATHS) -o $@ $^ $(LIBS)

$(SAMPLES_PATH)/queue_sample: $(SRCDIRS)/queue.cpp
	@echo "-- Generating $@"
	$(CXX) $(CXXFLAGS) $(INCPATHS) -o $@ $^ $(LIBS)

$(SAMPLES_PATH)/sort_sample: $(SRCDIRS)/sort.cpp
	@echo "-- Generating $@"
	$(CXX) $(CXXFLAGS) $(INCPATHS) -o $@ $^ $(LIBS)

$(SAMPLES_PATH)/algo_sample: $(SRCDIRS)/algo.cpp
	@echo "-- Generating $@"
	$(CXX) $(CXXFLAGS) $(INCPATHS) -o $@ $^ $(LIBS)

%.o: %.cpp
	@echo "-- Building $@"
	$(CXX) -g -std=c++11 $(INCPATHS) -c $< -o $@
%.o: %.cc
	@echo "-- Building $@"
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATHS) -c $< -o $@

%.o: %.cxx
	@echo "-- Building $@"
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) $(INCPATHS) -c $< -o $@

%.o: %.c
	@echo "-- Building $@"
	$(CC) $(CFLAGS) $(MYCFLAGS) $(INCPATHS) -c $< -o $@

#-------------------------------------
.PHONY: clean 
clean:
	@rm -f *.core *.o
	@rm -rf $(SAMPLES_PATH)/*.dSYM
	@rm -f $(SAMPLES_TARGETS)

#############################################################################
