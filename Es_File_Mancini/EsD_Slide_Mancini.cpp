/*****************
* Matteo Mancini *
*      4^H       *
*    28/11/22    *
*   Esercizio D  *
*   Versione 1.3 *
******************/

// dalla traccia il file deve iniziare e termiare con una cifra

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char nomeFile1[]={"numeri.txt"};
	char nomeFile2[]={"pari.txt"};
	char nomeFile3[]={"dispari.txt"};
	char s;

	FILE *puntaFile1,*puntaFile2,*puntaFile3;
	
	puntaFile1=fopen(nomeFile1,"r"); // apertura file "numeri.txt" in read
	puntaFile2=fopen(nomeFile2,"w");
	puntaFile3=fopen(nomeFile3,"w");
	
	if(puntaFile1!=0)
	{
		do // ciclo che verifica la fine del file
		{
			s=fgetc(puntaFile1); 	
			if(s%2==0)
			{
				fputc(s,puntaFile2); // copia numero pari in "numeri.txt"
				fputc(' ',puntaFile2);	
			}	
			else
			{
				fputc(s,puntaFile3); // copia numero dispari in "numeri.txt"
				fputc(' ',puntaFile3);	
			}
				
			s=fgetc(puntaFile1); // lettura spazio		
		}while(!feof(puntaFile1));
		
		fclose(puntaFile1); // chiusura file "numeri.txt"
		fclose(puntaFile2); // chiusura file "pari.txt"
		fclose(puntaFile3); // chiusura file "dispari.txt"
	}
	else 
		printf("\nIL FILE NON PUO' ESSERE APERTO!");
}
