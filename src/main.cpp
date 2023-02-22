/**
* @file main.cpp
* @description main dosyası
* @course Veri yapıları 2. Öğretim B grubu
* @assignment 1. Ödev
* @date 2 Kasım 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/

#include <iostream>
#include "IkiYonluBagliListe.hpp"
int main(){
   
    IkiYonluBagliListe* liste= new IkiYonluBagliListe();
    std::cout<<liste->yerBul(5)->veri<<"---------"<<std::endl;
}