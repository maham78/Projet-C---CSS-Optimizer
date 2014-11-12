#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 10

typedef struct element element;
struct element
{
    char* val;
    struct element *nxt;
};

typedef element* llist;

 llist ajouterEnFin(llist liste, char* valeur)
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
        printf("%c", tmp->val);
        /* On avance d'une case */
        tmp = tmp->nxt;
    }
    printf("\n");
}

void remplissage (llist liste, FILE* fichier, char* chaine)
{
    if (fichier != NULL) /**si le fichier existe*/
    {
    while(chaine != EOF) /**tant que le dernier caractere nest pas lu*/
        {
            chaine = fgetc(fichier);
            if(chaine == '{') /**si le caractere lu est une accolade ouvrante*/
                {

                }
           liste = ajouterEnFin(liste, chaine);
        }
    fclose(fichier);
}

    else
        printf("suce");

    afficherListe(liste);
}

int main(int argc, char **argv)
{
    llist ma_liste1 = NULL;
    llist ma_liste2 = NULL;
    char* chaine1;
    char* chaine2;
    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    fichier1 = fopen("css1.txt", "r");
    fichier2 = fopen("css2.txt", "r");

remplissage(ma_liste1, fichier1, chaine1);
//remplissage(ma_liste2, fichier2, chaine2);

    return 0;
}
