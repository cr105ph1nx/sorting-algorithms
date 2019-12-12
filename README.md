# sorting-algorithms-dynamic-structs

## Problématique
Un grand nombre de problèmes réels ont recours à la recherche d’éléments dans un vecteur ou
toute autre structure de données. Cette recherche devient quasiment lourde lorsqu’elle s’effectue
dans une structure volumineuse (plusieurs milliers d’éléments) et désordonnée, d’où le besoin de
trier ces structures afin de faciliter la recherche. Dans ce travail, il s’agit d’implémenter quelques
méthodes de tri de vecteurs (par sélection, par bulle, par insertion décrites ci-dessous). Et de les
généraliser par la suite, aux matrices et aux listes chainées.

## Description des méthodes
**1. Tri par sélection :**
cette technique consiste à parcourir séquentiellement le vecteur à trier. A
l'itération i, la plus petite valeur (respectivement la plus grande s’il s’agit d’un tri dans l’ordre
décroissant) du tableau est inter-changée avec la valeur située dans la case d'indice i. Au bout
d’une itération, un élément du vecteur est bien placé ( i.e, il est à sa bonne position).
**2. Tri par bulle :** 
les petits éléments (respectivement les plus grands) du tableau « remontent »
(comme des bulles) vers le début du tableau pour atteindre leur position finale. Une fois tous les
éléments remontés, le tableau est trié. Cette technique se fait par permutations success ives
d’éléments consécutifs t[i] et t[i+1] après les avoir comparé.
**3. Tri par insertion : **
cette technique consiste à considérer à chaque étape, un élément t[i] du
vecteur et à chercher sa position d’insertion, en décalant les autres éléments de façon à « libérer »
la position d’insertion de l’élément. À chaque étape, une partie du tableau est déjà ordonnée et une
nouvelle valeur est insérée à l'endroit approprié.

# Partie I
Implémentation des trois méthodes de tri su-décrites pour un vecteur d’entiers de taille n<=1000.

# Partie II
Généraliser ces méthodes au tri de matrices, le programme repond aux questions suivantes :
Trier une matrice d’entiers , ligne par ligne, indépenda mment les unes des autres (chaque
ligne sera triée à part).
1. Trier tous les éléments d’une matrice d’entiers.
2. trier cette matrice de caractères où chaque ligne représente une chaîne de caractères dans l’ordre alphabétique des mots (un mot par ligne.

## Partie III
Implementation d'un autre algorithme de tri.

## Partie IV
Aapter deux methodes de tries au tri d’une liste chainée (structure dynamique) de
mots (chaines de caractères).

## De plus
1. Chaque programme (ou algorithme) de tri affiche l’état du vecteur (matrice ou liste)
après chaque itération afin de voir la progression du tri.
2. Chaque programme de tri (ou algorithme) affiche à la fin le nombre de comparaisons
effectuées (nbComp) et le nombre de permutations effectuées (nbPerm). Ces deux
nombres sont calculés dans chaque algorithme et varient d’une exécution à l’autre.
