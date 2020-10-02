#include <stdio.h>
void elemanEkle (int*,int,int,int*);
void elemanSil (int*,int,int*);
void listeleriYazdir(int*,int*,int);
void siraliYazdir (int A[10],int PO[10]){
	int i=0,k,j=4;
	while(j!=-1){
		k=PO[i];
		
		printf("%d",A[PO[k]]);
		j=A[PO[k]];
		i=A[k];
		
	}
}


int main()
{
        static int B[10],A[10],PO[10],N,i,j,k,ek,sil;
        printf("eklenecek dizi eleman sayisi?\n");
        scanf("%d",&N);
        printf("elemanlar?\n");
        for (i=1;i<=N;i++)
                scanf("%d",&B[i]);
        PO[0]=1;
        A[1]=B[1];
        PO[1]=-1;
        for (i=2;i<=N;i++)
        {
                ek=B[i];
                elemanEkle (A,i,ek,PO);                
        }
        
//        listeleriYazdir(A,PO,N);
        
        printf("eklenecek eleman?\n");
        scanf("%d",&ek);
        elemanEkle (A,i,ek,PO);        
        N=N+1;

//        listeleriYazdir(A,PO,N);
       siraliYazdir(A,PO);
/*        printf("silineceklenecek eleman?\n");
        scanf("%d",&sil);
        elemanSil (A,sil,PO);                        
        listeleriYazdir(A,PO,N);
        siraliYazdir(A,PO);*/
        return 0;
        
}

//gelen eleman� A[]'n�n en sonuna ekle
//linkli listeyi ba�tan tara. linkli listenin her eleman� i�in bu elemana referans veren ve bu eleman�n referans verdi�i elemanlar� sakla
//gerekiyorsa araya, gerekiyorsa ba�a ya da sona eklemek i�in link baglantilarini kur
void elemanEkle (int A[],int i,int ek,int PO[])
{
        int k=0;                //ilgili elemana referans veren. �uan liste ba��n� i�aret ediyor
        int j;                        //bir sonraki elemana ge�ebilmek i�in
        A[i]=ek;                //yeni eleman� A[] dizisinin i. indisine yaz
        j=PO[0];                //j liste ba��ndaki eleman�n indisini g�stersin
        while ((j!=-1) && (A[j]<ek))        //listenin sonuna ula�mad���n ve s�radaki eleman eklenecek elemandan k���k oldu�u s�rece
                                                                        //bir sonraki elemana ge� ama �ncekini de sakla
        {
                k=j;                //bu elemana referans verenin indisi
                j=PO[j];        //bu eleman�n referans verdi�inin indisi
        }
        PO[k]=i;                
        PO[i]=j;                //yeni elman s�radaki elemana referans versin
}

