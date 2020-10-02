#include <stdio.h>

int main(){
	int i,j,sum,A,N,k,a,tmp;
	
	printf("lutfen A sayisini giriniz");
	scanf("%d",&A);
	printf("lutfen N basamak sayisiniz giriniz");
	scanf("%d",&N);
	sum=0;
	j=1;
	tmp=A;
	
	for(i=0;i<N;i++){
		j=tmp%10;
		tmp=tmp-j;
		tmp=tmp/10;
		a=j;
		for(k=0;k<N-1;k++){
			j=a*j;
			
		}
		sum=sum+j;
	}
	if(sum==A){
		printf("A amstrong sayisi");
		
	}else{
		printf("degil");

	}
	
	
	
	
	
	
	
}
