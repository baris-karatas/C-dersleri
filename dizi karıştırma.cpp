#include<stdio.h>
#include <stdlib.h>
#include <time.h>
void swipe(int array[100],int indis_1,int indis_2){
	int tmp;
	tmp=array[indis_1];
	array[indis_1]=array[indis_2];
	array[indis_2]=tmp;
}

int main(){
	int array[100],x;
	int N,i,indis_1,indis_2;
	printf("kac sayi girmek istediginizi giriniz");
	scanf("%d",&x);
	for(i=1;i<=x;i++){
		printf(" %d .inci sayiyi giriniz",i);
		scanf("%d",&array[i-1]);
	}	
	printf("kac kez degistirmek istediginizi giriiniz");
	scanf("%d",&N);
	srand(time(NULL));
	for(i=0;i<N;i++){
		indis_1=rand();
		indis_2=rand();
		swipe(array,indis_1,indis_2);	
	}	
	
	
	
	
}
