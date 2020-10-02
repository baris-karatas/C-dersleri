#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define SIZE 100
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

typedef enum {true,false} bool;
float a,b,c;
float fonksiyon(float x){
	float sonuc;
	sonuc=(a*x*x)+(b*x)+(c);
	return sonuc;
}

int main(int argc, char *argv[]) {
	bool control1,control2;
	int j;
	int i,k;
	float x_ilk,delta_x;
	float f_x;
	float e;
	k=1;
	printf("lutfen x^2 li terimin katsayisini giriniz \n");
	scanf("%f",&a);
	printf("lutfen x^1 li terimin katsayisini giriniz \n");
	scanf("%f",&b);
	printf("lutfen x^0 li terimin katsayisini giriniz\n");
	scanf("%f",&c);
	printf("lutfen ilk x degerini giriniz ");
	scanf("%f",&x_ilk);
	printf("lutfen  delta_x i kiriniz ");
	scanf("%f",&delta_x);
	printf("lutfen epsilon degerini giriniz");
	scanf("%f",&e);
	f_x=fonksiyon(x_ilk);
	control1=false;
	control2=false;
//	printf(" ilk deðer %f",f_x);
	if(f_x<0&&f_x<fonksiyon(x_ilk+delta_x)){
		j=1;
		control1=true;
	}else if(f_x>0&&f_x>fonksiyon(x_ilk+delta_x)){
		j=2;
		control2=true;
	}else{
		j=0;
	}
	
	while(j&&fabs(delta_x)>e){
		f_x=fonksiyon(x_ilk);
		if(f_x==0){
			
			break;
		}
		if(f_x<=0&&j==1){
			x_ilk+=delta_x;
		}else if(f_x>0&&control1==true){
			x_ilk-=delta_x;
			delta_x=delta_x/2;
		}
		if(f_x>=0&&j==2){
		  x_ilk+=delta_x;
		}else if(f_x<=0&&control2==true){
			x_ilk-=delta_x;
			delta_x=delta_x/2;
		}
	
	}
	if(j){
		printf("dentlemin koku : %f",x_ilk);
	}
	
	
	return 0;
}
