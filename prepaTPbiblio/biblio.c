

#include "biblio.h"


void init (T_Bibliotheque *ptrB)
{
	//on met le nombre de livres à 0 => biblio vide
    ptrB -> nbLivres=0;
}


int ajouterLivre(T_Bibliotheque  *ptrB)
{
	//si la biblio n'est pas pleine on peut ajouter le livre
    if(ptrB -> nbLivres < CAPACITE_BIBLIO)
    {
		//ajout du livre à la biblio
        saisirLivre(&(ptrB -> etagere[ptrB -> nbLivres]));
        //augmente le nb de livres dans la biblio de 1
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
		//affiche livre par livre la bibliotheque
        for(i=0;i<ptrB -> nbLivres;i++) afficherLivre(&(ptrB-> etagere[i]));
        return 1;
    }
    return 0;
}

int rechercherLivre(const T_Bibliotheque *ptrB, T_Titre titre)
{
    int i;
    //compteur
    int a=0;
    for (i=0;i<ptrB -> nbLivres;i++)
    {
		//on compare le livre que l'on veut rechercher avec chaque livre présent dans la biblio
        if (strcmp(titre, (ptrB->etagere[i].titre))==0) a++;
    }
    return a;
}


void AffRechAuteur(const T_Bibliotheque *ptrB, T_Aut auteur)
{
    int i;
    for (i=0;i<ptrB -> nbLivres;i++)
    {
		//affiche le titre de chaque livre de l'auteur demandé dès qu'on le trouve dans la bibliotheque jusqu'à l'avoir parcourue entierement
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
			//on remplace le livre que l'on veut supprimer par le dernier de la bibliotheque
            strcpy(ptrB->etagere[i].titre,ptrB->etagere[ptrB -> nbLivres-1].titre);
            strcpy(ptrB->etagere[i].auteur,ptrB->etagere[ptrB -> nbLivres-1].auteur);
            //diminue le nb de livres de la biblio de 1
            ptrB -> nbLivres--;
            return 1;
        }
    }
   
    return 0;
}

int positionLivre (const T_Bibliotheque *ptrB, T_Titre titre)
{
	int i;
    for (i=0;i<ptrB -> nbLivres;i++)
    {
		//on compare le livre que l'on veut rechercher avec chaque livre présent dans la biblio
        if (strcmp(titre, (ptrB->etagere[i].titre))==0) return i;
    }
    return -1;
	
}
	
	
int Emprunter (T_Bibliotheque  *ptrB, T_livre *livre, T_Emp nom)
{
    int i;
    strcpy(livre->auteur,"inconnu") ;
    if (positionLivre(ptrB,livre->titre)!=-1)
    {
        printf("emprunteur length: %d\n", strlen(livre->emprunteur));
printf("emprunteur: %s\n", livre->emprunteur);

        if (strcmp(livre->emprunteur, "") == 0)

        {
			printf("emprunteur length: %d\n", strlen(livre->emprunteur));
printf("emprunteur: %s\n", livre->emprunteur);

			printf("ok1\n");
          
            for (i=0;i<ptrB -> nbLivres;i++)
            {
				printf("ok2\n");
                if ((strcmp(livre->code,ptrB->etagere[i].code)==0) && (strcmp(livre->titre,ptrB->etagere[i].titre)==0))
                {
					printf("ok3\n");
					printf("%s",livre->emprunteur);
                    strcpy(livre->emprunteur,nom);
                    printf("%s",livre->emprunteur);
                    return 1;
                }
            }
        }
    }
    return 0;
}

int RendreLivre (T_Bibliotheque  *ptrB, T_livre *livre, const T_Emp *nom)
{
    int i;
    if (positionLivre(ptrB,livre->titre)!=-1)
    {
        for (i=0;i<ptrB -> nbLivres;i++)
        {
            if ((strcmp(livre->code,ptrB->etagere[i].code)==0) && (strcmp(livre->titre,ptrB->etagere[i].titre)==0)) 
            {
                if(strcmp(*nom,ptrB->etagere[i].emprunteur)==0)
                {
                    strcpy(livre->emprunteur,"\0");
                    return 1;
                }
            }
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
