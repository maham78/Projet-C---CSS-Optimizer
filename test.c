#include<stdio.h>
#include<stdlib.h>
#define TAILLE_MAX 10

/**d�fnition d'une nouvelle structure**/
typedef struct element element;
struct element
{
    char *val;
    struct element *next;
};
typedef element* llist;


llist ajouter(llist liste, int valeur)
{
    /** On cr�e un nouvel �l�ment **/
    element* nouvelElement = malloc(sizeof(element));

    /** On assigne la valeur au nouvel �l�ment **/
    nouvelElement->val = valeur;

    /** On ajoute en fin, donc aucun �l�ment ne va suivre **/
    nouvelElement->next = NULL;

    if(liste == NULL)
    {
        /** Si la liste est vide� il suffit de renvoyer l'�l�ment cr�� **/
        return nouvelElement;
    }
    else
    {
        /** Sinon, on parcourt la liste � l'aide d'un pointeur temporaire et on
        indique que le dernier �l�ment de la liste est reli� au nouvel �l�ment **/
        element* temp=liste;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = nouvelElement;
        return liste;
    }
}
void afficherListe(llist liste)
{
    element *tmp = liste;
    /**Tant que l'on n'est pas au bout de la liste**/
    while(tmp != NULL)
    {
        /**On affiche**/
        printf("%s", tmp->val);
        /**On avance d'une case**/
        tmp = tmp->next;
    }
}

/** fonction inutile pour le moment **/
void ecriture (FILE* fichier, llist ma_liste)
{
    /**if (fichier != NULL)**/
    printf("Ecriture executee");
}

    void remplissage(char* chaine, FILE* fichier, llist ma_liste)
    {

        if (fichier != NULL)
        {
        char *valeur;
        /**si le fichier existe: tant que la ligne parcouru contient une chaine de caract�re alors on ins�re la chaine dans la liste chain�e**/
        while ((fgets(chaine, TAILLE_MAX, fichier) != NULL)) /** On lit le fichier tant qu'on ne re�oit pas d'erreur (NULL)**/
        {
            valeur = malloc(sizeof(*valeur) * TAILLE_MAX);
            int j;
            for(j=0; j<=TAILLE_MAX; j++)
            {
                valeur[j]=chaine[j];
            }
            valeur[TAILLE_MAX]='\0';
            //printf(chaine);
            ma_liste = ajouter(ma_liste,valeur);
        }
         fclose(fichier);
         free(*valeur);
        }
        /**ecriture(fichierResult, ma_liste);**/
        afficherListe(ma_liste);
        free(ma_liste);
    }

/** pour la suite du projet on aura besoin de lire plusieurs fichier, mais pour linstant j'essaye deja den lire un ! **/
int main()
{
    FILE* fichier1 = NULL;
    FILE* fichier2 = NULL;
    //FILE* fichier3 = NULL;

    char chaine1[TAILLE_MAX];
    char chaine2[TAILLE_MAX] = "";

    /**ouverture du fichier .txt**/
    fichier1 = fopen("css1.txt", "r");
    fichier2 = fopen("css2.txt", "r");
    //fichier3 = fopen("result.txt", "r+");

    llist ma_liste = NULL;
    llist ma_liste2 = NULL;

remplissage(chaine1, fichier1, ma_liste);
remplissage(chaine2, fichier2, ma_liste2);

    return 0;
}
