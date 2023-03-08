#include "livre.h"


void saisirLivre(T_livre * ptrL)
{
lireChaine("TITRE :", (ptrL->titre), MAX_TITRE );
lireChaine("AUTEUR :", (ptrL->auteur ), MAX);
lireChaine("CODE :", (ptrL->code), K_MaxCode);
printf("ANNEE :");
scanf("%d",&(ptrL->annee));
getchar();
lireChaine("EDITEUR :", (ptrL->editeur), K_MaxEdit);
strcpy(ptrL->emprunteur,"\0");

}


void afficherLivre(const T_livre *ptrL)
{
afficherChaine("TITRE :", (ptrL->titre));
printf(" - ");
afficherChaine("AUTEUR :", (ptrL->auteur ));
printf(" - ");
afficherChaine("CODE:", (ptrL->code ));
printf(" - ");
printf("ANNEE :%d",ptrL->annee);
printf(" - ");
afficherChaine("EDITEUR :", (ptrL->editeur ));
printf(" - ");
afficherChaine("EMPRUNTEUR :", (ptrL->emprunteur));
printf("\n");
}

