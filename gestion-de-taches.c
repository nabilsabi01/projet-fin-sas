#include <stdio.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef enum
{
    FAIBLE,
    MOYENNE,
    ELEVEE
} Priorite;

typedef struct
{
    char titre[50];
    char desc[100];
    Date date_fin;
    Priorite priorite;
    int statut;
} Tache;

Tache taches[100];
int nbrTaches = 0;

void menu()
{
    printf("**************************************************************\n");
    printf("***               OneHand: Gestion De Taches               ***\n");
    printf("**************************************************************\n");
    printf("***            1: Ajouter une Tache                        ***\n");
    printf("***            2: Afficher la Liste des Taches             ***\n");
    printf("***            3: Modifier une Tache                       ***\n");
    printf("***            4: Supprimer une Tache                      ***\n");
    printf("***            5: Ordonner les Taches                      ***\n");
    printf("***            6: Filtrer les Taches                       ***\n");
    printf("***            7: Quitter application                      ***\n");
    printf("**************************************************************\n");
}

void ajouterTache()
{
    if (nbrTaches == 100)
    {
        printf("Liste des taches.\n");
        return;
    }
    printf("Titre de la tache : ");
    scanf(" %[^\n]", taches[nbrTaches].titre);
    printf("Description de la tache : ");
    scanf(" %[^\n]", taches[nbrTaches].desc);
    printf("Date d'echeance (JJ/MM/AAAA) : ");
    scanf("%d/%d/%d", &taches[nbrTaches].date_fin.jour, &taches[nbrTaches].date_fin.mois, &taches[nbrTaches].date_fin.annee);
    printf("Priorite (0: FAIBLE, 1: MOYENNE, 2: ELEVEE) : ");
    scanf("%d", &taches[nbrTaches].priorite);
    taches[nbrTaches].statut = 0;
    nbrTaches++;
    printf("Tache ajoutee avec succes.\n");
}

void afficherTaches()
{
    char priorite[10];
    if (nbrTaches < 0)
    {
        printf("Liste des taches est vide!!!");
    }
    else
    {
        printf("--------------------------------------------------------------\n");
        printf("|                      Liste des taches                      |\n");
        printf("--------------------------------------------------------------\n");
        for (int i = 0; i < nbrTaches; i++)
        {
            printf("Tache %d\n", i+1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].desc);
            printf("Date d'echeance : %d/%d/%d\n", taches[i].date_fin.jour, taches[i].date_fin.mois, taches[i].date_fin.annee);
            switch (taches[i].priorite) {
                case FAIBLE:
                    printf("Priorite : Faible\n");
                    break;
                case MOYENNE:
                    printf("Priorite : Moyenne\n");
                    break;
                case ELEVEE:
                    printf("Priorite : Elevee\n");
                    break;
                default:
                    printf("Priorite : Inconnue\n");
            }
            printf("Statut : %s\n", taches[i].statut ? "complete" : "incomplete");
            printf("\n--------------------------------------------------------------\n");
        }
    }
}

void modifierTache()
{
}

void supprimerTache()
{
}

void ordonnerTaches()
{
}

void filtrerTaches()
{
}

int main()
{
    int choix;
    printf("**************************************************************\n");
    printf("***             Realise par: Nabil Sabi                    ***\n");
    printf("***             Encadrer par: Ibrahim Zeroual              ***\n");
    do
    {
        menu();
        printf("Entrez votre choix: ");
        scanf("%d", &choix);
        switch (choix)
        {
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
