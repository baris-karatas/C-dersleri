#include <stdio.h>
float Enter(float array_x[10],float array_y[10],float x,int n){
	int i,j,k;
	float tmp,f_x;
	f_x=0;

		for(j=0;j<=n;j++){
			tmp=1;
			for(k=0;k<=n;k++){
				if(j==k){
				}else{
					tmp=tmp*(x-array_x[k])/(array_x[j]-array_x[k]);
				}
				
			}
			tmp*=array_y[j];
			f_x+=tmp;
		}
		
	
	return f_x;	
}





int main(){
 	
	float array_x[10]={3,7,15,22};
	float array_y[10]={1,-8,-22,-9};
	int n;
	float x,result;
	printf("lutfen n saisini giriniz");
	scanf("%d",&n);
	printf("lufen x i giriniz");
	scanf("%f",&x);
	result=Enter(array_x,array_y,x,n);
	printf("result is :%f",result);
	
	
	
	
	
	
}
