#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

bool tab_egaux(int tab1[],int size1, int tab2[], int size2)
{
    if (size1!=size2)
    {return false;}
    for (int i=0;i<size1;i++)
    {
        if (tab1[i]!=tab2[i])
        {return false;}
    }
    return true;
}

int * nb_lettres(char *chaine)
{
    int i = 0;
    int index;
    int * tab = malloc(sizeof(int)*26);
    for (int i=0; i<26; i++)
    {
        tab[i] = 0;
    }
    while (chaine[i]!='\0')
    {
        index = (int) chaine[i] - 65;
        tab[index] = tab[index] + 1;
        i = i + 1;
    }
    return tab;
}

 bool anagrammes(char * chaine1, char *chaine2)
 {
    return tab_egaux(nb_lettres(chaine1),26,nb_lettres(chaine2),26);
 }

 bool anagrammes(char * chaine1, char *chaine2)
 {
    int *tab1 = nb_lettres(chaine1);
    int *tab2 = nb_lettres(chaine2);
    bool anag;
    if (tab_egaux(tab1,26,tab2,26))
    {
        anag = true;
    }
    else
    {
        anag = false;
    }
    free(tab1);
    free(tab2);
    return anag;
    
 }
 
int main()
{   
    char chaine1[] = "NICHE";
    char chaine2[] = "CHIEN";
    if (anagrammes(chaine1,chaine2))
    {
        printf("Sont des anagrammes\n");
    }
    else
    {
        printf("Ne sont pas des anagrammes\n");
    }
}