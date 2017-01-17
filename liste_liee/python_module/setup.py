# coding=UTF-8

# =============================================================================
# titre           :setup.py
# description     :Script de compilation du module 'liste_liee_externe'
# author          :Louis Marchand
# date            :20150730
# version         :1.0
# usage           :python setup.py build
# notes           :
# license         :MIT
# python_version  :3.4.0
# =============================================================================

from distutils.core import setup, Extension

liste_liee_externe = Extension('liste_liee_externe',
                    include_dirs = ['../'],
                    libraries = ['liste_liee'],
                    library_dirs = ['../bin/Release/'],
                    sources = ['liste_liee_module.c'])

setup (name = 'liste_liee_externe',
       version = '1.0',
       description = "Liste implémenté à l'aide de structures liées",
       ext_modules = [liste_liee_externe])
