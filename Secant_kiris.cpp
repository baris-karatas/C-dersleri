#include <stdio.h>
#include <math.h>
float a,b,c,d;
float function(float x){
	float f_x= (d*x*x*x)+(a*x*x)+(b*x)+c;
	return f_x;
}
int main(){
	float x_a,x_b,x_c;
	float e;
	int k;
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
	if(function(x_a)*function(x_b)<0){
		x_c=x_a-((x_b-x_a)/(function(x_b)-function(x_a)))*function(x_a);
		if(function(x_c)*function(x_a)<0){
			k=1;
		}else if(function(x_c)*function(x_b)<0){
			k=2;
		}
	}else{
		k=0;
	}
	
	while(k){
		
		if(k==2){
			if(fabs(x_c-x_a)<e){
			break;
			}
			x_a=x_c;	
			
		}else if(k==1){
			if(fabs(x_c-x_b)<e){
				break;
			}
			x_b=x_c;
		}
		x_c=x_a-((x_b-x_a)/(function(x_b)-function(x_a)))*function(x_a);
		
		
		
	}
	if(k){
		printf(" denklemin yaklasik koku : %f",x_c);
	}else{
		printf("HATA!!!");
	}
	
	
	
}
