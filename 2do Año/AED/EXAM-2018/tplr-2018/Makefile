# -*- mode: makefile -*-
## GITVERSION: tpl-recup-2018-11-22-7-gc4b22c4a
CPP := util_btree.cpp,util.cpp,util_tree.cpp
HPP := eval.hpp util.hpp util_tree.hpp tree.hpp util_btree.hpp 
SRCS := $(CPP) $(HPP)
.PHONY: force
program.bin: force
	g++ -I. -std=gnu++11 -g3 -O0 -o $@ program.cpp aedtools/{$(CPP)}

check:
	$(MAKE) program.bin
	./program.bin
