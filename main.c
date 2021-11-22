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
  int nbr_cmp=0;
  compte comptes[50];
    void comptee()
	{
	 compte cmp ;
	 int found = 0;
         do
            {
                found = 0;
                printf("entrer voter cin\n");
		        scanf("%s",&cmp.cin);
              for(int i = 0; i < nbr_cmp; i++)
              {
                if(strcmp(comptes[i].cin, cmp.cin)==0)
                {
                  printf("ce client il a deja un compte!!\n");
                  found=1;
                }
              }

            }while(found == 1);
		     printf("entrer voter nom\n");
		    scanf(" %s",&cmp.nom);
		    printf("entrer voter prenom\n");
		    scanf(" %s",&cmp.prenom);
		    printf("entrer voter mpntant\n");
		    scanf("%f",&cmp.montant);
		    comptes[nbr_cmp]=cmp;
		    nbr_cmp++;


	}


int main()

{
    int choix,nbr,test,i;
    char rep,cin_r[20],cin_d[20];
do
{
 printf("  ----------------menu---------------\n");
 printf("  1==>Introduire un compte\n\n");
 printf("  2==>Introduire plusieure  comptes\n\n");
 printf("  3==>Operations : Retrait/ Depot\n\n");
 printf("  4==>Affichage\n\n");
 printf("  5==>Fidelisation\n\n");
 printf("  6==>quitter l application\n");
  printf("  ----------------------------------\n");
 scanf("%d",&choix);
switch (choix)
{
 printf("-------------------------------------------------------\n");
case 1: comptee();

 break;
 case 2:
 printf("-------------------------------------------------------\n");
 printf("donner le nbr de compte");
 scanf("%d",&nbr);

int total = nbr_cmp + nbr;
for(int i=nbr_cmp;i<total;i++)
{
comptee();
printf("le montant =    %f\n",comptes[i].montant);
}


 printf("-------------------------------------------------------\n");
break;

case 3:
printf("tapper (r) pour retrait");
printf("tapper (d) depo");
scanf("%s",&rep);
switch(rep)
{
    float montant_retait,montant_depo;

case 'r':
    test=0;
    do{

    printf("donner la cin du compte pour retrait\n");
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
    printf("montant retrait:\n");
    scanf("%f",&montant_retait);
          printf(" le montant :  %f   ",comptes[i].montant);
             comptes[i].montant -=   montant_retait;
             printf(" le montant total  :  %f   ",comptes[i].montant);
         }



    break;
case 'd':
    printf("donner la cin du compte pour depo");
    scanf("%s",cin_d);
    printf("montant depo:");
    scanf("%f",&montant_depo);
    for(int i=0;i<=nbr_cmp;i++)
    {
         if(strcmp(comptes[i].cin, cin_d)==0)
         {
             comptes[i].montant   =  comptes[i].montant   +  montant_depo;
         }
    }
    break;






break;

printf("-------------------------------");
case 4:
    break;
default:
printf("-------------------------------");
}
}














}while(choix>0 && choix<=6);







	return 0;
}
