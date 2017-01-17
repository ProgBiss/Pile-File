# coding=UTF-8

# =============================================================================
# titre           :liste_liee_externe_test.py
# description     :Tests pour le module liste_liee_externe
# author          :Louis Marchand
# date            :20150730
# version         :1.0
# usage           :python liste_liee_externe_test.py
# notes           :
# license         :MIT
# python_version  :3.4.0
# =============================================================================

import liste_liee_externe

liste1 = liste_liee_externe.creer()
liste_liee_externe.ajouter(liste1, 0)
liste_liee_externe.ajouter(liste1, 9)
liste_liee_externe.ajouter(liste1, 8)
liste_liee_externe.inserer(liste1, 0, 1)
liste_liee_externe.inserer(liste1, 2, 2)
liste_liee_externe.retirer(liste1, 3)
liste_liee_externe.sauvegarder(liste1, "test.bin");
liste_liee_externe.detruire(liste1)
liste2 = liste_liee_externe.charger("test.bin");
try:
    liste_liee_externe.remplacer(liste2, 0, 3)
except Exception as message:
    print("Ne peut remplacer l'élément à l'index 3: " + str(message) + "\n")
try:
    liste_liee_externe.remplacer(liste2, 4, 3)
except Exception as message:
    print("Ne peut remplacer l'élément à l'index 4: " + str(message) + "\n")
for i in range(liste_liee_externe.taille(liste2)):
    print("L'élément à l'index " + str(i) + " de la liste est " +
            str(liste_liee_externe.element(liste2, i)) + "\n")
liste_liee_externe.detruire(liste2)

