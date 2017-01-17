 #######################################################################
# Script de compilation de la librairie de Pile (pile)
# Auteur: Nicolas Bisson
# Date: 2015-10-08
# License: MIT
# Tiré de: Louis Marchand
#######################################################################

all:debug release

obj/Debug/pile.o:pile.h pile.c ../liste_liee/liste_liee.h
	mkdir -p obj/Debug/
	gcc -Wall -I../liste_liee -g -fpic -c pile.c -o $@

bin/Debug/libpile.a:obj/Debug/pile.o
	rm -f $@
	mkdir -p bin/Debug/
	ar -r -s $@ $^

bin/Debug/libpile.so:obj/Debug/pile.o
	mkdir -p bin/Debug/
	gcc -L../liste_liee/bin/Debug/ -shared $^ -l liste_liee -o $@

obj/Release/pile.o:pile.h pile.c 
	mkdir -p obj/Release/
	gcc -Wall -I../liste_liee -O2 -fpic -c pile.c -o $@

bin/Release/libpile.a:obj/Release/pile.o 
	rm -f $@
	mkdir -p bin/Release/
	ar -r -s $@ $^

bin/Release/libpile.so:obj/Release/pile.o 
	mkdir -p bin/Release/
	gcc -L../liste_liee/bin/Release/ -shared $^ -l liste_liee -o $@

debug_static:bin/Debug/libpile.a

debug_dynamic:bin/Debug/libpile.so

debug:debug_static debug_dynamic

release_static:bin/Release/libpile.a

release_dynamic:bin/Release/libpile.so

release:release_static release_dynamic

static: debug_static release_static

dynamic: debug_dynamic release_dynamic

clean:
	rm -rf obj
	rm -rf bin

.PHONY: all debug_static debug_dynamic debug release_static release_dynamic release static dynamic clean