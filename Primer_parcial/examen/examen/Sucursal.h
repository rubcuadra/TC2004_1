//
//  Sucursal.h
//  examen
//
//  Created by Ruben Cuadra on 9/9/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <cstdlib>
#include <map>
#include "Pastel.h"

class Sucursal
{
private:
    std::map<std::string,Aggregate<Pastel*>* > m;  //Ponemos nombre y nos regresara la lista de pasteles
public:
    void addCake(std::string typeOfCake, Pastel* newCake)
    {
        Aggregate<Pastel*> *temp;
        if (m.find(typeOfCake)==m.end()) 
        {
            temp = new Aggregate<Pastel*>(10);
            temp->addE(newCake);
            m.insert( std::pair<std::string,Aggregate<Pastel*>* >(typeOfCake, temp ));
        }
        else
        {
            temp = m.at(typeOfCake);
            temp->addE(newCake);
        }
    }
    int getTotalCakes(std::string typeOfCake)
    {
        if (m.find(typeOfCake)==m.end())
        {
            return 0;
        }
        return m.at(typeOfCake)->getIndex()+1;
    }
    void printCakes(std::string typeOfCake)
    {
        if (m.find(typeOfCake)==m.end())
        {
            std::cout<<"No hay pasteles de tipo "<<typeOfCake;
        }
        m.at(typeOfCake)->print();

        
    }
};
