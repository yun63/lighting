#############################################################################
#
# Generic Makefile for C/C++ Program
#
# Author:  yun63<thewardsthe@mail.com>
#
#############################################################################

include define.mk


TINYXML_DIR := src/core/tinyxml
SAMPLE_DIR := sample

all: 
	cd $(SAMPLE_DIR) && $(MAKE)
	cd $(TINYXML_DIR) && $(MAKE)

#-------------------------------------
.PHONY: clean 
clean:
	cd $(TINYXML_DIR) && make clean
	cd $(SAMPLE_DIR) && make clean

#############################################################################
