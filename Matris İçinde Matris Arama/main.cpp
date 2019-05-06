#include <iostream>
#include <fstream>

using namespace std;
 /*-*//*prototipler*//*_*/
/*_*/				/*-*/
void matrisOku(char[],int [][100],int&,int&);
void sonucYaz(char[],int[][2],int);
int arama(const int [][100],const int[][100],int[][2],int,int,int,int);
 /*-*/			/*_*/
/*_*//*		 *//*-*/
int main(int argc, char** argv) {
	
	
	char anaDosya[]="AnaMatris.txt";
	char arananDosya[]="ArananMatris.txt";
	char sonucD[]="Sonuc.txt";
	
	int anaMatris[100][100];
	int arananMatris[100][100];
	int sonuclar[100][2];
	
	
	int satir,sutun,arananSatir,arananSutun,sonucSayisi;
	
	matrisOku(anaDosya,anaMatris,satir,sutun);
	matrisOku(arananDosya,arananMatris,arananSatir,arananSutun);
	
	sonucSayisi=arama(anaMatris,arananMatris,sonuclar,satir,sutun,arananSatir,arananSutun);	
	cout<<"Islem tamam.";
	
	
	sonucYaz(sonucD,sonuclar,sonucSayisi);
	
	return 0;
}



void matrisOku(char dosyaAdi[],int matris [][100],int &satir,int &sutun){
	
	ifstream oku;
	oku.open(dosyaAdi,ios::app);
	oku>>satir;// ilk �nce dosyadaki sat�r say�s�n�,
	oku>>sutun;// sutun sayisini al�r.
	for(int i=0;i<satir;i++){ // daha sonra matrisi al�r
		for(int j=0;j<sutun;j++){
			oku>>matris[i][j];
			
			}	
	}	
	oku.close();	
	
}

int arama(const int anaMatris[][100],const int arananMatris[][100],int sonuc[][2],int satir,int sutun,int arananSatir,int arananSutun){
	
	int bulunanEsitMatris=0,sayac;
    
    int i, j, iAna, jAna; // de�i�ken tan�mlamalar�
     
    for( arananSatir = arananSatir ; arananSatir > 1 ; arananSatir--) {
        for (iAna = 0; iAna < satir-1; iAna++) { //anamatrisin satir sayisi kadar
            for (jAna = 0; jAna < sutun-1; jAna++) {// anamatrisin sutun sayisi kadar    
            	sayac=0;// esitlik sayac�
                for (i = 0; i < arananSatir; i++) {	//aranan matris satir
                    for (j = 0; j < arananSutun; j++){	//arananmatris sutunlar�nda dola�mak i�in
                    	if(anaMatris[i+iAna][j+jAna]==arananMatris[i][j]){//aranan matris ana matrise e�it mi kontrol ediyor.
							sayac++;//esitlik sayaci satir * sutun kadar olmal�.
                        	if(sayac==(arananSatir*arananSutun)){ // aranacak matrisin t�m elemanlar� ayn� ise 
								sonuc[bulunanEsitMatris][0]=iAna; // ana matrisin indislerini al�yor 
   								sonuc[bulunanEsitMatris][1]=jAna; //
								bulunanEsitMatris++; // e�it matris say�s�n� buluyor.
								}
                        	}	
                    } 
						
                }
                
            }
        }
        
    }
		return bulunanEsitMatris;
}


void sonucYaz(char dosyaAdi[],int sonuclar[][2],int sonucSayisi){
	
	ofstream yazdir(dosyaAdi, ios::out); //ios::out yazarsan dosya i�indekileri silip yeni de�erleri yazd�r�r.
	yazdir<<sonucSayisi<<endl;//�nce buldu�u sonu� say�s�n� yazd�r�r.
	for(int i=0;i<sonucSayisi;i++){ //daha sonra dizi i�indeki elemanlar� yazd�r�r.
			yazdir <<sonuclar[i][0]<<sonuclar[i][1]<<endl;
	}	
	yazdir.close();// dosyaya yazma i�lemi sonlandirilir
}
