#include<stdio.h>
int main(){
	int i,j,N,M,sum,counter;
	bool k=true;
	printf("N sayisini giriniz");
	scanf("%d",&N);
	printf("M sayisini giriniz");
	scanf("%d",&M);
	sum=0;counter=0;
	for(i=N;i<=M;i++){
		for(j=2;j<i/2;j++){
			if(i%j!=0){
				k=true;
			}else{
				k=false;
				j=i;
			}
		}
		if(k){
			printf("%d sayisi asal\n",i);
			if(i%10==3||i%10==7){
				counter++;
				sum=sum+i;
			}
		}else{
			printf("%d sayisi asal degil\n",i);
		}
		
		
	}
	printf("toplam %d ",sum);
	printf("%d tane sayi",counter);
	
	
	
	
	
	
	
	
}
