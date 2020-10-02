#include <stdio.h>
#define SIZE 100
void gauss(float matrix[][5],float sonuc[5],int x){
	int i,j,k;
	float tmp;
	//float temo[3][3];
	//float temo1[3];
	/*for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			temo[i][j]=matrix[i][j];
		}
		temo1[i]=sonuc[i];
	}*/

	for(i=0;i<x;i++){
		tmp=matrix[i][i];
		sonuc[i]=sonuc[i]/tmp;
		for(j=i;j<x;j++){
			matrix[i][j]=matrix[i][j]/tmp;
		}for(k=i+1;k<x;k++){
			tmp=matrix[k][i];
			sonuc[k]=sonuc[k]-sonuc[i]*tmp;
			for(j=i;j<x;j++){
				matrix[k][j]=matrix[k][j]-matrix[i][j]*tmp;
				
			}
		}
	}
	
}

int main(){
	float katsayi[4][5]={{2000,500,0},{-2000,7000,-4000},{0,-6500,6000}};
	int i,j;
	float tmp;
	float degisken[3]={'x','y','z'};
	float sonuc[5]={90,0,0};
	int x;
	printf("lutfen matrisin boytunu giriniz");
	scanf("%d",&x);
	gauss(katsayi,sonuc,x);
	printf("ust ucgen matrisi : \n");
	
	for(i=0;i<x;i++){
		for(j=0;j<x;j++){
			printf("%f ",katsayi[i][j]);
		}
		printf("\n");
	}
	/*
	for(i=0;i<x;i++){
		printf("%f \n",sonuc[i]);
	}*/
	degisken[x-1]=sonuc[x-1]/katsayi[x-1][x-1];
	for(i=x-2;i>=0;i--){
		tmp=0;
		for(j=i;j<x;j++){
			if(i==j){
			}else{
				tmp+=katsayi[i][j]*degisken[j];
			}
			
		}
		degisken[i]=sonuc[i]-tmp;
	}
	printf("kokler sirasiyla : \n");
	for(i=0;i<x;i++){
		printf("%f\n",degisken[i]);
	}







	
}
