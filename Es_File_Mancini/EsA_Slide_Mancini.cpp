// MATTEO MANCINI 4^H Es."a" slide 

#include <stdio.h>
#include <stdlib.h>

int main()
{
	char nomeFile1[] ={"nomi.txt"};
	char nomeFile2[]={"NOMI2.txt"};			
	char c;

	FILE *puntaFile1,*puntaFile2;						
	
	puntaFile1=fopen(nomeFile1,"r");			
	puntaFile2=fopen(nomeFile2,"w");				
	
	if(puntaFile1!=0 && puntaFile2!=0)					
	{
		while(!feof(puntaFile1))                   
		{
			c=fgetc(puntaFile1);					
			if(c>='a'&&c<='z')
				c-=32;
			fputc(c,puntaFile2);
		}
		fclose(puntaFile1);
		fclose(puntaFile2);
	}
	else
		printf("\nIL FILE NON PUO' ESSERE APERTO!");
}