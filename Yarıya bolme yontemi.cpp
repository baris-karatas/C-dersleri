#include <stdio.h>
#include <math.h>

float a,b,c,q;
float  function(float x);
float function(float x){
	float sonuc;
	sonuc= (q*x*x*x)+(a*x*x)+(b*x)+(c);
	return sonuc;
	
}

int main(){
	
	float x1,x2,d;
	float f_x1,f_x2,e,f_d;
	printf("lutfen x^3 li terimin katsayisini giriniz");
	scanf("%f",&q);
	printf("lutfen x^2 li terimin katsayisini giriniz");
	scanf("%f",&a);
	printf("lutfen x^1 li terimin katsayisini giriniz");
	scanf("%f",&b);
	printf("lutfen sabit terimin katsayisini giriniz");
	scanf("%f",&c);
	printf("lutfen epsilon hassasiyetini giriniz");
	scanf("%f",&e);
	printf("lutefen aralýgýn x_1 ini giriniz");
	scanf("%f",&x1);
	printf("lutefen aralýgýn x_2 ini giriniz");
	scanf("%f",&x2);
    f_x1=function(x1);
    f_x2=function(x2);
    if(f_x1*f_x2<0){
    		d=(a+b)/2;
    		f_d=function(d);	
    while(fabs(f_x1-f_x2)>e){
		
		d=(x1+x2)/2;
		f_x1=function(x1);
		f_x2=function(x2);
		f_d=function(d);
		if(f_x1*f_d<0){
			x2=d;	
		}
		 else if (f_x1==0){
			printf("denklemin koku %f",x1);
			break;
			
		} else if(f_x2==0){
			printf("denklemin koku %f",x2);
			break;
		}else{
			x1=d;
		}
		
		
		
    	
	}
	printf("denklemin koku %f",d);
    
    
	}else{
			printf("lutfen baska bir aralik belirleyiniz");

		}
	
    
    
    
    
	
	
	
	
	
	
}
