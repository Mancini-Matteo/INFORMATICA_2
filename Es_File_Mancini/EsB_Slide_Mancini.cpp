/** ****************************************************************************************
* \mainpage Esercizio B file di testo
*
* @brief Copiare le parole all' interno di un file in un secondo file
* File usati: "inTXT.txt", "outTXT.txt"
* 
* @author Matteo Mancini
* @date 28/11/22
* @version 1.0 <14/11/22> Creazione del programma
* @version 1.1 <17/11/22> Fine scrittura programma
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char nomeFile1[] ={"inTXT.txt"}; //Fle di partenza 
	char nomeFile2[]={"outTXT.txt"}; //File in cui copiare il testo di "inTXT.txt"
	int err;
	char c;
	
	FILE *puntaFile1,*puntaFile2; //Puntatori ai file
	
	puntaFile1=fopen(nomeFile1,"r"); //Apertura file "inTXT.txt" in modalità read
	puntaFile2=fopen(nomeFile2,"w"); //Apertura file "outTXT.txt" in modalità write
	
	if(puntaFile1!=0 && puntaFile2!=0) //Controllo se il file esiste ed è stato aperto correttamente
	{
		while(!feof(puntaFile1)) //Ciclo che verifica la fine del file
		{
			c=fgetc(puntaFile1); 
			fputc(c,puntaFile2); //Copio i caratteri del primo file nel secondo
		}
		fclose(puntaFile1); //Chiusura file
		fclose(puntaFile2);
	}
	else
		printf("\nIL FILE NON PUO' ESSERE APERTO!"); //Errore apertura file
}
