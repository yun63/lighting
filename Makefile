#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

include define.mk

ROOT=$(shell pwd)

BASE_PATH ?= $(ROOT)/base
CORE_PATH ?= $(ROOT)/core

LIBS_PATH ?= $(ROOT)/lib

## DEBUG开关选项
DEBUG	:= 1

## 头文件搜索路径 
INCPATH ?= -I$(GTEST_DIR)/include -I$(BASE_PATH) -I$(CORE_PATH)

## 源代码子目录
SRCDIRS := sample

## 目标目录
SAMPLES_PATH := sample

## GTest测试框架目录
GTEST_DIR := ../3rd/gtest-1.7.0
GTEST_HEADERS := $(GTEST_DIR)/include/gtest/*.h \
				$(GTEST_DIR)/include/gtest/internal/*.h 
GTEST_SRCS_ := $(GTEST_DIR)/src/*.cc $(GTEST_DIR)/src/*.h $(GTEST_HEADERS)

## 可执行目标程序
SAMPLES = list_sample stack_sample queue_sample \
		  sort_sample algo_sample

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

COMMON_SOURCES := \
	$(foreach e, $(addprefix *, $(SRCEXTS)), $(wildcard $(BASE_PATH)/$(e))) \
	$(foreach e, $(addprefix *, $(SRCEXTS)), $(wildcard $(CORE_PATH)/$(e)))

TINYXML_OBJECTS := $(patsubst %.cpp, %.o, $(wildcard $(CORE_PATH)/tinyxml/*.cpp))

SAMPLES_TARGETS := $(foreach v, $(SAMPLES), $(SAMPLES_PATH)/$(v))

all: \
	$(LIBS_PATH)/libltxml.a \
	$(LIBS_PATH)/libltxml.so \
	$(SAMPLES_TARGETS)


$(LIBS_PATH):
	mkdir $(LIBS_PATH)

$(LIBS_PATH)/libltxml.a: $(TINYXML_OBJECTS) | $(LIBS_PATH)
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@

$(LIBS_PATH)/libltxml.so: $(TINYXML_OBJECTS) | $(LIBS_PATH)
	$(LINK) -fPIC --shared -I$(CORE_PATH)/tinyxml $^ -o $@

$(SAMPLES_PATH)/list_sample: $(SRCDIRS)/list.cpp
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) -I$(BASE_PATH) $^ -o $@

$(SAMPLES_PATH)/stack_sample: $(SRCDIRS)/stack.cpp
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) -I$(BASE_PATH) $^ -o $@

$(SAMPLES_PATH)/queue_sample: $(SRCDIRS)/queue.cpp
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) -I$(BASE_PATH) $^ -o $@

$(SAMPLES_PATH)/sort_sample: $(SRCDIRS)/sort.cpp
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) -I$(BASE_PATH) $^ -o $@

$(SAMPLES_PATH)/algo_sample: $(SRCDIRS)/algo.cpp
	$(CXX) $(CXXFLAGS) $(MYCFLAGS) -I$(BASE_PATH) $^ -o $@

%.o:%.cpp
	$(CXX) $(CFLAGS) $(MYCFLAGS) $(INCPATH) -c $< -o $@

#-------------------------------------
clean:
	-rm -f *.core
	-rm -rf $(SAMPLES_PATH)/*.dSYM
	-rm -rf $(LIBS_PATH)
	-rm -f $(TINYXML_OBJECTS)
	-rm -f $(SAMPLES_TARGETS)

#############################################################################
