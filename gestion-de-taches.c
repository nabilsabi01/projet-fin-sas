#include <stdio.h>
#include <string.h>

typedef struct
{
    int jour;
    int mois;
    int annee;
} Date;

typedef struct
{
    char titre[50];
    char desc[100];
    Date date_fin;
    int priorite;
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
        printf("La liste des taches est pleine.\n");
        return;
    }
    else
    {
        printf("Titre de la tache : ");
        scanf(" %[^\n]", taches[nbrTaches].titre);
        printf("Description de la tache : ");
        scanf(" %[^\n]", taches[nbrTaches].desc);
        printf("Date d'echeance (JJ/MM/AAAA) : ");
        scanf("%d/%d/%d", &taches[nbrTaches].date_fin.jour, &taches[nbrTaches].date_fin.mois, &taches[nbrTaches].date_fin.annee);
        printf("Priorite (1: Faible, 2: Moyenne, 3: Elevee) : ");
        scanf("%d", &taches[nbrTaches].priorite);
        printf("Priorite (1: complete , 2: incomplete) : ");
        scanf("%d", &taches[nbrTaches].statut);
        nbrTaches++;
        printf("Tache ajoutee avec succes.\n");
    }
}

void afficherTaches()
{
    if (nbrTaches <= 0)
    {
        printf("Liste des taches est vide!!!");
        return;
    }
    else
    {
        printf("--------------------------------------------------------------\n");
        printf("|                      Liste des taches                      |\n");
        printf("--------------------------------------------------------------\n");
        for (int i = 0; i < nbrTaches; i++)
        {
            printf("Tache %d\n", i + 1);
            printf("Titre : %s\n", taches[i].titre);
            printf("Description : %s\n", taches[i].desc);
            printf("Date d'echeance : %d/%d/%d\n", taches[i].date_fin.jour, taches[i].date_fin.mois, taches[i].date_fin.annee);
            switch (taches[i].priorite)
            {
            case 1:
                printf("Priorite : Faible\n");
                break;
            case 2:
                printf("Priorite : Moyenne\n");
                break;
            case 3:
                printf("Priorite : Elevee\n");
                break;
            default:
                printf("Priorite : Inconnue\n");
            }
            printf("Statut : %s\n", taches[i].statut == 1 ? "complete" : "incomplete");
            printf("\n--------------------------------------------------------------\n");
        }
    }
}

void modifierTache()
{
    int index;
    printf("Entrez le numero de tache a modifier: ");
    scanf("%d", &index);
    if (index < 1 || index > nbrTaches)
    {
        printf("Numero de tache invalide.\n");
        return;
    }
    else
    {
        printf("Nouveau titre de la tache : ");
        scanf(" %[^\n]", taches[index - 1].titre);
        printf("Nouvelle description de la tache : ");
        scanf(" %[^\n]", taches[index - 1].desc);
        printf("Nouvelle date d'echeance (JJ/MM/AAAA) : ");
        scanf("%d/%d/%d", &taches[index - 1].date_fin.jour, &taches[index - 1].date_fin.mois, &taches[index - 1].date_fin.annee);
        printf("Nouvelle priorite (1: Faible, 2: Moyenne, 3: Elevee) : ");
        scanf("%d", &taches[index - 1].priorite);
        printf("Priorite (1: complete , 2: incomplete) : ");
        scanf("%d", &taches[nbrTaches - 1].statut);
        printf("Tache modifiee avec succes.\n");
    }
}

void supprimerTache()
{
    int index;
    printf("Entrez le numero de tache a supprimer: ");
    scanf("%d", &index);
    if (index < 1 || index > nbrTaches)
    {
        printf("Numero de tache invalide.\n");
        return;
    }
    else
    {
        for (int i = index - 1; i < index - 1; i++)
        {
            strcpy(taches[i].titre, taches[i + 1].titre);
            strcpy(taches[i].desc, taches[i + 1].desc);
            taches[i].date_fin = taches[i + 1].date_fin;
            taches[i].priorite = taches[i + 1].priorite;
            taches[i].statut = taches[i + 1].statut;
        }

        nbrTaches--;
        printf("Tache supprimer avec succes.\n");
    }
}

void ordonnerTaches()
{
    int ordre;
    if (nbrTaches <= 0)
    {
        printf("Liste des taches est vide!!!");
        return;
    }
    else
    {
        printf("Choisissez l'ordre de tri (1: Croissant, 2: Decroissant): ");
        scanf("%d", &ordre);
        if (ordre == 1)
        {
            for (int i = 0; i < nbrTaches - 1; i++)
            {
                for (int j = i + 1; j < nbrTaches; j++)
                {
                    if (taches[i].date_fin.annee > taches[j].date_fin.annee ||
                        (taches[i].date_fin.annee == taches[j].date_fin.annee && taches[i].date_fin.mois > taches[j].date_fin.mois) ||
                        (taches[i].date_fin.annee == taches[j].date_fin.annee && taches[i].date_fin.mois == taches[j].date_fin.mois && taches[i].date_fin.jour > taches[j].date_fin.jour))
                    {
                        Tache temp = taches[j];
                        taches[j] = taches[i];
                        taches[i] = temp;
                    }
                }
            }
        }
        else if (ordre == 2)
        {
            for (int i = 0; i < nbrTaches - 1; i++)
            {
                for (int j = i + 1; j < nbrTaches; j++)
                {
                    if (taches[i].date_fin.annee < taches[j].date_fin.annee ||
                        (taches[i].date_fin.annee == taches[j].date_fin.annee && taches[i].date_fin.mois < taches[j].date_fin.mois) ||
                        (taches[i].date_fin.annee == taches[j].date_fin.annee && taches[i].date_fin.mois == taches[j].date_fin.mois && taches[i].date_fin.jour < taches[j].date_fin.jour))
                    {
                        Tache temp = taches[j];
                        taches[j] = taches[i];
                        taches[i] = temp;
                    }
                }
            }
        }
    }
    printf("Taches ordonnees avec succes.\n");
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
