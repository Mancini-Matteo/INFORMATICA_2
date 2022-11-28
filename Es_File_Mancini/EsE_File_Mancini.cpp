/** ****************************************************************************************
* \mainpage Esercizio E file di testo
*
* @brief Partendo da una parola in un file di testo viene cryptata con l'algoritmo di cesare
* File usati: "testo.txt", "crypt.txt", "decrypt.txt"
* 
* @author Matteo Mancini
* @date 28/11/22
* @version 1.0 <14/11/22> Creazione del programma
* @version 1.1 <15/11/22> Modifica funzioni
* @version 1.2 <17/11/22> Implementazione commenti
* @version 1.3 <28/11/22> Rimozione switch case
* @version 1.4 <28/11/22> Fine scrittura programma
*/

#include <stdio.h>
#include <stdlib.h>
#define cryptXYZ -23

void cesareCrypt(char [],char []);
void cesareDecrypt(char [],char []);

int main()
{
// Assegnazione ad ogni stringa il nome del file
	char nomeFile1[]={"testo.txt"};
	char nomeFile2[]={"crypt.txt"};
	char nomeFile3[]={"decrypt.txt"};
 
	cesareCrypt(nomeFile1,nomeFile2);
	cesareDecrypt(nomeFile2,nomeFile3);

}

void cesareCrypt(char nomeFile1[],char nomeFile2[])
{
	char c;					
	FILE *FileIN,*FileOUT; 		//dichiara i puntatori
	
	FileIN=fopen(nomeFile1,"r"); 		//apre il file iniziale in read (lettura)
	
	FileOUT=fopen(nomeFile2,"w");		//apre il file di uscita in write (scritura)
	
	if (FileIN != NULL && FileOUT != NULL)  //controlla se il puntatore è diverso da NULL 
	{
		while(!feof(FileIN))
		{
		
			c=fgetc(FileIN);			//c prende il carattere dal file iniziale
			
			if(c==' ')	
			{
				c=' ';
				fputc(c,FileOUT);
			}
			else
			{
				if((c>='A' && c<='Z') || (c>='a' && c<='z'))  //controllo se il carattere è presente nell'alfabeto
				{
							
					if(c=='X' || c=='Y' || c=='Z' || c=='x' || c=='y' || c=='z')  //controllo se il carattere è x,y,z MAIUSC o MINUSC
					{
						c-=cryptXYZ;			//sottrae a c 23 al valore del carattere del codice ascii
					}
					fputc(c,FileOUT);		//inserisce il carattere preso da c nel file destinazione	
				}
			}			
		}
	}

	else
	{
		printf("\nerrore in apertura file");
		printf("\n");
	}
		
	fclose(FileIN);			//chiude file iniziale
	fclose(FileOUT);		//chiude file destinazione
	
}

void cesareDecrypt(char nomeFile1[],char nomeFile2[])
{
	char c;
	FILE *FileIN,*FileOUT;
	
	FileIN=fopen(nomeFile1,"r");
	FileOUT=fopen(nomeFile2,"w");
	
	if (FileIN != NULL && FileOUT != NULL)
	{
		while(!feof(FileIN))
		{
		
			c=fgetc(FileIN);
			
			if(c==' ')
			{
				c=' ';
				fputc(c,FileOUT);
			}
			else
			{
				if((c>='A' && c<'Z') || (c>='a' && c<'z'))
				{
							
					if(c=='A' || c=='B' || c=='C' || c=='a' || c=='b' || c=='c')  //controlla se c uguale a x,y, e z maiuscole e minuscole
					{
						c+=26;			//aggiunge a c 26 nel codice ascii
					}
					
					c-=3;			//toglie a c 3 nel codice ascii

				
					fputc(c,FileOUT);		//inserisce il carattere preso da c nel file destinazione
				}
			}
		}
	}
	else
	{
		printf("\nerrore in apertura file");
		printf("\n");
	}
}
