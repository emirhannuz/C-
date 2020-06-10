/* 
	X -> Bomba
	T-> Temiz
	O->Kullan�c�n�n se�ti�i yer	
*/

#include <iostream>
#include <iostream>
#include <stdlib.h> 
#include <time.h>

using namespace std;


/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void OyunMatOlustur(char [][5]);
int RastgeleSayi(int );
void DiziYazdir(char [][5]);

int main(int argc, char** argv) {
	char tekrarOyun,
		oyunMat[6][5];
		
	int kullaniciSutun;


	
basla://goto deyimi i�in belirtilmi� tan�mlay�c� goto basla kullan�ld���nda program burdan tekrar ba�lar
	srand(time(0));
	OyunMatOlustur(oyunMat);
	for(int i=0 ; i<6 ;i++){
		
		cout<<i+1<<". satira gectiniz."<<endl;
		cout<<"1 ile 5 arasinda bir sayi giriniz: ";
		cin>>kullaniciSutun;
		
		while(kullaniciSutun > 5 || kullaniciSutun < 1){
				cout<<"Gecersiz bir deger girdiniz. 1 ile 5 arasinda bir sayi giriniz: ";
				cin >>kullaniciSutun;
		}
		
		if(oyunMat[i][kullaniciSutun-1]=='X'){ // kullan�c�n�n grdi�i sutunda bomba var m� diye kontrol ediliyor
			// var ise bomba olan yer P ile i�aretleniyor ekrana mesaj ve dizi yazd�r�l�yor ve d�ng�den ��k�l�yor 
			oyunMat[i][kullaniciSutun-1]='P'; 
			cout<<"Mayin Patladi. Uzgunum Maalesef Kaybettiniz!\n";
			DiziYazdir(oyunMat);
			break;
		}else{ // bomba yok ise girilen s�t�nda o s�t�n i�aretleniyor.
			oyunMat[i][kullaniciSutun-1]='O';
			if(i==6){// dongu son turunda ise ve bombaya denk gelinmemi�se oyunu kazand��� s�yleniyor ve dizi ekrana yazd�r�l�yor
				cout<<"Tebrikler Kazandiniz!\n";
				DiziYazdir(oyunMat);
				break;
			}
		}
		
	}
	// tekrar onay�p oynamamak istedi�i soruluyor
	cout<<"Tekrar Oynamak Ister misiniz? (E/e evet - H/h hayir): ";
	cin>>tekrarOyun;
	
	// kullan�c� e ve E girdiyse oyununun tekrar ba�lamas� i�in goto deyimi yard�m�yla basla k�sm�na gidiyor.
	if(tekrarOyun=='e' || tekrarOyun=='E'){
		goto basla;
	}
	
	cout<<"Oyun Bitti! \n";
	
	return 0;
}


void OyunMatOlustur(char dizi[][5]){
	/* oyun matrisini T ve X lerle dolduran fonksiyon*/
	for(int satir = 0 ; satir < 6 ; satir++){
		int rastgeleSutun= RastgeleSayi(5);
		for(int sutun = 0 ; sutun < 5 ; sutun++){
			if(sutun == rastgeleSutun){
				dizi[satir][sutun]='X';
			}else{
				dizi[satir][sutun]='T';
			}
		}
	}
	
}
int RastgeleSayi(int n){
	
	return rand() % n;
}

void DiziYazdir(char dizi[][5]){
	// ouynmatrisini ekrana yazd�racak fonksiyon
	for(int i =0 ; i<6 ; i++){
		for (int j=0;j<5;j++){
			cout<<dizi[i][j]<<" ";
		}
		cout<<endl;
	}
}
