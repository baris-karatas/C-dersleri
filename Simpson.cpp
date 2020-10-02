#include <stdio.h>
#include <math.h>
float a,b,c,d;

float function(float x){
	float f_x=a*x*x*x+b*x*x+c*x+d;
	return f_x;
}
int find_root(float x_ilk){
	bool control1,control2;
	int j;
	int i,k;	
	float f_x,delta_x=0.5;
	float e=0.01;
	k=1;
	f_x=function(x_ilk);
	control1=false;
	control2=false;
//	printf(" ilk deðer %f",f_x);
	if(f_x<0&&f_x<function(x_ilk+delta_x)){
		j=1;
		control1=true;
	}else if(f_x>0&&f_x>function(x_ilk+delta_x)){
		j=2;
		control2=true;
	}else{
		j=0;
	}
	
	while(j&&fabs(delta_x)>e){
		f_x=function(x_ilk);
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
	
	
 	return x_ilk;	
}
float calculate(float x){
	int i,j;
	float tmp,f_x=0;
	for(i=4;i>0;i--){
		tmp=1;
		for(j=0;j<i;j++){
			tmp=tmp*x;
		}
		switch(i){
			case 4:tmp=tmp*a/i;
			break;
			case 3:tmp=tmp*b/i;
			break;
			case 2:tmp=tmp*c/i;
			break;
			case 1:tmp=tmp*d/i;
			break;
		}
		f_x+=tmp;
		
	}
	return f_x;
}







int main(){
	int n,i;
	float sum,x0,tmp,tmp1,x1,h0,h1,delta_x;
	printf("lutfen x^3 sayisinin katsiyisini giriniz");
	scanf("%f",&a);
	printf("lutfen x^2 sayisinin katsiyisini giriniz");
	scanf("%f",&b);
	printf("lutfen x^1 sayisinin katsiyisini giriniz");
	scanf("%f",&c);
	printf("lutfen sabit sayisinin katsiyisini giriniz");
	scanf("%f",&d);
	printf("lufen baslangýc x sayisini giriniz");
	scanf("%f",&x0);
	printf("lutfen bitis x saiyisini giriniz");
	scanf("%f",&x1);
	i=find_root(x0);
	tmp1=x1;
	if(function(i)<=0.01||function(i)>=-0.01){
	sum=fabs(calculate(i)-calculate(x0));
	sum+=fabs(calculate(tmp1)-calculate(i));
	
	}else{
		sum=calculate(x1)-calculate(x0);
		fabs(sum);
	}
	
	printf("secili kordinatlar arasýndaki alalan :%f",sum);
	
	
	
	
	
}
