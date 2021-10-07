#include <stdio.h>
#include <stdlib.h>
struct dugum {
    int deger;
    struct dugum *sag;
    struct dugum *sol;
};
struct dugum* kok;
int dugumAra(struct dugum* kok, int deger) 
{
	int adimSayisi=1;
    while (kok != NULL){ 
        if (deger == kok->deger) {
        	return adimSayisi;
		}
        else if (deger < kok->deger) {
        	kok = kok->sol; 
		} 
        else{
        	kok = kok->sag; 
		}
		adimSayisi++;
    }
    return -1; 
} 
struct dugum* yeniDugum(int deger)
{
    struct dugum* tmpDugum= (struct dugum*)malloc(sizeof(struct dugum));
    tmpDugum->deger = deger;
    tmpDugum->sag = NULL;
    tmpDugum->sol = NULL;
    return tmpDugum;
}
void seviyeyazdir(struct dugum *mevcutDugum, int hedefseviye, int mevcutseviye)
{
    if (mevcutDugum!=NULL)
    {
        if (hedefseviye == mevcutseviye){
        	printf("%d - ", mevcutDugum->deger);
		} 
        else
        {
            seviyeyazdir(mevcutDugum->sol, hedefseviye, mevcutseviye + 1);
            seviyeyazdir(mevcutDugum->sag, hedefseviye, mevcutseviye + 1);
        }
    }
}
void buyukDugumBul(struct dugum* mevcutDugum, int deger) 
{ 
    if (mevcutDugum != NULL) {
        buyukDugumBul(mevcutDugum->sol,deger);
        if(mevcutDugum->deger>deger)printf("%d - ", mevcutDugum->deger);
        buyukDugumBul(mevcutDugum->sag,deger);
    }
} 
struct dugum* dugumekle(struct dugum* mevcutDugum, int deger)
{
	if (mevcutDugum == NULL){
		return yeniDugum(deger);
	}  
	if (deger < mevcutDugum->deger){
		mevcutDugum->sol = dugumekle(mevcutDugum->sol, deger);
	} 
	else{
		mevcutDugum->sag = dugumekle(mevcutDugum->sag, deger);
	}
	return mevcutDugum;
}
int yaprakToplami(struct dugum* mevcutDugum)
{
    if(mevcutDugum==NULL){
    	return 0;
	}
	if(mevcutDugum->sol==NULL && mevcutDugum->sag ==NULL)
	{
	  return mevcutDugum->deger;
	}
	return (yaprakToplami(mevcutDugum->sol)+yaprakToplami(mevcutDugum->sag));
}
int yaprakSayisi(struct dugum* mevcutDugum)
{
    if(mevcutDugum==NULL)
    {
      return 0;    }
      if(mevcutDugum->sol==NULL && mevcutDugum->sag ==NULL)
      {
          return 1;
      }
      return (yaprakSayisi(mevcutDugum->sol)+yaprakSayisi(mevcutDugum->sag));
}
void Ortalama(){
	int adet=yaprakSayisi(kok);
	int toplam = yaprakToplami(kok);
	printf("Yaprak dugumlerinin ortalamasi: %d\n",toplam/adet);
}
void Ara(int deger){
	int adimSayisi=dugumAra(kok,deger);
	if(adimSayisi==-1){
		printf("%d Elemani Bulunamadi!\n",deger);
	}
	else{
		printf("%d Elemani %d adimda bulundu.\n",deger,adimSayisi);
	}
}
void Ekle(int deger){
	kok = dugumekle(kok,deger);
}
void SeviyedekiDugumler(int seviye){
    printf("%d. Seviyedeki elemanlar: ",seviye);
    seviyeyazdir(kok,seviye,0);
}
void DegerdenBuyukDugumler(int deger){
    printf("%d Degerinden buyuk elemanlar: ",deger);
    buyukDugumBul(kok,deger);
}
int main(int argc, char *argv[]) {
	kok = NULL;
    //a
    int secim;
    while(1){
    	printf("\n0-Cikis\n1-Dugum Ekle\n2-Seviyedeki Dugumleri Goster\n3-Dugum Ara\n4-Yapraklarin Ortalamasi\n5-Bir Degerden Buyuk Dugumleri Yazdir\n>>");
    	scanf("%d",&secim);
    	if(secim==0){
    		break;
		}
		else if(secim==1){
			printf("Dugum Degeri:");
			scanf("%d",&secim);
			Ekle(secim);
			printf("Dugum eklendi.\n");
		}
		else if(secim==2){
			printf("Seviye:");
			scanf("%d",&secim);
    		SeviyedekiDugumler(secim);
		}
		else if(secim==3){
			printf("Aranacak Deger:");
			scanf("%d",&secim);
			Ara(secim);
		}
		else if(secim==4){
    		Ortalama();
		}
		else if(secim==5){
			printf("Bir sayi giriniz:");
			scanf("%d",&secim);
    		DegerdenBuyukDugumler(secim);
		}
		else printf("Hatali giris\n");
	}
	return 0;
}
