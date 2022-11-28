// MATTEO MANCINI 4^H Es."e" slide 

#include <stdio.h>

void crypt(char testo []);
void decrypt(char testo []);

int main()
{
	
	char nomeFile1[]={"text.txt"};
	char nomeFile2[]={"crypt.txt"};
	crypt(nomeFile1);
	decrypt(nomeFile2);
	
}


void crypt(char nomeFile1[])
{
	char s;
	FILE *puntaFile1,*puntaFile2;//puntatori ai file
	puntaFile1=fopen(testo,"r");//apertura primo file in modalità read
	puntaFile2=fopen("crypt.txt","a");//apertura file crypt in modalità append
	
	if(puntaFile1!=0 && puntaFile2!=0)
	{
		while(!feof(puntaFile1)) // ciclo che verifica la fine del file
		{
			s=fgetc(puntaFile1); 
		
			if(s>='a'&& s<='w'|| s>='A'&& s<='W')//controllo  carattere sia nell'alfabeto
			{
				s+=3;
				fputc(s,puntaFile2);	//mette il carattere nel nuovo file		
			}
			else 
			{
				switch (s)
				{
					case 88: s=97;
					break;
					
					case 89: s=98;
					break;
					
					case 90: s=99;
					break;
					
					case 120: s=65;
					break;
					
					case 121: s=66;
					break;
					
					case 122: s=67;
					break;					
				}
				fputc(s,p1);//mette il carattere nel nuovo file	
			}	
		}
	}
	else 
	{
		printf("\nIL FILE NON PUO' ESSERE APERTO!"); // errore apertura file
	}
	fclose(puntaFile1);
	fclose(puntaFile2);
}

void decrypt(char nomeFile1[])
{
	char s;
	FILE *puntaFile1,*puntaFile2;//puntatori ai file
	puntaFile1=fopen(testo,"r");//apertura primo file in modalità read
	puntaFile2=fopen("decrypt.txt","a");//apertura file crypt in modalità append
	
	if(puntaFile1!=0&&puntaFile2!=0)//controllo se i file si sono aperti senza problemi
	{
		while(!feof(puntaFile1))//ciclo fino a quando non finisce il file
		{
			s=fgetc(puntaFile1);  //prende ilo carattere
		
			if((s>='d'&& s<='z')||(s>='D'&& s<='Z')) //controllo  carattere sia nell'alfabeto
			{
				s-=3;
				fputc(s,puntaFile2);	//mette il carattere nel nuovo file		
			}
			else 
			{
				switch (s)
				{
					case 97: 
						s=88;
					break;
					
					case 98:
						s=89;
					break;
					
					case 99:
						s=90;
					break;
					
					case 65: 
						s=120;
					break;
					
					case 66: 
						s=121;
					break;
					
					case 67: 
						s=122;
					break;					
				}
				fputc(s,puntaFile2);//mette il carattere nel nuovo file	
			}	
		}
	}
	else 
	{
		printf("\nIL FILE NON PUO' ESSERE APERTO!"); // errore apertura file
	}
	fclose(puntaFile1);
	fclose(puntaFile2);
}
