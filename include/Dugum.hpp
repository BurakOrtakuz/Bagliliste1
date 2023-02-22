/**
* @file IkiYonluBagliListe.hpp
* @description Dugum dosyasının başlık kısmı burada dugume ait veriler tanımlandı
* @course Veri yapıları 2. Öğretim B grubu
* @assignment 1. Ödev
* @date 2 Kasım 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#ifndef Dugum_hpp
#define Dugum_hpp
#include <iostream>
class Dugum
{
public:
    Dugum (std::string veri);
    std::string veri="";          
    Dugum* sonraki;
    Dugum* onceki;
};


#endif
