/* 
	X -> Bomba
	T-> Temix
	O->Kullan�c�n�n se�ti�i yer	
*/

#include <iostream>
#include <stdlib.h> /* random */
#include <time.h>       /* time */
using namespace std;

/*Function Prototypes*/
void createArray(char[][5]);
void printArray(char[][5]);
void setBomb(char[][5]);
bool isThereBomb(char[][5], int, int);
void setUserSelectedIndex(char[][5], int, int);
void bombExplode(char[][5], int, int);


int main(int argc, char** argv) {
	/* De�i�ken Tan�mlamalar� */
	char oyunMat[6][5];
	char userInput='E';
	int userColumnInput;
	/************************/
	
	
	while(userInput=='E' || userInput=='e'){/* Kullan�c� e veya E girdi�i S�rece d�ng� d�necek*/
		
		srand(time(0)); /* Her seferinde Farkl� Rastgele Say�lar �retmek i�in*/
	
		createArray(oyunMat);
		setBomb(oyunMat);
		
		int satir;
		for (satir=0; satir < 6; satir++){
			cout<< satir+1 <<". satira gectiniz."<<endl;
			cout<<"1 ile 5 arasinda bir sayi giriniz: ";
			cin >>userColumnInput; /* kullan�c�n�n girdi�i de�er okundu*/
			/* 5 ten b�y�k veya 1 den k���k bir de�er girildi�inde kullan�c�dan de�er yeniden isteniyor*/
			while(userColumnInput > 5 || userColumnInput < 1){
				cout<<"Gecersiz bir deger girdiniz. Tekrar giriniz: ";
				cin >>userColumnInput;
			}
			
			bool bomb = isThereBomb(oyunMat,satir,userColumnInput); /* se�ilen konumda bomba var m� diye kontrol etmek i�in fonksiyonumuza matrisle birlikte satir ve kullan�c�n�n girdi�i de�eri yolluyoruz*/
			if (bomb) /*d�nen de�er true ise yani bomba var ise kullan�c�  oyunu kaybetti mesaj� yazd�r�p oyunu */
			{
				cout<< endl << "Mayin Patladi. Uzgunum Kaybettiniz!"<<endl;
				bombExplode(oyunMat, satir, userColumnInput); /*se�ilen konumda bomba var ise konumdaki harf de�i�tirildi*/
				printArray(oyunMat); /*oyun bitti. matrisi yazd�rd�k*/
				break; /* for d�ng�s� sonland�r�ld�*/
			}
			setUserSelectedIndex(oyunMat, satir, userColumnInput); /* Kullan�c�n�n se�ti�i index i O harfi ile dolduran fonksiyon �a��r�ld� ve o anki satir ve kullancinin yazd��� de�er fonksiyona g�nderildi*/
		}
		if(satir==6 /* d�ng� 6 kez d�nm��se kullan�c� oyunu kazanm�st�r*/){
			cout<<"Tebrikler Kazandiniz!"<<endl<<endl;
			printArray(oyunMat); /* oyun matrisini ekrana yazd�rd�k*/
		}
		
		cout<<"Yeniden Oynamak Ister misiniz? (Evet icin e/E, Hay�r icin h/H giriniz.): "<<endl;
		cin>>userInput; /*kullan�c�n�n cevab� al�nd�*/
	}
	
	return 0;
}

/* oyunMat �n i�ini T Harfleri ile Dolduruyoruz */
void createArray(char mat[][5])
{
	for (int satir = 0 ; satir < 6 ; satir++)
	{
		for(int sutun = 0 ; sutun < 5 ; sutun++)
		{
			mat[satir][sutun]='T';
		}
	}
}

/* Dizimizi Ekrana Yazd�racak Fonksiyon */
void printArray(char mat[][5])
{
	for (int satir = 0 ; satir < 6 ; satir++)
	{
		for(int sutun = 0 ; sutun <5 ;sutun++)
		{
			cout << mat[satir][sutun]<< "  ";
		}
		cout << endl ;
	}
}

/* Bombalar Rastgele Konumlara Atan�yor */
void setBomb(char mat[][5])
{
	int randomNumber;
	for(int satir = 0 ; satir < 6 ; satir++)
	{
		randomNumber = rand() % 5;
		mat[satir][randomNumber] = 'X';
	}
	
}

/* 
	Kullan�c�n�n girdi�i indiste bomba var m� diye kontrol eden fonksiyon 
	bomba var ise true de�eri d�nd�r�yor yok ise false
*/
bool isThereBomb(char mat[][5], int row, int column)
{
	return mat[row][column-1]=='X' ? true :false ;
}

/*
	Kullanicinin Se�ti�i indisler O harfi ile de�i�tiriliyor.
*/
void setUserSelectedIndex(char mat[][5], int row, int column)
{
	mat[row][column-1]='O';
}

/*
	Kullan�c�n�n Se�ti�i indiste bomba var ise o indise P harfi ile de�i�tiriliyor
*/
void bombExplode(char mat[][5], int row, int column)
{
	mat[row][column-1]='P';
}

