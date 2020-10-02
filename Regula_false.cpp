#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

float a,b,c,d;
float fonksiyon(float x){
	float sonuc;
	sonuc=(d*x*x*x)+(a*x*x)+(b*x)+(c);
	return sonuc;
}
int main(int argc, char *argv[]) {
	bool control1,control2;
	int j;
	int i,k;
	float x_a,x_b,x_c;
	float f_a,f_b,f_c;
	float e;
	printf("lutfen x^3 lu terimin katsayýsýný giriniz \n");
	scanf("%f",&d);
	printf("lutfen x^2 li terimin katsayisini giriniz \n");
	scanf("%f",&a);
	printf("lutfen x^1 li terimin katsayisini giriniz \n");
	scanf("%f",&b);
	printf("lutfen x^0 li terimin katsayisini giriniz\n");
	scanf("%f",&c);
	printf("lutfen ilk x degerini giriniz ");
	scanf("%f",&x_a);
	printf("lutfen  ikinci x i  giriniz ");
	scanf("%f",&x_b);
	printf("lutfen epsilon degerini giriniz");
	scanf("%f",&e);
	f_a=fonksiyon(x_a);
	f_b=fonksiyon(x_b);
	x_c=(x_b*fonksiyon(x_a))-(x_a*fonksiyon(x_b));
	x_c=x_c/(fonksiyon(x_a)-fonksiyon(x_b));
	if(f_a*fonksiyon(x_c)<0){
		k=1;
	}else if(f_b*fonksiyon(x_c)<0){
		k=2;
	}else{
		k=0;
	}
	while(k&&fabs(fonksiyon(x_c))>e){
	x_c=(x_b*fonksiyon(x_a))-(x_a*fonksiyon(x_b));
	x_c=x_c/(fonksiyon(x_a)-fonksiyon(x_b));
		if(k==1){
			x_b=x_c;
		}else if(k==2){
			x_a=x_c;
		}
	}
	if(k){
		printf("denkleminin kooku : %f",x_c);
	}else("HATA !!!");
	
	
	
	
	
}
