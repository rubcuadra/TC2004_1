//
//  Pastel.h
//  examen
//
//  Created by Ruben Cuadra on 9/9/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <iostream>

template <class Base, class SubClase>
class Clon : public Base
{
public:
    using Base::Base;
    
    virtual Base* clonar()
    {
        return new SubClase(dynamic_cast<SubClase&>(*this));
    }
};

class Pastel
{
public:
    virtual void batido() =0;
    virtual void amasado()=0;
    virtual void horneado()=0;
    virtual void decorado()=0;
    virtual void empacar()=0;
    void create_cake()
    {
        batido();
        amasado();
        horneado();
        decorado();
        empacar();
    }
};

class Sacher : public Clon<Pastel,Sacher>
{
    void batido()  {std::cout<<"Batiendo "<<name<<"\n";}
    void amasado() {std::cout<<"Amasando " <<name<<"\n";}
    void horneado() {std::cout<<"Amasando "<<name<<"\n";}
    void decorado(){std::cout<<"Decorando "<<name<<"\n";}
    void empacar() {std::cout<<"Empacando "<<name<<"\n";}
    std::string getName() {return name;}
    friend class DF_Factory;
    private:
        Sacher(){};
        std::string name="Sacher";
};

class Imposible : public Clon<Pastel,Sacher>
{
    void batido()  {std::cout<<"Batiendo "<<name<<"\n";}
    void amasado() {std::cout<<"Amasando " <<name<<"\n";}
    void horneado() {std::cout<<"Amasando "<<name<<"\n";}
    void decorado(){std::cout<<"Decorando "<<name<<"\n";}
    void empacar() {std::cout<<"Empacando "<<name<<"\n";}
    std::string getName() {return name;}
    friend class DF_Factory;
    private:
        Imposible(){};
        std::string name="Imposible";
};

class Tres_leches : public Clon<Pastel,Sacher>
{
    void batido()  {std::cout<<"Batiendo "<<name<<"\n";}
    void amasado() {std::cout<<"Amasando " <<name<<"\n";}
    void horneado() {std::cout<<"Amasando "<<name<<"\n";}
    void decorado(){std::cout<<"Decorando "<<name<<"\n";}
    void empacar() {std::cout<<"Empacando "<<name<<"\n";}
    std::string getName() {return name;}
    friend class Aguascalientes_Factory;
    private:
        Tres_leches(){};
        std::string name="Tres leches";
};