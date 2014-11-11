#include<stdio.h>
#include<stdlib.h>

typedef struct element element;
struct element
{
    char* val;
    struct element *nxt;
};

typedef element* llist;

 llist ajouterEnFin(llist liste, char* valeur)
{
    /* On crée un nouvel élément */
    element* nouvelElement = malloc(sizeof(element));

    /* On assigne la valeur au nouvel élément */
    nouvelElement->val = valeur;

    /* On ajoute en fin, donc aucun élément ne va suivre */
    nouvelElement->nxt = NULL;

    if(liste == NULL)
    {
        /* Si la liste est videé il suffit de renvoyer l'élément créé */
        return nouvelElement;
    }
    else
    {
        /* Sinon, on parcourt la liste à l'aide d'un pointeur temporaire et on
        indique que le dernier élément de la liste est relié au nouvel élément */
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
    if (fichier != NULL)
{
    do
    {
        chaine = fgetc(fichier);
        liste = ajouterEnFin(liste, chaine);
    }while(chaine != EOF);
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
remplissage(ma_liste2, fichier2, chaine2);

    return 0;
}
