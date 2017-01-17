#######################################################################
# Script de compilation de la librairie de Liste Liée (liste_liee)
# Auteur: Louis Marchand
# Date: 2015-07-30
# License: MIT
#######################################################################

all:debug release

obj/Debug/liste_liee.o:liste_liee.h liste_liee.c
	mkdir -p obj/Debug
	gcc -Wall -g -fpic -c liste_liee.c -o $@

bin/Debug/libliste_liee.a:obj/Debug/liste_liee.o
	rm -f $@
	mkdir -p bin/Debug/
	ar -r -s $@ $^

bin/Debug/libliste_liee.so:obj/Debug/liste_liee.o
	mkdir -p bin/Debug/
	gcc -shared $^ -o $@

obj/Release/liste_liee.o:liste_liee.h liste_liee.c
	mkdir -p obj/Release
	gcc -O2 -Wall -fpic  -c liste_liee.c -o $@

bin/Release/libliste_liee.a:obj/Release/liste_liee.o
	rm -f $@
	mkdir -p bin/Release/
	ar -r -s $@ $^

bin/Release/libliste_liee.so:obj/Release/liste_liee.o
	mkdir -p bin/Release/
	gcc -shared $^ -o $@

debug_static:bin/Debug/libliste_liee.a

debug_dynamic:bin/Debug/libliste_liee.so

debug:debug_static debug_dynamic

release_static:bin/Release/libliste_liee.a

release_dynamic:bin/Release/libliste_liee.so

release:release_static release_dynamic

static: debug_static release_static

dynamic: debug_dynamic release_dynamic

clean:
	rm -rf obj
	rm -rf bin

.PHONY: all debug_static debug_dynamic debug release_static release_dynamic release static dynamic clean
