#######################################################################
# Script de compilation du programme de test de la librairie Liste Liée
# Auteur: Louis Marchand
# Date: 2015-07-30
# License: MIT
#######################################################################

UNAME=$(shell uname)

SUFIX=.exe
ifeq ($(UNAME), Linux)
SUFIX=
endif
ifeq ($(UNAME), Solaris)
SUFIX=
endif
ifeq ($(UNAME), Darwin)
SUFIX=
endif

all:debug release

obj/Debug/main.o:main.c ../liste_liee/liste_liee.h
	mkdir -p obj/Debug
	gcc -Wall -g -I../liste_liee -c main.c -o $@

bin/Debug/liste_liee_test$(SUFIX):obj/Debug/main.o ../liste_liee/bin/Debug/libliste_liee.a
	mkdir -p bin/Debug/
	gcc  -o $@ $^

obj/Release/main.o:main.c ../liste_liee/liste_liee.h
	mkdir -p obj/Release
	gcc -Wall -O2 -I../liste_liee  -c main.c -o $@

bin/Release/liste_liee_test$(SUFIX):obj/Release/main.o ../liste_liee/bin/Release/libliste_liee.a
	mkdir -p bin/Release/
	gcc -s -o $@ $^

debug: bin/Debug/liste_liee_test$(SUFIX)

release: bin/Release/liste_liee_test$(SUFIX)

clean:
	rm -rf obj
	rm -rf bin

.PHONY: all debug release clean
