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

/***************************************************************************/
/* NOM FONCTION : init						  						 	   */
/* DESCRIPTION :  initialise la bibliotheque           					   */
/* Retourne :														   	   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque	  		   */
/* Paramètres en sortie : 												   */
/***************************************************************************/
void init (T_Bibliotheque *ptrB);

/***************************************************************************/
/* NOM FONCTION : ajouterLivre											   */
/* DESCRIPTION :  permet d'ajouter un livre à la bibliothèque			   */
/* Retourne : 1 si l'ajout a été fait (possible, bibliotheque non pleine), */
/* ou 0 si l'ajout n'a pas été possible									   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque			   */
/* Paramètres en sortie : la bibliotheque modifiee    			   */
/***************************************************************************/
int ajouterLivre(T_Bibliotheque  *ptrB);

/***************************************************************************/
/* NOM FONCTION : afficherBibliotheque									   */
/* DESCRIPTION :  affiche la bibliotheque, c'est à dire chaque livre des   */
/* etagères.															   */
/* Retourne : 1 si l'on a des livres à afficher ou 0 si la bibliotheque    */
/* est vide.															   */ 			                                  
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque			   */
/* Paramètres en sortie : la bibliotheque					  			   */
/***************************************************************************/
int  afficherBibliotheque(const T_Bibliotheque  *ptrB);

/***************************************************************************/
/* NOM FONCTION : rechercherLivre										   */
/* DESCRIPTION :  recherche un livre par son titre.				           */
/* Retourne : nombre de fois où le titre de son livre est présent dans la  */
/* bibliotheque.													   	   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque, titre: titre */
/* du livre qu'on recherche.											   */
/* Paramètres en sortie : nombre de fois où le titre du livre recherché    */ 
/* est dans la bibliotheque (0 signifie qu'il n'y est pas.)   			   */
/***************************************************************************/
int rechercherLivre(const T_Bibliotheque *ptrB, T_Titre titre);

/***************************************************************************/
/* NOM FONCTION : AffRechAuteur											   */
/* DESCRIPTION :  rechercher et afficher tous les livres d'un auteur       */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque, 		   	   */
/* auteur: auteur des livres qu'on recherche.	 						   */
/* Paramètres en sortie : 												   */
/***************************************************************************/
void AffRechAuteur(const T_Bibliotheque *ptrB, T_Aut auteur);

/***************************************************************************/
/* NOM FONCTION : SuppLivre												   */
/* DESCRIPTION : supprimer un livre de la bibliotheque			           */
/* Retourne : 1 si le livre a bien été supprimé ou 0 sinon.			   	   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque, 		       */
/* livre: pointeur sur le livre qu'on veut supprimer					   */
/* Paramètres en sortie : 									   			   */
/***************************************************************************/
int SuppLivre(T_Bibliotheque  *ptrB, T_livre *livre);

/***************************************************************************/
/* NOM FONCTION : sauvegarde											   */
/* DESCRIPTION :  permet de sauvegarder la bibliotheque afin de ne pas	   */
/*  devoir la remplir à chaque fois qu'on quitte.         				   */
/* Retourne :														   	   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque			   */
/* Paramètres en sortie : 												   */
/***************************************************************************/
void sauvegarde(T_Bibliotheque *ptrB);

/***************************************************************************/
/* NOM FONCTION : chargement											   */
/* DESCRIPTION :  charge la bibliotheque sauvegardée a l'aide de la 	   */
/* fonction sauvegarde.   												   */
/* Retourne :														   	   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque			   */
/* Paramètres en sortie : 									  			   */
/***************************************************************************/
void chargement(T_Bibliotheque *ptrB);

/***************************************************************************/
/* NOM FONCTION : rechercherLivre										   */
/* DESCRIPTION :  recherche un livre par son titre.				           */
/* Retourne : nombre de fois où le titre de son livre est présent dans la  */
/* bibliotheque.													   	   */
/* Paramètres en entree : ptrB: pointeur sur la bibliotheque, titre: titre */
/* du livre qu'on recherche.											   */
/* Paramètres en sortie : nombre de fois où le titre du livre recherché    */ 
/* est dans la bibliotheque (0 signifie qu'il n'y est pas.)   			   */
/***************************************************************************/
int positionLivre (const T_Bibliotheque *ptrB, T_Titre titre);

/***************************************************************************/
/* NOM FONCTION : Emprunter												   */
/* DESCRIPTION : permet d'emprunter un livre de la bibliotheque	           */
/* Retourne : COMPLETER												   	   */
/* Paramètres en entree : COMPLETER	   */
/* Paramètres en sortie : COMPLETER   			   */
/***************************************************************************/
int Emprunter (T_Bibliotheque  *ptrB, T_livre *livre, T_Emp nom);
int RendreLivre (T_Bibliotheque  *ptrB, T_livre *livre, const T_Emp *nom);

#endif
