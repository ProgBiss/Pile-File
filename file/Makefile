#######################################################################
# Script de compilation de la librairie de file (file)
# Auteur: Nicolas Bisson
# Date: 2015-10-08
# License: MIT
# Tiré de: Louis Marchand
#######################################################################

all:debug release

obj/Debug/file.o:file.h file.c ../liste_liee/liste_liee.h
	mkdir -p obj/Debug/
	gcc -Wall -I../liste_liee -g -fpic -c file.c -o $@

bin/Debug/libfile.a:obj/Debug/file.o
	rm -f $@
	mkdir -p bin/Debug/
	ar -r -s $@ $^

bin/Debug/libfile.so:obj/Debug/file.o
	mkdir -p bin/Debug/
	gcc -L../liste_liee/bin/Debug/ -shared $^ -l liste_liee -o $@

obj/Release/file.o:file.h file.c 
	mkdir -p obj/Release/
	gcc -Wall -I../liste_liee -O2 -fpic -c file.c -o $@

bin/Release/libfile.a:obj/Release/file.o 
	rm -f $@
	mkdir -p bin/Release/
	ar -r -s $@ $^

bin/Release/libfile.so:obj/Release/file.o 
	mkdir -p bin/Release/
	gcc -L../liste_liee/bin/Release/ -shared $^ -l liste_liee -o $@

debug_static:bin/Debug/libfile.a

debug_dynamic:bin/Debug/libfile.so

debug:debug_static debug_dynamic

release_static:bin/Release/libfile.a

release_dynamic:bin/Release/libfile.so

release:release_static release_dynamic

static: debug_static release_static

dynamic: debug_dynamic release_dynamic

clean:
	rm -rf obj
	rm -rf bin

.PHONY: all debug_static debug_dynamic debug release_static release_dynamic release static dynamic clean