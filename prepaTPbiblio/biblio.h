#ifndef BIBLIO_H   //compilation conditionnelle
#define BIBLIO_H


#include "livre.h"

#define CAPACITE_BIBLIO 5 // nb maximum de livres ds la bibliotheque

typedef  T_livre 	T_tabloDeLivres[CAPACITE_BIBLIO];

typedef struct
{
	T_tabloDeLivres etagere;
	int nbLivres;  //nb de livres actuellement ds la bibliotheque

} T_Bibliotheque;




//prototypes
void init (T_Bibliotheque *ptrB);
int ajouterLivre(T_Bibliotheque  *ptrB);
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);
int rechercherLivre(const T_Bibliotheque *ptrB, T_Titre titre);
void AffRechAuteur(const T_Bibliotheque *ptrB, T_Aut auteur);
int SuppLivre(T_Bibliotheque  *ptrB, T_livre *livre);
void sauvegarde(T_Bibliotheque *ptrB);
void chargement(T_Bibliotheque *ptrB);
int Emprunter (T_Bibliotheque  *ptrB, T_livre *livre, T_Emp *date);


#endif
