#Documentation technique sur l'architecture de l'exiaSaver


###Le lanceur :

> "**./exiasaver**" : Cette commande sera à rentrer dans un terminal (raccourcis clavier ctrl+alt+t) pour pouvoir lancer l'application en arrière plan. 
> 
>Le mode veille ce lance automatiquement au bout de 15 secondes et fait apparaître un des trois termSaver disponible.
>
>Pour quitter le mode statique, vous aurez à appuyer sur une touche du clavier. Pour quitter le mode dynamique vous aurez à kill le processus avec la commande ctrl+c. Enfin, pour quitter le mode interactif, appuyez sur la lettre q.

###Les bibliothèques : 

> Nom de la bibliothèque | définitions qu'elle contient et qui sont utilisées dans le programme

> + **stdlib.h** | rand ; system() ; malloc() ; free() ; atoi() ; 
> > Cette bibliothèque renferme les routines Standard.
> 
> + **stdio.h** | fopen() ; printf() ; fgets() ; fgetc() ; rewind() ;
> > Cette bibliothèque renferme les routines de traitement d'entrée/sortie fichier. 
> 
> + **sys/types.h** | pid_t ; time_t  ; wait() ;
> > Cette bibliothèque renferme les définitions de temps pour Unix.
> 
> + **sys/wait.h** | wait() ;
> > Cette bibliothèque renferme les définitions d'attente.
> 
> + **unistd.h** | fork () ;
> > Cette bibliothèque renferme les types et les constantes symbole standard.
> 
> + **string.h** | strcmp () ; strtok () ; strcpy() ;
> > Cette bibliothèque renferme les routines de traitement de chaîne de caractères.
> 
###Définitions :

>**rand** : (int) cette fonction retourne un nombre pseudo aléatoire entier
>
>**system()** : int system(const char *commande) --> le paramètre commande permet d'indiquer la commande à faire exécuter par le système d'exploitation. Cette fonction permet de lancée un commande dans le système d'exploitation.
>
>**malloc()** : Cette fonction effectue une allocation de mémoire dynamique
>
>**free()** : Cette procédure permet de libérer un bloc de mémoire.
>
>**fopen()** : Cette fonction effectue l'ouverture d'un fichier.
>
>**printf()** : Cette fonction effectue l'écriture de texte sur la console.
>
>**fgets()** : Cette fonction effectue la lecture d'une chaîne de caractères dans un fichier.
>
>**fgetc()** : Cette fonction effectue la lecture d'un caractère dans un fichier.
>
>**fork()** : Appel système standard ; cette fonction permet à un processus de donner naissance à un nouveau processus qui est sa copie conforme.
>
>**strcmp()** : Cette fonction effectue la comparaison de deux chaines de caractères.
>
>**strtok()** : Cette fonction permet de couper la chaine de caractères «str1» en token en les séparant par les caractères de la chaine de caractères «str2».
>
>**strcpy()** : Cette fonction effectue la copie d'une chaine de caractères dans une autre chaine de caractères.
>
>**wait()** : L'appel système wait() suspend l'exécution du processus appelant jusqu'à ce que l'un de ses fils se termine.
>
>**pid_t** : Lors de l'utilisation de la fonction fork, la valeur retourné est de type pid_t (c'est un int)
>
>**rewind()** : Cette fonction permet de replacer le curseur au début du fichier. (Ici, permet de ce remettre à la colonne 0 de la ligne 0, au tout début du tableau qui contient l'image)  
> 
> **atoi()** : Convertie une chaîne de caractère en une valeur entière (char en int)


### Executables : 

>**Ce programme est composé de 4 exécutables** : 
> 
	> Le premier exécutable est le lanceur. Il servira à lancer les autres exécutables qui sont termSaver1, termSaver2 et termSaver 3.

> **termSaver1** : Cet exécutable est lancé si le lanceur à généré le nombre aléatoire 1. Il exécutera ensuite les différente fonction comprise à l'intérieur de celui-ci, comme la génération de nombre aléatoire, l'écriture dans l'historique (heure, date, numéro de l'image choisie), la récupération d'un contenu de fichier, la conversion en caractère ASCII des 0 et des 1,  le centrage et l'affichage d'une image
>  
>  **termSaver2** : Cet exécutable est lancé si le lanceur à généré le nombre aléatoire 2. Les fonctions utilisés dans ce termSaver sont la lecture de l'heure, la récupération des fichiers image en fonction de l'heure, la lecture de fichier un par un, l'affichage des fichiers images, la mise à jour des images affiché correspondant à l'heure.
>   
>   **termSaver3** : En cours de développement



