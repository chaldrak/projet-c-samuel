//structures de donnees

struct Etudiant {
    char nom[20];
    char prenom[20];
    char sexe;
    int age;
    float *notes;
    float moyenne;
};

typedef struct Etudiant *Filiere;

//declaration de fonctions
int aficherMenu();

//definition de fonctions
int afficherMenu() {
    int choix;

    printf("+-------------------------------- MENU --------------------------------+\n\n");
    printf("  1: Afficher les moyennes de chaque etudiant \n");
    printf("  2: Afficher les moyennes de chaque etudiant par ordre d'excellence\n");
    printf("  3: Afficher la moyenne de la salle \n");
    printf("  4: Afficher les moyennes des trois meilleurs etudiants \n");
    printf("  5: Afficher l'etudiant ayant la meilleure moyenne \n");
    printf("  0: Sortir \n\n");
    printf("+----------------------------------------------------------------------+\n\n");

    printf("Faites un choix entre 0 et 5 : ");
    scanf("%d", &choix);

    return choix;
};
