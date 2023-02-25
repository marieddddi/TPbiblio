#include "biblio.h"


void init (T_Bibliotheque *ptrB)
{
    ptrB -> nbLivres=0;
}


int ajouterLivre(T_Bibliotheque  *ptrB)
{
    if(ptrB -> nbLivres<CAPACITE_BIBLIO)
    {
        saisirLivre(&(ptrB -> etagere[ptrB -> nbLivres]));
        ptrB -> nbLivres++;
        return 1;
    }
    return 0;
}


int  afficherBibliotheque(const T_Bibliotheque  *ptrB)
{
    int i;
    if (ptrB->nbLivres>0)
    {
        for(i=0;i<ptrB -> nbLivres;i++) afficherLivre(&(ptrB-> etagere[i]));
        return 1;
    }
    return 0;
}

int rechercherLivre(const T_Bibliotheque *ptrB, T_Titre titre)
{
    int i;
    int a=0;
    for (i=0;i<ptrB -> nbLivres;i++)
    {
        if (strcmp(titre, (ptrB->etagere[i].titre))==0) a++;
    }
    return a;
}


void AffRechAuteur(const T_Bibliotheque *ptrB, T_Aut auteur)
{
    int i;
    for (i=0;i<ptrB -> nbLivres;i++)
    {
        if (strcmp(auteur, (ptrB->etagere[i].auteur))==0) printf("Un des titres de %s est: %s \n",auteur,ptrB->etagere[i].titre);
    }
}

int SuppLivre(T_Bibliotheque  *ptrB, T_livre *livre)
{
    int i;
    for (i=0;i<ptrB -> nbLivres;i++)
    {
        if ((strcmp(livre->titre, (ptrB->etagere[i].titre))==0)&&(strcmp(livre->auteur, (ptrB->etagere[i].auteur))==0))
        {
            strcpy(ptrB->etagere[i].titre,ptrB->etagere[ptrB -> nbLivres-1].titre);
            strcpy(ptrB->etagere[i].auteur,ptrB->etagere[ptrB -> nbLivres-1].auteur);
            ptrB -> nbLivres--;
            return 1;
        }
    }
   
    return 0;
}

int Emprunter (T_Bibliotheque  *ptrB, T_livre *livre, T_Emp *date)
{
    if (rechercherLivre(&ptrB,&livre)!=0)
    {
        if ((strlen(livre->emprunteur)==0)&&(strcmp(livre->code,ptrB->etagere[i].code)==0))
        {
            strcpy(livre->emprunteur,date);
            return 1;
            //rechercher d'abord la position du livre, verif pas emprunteur deja, regarder si meme code car peut avoir 2 meme livre
            //copier date dans la case emprunteur du livre 
        
        }
    }
    return 0;
}



void sauvegarde(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i;
fic=fopen("baseLivres","w"); // w = le mode = write avec ECRASEMENT
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	for(i=0;i<ptrB->nbLivres;i++)
		{
//fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream)
    fwrite(  &(ptrB->etagere[i]),sizeof(T_livre),1,fic);

		}
	fclose(fic);
	puts("SAUVEGARDE REUSSIE ..............");

	}
	else puts("ECHEC DE SAUVEGARDE  !!!!!  ");




}



void chargement(T_Bibliotheque *ptrB)
{
FILE *fic=NULL; //le type FILE
int i=0;
fic=fopen("baseLivres","r"); // r = le mode read
//fopen renvoie NULL si probleme (disque plein, disque non accessible ...
if (fic!=NULL)
	{
	do
		{

		fread(  &(ptrB->etagere[i]) ,sizeof(T_livre),1,fic);
		i++;
		}
		while(!feof(fic));
	fclose(fic);
	ptrB->nbLivres=i-1;
	puts("CHARGEMENT  REUSSI ..............");
	}
	else puts("ECHEC DE CHARGEMENT  !!!!!  ");

}



