# Makefile for TASKY DSL Compiler

CXX = g++
CXXFLAGS = -std=c++17 -Wall -g
FLEX = flex
BISON = bison
LLVM_CONFIG = llvm-config

# Check if llvm-config is available
LLVM_AVAILABLE := $(shell which $(LLVM_CONFIG) 2>/dev/null)

ifeq ($(LLVM_AVAILABLE),)
  # LLVM not available, build without it
  $(warning LLVM not found, building without LLVM backend support)
  LLVM_FLAGS =
  LLVM_LIBS =
  LLVM_SOURCES =
  LLVM_OBJS =
else
  # LLVM available, build with it
  LLVM_FLAGS = $(shell $(LLVM_CONFIG) --cxxflags) -DUSE_LLVM
  LLVM_LIBS = $(shell $(LLVM_CONFIG) --ldflags --libs core support)
  LLVM_SOURCES = tasky_codegen.cpp
  LLVM_OBJS = tasky_codegen.o
endif

all: tasky

# Use direct compilation instead of relying on implicit rules
tasky: main.o lex.yy.o tasky.tab.o tasky_runtime.o $(LLVM_OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LLVM_LIBS) -lfl

tasky_runtime.o: tasky_runtime.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

tasky.tab.c tasky.tab.h: tasky.y
	$(BISON) -d $<

lex.yy.c: tasky.l tasky.tab.h
	$(FLEX) $<

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

tasky.tab.o: tasky.tab.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

lex.yy.o: lex.yy.c
	$(CXX) $(CXXFLAGS) -c $< -o $@

tasky_codegen.o: tasky_codegen.cpp
	$(CXX) $(CXXFLAGS) $(LLVM_FLAGS) -c $< -o $@

clean:
	rm -f tasky lex.yy.c tasky.tab.c tasky.tab.h *.o

install: tasky
	install -m 755 tasky /usr/local/bin

.PHONY: all clean install
