#include <stdio.h>
#include <math.h>
float a,b,c,d;
float Function(float x){
	float h_x=(a*x*x*x)+(b*x*x)+c*x+d;
	return h_x;
}



float Turev(float x){
	float h_x=(a*x*x*x)+(b*x*x)+c*x+d;
	float x1,x2,y1,y2,turev;
	x1=x;
	y1=Function(x1);
	y2=Function(x2);
	turev=(y2-y1)/(x2-x1);
	return turev;	
}


int main(){
	int i;
	float x1,e,x0;
	printf("x^3 lü terimin katsayýsýý giriniz");
	scanf("%f",&a);
	printf("x^2 li terimin katsayisini giriniz");
	scanf("%f",&b);
	printf("x^1 li terimin katsayisini giriniz");
	scanf("%f",&c);
	printf("sabit terimin katsayisini giriniz");
	scanf("%f",&d);
	printf("lýtfen baslangic sayisini giriniz");
	scanf("%f",&x0);
	printf("lutfen epsilo sayisini giriniz");
	scanf("%f",&e);
	x1=x0-Function(x0)/Turev(x0);
	while(fabs(x1-x0)>e){
		x0=x1;
		x1=x0-Function(x0)/Turev(x0);
	}
	printf("root of funciton is %f",x1);
	 
	
}
