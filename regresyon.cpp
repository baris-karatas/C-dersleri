#include <stdio.h>
#include <math.h>
void gauss(float matrix[][2],float sonuc[2],int x){
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
	/*
	for(i=0;i<x;i++){
		printf("%f \n",sonuc[i]);
	}*/
}




int main(){
	float x_i[10]={0,2,3,4,5};
	float y_i[10]={5.2,56.628,186.872,616.679,2035.040};
	double B_0,B_1,tmp,sum_x,sum_y,sum_xy,sum_x2,f_x;
	float katsayi[2][2],sonuc[2];
	int x,n,i,j,c;
	float degisken[2],degisken_x;
	printf("fonksiyon polinom ise 1 doðrusal ise 0 a bas");
	scanf("%d",&c);
	printf("please enter n digit");
	scanf("%d",&n);
	katsayi[0][0]=n;
	sum_x=0;
	sum_y=0;
	sum_xy=0;
	sum_x2=0;
	x=2;
	if(c==0){
	for(i=0;i<n;i++){
		sum_x+=x_i[i];
		sum_y+=y_i[i];
		sum_xy+=x_i[i]*y_i[i];
		sum_x2+=x_i[i]*x_i[i];
	}
	katsayi[0][1]=sum_x;
	katsayi[1][0]=sum_x;
	katsayi[1][1]=sum_x2;
	printf("plesae enter value of x");
	scanf("%f",&degisken_x);
	x=2;
	
	sonuc[0]=sum_y;
	sonuc[1]=sum_xy;
	gauss(katsayi,sonuc,x);
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
	f_x=degisken[0]+degisken[1]*degisken_x;
	printf("sonuc %f",f_x);
	
	double sum_yx;
	}else if(c==1){
		
		printf("plesae enter value of x");
	scanf("%f",&degisken_x);
		for(i=0;i<n;i++){
			sum_y+=log(y_i[i]);
			sum_xy+=log(y_i[i])*x_i[i];
			sum_x+=x_i[i];
			sum_x2+=x_i[i]*x_i[i];
		}
		sonuc[0]=sum_y;
		sonuc[1]=sum_xy;
		katsayi[0][1]=sum_x;
		katsayi[1][0]=sum_x;
		katsayi[1][1]=sum_x2;
		gauss(katsayi,sonuc,x);
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
	f_x=degisken[0]+degisken[1]*degisken_x;
	printf("sonuc %f",f_x);
		degisken[0]=pow(2.71,degisken[0]);
		f_x=degisken[0]*pow(x,degisken[1]);//change this
	}
	
	
	
	
}
