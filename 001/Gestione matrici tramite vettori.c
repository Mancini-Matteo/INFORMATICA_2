/**************************************
 *		Matteo Mancini 4H 15/09/22	  *
 *	Gestione matrici tramite vettori  *
 **************************************/
 
//LIBRERIE e COSTANTI
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
 #include <limits.h>	

#define R 10
#define C 10
#define N 10

//DICHIARAZIONE FUNZIONI

void menu();//stampa menu
void caricaVettoreM(int [] ,int );//carica vettore manualmente
void caricaVettoreR(int [],int );//carica vettore random
void caricaMatriceM(int [][C],int );//carica matrice manualmente
void caricaMatriceR(int [][C],int );//carica matrice random
void stampaVettore(int [],int );//stampa vettore
void stampaMatrice(int [][C],int );//stampa matrice
void ordinaBubbleVett(int [], int );//ordinamento bubble sort vettore
void ordinaBubbleRiga(int [][C],int );//ordinamento bubble sort della riga di una matrice
int ricercaVett(int [],int);//ricerca con sentinella vettore
int ricercaMat(int [][C],int , int );//ricerca con sentinella della riga di una matrice
int MaxMat(int [][C], int, int);//numero piu' grande della matrice
int MinMat(int [][C], int, int);//numero piu' piccolo della matrice
void StampaColonna(int [][C], int, int); //stampa una colonna della matrice

//MAIN
int main()
{
	int v[N],m[R][C],s1,s2,s3,s4,s5,f1,f2,f3,f4,s6;
	
	srand(time(NULL));
	menu();
	
	do
	{
		printf("\nInserisci un numero: ");
		scanf("%d",&s1);
		switch(s1)
		{
			case 0:
				printf("\n PROGRAMMA TERMINATO");	
			break;
			
			case 1:
				caricaVettoreR(v,N);	
			break;
			
			case 2:
				caricaVettoreM(v,N);	
			break;
			
			case 3:
				caricaMatriceR(m,R);
			break;
			
			case 4:
				caricaMatriceM(m,R);
			break;
			
			case 5:
				printf("Vettore:");
				stampaVettore(v,N);
			break;
			
			case 6:
				printf("Matrice:\n");
				stampaMatrice(m,R);
			break;
			
			case 7:
				ordinaBubbleVett(v,N);	
			break;
			
			case 8:
				printf("Inserisci la riga della matrice da ordinare: ");
				scanf("%d",&s2);
				ordinaBubbleRiga(m,s2);		
			break;
			
			case 9:
				printf("Inserisci il numero da cercare nel vettore: ");
				scanf("%d",&s3);
				f1=ricercaVett(v,s3);	
				if(f1==N)
					printf("Numero non trovato!\n");
					else
					printf("\nIl numero %d e' in posizione: %d\n",s3,f1+=1);	
			break;
			
			case 10:
				printf("Inserisci il numero della riga: ");
				scanf("%d",&s4);
				printf("Inserisci il numero da cercare nella riga %d: ",s4);
				scanf("%d",&s5);
				//f2=ricercaMat(m,s4,s5); NON FUNZIONA
				printf("Il numero e' in posizione : %d",f2);
			break;
			
			case 11:
				f3=MaxMat(m,R,C);
				printf("Il numero piu grande della matrice e' %d",f3);
			break;
			
			case 12:
				f4=MinMat(m,R,C);
				printf("Il numero piu piccolo della matrice e' %d",f4);
			break;
			
			case 13:
				printf("Inserisci la colonna che vuoi stampare: "); 
        		scanf("%d", &s6); 
        		StampaColonna(m,R,s6);	
			break;
			
			default:
				printf("INSERISCI UN NUMERO VALIDO");
		}
	} while(s1!=0);

	return 0;
}

//FUNZIONI 

void menu()
{
	printf("0: TERMINA PROGRAMMA\n");
	printf("1: Carica vettore random\n");
	printf("2: Carica vettore manualmente\n");
	printf("3: Carica matrice random\n");
	printf("4: Carica matrice manualmente\n");	
	printf("5: Stampa vettore\n");	
	printf("6: Stampa matrice\n");
	printf("7: Ordina il vettore\n");
	printf("8: Ordina una riga della matrice a scelta\n");
	printf("9: Cerca un numero nel vettore\n");
	printf("10: Cerca un numero nella riga della matrice a scelta\n");
	printf("11: Cerca il numero piu grande della matrice\n");
	printf("12: Cerca il numero piu piccolo della matrice\n");
	printf("13: Stampa colonna a scelta della matrice\n");
}

void caricaVettoreM( int v[],int x)
{
	int i,a;
	for(i=0;i<x;i++)
	{ 
		scanf("%d", &a);
		v[i]=a;
	}
}

void caricaVettoreR(int v[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{ 
		v[i]=rand()%100;
	}
}

void caricaMatriceM(int m[][C],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		caricaVettoreM(m[i],N);	
	}
}

void caricaMatriceR(int m[][C],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		caricaVettoreR(m[i],N);	
	}
}

void stampaVettore(int v[],int x)
{
	int i;
	for(i=0;i<x;i++)
	{
		printf(" %d,",v[i]);	
	}
	printf("\n");
}

void stampaMatrice(int m[][C],int x)
{
	int i;
	for(i=0;i<N;i++)
	{
		stampaVettore(m[i],N);	
	}
}

void ordinaBubbleVett(int v[],int x)
{
	int i, temp, scambio;
	do
	{
		scambio=0;
	
		for(i=0; i<N-1; i++)
		{
			if(v[i]>v[i+1])
			{
				temp=v[i];
				v[i]=v[i+1];
				v[i+1]=temp;
				scambio=1;
			}
		}
	}while(scambio==1);
	
}

void ordinaBubbleRiga(int m[][C],int x)
{
	int i;
	
	for(i=0;i<C;i++)
	{
		ordinaBubbleVett(m[i],x);
	}
	
	
}

int ricercaVett(int v[],int x)
{
	int i=0;
	while(v[i]!=x && i<N)
	{
		i++;
	}
	return i;
}

/*  cerca il numero num nella riga rig della matrice m 
	
	scanf("%d",&s4); s4=rig
	scanf("%d",&s5); s5=num
	f2=ricercaMat(m,s4,s5); m=mat

int ricercaMat(int m[], int rig, int num) NON FUNZIONA
{
	int r;
	
	r=ricercaVett(m[rig],num);
		
	return r;	
}
*/
int MaxMat(int m[][C],int r,int c)
{
	int i,j,min=INT_MIN; 
	 
    for(i=0;i<r;i++) 
    {
		for(j=0;j<c;j++) 
         {         
        	if(m[i][j]>min) 
            { 
            	min=m[i][j];
            }   
         }
	}
	
	return min; 
}

int MinMat(int m[][C],int r,int c)
{
	int i,j,max=INT_MAX; 
	
    for(i =0;i<r;i++) 
    {
    	for(j =0;j<c;j++) 
        {         
            if(m[i][j]<max) 
            { 
                max=m[i][j]; 
        	}            
    	}
	}
	
	return max; 	
}

void StampaColonna(int m[][C], int r, int x) 
 { 
    int i; 
    
	for(i=0;i<r;i++) 
    { 
    	printf("%d\n", m[i][x]); 
    } 
    
 }
