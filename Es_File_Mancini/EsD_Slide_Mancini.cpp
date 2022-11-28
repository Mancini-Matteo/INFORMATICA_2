/** ****************************************************************************************
* \mainpage Esercizio D file di testo
*
* @brief Partendo da un file di testo contenente numeri casuali a una cifra separare i pari dai dispari in due separati file
* File usati: "numeri.txt", "pari.txt", "dispari.txt"
* Dalla traccia il file deve iniziare e termiare con una cifra
*
* @author Matteo Mancini
* @date 28/11/22
* @version 1.0 <14/11/22> Creazione del programma
* @version 1.1 <21/11/22> Fine scrittura programma
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char nomeFile1[]={"numeri.txt"}; //File contenente numeri casuali a una cifra
	char nomeFile2[]={"pari.txt"}; //File vuoto dove andranno i numeri pari
	char nomeFile3[]={"dispari.txt"}; //File vuoto dove andranno i numeri dispari
	char s;

	FILE *puntaFile1,*puntaFile2,*puntaFile3; //Puntatori ai file
	
	puntaFile1=fopen(nomeFile1,"r"); //Apertura file "numeri.txt" in read
	puntaFile2=fopen(nomeFile2,"w"); //Apertura file "pari.txt" in write
	puntaFile3=fopen(nomeFile3,"w"); //Apertura file "dispari.txt" in write
	
	if(puntaFile1!=0)
	{
		do // ciclo che verifica la fine del file del file
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
		printf("\nIL FILE NON PUO' ESSERE APERTO!"); //Errore apertura file
}
