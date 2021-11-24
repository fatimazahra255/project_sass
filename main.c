#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
  {
  	char  cin[50];
  	char  nom[50];
  	char  prenom[50];
  	float montant;

  }compte;
  int nbr_cmp=0,s;
  compte comptes[50],c1[100];
    void comptee()
	{
	 compte cmp ;
	 int found = 0;
         do
            {
                found = 0;
                printf("\nCIN: ");
		        scanf("%s",cmp.cin);
              for(int i = 0; i < nbr_cmp; i++)
              {
                if(strcmp(comptes[i].cin, cmp.cin)==0)
                {
                  printf("Ce client a deja un compte!!\n");
                  found=1;
                }
              }

            }while(found == 1);
            printf("\nNom: ");
		    scanf(" %s",cmp.nom);
		    printf("\nPrenom: ");
		    scanf(" %s",cmp.prenom);
		    printf("\nMontant: ");
		    scanf("%f",&cmp.montant);
		    comptes[nbr_cmp]=cmp;
		    nbr_cmp++;


	}
	void plusieurs_comptes()
	{
int nbr;
 printf("Saisissez le nombre de comptes souhaites: ");
 scanf("%d",&nbr);
int total = nbr_cmp + nbr;
for(int i=nbr_cmp;i<total;i++)
{
comptee();

}
	}
	void tri(){
	for(int i=0;i<nbr_cmp;i++)
	   {
	       for(int j=i+1;j<nbr_cmp;j++)
	       {
	           if(comptes[i].montant>comptes[j].montant)
               {
                  compte p=comptes[i];
                   comptes[i]=comptes[j];
                   comptes[j]=p;
                   }
            }
       }
	}
	void ascendant()
	{
       tri();
        for(int i=0;i<nbr_cmp;i++)
       {
        printf("\nCIN: %s\n",comptes[i].cin);
        printf("\nNom: %s\n",comptes[i].nom);
        printf("\nMontant: %f\n",comptes[i].montant);
       }
	}
	void  descendant()
	{
       tri();
       for(int i=nbr_cmp - 1;i>=0;--i)
       {
        printf("\nCIN: %s\n",comptes[i].cin);
        printf("\nNom: %s\n",comptes[i].nom);
        printf("\nMontant: %f\n",comptes[i].montant);
       }
	}

	void  ascendant_n()
	{  float tst;
       printf("Donner un montant: ");
       scanf("%f",&tst);

tri();
       for(int i=0;i<=nbr_cmp;i++)
       if(comptes[i].montant>tst)
       {
            printf("CIN: %s\n",comptes[i].cin);
            printf("Nom: %s\n",comptes[i].nom);
            printf("Montant: %f\n\n",comptes[i].montant);
       }
}
void  descendant_a()
	{  float tst;
       printf("Donner un montant: ");
       scanf("%f",&tst);
//       ascendant();
tri();
       for(int i=nbr_cmp;i>=0;i--)
       if(comptes[i].montant<tst)
       {
            printf("CIN: %s\n",comptes[i].cin);
            printf("Nom: %s\n",comptes[i].nom);
            printf("Montant: %f\n\n",comptes[i].montant);
       }
}
void recherch_par_cin()
{
    char cin_r[7];
    printf("CIN: ");
    scanf("%s",cin_r);
    int v,r;

    for(int i=0;i<nbr_cmp;i++)
    {

        int tst =stricmp(comptes[i].cin,cin_r);
        if( tst == 0 )
    {
      v=1;
      r=i;
      break;
    }
    }
    if(v==1)
     printf("CIN: %s\n",comptes[r].cin);
     printf("Nom: %s\n",comptes[r].nom);
     printf("Prenom: %s\n",comptes[r].prenom);
     printf("Montant: %f\n",comptes[r].montant);
}
void Fidelisation()
{
    tri();
    for(int i=nbr_cmp-1;i>=nbr_cmp-3;i--)
    {
       comptes[i].montant +=((comptes[i].montant*1.3)/100);
        printf("***CIN:   %s    \n",comptes[i].cin) ;
        printf("***Nom:   %s    \n",comptes[i].nom) ;
        printf("***Prenom:   %s    \n",comptes[i].prenom) ;
        printf("***Montant apres la fedilisation:  %f\n\n",comptes[i].montant);
        printf("***************************************************\n") ;

    }
}


int main()

{
    int choix,nbr,test,i,indice,choix_affichage;
    char rep,cin_r[20],cin_d[20];
    int test_d=0;
do
{
 printf("\n  ----------------MENU---------------\n");
 printf("  1 ==>  Creer un compte\n\n");
 printf("  2 ==>  Creer plusieure comptes\n\n");
 printf("  3 ==>  Operations bancaires\n\n");
 printf("  4 ==>  Affichage\n\n");
 printf("  5 ==>  Fidelisation\n\n");
 printf("  6 ==>  Quitter l'application\n");
 printf(" ----------------------------------\n");
 scanf("%d",&choix);
switch (choix)
{
case 1: comptee();

 break;
 case 2:
 plusieurs_comptes();
break;

case 3:
printf("Tapper: (r) retrait / (d) depot \n");

scanf(" %c",&rep);
switch(rep)
{
    float montant_retait,montant_depo;

case 'r':
    test=0;
    do{

    printf("Donner la CIN du compte pour retrait: \n");
    scanf("%s",cin_r);

    for(int i=0;i<=nbr_cmp;i++)

    {
        int t=strcmp(cin_r,comptes[i].cin);
         if(t==0)
         {
             test=1;
         }
    }
         }while(test==0);
         if(test==1)
         {
    printf("Montant retrait: \n");
    scanf("%f",&montant_retait);
          printf("Le montant:  %f   ",comptes[i].montant);
             comptes[i].montant -=   montant_retait;
             printf("Le montant total:  %f   \n\n",comptes[i].montant);
         }



    break;

case 'd':

    do
    {
    printf("Donner la CIN du compte pour depo: ");
    scanf("%s",cin_d);

     for(int i=0;i<=nbr_cmp;i++)

    {
        int t=strcmp(cin_d,comptes[i].cin);
         if(t==0)
         {
             test_d=1;
             indice=i;
         }



    }

         }while(test_d==0);


         if(test_d==1)

         {
               printf("Montant depo: ");
                scanf("%f",&montant_depo);
             comptes[indice].montant   =  comptes[indice].montant   +  montant_depo;
               printf("Le montant total:  %f   \n\n",comptes[indice].montant);
         }
break;
 }
  break;
 case 4:
printf("\n Affichage:******************************************\n");
printf(" 1 =======>  Par ordre ascendant\n");
printf(" 2 =======>  Par ordre descendant\n");
printf(" 3 =======>  Les comptes bancaires ayant un montant superieur a un chiffre introduit\n");
printf(" 4 =======>  Les comptes bancaires ayant un montant superieur a un chiffre introduit\n");
printf(" 5 =======>  Recherche par CIN\n");
scanf("%d",&choix_affichage);
switch( choix_affichage )
{
  case 1:
      ascendant();
      break;
  case 2:
      descendant();
      break;
  case 3:
    ascendant_n();
    break;
  case 4:
    descendant_a();
    break;
  case 5:
      recherch_par_cin();
      break;
      }
      break;
 case 5:
      Fidelisation();
      break;
case 6:
      exit(0);
      break;

}

}while(choix>0 && choix<=6);
return 0;
}
