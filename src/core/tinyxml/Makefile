#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

BASE_DIR=$(shell pwd)/../../..

include $(BASE_DIR)/define.mk

LIBS_PATH ?= $(BASE_DIR)/lib

## 头文件搜索路径 
INCPATHS = -I$(BASE_DIR)/src/core/tinyxml#$(addprefix -I, $(HDRS)) 

## 库文件搜索路径及库
LIBS := $(addprefix -L, $(LIBPATHS)) -L$(LIBS_PATH)# -lpthread

## DEBUG开关选项
DEBUG	:= 1

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2
endif

TINYXML_OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(LIBS_PATH)/libltxml.a $(LIBS_PATH)/libltxml.so

$(LIBS_PATH):
	@mkdir $(LIBS_PATH)

$(LIBS_PATH)/libltxml.a: $(TINYXML_OBJECTS) | $(LIBS_PATH)
	@echo "-- Linking static library $@"
	@$(AR) $(ARFLAGS) $@ $(filter %.o, $^) $^
	@$(RANLIB) $@

$(LIBS_PATH)/libltxml.so: $(TINYXML_OBJECTS) | $(LIBS_PATH)
	@echo "-- Linking shared library $@"
	@$(LINK) -fPIC --shared $(filter %.o, $^) -o $@ $(INCPATHS) $(LIBS)

%.o:%.cpp
	@echo "-- Building $@"
	@$(CXX) -c $(CFLAGS) $(MYCFLAGS) $< -o $@ $(INCPATHS) 

#-------------------------------------
.PHONY: clean 
clean:
	@rm -f *.o
	@rm -f $(LIBS_PATH)/libltxml.so $(LIBS_PATH)/libltxml.a
	@rm -f $(TINYXML_OBJECTS)

#############################################################################
