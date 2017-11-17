//Mikołaj Bronk 234998
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double potega(double x, int n){

  int i;
  double wynik = 1;
    for(i=0; i<n; i++)
      {
       wynik = (double) wynik * x;
      }

  return wynik;
}



double sumowanie_od_przodu(int n, int koniec, double x){

  double suma = 0;

  for(n;n<=koniec;n++){
    suma = suma + (potega(-1,n+1)/n) * potega(x,n);
  }

  return suma;
}

double sumowanie_od_tylu(int n, int koniec, double x){

  double suma = 0;

  for(n=koniec;n>0;n--){
    suma = suma + (potega(-1,n+1)/n) * potega(x,n);
  }

  return suma;
}


double modul(double liczba){

	if(liczba < 0) return liczba * (-1);
	else return liczba;
	
}


double blad_bezwzgledny(double x, double x0){
	
	return modul(x-x0);
	
}

double blad_wzgledny(double x, double x0){
	
	return blad_bezwzgledny(x,x0)/x*100;
	
}


double nastepny_wyraz_przod(int koniec, double x){

  double suma = x;
  double q = 1;
  int n;

  for(n=1;n<koniec;n++){
  	q = ((potega(x,n+1)/(n+1)) * (n/potega(x,n))); 
  		if(n%2!=0) q = q *(-1);	 
	  double wyraz = (potega(x,n)/n);	   
    suma = suma+= wyraz*q;
   }

  return suma;
}


double nastepny_wyraz_tyl(int koniec, double x){

  double suma = x;
  double q = 1;
  int n;

  for(n=koniec;n>0;n--){
  	q = ((potega(x,n+1)/(n+1)) * (n/potega(x,n))); 
  		if(n%2!=0) q = q *(-1);	 
	  double wyraz = (potega(x,n)/n);	   
    suma = suma+= wyraz*q;
   }

  return suma;
}







int main(){

  int n = 1;
  int koniec = 100;
  double x = -0.990;  
  FILE *fp = fopen("wyniki.csv", "w");
	
 fprintf(fp, "x;funkcja biblioteczna;sumowanie szeregu od tylu;sumowanie szeregu od przodu; sumowanie ciagu od przodu; sumowanie ciagu od tylu;blad bezwzgledny od przodu;blad bezwzgledny od tylu;blad bezwzgledny ciagu p.;blad bezwzgledny ciagu t.;blad wzgledny od przodu;blad wzgledny od tylu;blad wzgledny c. przod;blad wzgledny c. tyl\n");
  	

  for(x;x<1;x=x+0.005){
  	
fprintf(fp,"%.3f;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf;%.16lf\n",x,log(1+x),sumowanie_od_tylu(n,koniec,x),sumowanie_od_przodu(n,koniec,x),nastepny_wyraz_przod(koniec,x),nastepny_wyraz_tyl(koniec,x), blad_bezwzgledny(log(1+x),sumowanie_od_przodu(n,koniec,x)),blad_bezwzgledny(log(1+x),sumowanie_od_tylu(n,koniec,x)),blad_bezwzgledny(log(1+x),nastepny_wyraz_przod(koniec,x)),blad_bezwzgledny(log(1+x),nastepny_wyraz_tyl(koniec,x)),blad_wzgledny(log(1+x),sumowanie_od_przodu(n,koniec,x)),blad_wzgledny(log(1+x),sumowanie_od_tylu(n,koniec,x)),blad_wzgledny(log(1+x),nastepny_wyraz_przod(koniec,x)),blad_wzgledny(log(1+x),nastepny_wyraz_tyl(koniec,x)));  	

printf("dla x = : %lf\n", x);
printf("Funkcja biblioteczna:        %.2lf\n", log(1+x));
printf("Sumowanie od tylu:           %.16lf\n", sumowanie_od_tylu(n,koniec,x));
printf("Sumowanie od przodu:         %.16lf\n", sumowanie_od_przodu(n,koniec,x));
printf("Sumowanie ciagu od przodu:   %.16lf\n",  nastepny_wyraz_przod(koniec,x));
printf("Sumowanie ciagu od tylu:     %.16lf\n",  nastepny_wyraz_tyl(koniec,x));
printf("blad bezwzgledny od przodu:  %.16lf\n", blad_bezwzgledny(log(1+x),sumowanie_od_przodu(n,koniec,x)));

printf("blad bezwzgledny od tylu:    %.16lf\n", blad_bezwzgledny(log(1+x),sumowanie_od_tylu(n,koniec,x)));
printf("blad bezwzgledny ciagu p.:   %.16lf\n", blad_bezwzgledny(log(1+x),nastepny_wyraz_przod(koniec,x)));
printf("blad bezwzgledny ciagu t.:   %.16lf\n", blad_bezwzgledny(log(1+x),nastepny_wyraz_tyl(koniec,x)));
printf("blad wzgledny od przodu:     %.16lf\n", blad_wzgledny(log(1+x),sumowanie_od_przodu(n,koniec,x)));
printf("blad wzgledny od tylu:       %.16lf\n", blad_wzgledny(log(1+x),sumowanie_od_tylu(n,koniec,x)));
printf("blad wzgledny c. przod       %.16lf\n", blad_wzgledny(log(1+x),nastepny_wyraz_przod(koniec,x)));
printf("blad wzgledny c. tyl         %.16lf\n", blad_wzgledny(log(1+x),nastepny_wyraz_tyl(koniec,x)));
}

 fclose(fp);


return 0;
}
