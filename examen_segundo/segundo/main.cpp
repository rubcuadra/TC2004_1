//
//  main.cpp
//  examen_segundo
//
//  Created by Ruben Cuadra on 10/21/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
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
    
    MVS *m = new MVS();
    CNN *cnn = new CNN();
    Azteca *az = new Azteca();
    Televisa* tv = new Televisa();
    Formula *fm = new Formula();
    
    while (flag==0)
    {
        std::cout<<"Cual es la noticia?";
        std::cin>>_note;
        
        m->addNew(*current,_note);
        cnn->addNew(*current,_note);
        az->addNew(*current,_note);
        tv->addNew(*current,_note);
        fm->addNew(*current,_note);
        
        std::cout<<"Hay mas noticias?\n0.- SI \n1.- NO\n";
        std:cin>>flag;
    }
    return 0;
    
}
