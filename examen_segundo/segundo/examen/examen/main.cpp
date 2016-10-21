//
//  main.cpp
//  examen_segundo
//
//  Created by Ruben Cuadra on 10/21/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include <vector>
#include "models.h"

int main(int argc, const char * argv[])
{
    int user = 0; int flag = 0;
    std::string _note;
    std::cout<<"Que usuario posteara?\n 1 .- P.Nieto \n 2 .-Hilary\n 3 .- Trump\n";
    std::cin>>user;
    
    Person *current = nullptr;
    switch (user)
    {
        case 1:
            current = new Nieto();
            break;
        case 2:
            current = new Hillary();
            break;
        case 3:
            current = new Trump();
            break;
        default:
            std::cout<<"Usuario incorrecto\n";
            return 1;
    }
    
    vector<Noticiero*> nt;
    nt.push_back( new MVS() );
    nt.push_back( new CNN() );
    nt.push_back( new Azteca() );
    nt.push_back( new Televisa() );
    nt.push_back( new Formula() );
    
    while (flag==0)
    {
        std::cout<<"Cual es la noticia?";
        std::cin >>_note;
        
        for ( auto &i : nt ) //Iterador de c++11
            i->addNew(*current,_note);
        
        std::cout<<"Hay mas noticias?\n0.- SI \n1.- NO\n";
        std:cin>>flag;
    }
    return 0;
}
