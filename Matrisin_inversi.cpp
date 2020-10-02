#include <stdio.h>
void transpoze(float ana[][3],int n,float birim[][3]);
void Inverse(float ana[][3],int n,float birim[][3]){
	int i,j,k,d;
	float tmp=0;
	float anac[3][3];
	float birimc[3][3];
	/*for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			anac[i][j]=ana[i][j];
			birimc[i][j]=birim[i][j];
		}
	}*/
	
	
	for(d=0;d<n;d++){
		tmp=ana[d][d];
		for(j=0;j<n;j++){
			birim[d][j]=birim[d][j]/tmp;
			ana[d][j]=ana[d][j]/tmp;
		}
		// constant to make zero
		for(i=d;i<n-1;i++){
			tmp=ana[i+1][d];
			for(k=0;k<n;k++){
				birim[i+1][k]=birim[i+1][k]-tmp*(birim[d][k]);
				ana[i+1][k]=ana[i+1][k]-tmp*(ana[d][k]);
				
			}
		}
		
	}
	for(d=n-1;d>0;d--){
		for(i=d;i>0;i--){
		tmp=ana[i-1][d];
		
		for(j=n-1;j>-1;j--){
			ana[i-1][j]=ana[i-1][j]-ana[d][j]*tmp;
			birim[i-1][j]=birim[i-1][j]-birim[d][j]*tmp;	
		}
	}
	}
	
	


	
	
	
}



int main(){
	int i,j,k,d,n;
	float tmp;
	float ana[3][3]={
	{2,0,-1},
	{0,1,3},
	{-2,0,4}
	};
	float birim[3][3];
	printf("lütfen kare matrixin boyutunu giriniz");
	scanf("%d",&n);
	n=3;
		for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			if(i==j){
				birim[i][j]=1;
			}else{
				birim[i][j]=0;
			}
			
		}
	}
	
	Inverse(ana,n,birim);
	printf(" inverse matrix; \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f\t",birim[i][j]);
			
		}
		printf("\n");
	}
	printf("\n main matrix \n");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			printf("%f\t",ana[i][j]);
			
		}
		printf("\n");
	}
		printf("\n");
//	transpoze(ana,n,birim);
	

	return 0;
}
void transpoze(float ana[][3],int n,float birim[][3]){
	int i,j;
	float tmp1,tmp2;
	for(i=0;i<n;i++){
		for(j=i+1;j<n;j++){
			tmp1=ana[i][j];
			ana[i][j]=ana[j][i];
			ana[j][i]=tmp1;
			tmp2=birim[i][j];
			birim[i][j]=birim[j][i];
			birim[j][i]=tmp2;
		}
	}
	
}
