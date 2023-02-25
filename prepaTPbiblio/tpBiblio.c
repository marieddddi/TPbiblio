// TP GESTION D'UNE BIBLIOTHEQUE 
#include "biblio.h"



int menu()
{
	int choix;
// au programme du TP7 :
	printf("\n\n 1 - ajouter un nouveau livre dans la bibliotheque "); 
	printf("\n 2 - afficher tous les livres de la bibliotheque "); 
	printf("\n 3 - rechercher un livre (par son titre)");  // il peut y avoir plusieurs livres de même titre. Dans ce cas, indiquez le nombre d'exemplaires disponibles
	printf("\n 4 - rechercher et afficher tous les livres d'un auteur");
	printf("\n 5 - supprimer un livre de la bibliotheque");
// si les 5 choix ci dessus sont bien codés, modifiez votre structure T_Livre et passez à 5 champs (avec code,editeur et annee)


// au programme du TP8 :
// ajouter le champ emprunteur à votre structure T_Livre
	printf("\n 6 - emprunter un livre de la bibliotheque");
	printf("\n 7 - restituer/rendre un livre de la bibliotheque");
	printf("\n 8 - trier les livres (par titre)");
	printf("\n 9 - trier les livres (par auteur)");
	printf("\n 10 - trier les livres (par annee)");

// si les 5 choix (6-10) sont bien codés, changez le type T_Emp et remplacez-le par la structure T_Emp visible dans livre.h
// vous pourrez alors faire les menus 11,12,etc...
// printf("\n 11- lister les livres disponibles "); 
// printf("\n 12 - lister les emprunts en retard "); //on suppose qu'un emprunt dure 7 jours.
// printf("\n 13 - ... imaginez vous même vos propres fonctionnalités ")

	printf("\n 0 - QUITTER");
	printf("\n Votre choix : ");
	scanf("%d[^\n]",&choix);getchar();
	return choix;
}



int main()
{
	int reponse,chx;
	T_Bibliotheque B; 
	init( &B );
	T_Titre titre;
	T_Aut auteur;
	int a;
	int i;
	T_livre livre;

	do
	{
		chargement(&B);
		chx= menu();
		switch(chx)
		{
			
			case 1 : reponse = ajouterLivre(&B);
					 if (reponse==1) printf(" ajout reussi !!");
					 else printf("impossible d ajouter (bibliotheque pleine)");
					 break;
					 
			case 2 : reponse=afficherBibliotheque(&B);
					 if (reponse==0)	
					 printf("La bibliotheque est vide");
					 break;
					
			case 3 : printf("quel titre ?\n");
					 i=0;
					 //essayer avce lire chaine !!!
					 fgets(titre,MAX_TITRE,stdin);
					 while(titre[i]!='\n') i++;
					 titre[i]='\0';
					 a=rechercherLivre(&B,titre);
					 if(a==0)printf("le livre n'y est pas\n");
					 else printf("le livre est présent %d fois \n",a);
					 break;
					
			case 4 : printf("quel auteur ?\n");
					 i=0;
					 //essayer avec lirechaine
					 fgets(auteur,K_MaxAut,stdin);
					 while(auteur[i]!='\n') i++;
					 auteur[i]='\0';
					 AffRechAuteur(&B,auteur);
					 break;
					
			case 5 : printf("quel auteur souhaitez-vous supprimer ?\n");
					 i=0;
					  //essayer avec lirechaine
					 fgets(livre.auteur,K_MaxAut,stdin);
					 while(livre.auteur[i]!='\n') i++;
					 livre.auteur[i]='\0';
				 	 printf("quel titre de cet auteur souhaitez-vous supprimer ? ?\n");
				  	 i=0;
				  	  //essayer avec lirechaine
					 fgets(livre.titre,MAX_TITRE,stdin);
					 while(livre.titre[i]!='\n') i++;
					 livre.titre[i]='\0';
					 a=SuppLivre(&B,&livre);
					 if(a==0)printf("le livre n'y est pas\n");
					 else printf("le livre est bien supprimé");
					 break;			
			
		}
		sauvegarde(&B);

	}
	while(chx!=0);
	return 0;

}
