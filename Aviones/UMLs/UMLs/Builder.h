//
//  Builder.h
//  UMLs
//
//  Created by Ruben Cuadra on 8/26/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include "Avion.h"

class Builder
{
protected:
    Avion* avion;
    
public:
    Avion* getAvion() {return new Avion();}
    void createAvion() { avion = getAvion();}
    
    virtual void buildAlas() =0;
    virtual void buildMotor()=0;
    virtual void buildMarca()=0;
    virtual void buildSerie()=0;
    virtual void buildModelo()=0;
};

class BuilderBoeing : public Builder
{
    void buildAlas()
    {
        Alas * boeing_Alas = new Alas("Boeing Wings");
        boeing_Alas->setNumSerie(2312);
        boeing_Alas->setHipersustentador(1000);
        avion->setAlas(boeing_Alas);
    }
    void buildMotor()
    {
        Motor * m = new Motor("Boeing Motors");
        m->setNumSerie(12312);
        m->setPotencia(321);
        avion->setMotor(m);
    }
    void buildMarca(){avion->setMarca("Boeing");}
    void buildSerie(){avion->setNumSerie(12312787);}
    void buildModelo(){avion->setModelo("787");}
};

class Director
{
private:
    Builder* builder;
public:
    void setBuilder(Builder *bd)
    {
        builder = bd;
    }
    
    Avion* getAvion()
    {
        return builder->getAvion();
    }
    
    void construct()
    {
        builder->createAvion();
        builder->buildMarca();
        builder->buildModelo();
        builder->buildAlas();
        builder->buildMotor();
        builder->buildSerie();
    }
};
