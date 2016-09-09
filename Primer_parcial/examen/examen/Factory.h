//
//  Factory.h
//  tarea_1
//
//  Created by Ruben Cuadra on 8/18/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include "Pastel.h"
class Factory
{
public:
    
    virtual Pastel* factoryMethod(int)=0;
    
    Pastel* createPastel(int tipo)
    {
        Pastel* myCake = factoryMethod(tipo);
        if(myCake)myCake->create_cake();
        return myCake;
    }
};

class DF_Factory : public Factory
{
    
    Pastel* factoryMethod(int tipo)
    {
        switch (tipo)
        {
            case 1:
                return new Sacher;
            case 2:
                return new Imposible;
            default:
                return nullptr;
        }
    }
    public:
    void printIngrediente()
    {
        std::cout<<"Chocolate, frutas, merengue";
    }
        static DF_Factory* GetInstance()
        {
            static DF_Factory* instance = new DF_Factory;
            return instance;
        }
    private: //Obligamos a que NO existan copias
        DF_Factory(){};
        DF_Factory(const DF_Factory &old);
        const DF_Factory &operator=(const DF_Factory &old);
};


class Aguascalientes_Factory : public Factory
{
    Pastel* factoryMethod(int tipo)
    {
        switch (tipo)
        {
            case 1:
                return new Tres_leches;
            default:
                return nullptr;
        }
    }
public:
    void printIngrediente()
    {
        std::cout<<"Leche, Huevo, Mantequilla";
    }

    static Aguascalientes_Factory* GetInstance()
    {
        static Aguascalientes_Factory* instance = new Aguascalientes_Factory;
        return instance;
    }
private: //Obligamos a que NO existan copias
    Aguascalientes_Factory(){};
    Aguascalientes_Factory(const Aguascalientes_Factory &old);
    const Aguascalientes_Factory &operator=(const Aguascalientes_Factory &old);
};

