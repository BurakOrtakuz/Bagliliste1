/**
* @file IkiYonluBagliListe.cpp
* @description Bağlı liste sınıfının gövde kısmı
* @course Veri yapıları 2. Öğretim B grubu
* @assignment 1. Ödev
* @date Son işlem 11 Kasım 2021
* @author Burak Ortakuz burak.ortakuz@ogr.sakarya.edu.tr
*/
#include "IkiYonluBagliListe.hpp"
#include <sstream> 
#include <fstream>
IkiYonluBagliListe::IkiYonluBagliListe()
{
    ilk=0;
    boyut=-1;
    std::ifstream listeOku("./doc/Veri.txt");
    listeOku.seekg(0);

    while(!listeOku.eof()){
        std::string alınanVeri="";
        getline(listeOku,alınanVeri);
        if(alınanVeri=="") return;
        if(alınanVeri[0]=='S'){
            int alınanSıra;
            std::stringstream ss;
            ss<<alınanVeri.substr(alınanVeri.find_first_of('(')+1,alınanVeri.find_first_of(')')-alınanVeri.find_first_of('(')-1);  
            ss>>alınanSıra;         
            sil(alınanSıra);                     
        }else if(alınanVeri[0]='E'){
            int alınanSıra;
            std::stringstream ss;
            ss<<alınanVeri.substr(alınanVeri.find_first_of('(')+1, alınanVeri.find_first_of(')')- alınanVeri.find_first_of('#'));
            ss>>alınanSıra;
            std::string parcalananVeri=alınanVeri.substr(alınanVeri.find_first_of('#')+1,alınanVeri.find_first_of(')')-alınanVeri.find_first_of('#')-1);            
            ekle(alınanSıra,parcalananVeri);
        }
    }    
    yazdır();
}
IkiYonluBagliListe::~IkiYonluBagliListe(){
    temizle();
}
void IkiYonluBagliListe::ekle(int sıra,std::string veri){

    if(ilk==0){
        Dugum* gelenVeri= new Dugum(veri);
        ilk=gelenVeri;
    }else if(sıra>boyut){
        Dugum* gec= yerBul(boyut);
        Dugum* gelenVeri= new Dugum(veri);
        gec->sonraki=gelenVeri;
        gelenVeri->onceki=gec;
    }else{
        Dugum* gecici= yerBul(boyut);
        Dugum* gelenVeri= new Dugum("");  
        gecici->sonraki=gelenVeri;
        gelenVeri->onceki= gecici;
        gecici=gecici->sonraki;  
        for(int i=boyut+1; i>sıra;i-- ){            
            if(gecici!=ilk){
                gecici->veri=gecici->onceki->veri;
                gecici=gecici->onceki;
            }
            
        }                
        if(sıra==0){
            ilk->sonraki->veri=ilk->veri;
            ilk->veri=veri;
        }{
            gecici->veri=veri;
        }
    }
    boyut++;
}

void IkiYonluBagliListe::sil(int sıra){
    
    if(ilk==0) return ;
    if( ilk->sonraki==0){
        delete ilk;
        ilk=0;
    }else if(sıra>=boyut){
        Dugum* gec= yerBul(boyut);
        gec->onceki->sonraki=0;
        delete gec;
    }else{   
        Dugum* gec= yerBul(sıra);
        Dugum* silinecek= yerBul(boyut);
        for(int i=0;i<boyut-sıra;i++){
            if(gec!=ilk){;
                gec->veri=gec->sonraki->veri;
                gec=gec->sonraki;
            }
        }
        if(sıra==0){
            Dugum* yedek=ilk;
            ilk=ilk->sonraki;
            ilk->onceki=0;
            delete yedek;
        }else{
            silinecek->onceki->sonraki=0;        
            delete silinecek;
        }        

    }
    boyut--;    
}   
void IkiYonluBagliListe::yazdır(){
    if(ilk!=0){
        Dugum* gecici;
        gecici=ilk;
        while(gecici!=0){
            std::cout<<gecici->veri;
            if(gecici->sonraki!=0){
                std::cout<<" <--> ";
            }
            gecici= gecici->sonraki;
        }
      
    }    
}

void IkiYonluBagliListe::temizle(){
    Dugum* gecici;
    gecici=ilk;
    while(gecici!=0){
        Dugum* silinecek=gecici;
        gecici=gecici->sonraki;
        delete silinecek;
    }
    boyut=-1;
}
 
Dugum* IkiYonluBagliListe::yerBul(int sıra){
    Dugum* gecici=ilk;
    if(sıra==0){
        return ilk;
    }else{        
        for(int i=0;i<sıra;i++){
            gecici=gecici->sonraki;
        }
        return gecici;
    }
}
