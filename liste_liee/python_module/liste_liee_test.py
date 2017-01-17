# coding=UTF-8

# =============================================================================
# titre           :liste_liee_test.py
# description     :Tests pour la classe Liste_liee
# author          :Louis Marchand
# date            :20150730
# version         :1.0
# usage           :python liste_liee_test.py
# notes           :
# license         :MIT
# python_version  :3.4.0
# =============================================================================

from liste_liee import Liste_liee

liste1 = Liste_liee()
liste1.ajouter(0)
liste1.ajouter(9)
liste1.ajouter(8)
liste1.inserer(0, 1)
liste1.inserer(2, 2)
liste1.retirer(3)
liste1.sauvegarder("test.bin");
liste2 = Liste_liee("test.bin");
try:
    liste2.remplacer(0, 3)
except Exception as message:
    print("Ne peut remplacer l'élément à l'index 3: " + str(message) + "\n")
try:
    liste2.remplacer(4, 3)
except Exception as message:
    print("Ne peut remplacer l'élément à l'index 4: " + str(message) + "\n")
for i in range(liste2.taille()):
    print("L'élément à l'index " + str(i) + " de la liste est " +
            str(liste2.element(i)) + "\n")

