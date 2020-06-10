/* 
	X -> Bomba
	T-> Temiz
	O->Kullan�c�n�n se�ti�i yer	
*/

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

/*Fonksiyon prototipleri*/
void MayinDose(char[][5]);
int RastgeleSayiUret();
void YolYazdir(char[][5]);

int main()
{
	setlocale(LC_ALL, "Turkish");//T�rk�e Karakter ��kt�s� ��in 

	srand((unsigned)time(NULL)); //Rastgele say� �retmek i�in �uanki zaman ile seedliyoruz.
	char yol[6][5]; //6x5 Matrix tan�ml�yoruz.
	int mayin;
	while (true) //D�ng� olu�turuyoruz
	{
		//Oyunun tekrar oynanabilmesi i�in while d�ng�s� i�ine kodlar�m�z� yazaca��z
		MayinDose(yol);
		int kaybetti = 0;
		//Oyunun kaybedilip kaybedilmedi�ini denetliyoruz.
		for (int i = 0; i < 6; i++)
		{
			int sayi = 0;
			while (true)
			{
				cout << "1 ile 5 Aras�nda say� giriniz:\n";
				//Girilen say�n�n 1 ile 5 aras�nda olup olmad���n� kontrol ediyoruz.
				cin >> sayi;
				if ((sayi < 1) || (sayi > 5)) {
					cout << "L�tfen ge�erli bir de�er giriniz!\n";
				}
				else {
					// 1 ile 5 aras�ndaysa i�leme devam ediyoruz.
					break;
				}
			}
			//Matrix elemanlar� 0 dan ba�lad��� i�in, girilen say�y� 1 azalt�yoruz.
			sayi--;
			if (yol[i][sayi] != 'X') {
				//E�er may�na bas�lmam��sa b�lgeyi O ile i�aretliyoruz
				yol[i][sayi] = 'O';
				if (i + 2 < 7)cout << i + 2 << ". sat�ra ge�tiniz." << endl;
			}
			else {
				//May�na bas�l�rsa oyunu bitiriyoruz.
				cout << "May�n patlad�.�zg�n�m, maalesef kaybettiniz." << endl;
				kaybetti = 1;
				break;
			}
		}
		//Oyun normal �ekilde bittiyse kazand�n�z mesaj� yazd�r�yoruz.
		if (kaybetti == 0)cout << "Tebrikler! Kazand�n�z." << endl;
		//Oyun bittikten sonra d�ng� ile yollar� ekrana yazd�r�yoruz.
		YolYazdir(yol);
		char cevap;
		//Ve kullan�c�ya yeniden oynamak isteyip istemedi�ini soruyoruz.
		//Evet ise program�n ba��nda tan�tt���m�z while d�ng�s� tekrarlan�yor. Hay�r ise d�ng�den ��k�l�yor
		//ve oyun bitiyor.
		cout << "Yeniden oynamak ister misiniz ? E/e Evet, H/h Hayir:" << endl;
		cin >> cevap;
		if (cevap == 'H' || cevap == 'h')
		{
			cout << "Ho��akal!";
			break;
		}
	}

}

void MayinDose(char dizi[][5])
{
	int mayin;
	for (int i = 0; i < 6; i++)
		{
			mayin = RastgeleSayiUret();
			//May�nlar�n koyulaca�� b�lgeleri rastgele say� ile belirliyoruz
			for (int j = 0; j < 5; j++)
			{
				//May�n b�lgesini X di�er b�lgleri T ile i�aretliyoruz.
				if (mayin == j)
				{
					dizi[i][j] = 'X';
				}
				else
				{
					dizi[i][j] = 'T';
				}
			}
		}
}

int RastgeleSayiUret()
{
	return rand() % 5;
}

void YolYazdir(char dizi[][5])
{
	for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				cout << dizi[i][j] << "  ";
			}
			cout << endl;
		}
}
