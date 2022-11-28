/** ****************************************************************************************
* \mainpage Esercizio A file di testo                          
*
* @brief trasformare dei nomi scritti in minuscolo in maiuscolo
* File usati: "nomi.txt", "NOMI2.txt"
* 
* @author Matteo Mancini
* @date 28/11/22
* @version 1.0 <14/11/22> Creazione del programma
* @version 1.1 <17/11/22> Fine scrittura programma
*/

#include <stdio.h>
#include <stdlib.h>
#define MAIUSC -32

int main()
{
	char nomeFile1[] ={"nomi.txt"}; //File di partenza
	char nomeFile2[]={"NOMI2.txt"}; //File da creare			
	char c;

	FILE *puntaFile1,*puntaFile2; //Puntatori ai file					
	
	puntaFile1=fopen(nomeFile1,"r"); //Apertura "nomi.txt" in modalità read			
	puntaFile2=fopen(nomeFile2,"w"); //Apertura "NOMI2.txt" in modalità write				
	
	if(puntaFile1!=0 && puntaFile2!=0) //Controllo se il file esiste ed è stato aperto correttamente					
	{
		while(!feof(puntaFile1)) //Ciclo che verifica quando il file finisce                   
		{
			c=fgetc(puntaFile1);					
			if(c>='a'&&c<='z') //Controllo se le lettere nel file sono minuscole
				c-=MAIUSC; //Sottraggo 32 al numero del codice asii corrispondente alla lettera minuscola per trasformarla in maiuscola
			fputc(c,puntaFile2); //Scrittura lettere in maiuscoilo nel fil "NOMI2.txt"
		}
		fclose(puntaFile1); //Chiusura file "nomi.txt"
		fclose(puntaFile2); //Chiusura file "NOMI2.txt"
	}
	else
		printf("\nIL FILE NON PUO' ESSERE APERTO!"); //Errore apertura file 
}
