#include <stdio.h>

void menu(){
    printf("**************************************************************\n");
    printf("***----------------------- OneHand ------------------------***\n");
    printf("**************************************************************\n");
    printf("***----------- 1: Ajouter une Tache            ------------***\n");
    printf("***----------- 2: Afficher la Liste des Taches ------------***\n");
    printf("***----------- 3: Modifier une Tache           ------------***\n");
    printf("***----------- 4: Supprimer une Tache          ------------***\n");
    printf("***----------- 5: Ordonner les Taches          ------------***\n");
    printf("***----------- 6: Filtrer les Taches           ------------***\n");
    printf("***----------- 7: Quitter application          ------------***\n");
    printf("**************************************************************\n");
    printf("***             Realise par: Nabil Sabi                    ***\n");
    printf("***             Encadrer par: Ibrahim Zeroual              ***\n");
    printf("**************************************************************\n");
}

void ajouterTache(){}
void afficherTaches(){}
void modifierTache(){}
void supprimerTache(){}
void ordonnerTaches(){}
void filtrerTaches(){}

int main()
{ 
    int choix;
    do
    {
        menu();
        
        printf("Entrez votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1:
                ajouterTache();
                break;
            case 2:
                afficherTaches();
                break;
            case 3:
                modifierTache();
                break;
            case 4:
                supprimerTache();
                break;
            case 5:
                ordonnerTaches();
                break;
            case 6:
                filtrerTaches();
                break;
            case 7:
                printf("Au revoir !");
                return 0;
            default:
                printf("Choix invalide.");
                break;
        }
    } while (choix != 7);    
    return 0;
}
