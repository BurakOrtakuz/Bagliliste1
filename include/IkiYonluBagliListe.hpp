/**
* @file IkiYonluBagliListe.hpp
* @description IkiYonluBagliListe başlık kısmı fonksiyonların tanımlandığı yer
* @course Veri yapıları 2. Öğretim B grubu
* @assignment 1. Ödev
* @date Son işlem 9 Kasım 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#ifndef IkiYonluBagliListe_hpp
#define IkiYonluBagliListe_hpp
#include "Dugum.hpp"

class IkiYonluBagliListe{
public:
    IkiYonluBagliListe();
    ~IkiYonluBagliListe();
    void temizle();
    void ekle(int sıra,std::string veri);   
    void sil(int sıra);
    void yazdır();
        Dugum* yerBul(int sıra);
private:
    Dugum* ilk;
    int boyut;    

    
};

#endif