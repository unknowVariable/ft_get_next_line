# Projet get_next_line

## Description

Le projet get_next_line consiste en une fonction en langage C qui permet de lire une ligne depuis un descripteur de fichier donné (comme un fichier, un terminal, ou même une connexion réseau) et de la renvoyer à chaque appel de la fonction. L'objectif est de réaliser cette fonction de manière efficace, en utilisant un minimum de ressources, et en permettant une utilisation aisée dans d'autres programmes.

## Fonctionnalités

- Lecture de lignes depuis un descripteur de fichier
- Gestion des différents caractères de fin de ligne (newline)
- Possibilité de lire des fichiers de taille quelconque, ligne par ligne
- Gestion des cas particuliers comme les fichiers vides ou les fins de fichier

## Utilisation

Pour utiliser la fonction get_next_line dans votre programme, vous devez inclure le fichier header correspondant et compiler votre code avec la fonction get_next_line. Voici un exemple minimal d'utilisation :

```c
#include "get_next_line.h"

int main(int argc, char **argv)
{
    int fd;
    char *line;

    if (argc != 2)
    {
        printf("Usage: %s file\n", argv[0]);
        return 1;
    }

    // Ouvre le fichier en lecture seule
    fd = open(argv[1], O_RDONLY);
    // -1 en cas de probleme
    if (fd == -1)
    {
        perror("Error opening file");
        return 1;
    }
    // Recupere la ligne suivante a chaque appel
    while ((line = get_next_line(fd)) != NULL)
    {
        printf("%s\n", line);
        free(line);  
    }
    // Ferme de descripteur 
    close(fd); 
    return 0;
}

