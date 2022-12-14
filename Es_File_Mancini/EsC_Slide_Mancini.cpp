/** ****************************************************************************************
* \mainpage Esercizio C file di testo                          
*
* @brief partendo da un file contenente parole spazi e "a capo" ricevere in output 
* quanti caratteri, spazi e "a capo" sono presenti nel file di partenza
*File usati: "parole_casuali.txt"
* 
* @author Matteo Mancini
* @date 28/11/22
* @version 1.0 <14/11/22> Creazione del programma
* @version 1.1 <17/11/22> Fine scrittura programma
*/

#include<stdio.h>
#include<stdlib.h>

int main()
{
	char nomeFile[]={"parole_casuali.txt"}; //File di partenza contenente parole casuali, spazi e "a capo"
	char s;
	int cont1=0,cont2=0,cont3=1; //Dichiarazione contatori
	
	FILE *puntaFile; //Puntatore file
	
	puntaFile=fopen(nomeFile,"r"); //Apertura file"parole_casuali.txt" in modalità read
	
	if(puntaFile!=0)
	{
		while(!feof(puntaFile)) //Ciclo che verifica la fine del file
		{
			s=fgetc(puntaFile); 	
			if(s!=' ' && s!='\0' && s!='\n') //Controlla è diverso da spazio e a capo
			{
				cont1++; //contatore caratteri
			}
			
			if(s==' ')
			{
				cont2+=2; //contatore parole
			}
			
			if(s=='\n')
			{
				cont3++; //contatore "a capo"
			}	
		}
		printf("Caratteri:%d, Parole:%d, Righe:%d",cont1,cont2,cont3);
	}
	else 
		printf("\nIL FILE NON PUO' ESSERE APERTO!"); //Errore apertura file
	
	fclose(puntaFile); //Chiusura file
}
