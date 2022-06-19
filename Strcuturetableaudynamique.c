#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX_JOUEUR 100

typedef struct joueur joueur;
struct joueur {
    char* pseudo[100];
    int* lvl;
};

int main() {

    joueur** p = NULL;
    int i = 0, nbrep = 0;

    printf("Combien de joueur?\n");
    scanf("%d", &nbrep);

    p = malloc(nbrep * sizeof(*p));

    if (p == NULL) {
        printf("Erreur d'allocation de memoire");
        exit(0);
    }

    for (i = 0; i < nbrep; i++) {

        p[i] = malloc(sizeof(**p) * 100);


        if (p[i] == NULL) {
            printf("Erreur d'allocation de mémoire");
            exit(0);
        }
        char pseudo[100] = { 0 };
        int *lvl = 0;

        printf("\nEcrivez le pseudo du joueur %d.\n", i);
        scanf("%s", pseudo);
        strcpy(p[i]->pseudo, pseudo);
        printf("Son niveau?\n");
        scanf("%d", &lvl);
        p[i]->lvl = lvl;
    }

    for (i = 0; i < nbrep; i++) { // Lecture du tableau

        printf("\nLe pseudo du joueur %d est %s et son niveau est %d.\n", i, p[i]->pseudo, p[i]->lvl);
    }


    for (i = 0; i < nbrep; i++) { // Libération des chaines de caractères et du tableau de pointeurs

        if (p[i]->pseudo != NULL)
            free(p[i]->pseudo);

    }

    free(p);
    return 0;
}