#include<stdio.h>
#include<stdlib.h>

typedef struct element element;
struct element
{
    char *val;
    struct element *nxt;
};
typedef element* llist;

llist ajouterEnFin(llist liste, int valeur)
{
    /* On cr�e un nouvel �l�ment */
    element* nouvelElement = malloc(sizeof(element));

    /* On assigne la valeur au nouvel �l�ment */
    nouvelElement->val = valeur;

    /* On ajoute en fin, donc aucun �l�ment ne va suivre */
    nouvelElement->nxt = NULL;

    if(liste == NULL)
    {
        /* Si la liste est vide� il suffit de renvoyer l'�l�ment cr�� */
        return nouvelElement;
    }
    else
    {
        /* Sinon, on parcourt la liste � l'aide d'un pointeur temporaire et on
        indique que le dernier �l�ment de la liste est reli� au nouvel �l�ment */
        element* temp=liste;
        while(temp->nxt != NULL)
        {
            temp = temp->nxt;
        }
        temp->nxt = nouvelElement;
        return liste;
    }
}
void afficherListe(llist liste)
{
    element *tmp = liste;
    /* Tant que l'on n'est pas au bout de la liste */
    while(tmp != NULL)
    {
        /* On affiche */
        printf("%c ", tmp->val);
        /* On avance d'une case */
        tmp = tmp->nxt;
    }
}

int main()
{
    FILE* fichier = NULL;
    fichier = fopen("css1.txt", "r");
    llist ma_liste = NULL;
    int caractereActuel = 0;

     if (fichier != NULL)
    {
        int i=0;
        char* valeur;
        // Boucle de lecture des caract�res un � un
        do
        {
            caractereActuel = fgetc(fichier); // On lit le caract�re
            ajouterEnFin(ma_liste, caractereActuel);
        } while (caractereActuel != EOF); // On continue tant que fgetc n'a pas retourn� EOF (fin de fichier)

afficherListe(ma_liste);
        fclose(fichier);
    }
    return 0;
}
