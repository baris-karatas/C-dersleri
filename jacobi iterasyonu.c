#include <stdio.h>
#include <math.h>
#include <stdbool.h>  
  int a,b,c,d,selector=0;
   
  float Turev(float x);
  float function_kare_1(float x){// x^2 yi yalnýz býrakma
  	float h_x=(b*x)+(c);
    h_x=h_x/(-a*x);
	return h_x;
  }
  float function_tek_2(float x){
  	float h_x=(a*x*x)+c;
  	h_x=h_x/(-b*x);
  	return h_x;
  }
  float function_sabit_3(float x){
  float h_x=(a*x*x*x+b*x*x)/-c;
  return h_x;	
  }
  float Turev(float x){
  	float x1,x2,y1,y2;
  	float turev;
  	x1=x;
  	x2=x+00.1;
  	y1=function_kare_1(x1);
  	y2=function_kare_1(x2);
  	turev=(y2-y1)/(x2-x1);
  	if( 1>fabs(turev)){
  		selector=1;
		return turev;
  		
    }
    y1=function_tek_2(x1);
  	y2=function_tek_2(x2);
  	turev=(y2-y1)/(x2-x1);
  	if(1>fabs(turev)){
  			selector=2;
			return turev;
	  }
	y1=function_sabit_3(x1);
  	y2=function_sabit_3(x2);
  	turev=(y2-y1)/(x2-x1);
  	if(1>fabs(turev)){
  		selector=3;
  		return turev;
	 }
	  
  } 
int main(){
	int i;
	bool j;
	float x0,turev;
	float x1;
	float e;
	printf("lutfen x^2 li tirimi giriniz");
	scanf("%d",&a);
	printf("lutfen x^1 li tirimi giriniz");
	scanf("%d",&b);
	printf("lutfen x^0 li tirimi giriniz");
	scanf("%d",&c);
	printf("lütfen x baslangic sayisi giriniz");
	scanf("%f",&x0);
	printf("lütfen bir epsilon degiri giriniz");
	scanf("%f",&e);
	turev=Turev(x0);
	switch(selector){
		case 0: printf("partition error ");
		break;
		case 1: x1=function_kare_1(x0);
		while(fabs(x1-x0)>e){
			x0=x1;
			x1=function_kare_1(x0);
		}
		break;
		case 2:x1=function_tek_2(x0);
			while(fabs(x1-x0)<e){
				x0=x1;
				x1=function_tek_2(x0);
			}
			break;
			case 3:x1=function_sabit_3(x0);
			while(fabs(x1-x0)<e){
				
				x0=x1;
				x1=function_sabit_3(x0);
			}
			
			
	}
	printf("denklemin koku %f",x1);
	
		
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
}   

