#include <stdio.h>
#include <math.h>
float a,b,c,d;

float function(float x){
	float f_x=a*x*x*x+b*x*x+c*x+d;
	return f_x;
}
int find_root(float x_ilk,float x_son){	//bu bölümde seçili aralýkta kök olup olmadýðý kontrol ediliyor
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
		if(x_ilk>x_son){
			j=0;
		}
	
	}
	if(j){
		printf("dentlemin koku : %f",x_ilk);
	}
	
	
 	return x_ilk;	
}
float addition(int n,float x0,float tmp,float x1,float h0,float h1,float delta_x){
	int i;
	tmp=0;
	delta_x=(x1-x0)/n;
	h0=function(x0);
	h1=function(x0+delta_x);
	
	for(i=0;i<n;i++){
	   h0=function(x0);
	   h1=function(x0+delta_x);
	   x0=x0+delta_x;
	   tmp=tmp+fabs(((h0+h1)/2)*delta_x);
	   
	}
	return tmp;
}

int main(){
	int n,i;
	float sum,x0,tmp,tmp1,x1,h0,h1,delta_x;
	printf("lutfen x^3 katsayisini giriniz");
	scanf("%f",&a);
	printf("lutfen x^2 katsayisini giriniz");
	scanf("%f",&b);
	printf("lutfen x^1 katsayisini giriniz");
	scanf("%f",&c);
	printf("lutfen sabit terimi girinz");
	scanf("%f",&d);
	printf("lufen baslangýc x sayisini giriniz");
	scanf("%f",&x0);
	printf("lutfen bitis x saiyisini giriniz");
	scanf("%f",&x1);
	printf("lutfen kac parcaya bolmek istediginizi giriniz");
	scanf("%d",&n);
	i=find_root(x0,x1);
	tmp1=x1;
	if(function(i)<=0.01||function(i)>=-0.01){
	  x1=i;
	  sum=addition(n,x0,tmp,x1,h0,h1,delta_x);
	  x0=i;
	  x1=tmp1;	
	  sum+=addition(n,x0,tmp,x1,h0,h1,delta_x);
	}else{
	sum=addition(n,x0,tmp,x1,h0,h1,delta_x);
	}
	
	printf("secili kordinatlar arasýndaki alalan :%f",sum);
	
}
