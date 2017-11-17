//Miko³aj Bronk, 234998
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char alfabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};


int alphabet(char x)
{
	if(x >= 97 && x <= 122){
		return x - 97;
	}
	if( x >= 65 && x <= 90){
		return x - 65;
	}	
	
}


int odwrotna(int a){
	
  int b,u,w,x,z,q;
  b = 26;
  u = 1; w = a;
  x = 0; z = b;
  while(w)
  {
    if(w < z)
    {
    	q = u; u = x; x = q;
		q = w; w = z; z = q;
    }
    	q = w / z;
    	u -= q * x;
    	w -= q * z;
  }
	  if(z == 1)
	  {
	    if(x < 0) x += b;
		return x;	
	  }

}



int poprawnosc(int a, int b){
	int flaga = 0;
	
	if( b < 0 || b > 25) flaga = 1;
	if( a < 0 || a > 25) flaga = 1;
	if( a % 2 == 0) flaga = 1;
	if( a == 13) flaga = 1;
	
	if(flaga == 0)	return 0;
	else return 1;
}



void afin_szyfr(){	
 
 int a, b;
  
FILE *klucz = fopen("key.txt", "r"); 
 fscanf(klucz, "%d", &a);	
 fscanf(klucz, "%d", &b);
 
	 if(poprawnosc(a,b) == 0)
		 {
		 	int dlugosc = 0;		 	
		 	char c;
		 			 	
			FILE *odczyt_tekst = fopen("plain.txt", "r");
			FILE *zakoduj_tekst = fopen("crypto.txt", "w");
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
				
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	int i = 0;
		 	for(i; i<dlugosc; i++){
		 		char szyfr_litera = (a * alphabet(szyfr[i]) + b ) % 26;
		 		if(szyfr_litera < 0) szyfr_litera+=26;
		 		fprintf(zakoduj_tekst, "%c", alfabet[szyfr_litera]);		 	
			 }			
			 fclose(odczyt_tekst);
			 fclose(zakoduj_tekst);	 		 	
		 	
		 }	
	 else
		 {
		 	printf("klucz jest niepoprawny\n");
		 }	

fclose(klucz);	
}


void afin_deszyfr(){	
 
 int a, b;
  
FILE *klucz = fopen("key.txt", "r"); 
 fscanf(klucz, "%d", &a);	
 fscanf(klucz, "%d", &b);
 
	 if(poprawnosc(a,b) == 0)
		 {
		 	int dlugosc = 0;		 	
		 	char c;
		 			 	
			FILE *odczyt_tekst = fopen("crypto.txt", "r");
			FILE *zakoduj_tekst = fopen("decrypt.txt", "w");
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
				
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	int i = 0;
		 	for(i; i<dlugosc; i++){
		 		int szyfr_litera = ( odwrotna(a) * (alphabet(szyfr[i]) - b) ) %26;
		 		if(szyfr_litera < 0) szyfr_litera+=26;
		 		fprintf(zakoduj_tekst, "%c", alfabet[szyfr_litera]);
				 
			 }			
			 fclose(odczyt_tekst);
			 fclose(zakoduj_tekst);	 		 	
		 	
		 }	
	 else
		 {
		 	printf("klucz jest niepoprawny\n");
		 }	

fclose(klucz);	
}



void cezar_szyfr(){	
 
 int a, b;
  
FILE *klucz = fopen("key.txt", "r"); 
 fscanf(klucz, "%d", &a);	
 fscanf(klucz, "%d", &b);
 a = 1;
 
	 if(poprawnosc(a,b) == 0)
		 {
		 	int dlugosc = 0;		 	
		 	char c;
		 			 	
			FILE *odczyt_tekst = fopen("plain.txt", "r");
			FILE *zakoduj_tekst = fopen("crypto.txt", "w");
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
				
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	int i = 0;
		 	for(i; i<dlugosc; i++){
		 		char szyfr_litera = (a * alphabet(szyfr[i]) + b ) % 26;
		 		if(szyfr_litera < 0) szyfr_litera+=26;
		 		fprintf(zakoduj_tekst, "%c", alfabet[szyfr_litera]);		 	
			 }			
			 fclose(odczyt_tekst);
			 fclose(zakoduj_tekst);	 		 	
		 	
		 }	
	 else
		 {
		 	printf("klucz jest niepoprawny\n");
		 }	

fclose(klucz);	
}


void cezar_deszyfr(){	
 
 int a, b;
  
FILE *klucz = fopen("key.txt", "r"); 
 fscanf(klucz, "%d", &a);	
 fscanf(klucz, "%d", &b);
 
 a = 1;
 
	 if(poprawnosc(a,b) == 0)
		 {
		 	int dlugosc = 0;		 	
		 	char c;
		 			 	
			FILE *odczyt_tekst = fopen("crypto.txt", "r");
			FILE *zakoduj_tekst = fopen("decrypt.txt", "w");
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
				
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	int i = 0;
		 	for(i; i<dlugosc; i++){
		 		int szyfr_litera = ( odwrotna(a) * (alphabet(szyfr[i]) - b) ) %26;
		 		if(szyfr_litera < 0) szyfr_litera+=26;
		 		fprintf(zakoduj_tekst, "%c", alfabet[szyfr_litera]);
				 
			 }			
			 fclose(odczyt_tekst);
			 fclose(zakoduj_tekst);	 		 	
		 	
		 }	
	 else
		 {
		 	printf("klucz jest niepoprawny\n");
		 }	

fclose(klucz);	
}



void cezar_kryptogram(){	
 			int b = 0;
 			int a = 1;
		 	int dlugosc = 0;		 	
		 	char c;
		 			 	
			FILE *odczyt_tekst = fopen("crypto.txt", "r");
			FILE *zakoduj_tekst = fopen("kryptoanaliza.txt", "w");
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
				
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	int i = 0;
		 	for(b; b<26; b++)
				 {
			 		fprintf(zakoduj_tekst, "klucz = %d  ", b);
			 		printf("klucz = %d  ", b);
			 	
				 for(i=0; i<dlugosc; i++)
				    {		 		
				 		int szyfr_litera = ( odwrotna(a) * (alphabet(szyfr[i]) - b) ) %26;
				 		if(szyfr_litera < 0) szyfr_litera+=26;
				 		fprintf(zakoduj_tekst, "%c", alfabet[szyfr_litera]);
				 		printf("%c", alfabet[szyfr_litera]);
				 		
					}
					fprintf(zakoduj_tekst, "\n");
					printf("\n");
					
				 }			
			 fclose(odczyt_tekst);
			 fclose(zakoduj_tekst);	 	
			printf("\nZapis dostepny w pliku kryptoanaliza.txt\n\n");	 	 	
	
}


void cezar_jawny(){	
 			int b = 0;
 			int a = 1;
		 	int dlugosc = 0;		 	
		 	char c;
		 	
		 			 	
			FILE *odczyt_tekst = fopen("extra.txt", "r");			
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
				dlugosc/=2;
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
			char pomoc[dlugosc];
				
			fscanf(odczyt_tekst, "%s", pomoc);
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	
		 	
		 	for(a = 0; a<26; a++){
		 	
		 			int kod = (alphabet(pomoc[0]) + a) % 26;					 			
		 				if(kod == alphabet(szyfr[0]))
						 {
		 					printf("kod to %d\n", a);
						 }
		 	
			 }
		 	
			fclose(odczyt_tekst);	 						 	 	
	
}


void afin_kryptogram(){	
 			int b = 0, iteracja = 1;
 			int a;
 			int t_a[12] = {1,3,5,7,9,11,15,17,19,21,23,25};
		 	int dlugosc = 0;
			 char c;		 	
		    
		 			 	
			FILE *odczyt_tekst = fopen("crypto.txt", "r");
			FILE *zakoduj_tekst = fopen("kryptoanaliza.txt", "w");
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
				
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	int i = 0;
		 	for(b; b<26; b++)
				 {	
				 		 		
			 	for(a=0;a<12;a++)
					 {
					 fprintf(zakoduj_tekst, "%d.\ta = %d\tb = %d\t",iteracja, t_a[a], b);
					  printf("%d.\ta = %d\tb = %d\t",iteracja, t_a[a], b);
					 for(i=0; i<dlugosc; i++)
					    {		 		
					 		int szyfr_litera = ( odwrotna(t_a[a]) * (alphabet(szyfr[i]) - b) ) %26;
					 		if(szyfr_litera < 0) szyfr_litera+=26;
					 		fprintf(zakoduj_tekst, "%c", alfabet[szyfr_litera]);
					 		printf("%c", alfabet[szyfr_litera]);
					 		
						}
						fprintf(zakoduj_tekst, "\n");
						printf("\n");
						iteracja ++;
					 }
					
				 }			
			 fclose(odczyt_tekst);
			 fclose(zakoduj_tekst);	 	
			 printf("\nZapis dostepny w pliku kryptoanaliza.txt\n\n");	 	
	
}

void afin_jawny(){	
 			int b = 0, iteracja = 1;
 			int a;
 			int t_a[12] = {1,3,5,7,9,11,15,17,19,21,23,25};
		 	int dlugosc = 0;
			 char c;		 	
		    
		 			 	
			FILE *odczyt_tekst = fopen("extra.txt", "r");			
			
			while ((c = fgetc(odczyt_tekst)) != EOF) 
				{
				dlugosc++;
				}
				dlugosc/=2;
			
			rewind(odczyt_tekst);
			char szyfr[dlugosc];
			char jawny[dlugosc];
			char pom[dlugosc];
			
			fscanf(odczyt_tekst, "%s", jawny);	
		 	fscanf(odczyt_tekst, "%s", szyfr);
		 	
		 	int i = 0;
		 	for(b; b<26; b++)
				 {	
				 		 		
			 	for(a=0;a<12;a++)
					 {
					 	
					 for(i=0; i<dlugosc; i++)
					    {		 		
					 		int szyfr_litera = ( odwrotna(t_a[a]) * (alphabet(szyfr[i]) - b) ) %26;
					 		if(szyfr_litera < 0) szyfr_litera+=26;
					 		
					 		pom[i] = alfabet[szyfr_litera];					 	
					 		
						}
						
						if(strcmp(pom,jawny)==0){				
											
						printf("\nkod to = %d, %d", t_a[a], b);
						}
				
					 }
					
				 }			
			 fclose(odczyt_tekst);
			 printf("\nZapis dostepny w pliku kryptoanaliza.txt\n\n");	 	
	
}


int main(){

int wyjscie = 0;
char znak[2];

while(wyjscie != 1)
	{
	
	printf("Podaj co chcesz zrobic\n c (szyfr Cezara), \n a (szyfr afiniczny),\n\n +\n\n e (szyfrowanie),\n d (odszyfrowywanie),\n j (kryptoanaliza z tekstem jawnym),\n k (kryptoanaliza wylacznie w oparciu o kryptogram)\n /np. \"ce\" uruchomi cezar - szyfrowanie\n");
	scanf("%s", znak);
	if(strcmp(znak, "ae") == 0) afin_szyfr(); 
	if(strcmp(znak, "ad") == 0) afin_deszyfr(); 
	if(strcmp(znak, "ce") == 0) cezar_szyfr(); 
	if(strcmp(znak, "cd") == 0) cezar_deszyfr(); 
	if(strcmp(znak, "ck") == 0) cezar_kryptogram(); 
	if(strcmp(znak, "ak") == 0) afin_kryptogram(); 
	if(strcmp(znak, "cj") == 0) cezar_jawny(); 
	if(strcmp(znak, "aj") == 0) afin_jawny(); 
	
	}


  return 0;
}

