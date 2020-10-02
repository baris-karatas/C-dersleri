#include <stdio.h>
float a,b,c,d;
float function(float x){
	float f_x;
	f_x=a*x*x*x+b*x*x+c*x+d;
	return f_x;
}
float Turev_ileri(float x,float h){
	float x1,y0,y1,turev;
	x1=x+h;
	y0=function(x);
	y1=function(x1);
	turev=(y1-y0)/(x1-x);
	return turev;
}
float Turev_geri(float x1,float h){
	float x,y1,y0,turev;
	x=x1-h;
	y1=(function(x1));
	y0=function(x);
	turev=(y1-y0)/(x1-x);
	return turev;
}

int main(){
	float h,x;
printf("lutfen x^3 sayisinin katsiyisini giriniz");
	scanf("%f",&a);
	printf("lutfen x^2 sayisinin katsiyisini giriniz");
	scanf("%f",&b);
	printf("lutfen x^1 sayisinin katsiyisini giriniz");
	scanf("%f",&c);
	printf("lutfen sabit sayisinin katsiyisini giriniz");
	scanf("%f",&d);
	printf("lufen hassasiyeti  sayisini giriniz");
	scanf("%f",&h);
	printf("lutfen turev alýnacak  x saiyisini giriniz");
	scanf("%f",&x);
	printf("ileri turev : %f",Turev_ileri(x,h));
	printf("geri turev : %f",Turev_geri(x,h));
	
}

