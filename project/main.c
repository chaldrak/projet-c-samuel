#include <stdio.h>
#include <stdlib.h>
#include "function.h"

//declaration des fonctions


int main()
{
    //choix des variables
    int choix, effectif, nombreMatiere;
    char nomFiliere[20];
    float average = 0;

    Filiere filiere;

    printf("\nnom de la filiere : ");
    scanf("%s", &nomFiliere);

    printf("\nnombre d'etudiants de la filiere : ");
    scanf("%d", &effectif);

    printf("\nnombre de matieres de la filiere : ");
    scanf("%d", &nombreMatiere);

    filiere = (Filiere)malloc(effectif * sizeof(struct Etudiant));

    for(int i = 0; i < effectif; i++) {
        printf("\nSaisie de l'etudiant numero %d\n", i+1);
        printf("Entrer le nom : ");
        scanf("%s", &filiere[i].nom);
        printf("Entrer le prenom : ");
        scanf("%s", &filiere[i].prenom);
        printf("Entrer le sexe : ");
        scanf("%s", &filiere[i].sexe);
        printf("Entrer l'age de l'etudiant: ");
        scanf("%d", &filiere[i].age);

        float *notes;
        notes = (float*)malloc(nombreMatiere * sizeof(float));

        for(int j = 0; j < nombreMatiere; j++) {
            printf("Entrer la note_%d: ", j+1);
            scanf("%f", &notes[j]);
        }

        filiere[i].notes = notes;

    }

    printf("\n+----------------------------------------------------------------------+\n");
    printf("Filiere = %s\n", nomFiliere);
    printf("Effectif = %d\n", effectif);
    printf("Nombre de matieres = %d\n", nombreMatiere);
    printf("\n");

    //Calcul de moyennes
    for(int i = 0; i < effectif; i++) {
        average = 0;
        for(int j = 0; j < nombreMatiere; j++) {
            average += *((filiere[i].notes)+j);
        }
        filiere[i].moyenne = average / nombreMatiere;
    }

    //menu principal
    do {
        choix = afficherMenu();

        switch(choix) {
            case 1: printf("\v--------------MOYENNE DE CHAQUE ETUDIANT-------------\n");
                    for(int i = 0; i < effectif; i++) {
                        printf("%s %s ------> %f\n", filiere[i].nom, filiere[i].prenom, filiere[i].moyenne);
                    };
                    break;
            case 2: printf("\v-------MOYENNE DE CHAQUE ETUDIANT PAR ORDRE D'EXCELLENCE------\n");
                    struct Etudiant temp;
                    Filiere newFiliere;
                    newFiliere = (Filiere)malloc(effectif * sizeof(struct Etudiant));
                    newFiliere = filiere;
                    for(int i = 0; i < effectif; i++) {
                        for(int j = 1; j < effectif; j++) {
                            if(newFiliere[i].moyenne < newFiliere[j].moyenne) {
                                temp = newFiliere[i];
                                newFiliere[i] = newFiliere[j];
                                newFiliere[j] = temp;
                            }
                        };
                    };
                    for(int i = 0; i < effectif; i++) {
                        printf("%s %s ------> %f\n", newFiliere[i].nom, newFiliere[i].prenom, newFiliere[i].moyenne);
                    };
                    free(newFiliere);
                    break;
            case 3: printf("\v--------------MOYENNE DE LA SALLE-------------\n");
                    float moyenneDeLaSalle = 0;
                    for(int i = 0; i < effectif; i++) {
                        moyenneDeLaSalle += filiere[i].moyenne;
                    };
                    printf("moyenne ------> %f\n", moyenneDeLaSalle / effectif );
                    break;
            case 4: printf("2");
                    break;
            case 5: printf("2");
                    break;
            case 0: printf("Au revoir !!!\n"); exit(1);
                    break;
            default: printf("Saisie erronee, veuillez reessayer\n");
                     break;
        };

    } while(choix != 0);


    free(filiere);

    return 0;
}
