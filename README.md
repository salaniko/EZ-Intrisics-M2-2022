# EZ-Intrisics-M2-2022

----------------------

## Présentation

Les Intrinsics sont des instructions, des fonctions disponibles dans un langage de programmation et son implémentation
est gérée par le compilateur. Ces instructions sont utilisées pour faire de la vectorisation ou de la parralélisation, 
pour les langages qui n'ont pas cette gestion déjà intégrée. 

Ici dans notre cas, ce sont des fonctions qui seront remplacées par des instructions vectorielles lors de la génération 
du code par le compilateur. Par défaut les instructions proposées par les librairies de Intel sont difficiles à utiliser,
car leur format et les nommage des fonctions, des types, ne sont pas précis. Et aucun outil ne permet de faire un
affichage simple des différents registres.

L'objectif de se projet est donc de simplifier les appels à ces fonctions qui permettent d'optimiser des calculs
vectoriels en assembleur. Il faut également développer une interface permettant d'afficher les registres SSE et qui 
affiche en console selon différents formats les informations qu'ils contiennent. 

## Installation

Pas de librairies particulières a installer 

## Générations de la bibliothèque C++

Dans un terminal, a la racine du projet, tapez : 

```shell
make
```

Ensuite pour lancer le programme il suffit de taper la commande suivante au même endroit :

```shell
./bin/main.exe
```