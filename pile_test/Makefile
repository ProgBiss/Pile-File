#######################################################################
# Script de compilation du programme de test de la librairie Pile
# Auteur: Nicolas Bisson
# Date: 2015-10-08
# License: MIT
# Tiré de: Louis Marchand
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

obj/Debug/main.o:main.c ../pile/pile.h ../liste_liee/liste_liee.h
	mkdir -p obj/Debug/
	gcc -Wall -g -I../pile -I../liste_liee -c main.c -o $@

bin/Debug/pile_test$(SUFIX):obj/Debug/main.o ../pile/bin/Debug/libpile.a
	mkdir -p bin/Debug/
	gcc -o $@ $^ ../pile/bin/Release/libpile.so

obj/Release/main.o:main.c ../pile/pile.h ../liste_liee/liste_liee.h
	mkdir -p obj/Release/
	gcc -Wall -I../pile -I../liste_liee -O2 -c main.c -o $@

bin/Release/pile_test$(SUFIX):obj/Release/main.o ../pile/bin/Release/libpile.a
	mkdir -p bin/Release/
	gcc -s -o $@ $^ ../pile/bin/Release/libpile.so

debug: bin/Debug/pile_test$(SUFIX)

release: bin/Release/pile_test$(SUFIX)

clean:
	rm -rf obj
	rm -rf bin

.PHONY: all debug release clean
