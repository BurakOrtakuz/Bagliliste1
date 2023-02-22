/**
* @file IkiYonluBagliListe.hpp
* @description Dugum dosyasının gövde kısmı tanımlanan fonksiyonlara işlevleri atandı
* @course Veri yapıları 2. Öğretim B grubu
* @assignment 1. Ödev
* @date 2 Kasım 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "Dugum.hpp"

Dugum::Dugum(std::string veri){
    this->veri=veri;
    this->sonraki=0;
    this->onceki=0;
};
