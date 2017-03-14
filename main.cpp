#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <fstream>
#include <time.h>
#define BENZIN_FIYAT 4.58 /** DEFINE ILE BENZIN_FIYAT SABITLENDI */
#define DIESEL_FIYAT 3.89 /** DEFINE ILE DIESEL_FIYAT SABITLENDI */
#define LPG_FIYAT 2.45 /** DEFINE ILE LPG_FIYAT SABITLENDI */

using namespace std; /** :: OPERATORUNU KULLANMAMAK ICIN TANIMLANDI*/


class  petrol /** TEMEL SINIF */
{
private : /** FONKSIYON DISINDA ERISILEMEYEN KASA */

     float kasa;

public : /** DISARIDAN ERISILEBILEN FONKSIYON */

    petrol() /** CONSTRUCTOR YAPICI FONKSIYON */
    {
        kasa=0;
    }


   void kasaKazanci(float gelen)/** GELEN KASAYI GOSTERME */
   {
       kasa=kasa+gelen; /** ALDIGI DEGISKEN ILE ANLIK KASAYI TOPLAYAN YER*/
       yazdir();


   }

    void yazdir() /** YAZDIRMA ISLEMI */
    {
        cout<<"Kasaya odenen miktar :' "<<kasa<<" ' TL'dir. ";
    }


};

class lpg : public petrol /**  TURETILMIS SINIF */
{
protected: /** KORUNAN LPG DEPOSU */

    float lpgdepo;

public:

    lpg() /** CONSTRUCTOR YAPICI FONKSIYON */
    {
        lpgdepo=100;
    }



    virtual float bilgiiste() /** OVERLOAD YAPILAN , BILGI ISTENEN YER*/
    {
        float litre;
        float anakasa;
        cout<<endl;
        cout<<"Kac litre yakit almak istersiniz?: ";
        cin>>litre;

        if(litre>lpgdepo)
        {
            cout<<"Maalesef istediginiz miktarda yakit kalmamistir\n"<<endl;
            cout<<"Yeniden bekleriz"<<endl;
            exit(1);

        }
        azalt(litre);

        anakasa=litre*LPG_FIYAT;
        fis(litre,anakasa); /** AYNI CLASS ICINDE DIGER FONKSIYONA GONDERME 1 KEZ CAGIRILIR HEPSI GIDER */
        kasaKazanci(anakasa);/** AYNI CLASS ICINDE DIGER FONKSIYONA GONDERME 1 KEZ CAGIRILIR HEPSI GIDER */

    return anakasa; /**  TOPLAM FIYATI DONDURMEK ICIN*/
    }


    virtual void rastgelePlaka() /** RANDOM PLAKA GENERATOR */
    {
        srand(time(NULL));
        string plaka[8]={"34 FON 19","41 MS 47","01 PLT 10","33 T 348","78 KLS 01","34 HN 48","53 TH 124","\0"};
        int rastgele;
        ofstream plakalar("ZRapor.txt",ios::app); /** +++ YAZILAN KLASORU SILMEDEN UZERINE YAZAR */

        rastgele= rand() % 7 ;/** RANDOM DONDURME */

        plakalar << "Gelen aracin plakasi: " << plaka[rastgele] << endl; /** DOSYAYA YAZDIRMA */

    }

     void azalt(float litre) /** AZALTMA FONKSIYONU */
   {
       lpgdepo=lpgdepo-litre;

        kalanDepo(lpgdepo);


   }

    void kalanDepo(float lpgdepo) /**  KALAN DEPO MIKTARINI YAZDIRMA*/

   {
       cout<<"Kalan depo miktari:" <<lpgdepo<<endl;
   }

    virtual void fis(float litre,float anakasa) /** FIS YAZDIRMA*/
    {
        ofstream lpg("ZRapor.txt",ios::app); /** GUNLUK Z RAPORU ICIN DOSYA OLUSTURMA*/
        /** BUNLARIN DOSYAYA YAZDIRILMASI */
        lpg << "Alinan yakit turu : LPG "<<endl;
        lpg << "Alinan yakit miktari: " << litre << " litre "<<endl;
        lpg << "Odenen fiyat: " << anakasa <<endl;
        lpg <<endl;

    }



};

class benzinli : public petrol /** TURETILMIS SINIF */
{
protected:/**  KORUNAN BENZINLI FONKSIYONU*/

    int benzinlidepo;

public:


    benzinli()/** CONSTRUCTOR YAPICI FONKSIYON */
    {
        benzinlidepo=100;
    }

    virtual void rastgelePlaka() /** PLAKA DONDURMEK ICIN RANDOM OLUSTURULMUS FONKSIYON */
    {
        srand(time(NULL));
        string plaka[8]={"34 FON 19","41 MS 47","01 PLT 10","33 T 348","78 KLS 01","34 HN 48","53 TH 124","\0"};
        int rastgele;
        ofstream plakalar("ZRapor.txt",ios::app);/** +++ YAZILAN KLASORU SILMEDEN UZERINE YAZAR */


        rastgele= rand() % 8 ;/** RANDOM DONDURME */

        plakalar << "Gelen aracin plakasi: " << plaka[rastgele] << endl; /** DOSYAYA YAZDIRMA */







    }

     virtual float bilgiiste() /** OVERLOAD YAPILAN , BILGI ISTENEN YER*/
    {
        float litre;
        float anakasa;
        cout<<"Kac litre yakit almak istersiniz ?: ";
        cin>>litre;

        if(litre>benzinlidepo)
        {
            cout<<"Maalesef istediginiz miktarda yakit kalmamistir\n"<<endl;
            cout<<"Yeniden bekleriz"<<endl;
            exit(1);

        }

        azalt(litre);
        anakasa=litre*BENZIN_FIYAT;
        fis(litre,anakasa); /** AYNI CLASS ICINDE DIGER FONKSIYONA GONDERME 1 KEZ CAGIRILIR HEPSI GIDER */
        kasaKazanci(anakasa); /** AYNI CLASS ICINDE DIGER FONKSIYONA GONDERME 1 KEZ CAGIRILIR HEPSI GIDER */
        return anakasa; /**  TOPLAM FIYATI DONDURMEK ICIN*/
    }

   void azalt(float litre) /** AZALTMA FONKSIYONU */
   {
       benzinlidepo=benzinlidepo-litre;

        kalanDepo(benzinlidepo);

   }

   void kalanDepo(float benzinlidepo)  /**  KALAN DEPO MIKTARINI YAZDIRMA*/

   {
       cout<<"Kalan depo miktari:" <<benzinlidepo<<endl;
   }

    virtual void fis(float litre,float anakasa)   /** FIS YAZDIRMA*/
    {
        ofstream benzin("ZRapor.txt",ios::app); /**  Z RAPORU CIKARTMA */
        /** DOSYAYA YAZDIRMA  */
        benzin << "Alinan yakit turu : Benzinli "<<endl;
        benzin << "Alinan yakit miktari: " << litre << " litre "<<endl;
        benzin << "Odenen fiyat: " << anakasa <<endl;
        benzin << endl;

    }


};

class diesel : public petrol/** TURETILMIS SINIF */
{
protected: /**  KORUNAN DIESEL  FONKSIYONU*/

    float dieseldepo;

public:

    diesel() /** CONSTRUCTOR YAPICI FONKSIYON */
    {
        dieseldepo=100;
    }

    virtual void rastgelePlaka() /** PLAKA DONDURMEK ICIN RANDOM OLUSTURULMUS FONKSIYON */
    {
        srand(time(NULL));
        string plaka[8]={"34 FON 19","41 MS 47","01 PLT 10","33 T 348","78 KLS 01","34 HN 48","53 TH 124","\0"};
        int rastgele;
        ofstream plakalar("ZRapor.txt",ios::app); /** +++ YAZILAN KLASORU SILMEDEN UZERINE YAZAR */

        rastgele= rand() % 7 ;  /** RANDOM DONDURME */

        plakalar << "Gelen aracin plakasi: " << plaka[rastgele] << endl; /** DOSYAYA YAZDIRMA */


    }

    virtual float bilgiiste() /** OVERLOAD YAPILAN , BILGI ISTENEN YER*/
    {
        float litre;
        float anakasa;
        cout<<"Kac litre yakit almak istersiniz?: ";
        cin>>litre;

        if(litre>dieseldepo)
        {
            cout<<"Maalesef istediginiz miktarda yakit kalmamistir\n"<<endl;
            cout<<"Yeniden bekleriz"<<endl;
            exit(1);

        }
        azalt(litre);
        anakasa=litre*DIESEL_FIYAT;
        fis(litre,anakasa); /** AYNI CLASS ICINDE DIGER FONKSIYONA GONDERME 1 KEZ CAGIRILIR HEPSI GIDER */
        kasaKazanci(anakasa);/** AYNI CLASS ICINDE DIGER FONKSIYONA GONDERME 1 KEZ CAGIRILIR HEPSI GIDER */

    return anakasa; /**  TOPLAM FIYATI DONDURMEK ICIN*/
    }


   void azalt(float litre) /** AZALTMA FONKSIYONU */
   {
       dieseldepo=dieseldepo-litre;

        kalanDepo(dieseldepo);

   }

   void kalanDepo(float dieseldepo)   /**  KALAN DEPO MIKTARINI YAZDIRMA*/

   {
       cout<<"Kalan depo miktari:" <<dieseldepo<<endl;
   }

     virtual void fis(float litre,float anakasa)  /** FIS YAZDIRMA*/
    {
        ofstream diesel("ZRapor.txt",ios::app);

        diesel << "Alinan yakit turu : Diesel "<<endl;
        diesel << "Alinan yakit miktari: " << litre << " litre "<<endl;
        diesel << "Odenen fiyat: " << anakasa <<endl;
        diesel << endl;

    }



};


int main()
{
    benzinli b1; /** BENZINLI SINIFDAN NESNE OLUSTURULUYOR */
    lpg l1; /** LPG SINIFDAN NESNE OLUSTURULUYOR */
    diesel d1; /** DIESEL SINIFDAN NESNE OLUSTURULUYOR */

    int secim=0; /**  SECENEK */
    double toplam_para=0; /**  GUNLUK KABA RAPOR ICIN */
    int sayac=0;
while(1)
{


    cout<<"\nAracinizin yakit turu nedir? \n\n 1:LPG\n 2:Benzinli\n 3:Diesel\n 4:Fiyat Listesi\n 5:Cikis"<<endl;
    cin>>secim;


    switch(secim)
    {
    case 1:
    {

        cout<<"\n\nLPG"<<endl;
        l1.rastgelePlaka(); /** RASTGELE PLAKA OLUSTURMA */
        toplam_para+=l1.bilgiiste(); /** TOPLAM KABA RAPOR ICIN  */ /** OVERLOAD FONKSIYONU CAGIRILIYOR */
        sayac++; /** GELEN ARABAYI ARTTIRMAK ICIN*/
        break;
    }
    case 2:
    {

        cout<<"\n\nBenzinli"<<endl;
        b1.rastgelePlaka(); /** RASTGELE PLAKA OLUSTURMA */
        toplam_para+=b1.bilgiiste(); /** TOPLAM KABA RAPOR ICIN  */ /** OVERLOAD FONKSIYONU CAGIRILIYOR */
        sayac++;/** GELEN ARABAYI ARTTIRMAK ICIN*/
        break;
    }
    case 3:
    {

        cout<<"\n\nDiesel"<<endl;
        d1.rastgelePlaka();/** RASTGELE PLAKA OLUSTURMA */
        toplam_para+=d1.bilgiiste();/** TOPLAM KABA RAPOR ICIN  */ /** OVERLOAD FONKSIYONU CAGIRILIYOR */
        sayac++;/** GELEN ARABAYI ARTTIRMAK ICIN*/
        break;
    }
    case 4:
    {
        cout<<endl;
        cout<<"Benzin fiyati: "<<BENZIN_FIYAT<<endl;
        cout<<"Diesel fiyati: "<<DIESEL_FIYAT<<endl;
        cout<<"Lpg fiyati: "<<LPG_FIYAT<<endl;
        char devam;
        cout<<"Yakit almak icin 'E' tusuna basiniz\n"<<endl;
        cin>>devam;

        if('E' || 'e' == devam)
        {
            continue;

        }
        else
        {
          cout<<"Devam edilemiyor\n"<<endl;
          exit(1);

        }

        break;

    }

    case 5:
    {
           cout<<"Iyi gunler,yine bekleriz\n"<<endl;
           exit(1);

    }

    default:
        cout<<"\nBoyle bir yakit turu bulunamamistir"<<endl;
        cout<<"Programdan cikiliyor"<<endl;
        exit(1);

    }
    ofstream yonetici("GenelRapor.txt"); /** KABA RAPOR*/
    yonetici << "Toplam kasadaki para :" << toplam_para <<endl;
    yonetici << "Toplam gelen arac sayisi: " << sayac <<endl;
}








    return 0;
}
