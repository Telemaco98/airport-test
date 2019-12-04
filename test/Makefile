# auxiliary variables
PROJECT_DIR=/mnt/c/Users/ohara/Documents/cpputest-airport
SRC_DIR=$(PROJECT_DIR)/src
TEST_DIR=$(PROJECT_DIR)/test
INC_DIR=$(PROJECT_DIR)/include

# variables defined as described in the MakeileWorker.mk
CPPUTEST_HOME=/mnt/c/Users/ohara/Documents/E/cpputest
INCLUDE_DIRS=$(INC_DIR) $(CPPUTEST_HOME)/include
SRC_DIRS=$(SRC_DIR)
TEST_SRC_DIRS = $(TEST_DIR) $(TEST_DIR)/tests
TEST_TARGET=out
CPPUTEST_USE_GCOV=Y

# run MakefileWorker.mk with the variables defined here
include $(CPPUTEST_HOME)/build/MakefileWorker.mk

# flags to memoryleak
CXXFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorNewMacros.h
CFLAGS += -include $(CPPUTEST_HOME)/include/CppUTest/MemoryLeakDetectorMallocMacros.h

# removes some compilation flags
CPPUTEST_WARNINGFLAGS:=$(filter-out -Werror,$(CPPUTEST_WARNINGFLAGS)) 

# adds some other warnings
CPPUTEST_WARNINGFLAGS+=-Wunused-result