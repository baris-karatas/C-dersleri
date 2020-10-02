#include <stdio.h>
#include <stdlib.h>
int random( long int x){
	int i;
	for(i=0;i<1000;i++){
		 x=x+rand();
	}
	return x;
}

int sayi (long int x){
	int i;
	for(i=0;i<1000;i++){
		x=x*i;
	    x=random(x);	
	}
	
	return x;
}

int main(){
	int i,j;
	j=rand();
	srand(NULL);
	for(i=0;i<6;i++){
		j=sayi(i);
		j=j%49;
		j++;
		printf("%d.inci sayi %d \n",i,j);	
	}
}
