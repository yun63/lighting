#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

ROOT=$(shell pwd)/../..

include $(ROOT)/define.mk

LIBS_PATH ?= $(ROOT)/lib

## DEBUG开关选项
DEBUG	:= 1

ifeq ($(DEBUG), 1)
	CXXFLAGS += -g
else
	CXXFLAGS += -O2
endif

.PHONY: clean 
.SUFFIXES:

TINYXML_OBJECTS := $(patsubst %.cpp, %.o, $(wildcard *.cpp))

all: $(LIBS_PATH)/libltxml.a $(LIBS_PATH)/libltxml.so

$(LIBS_PATH):
	mkdir $(LIBS_PATH)

$(LIBS_PATH)/libltxml.a: $(TINYXML_OBJECTS) | $(LIBS_PATH)
	$(AR) $(ARFLAGS) $@ $^
	$(RANLIB) $@

$(LIBS_PATH)/libltxml.so: $(TINYXML_OBJECTS) | $(LIBS_PATH)
	$(LINK) -fPIC --shared -I. $^ -o $@

%.o:%.cpp
	$(CXX) $(CFLAGS) $(MYCFLAGS) -I. -c $< -o $@

#-------------------------------------
clean:
	-rm $(LIBS_PATH)/libltxml.so $(LIBS_PATH)/libltxml.a
	-rm -f $(TINYXML_OBJECTS)

#############################################################################
