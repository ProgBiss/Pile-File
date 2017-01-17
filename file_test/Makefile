#######################################################################
# Script de compilation du programme de test de la librairie File
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

obj/Debug/main.o:main.c ../file/file.h ../liste_liee/liste_liee.h
	mkdir -p obj/Debug/
	gcc -Wall -g -I../file -I../liste_liee -c main.c -o $@

bin/Debug/file_test$(SUFIX):obj/Debug/main.o ../file/bin/Debug/libfile.a
	mkdir -p bin/Debug/
	gcc -o $@ $^ ../file/bin/Debug/libfile.so

obj/Release/main.o:main.c ../file/file.h ../liste_liee/liste_liee.h
	mkdir -p obj/Release/
	gcc -Wall -I../file -I../liste_liee -O2 -c main.c -o $@

bin/Release/file_test$(SUFIX):obj/Release/main.o ../file/bin/Release/libfile.a
	mkdir -p bin/Release/
	gcc -s -o $@ $^ ../file/bin/Release/libfile.so

debug: bin/Debug/file_test$(SUFIX)

release: bin/Release/file_test$(SUFIX)

clean:
	rm -rf obj
	rm -rf bin

.PHONY: all debug release clean