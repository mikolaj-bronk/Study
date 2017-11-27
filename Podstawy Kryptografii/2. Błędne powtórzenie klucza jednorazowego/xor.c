//Mikolaj Bronk 234998 INF

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 64 

 
void przygotowanie(){
	
	
 FILE *klucz = fopen("key.txt", "r");    
 FILE *plain = fopen("plain.txt", "w");	
 FILE *orig = fopen("orig.txt", "r");    
 
 char znak, znak2;
 char klucz_tab[MAX];    
 int i = 0; 
 
 znak = fgetc(klucz);
 
 while(znak != EOF)
 {
 	klucz_tab[i] = znak;
 	znak = fgetc(klucz);
  	i++;
 }
 
  int dlugosc = strlen(klucz_tab);     
  int j=0;    
     
	while((znak2 = fgetc(orig)) != EOF){
		if(j != dlugosc){ fprintf(plain, "%c", znak2);  j++;   }
		if(j == dlugosc){ fprintf(plain, "\n"); j = 0; }
	}
      
  fclose(orig);
  fclose(plain);
}
 
 
void szyfrowanie_xor(){
 
  
  FILE *klucz = fopen("key.txt", "r");
  FILE *plain = fopen("plain.txt", "rb");
  FILE *crypto = fopen("crypto.txt", "wb");
  
           
 char znak, znak2;
 char klucz_tab[MAX];    
 int i = 0; 
 
 znak = fgetc(klucz);
 
 while(znak != EOF)
 {
 	klucz_tab[i] = znak;
 	znak = fgetc(klucz);
  	i++;
 }
       
  int j = 0, xor_op;
  int dlugosc =  strlen(klucz_tab);
 
 
	while((znak2 = fgetc(plain))!= EOF){
		if(j != i && znak2 != '\n')
	    {
	      xor_op = (int)znak2 ^ klucz_tab[j];
	      fprintf(crypto, "%d ", xor_op);
	      j++;
	    }
	    if(j == i) {fprintf(crypto, "\n"); j = 0;  }
  	}
  
	fclose(plain);
	fclose(crypto);
	
}
 
void kryptoanaliza(){
	
 
  FILE *klucz = fopen("key.txt", "r");
  FILE *decrypt = fopen("decrypt.txt", "wb");
  FILE *crypto = fopen("crypto.txt", "rb");
  
           
 char znak;
 char klucz_tab[MAX];    
 int i = 0; 
 
 znak = fgetc(klucz);
 
 while(znak != EOF)
 {
 	klucz_tab[i] = znak;
 	znak = fgetc(klucz);
  	i++;
 }
 
  char c, k;
  int j=0, dlugosc=strlen(klucz_tab);
  int tab_xor[i];
  char odszyfr[i];
  char spacje[i]; 
  
    
  for(j; j < i; j++)  spacje[j] = '*';
  j=0;
 
while((fscanf(crypto, "%d ", &tab_xor[j])) != EOF){
    if(j != i)
    {
      if(spacje[j] != '*') 
	  {
      	fprintf(decrypt, "%c", (tab_xor[j] ^ spacje[j]));
	  }
	  
       else{
       	
          if(tab_xor[j] >= 64)
          {
            odszyfr[j] = (char)( tab_xor[j] ^ 32);
            fprintf(decrypt,"%c", odszyfr[j]);
	            
				if(spacje[j] == '*') 
				{
					spacje[j]=odszyfr[j];
	            }
		  }
          
          else fprintf(decrypt," ");
 
        }
        j++;
    }
    if(j == i)
    {
      j = 0;
      fprintf(decrypt,"\n");
    }
  }
    
  printf("Znaleziony klucz: %s\n", odszyfr);
  
  
  fclose(decrypt);
  fclose(crypto);
}
 
 
 
 
int main(int argc, char *argv[]){
 
 
 if(strcmp(argv[1], "-p") == 0) przygotowanie();
 if(strcmp(argv[1], "-e") == 0) szyfrowanie_xor();
 if(strcmp(argv[1], "-k") == 0) kryptoanaliza(); 
        

   return 0;
 
}

