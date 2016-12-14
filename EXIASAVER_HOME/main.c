#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h> // (Fork)

#include "random.h"
#include "termSaver1.h"
#include "termSaver2.h"
#include "termSaver3.h"
#include "history.h" //

//#define TAILLE_MAX 1000
// #include "history_ecriture.h"

int main(int argc, char *argv[])
{
    // while (1){
    pid_t pid = 0;
    int nbgen = 0;

    if (argc != 1 && strcmp(argv[1], "-stats") == 0)
    {
        history();
    }
    else if (argc != 1 && strcmp(argv[1], "-stats") != 0)
    {
        printf("no valid arguments\n");
    }
    else if( argc == 1)
    {
        nbgen = alea(1, 3);
    }
    
    history(); //
    return 0;
    system("clear");
    
    if (nbgen == 1)
    {
        pid=fork();
        system("clear");
        if (pid == 0)
        {
            termSaver1();
        }
        else
        {
                    //Détection touche entrée
        }
    }
    else if (nbgen == 2)
    {
        pid=fork();
        system("clear");
        if (pid == 0)
        {
            termSaver2();
        }
        else
        {
            wait(NULL);
        }
        }
        else
        {
            pid=fork();
            system("clear");
                if (pid == 0)
                {
                    termSaver3();
                }
                else
                {
                    wait(NULL);
                }
        }
    //}
}
