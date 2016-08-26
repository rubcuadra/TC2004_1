//
//  Avion.h
//  UMLs
//
//  Created by Ruben Cuadra on 8/26/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <iostream>

class Motor
{
private:
    std::string marca;
    int num_serie;
    int potencia;
public:
    void setMarca(std::string m){marca = m;}
    void setNumSerie(int m){num_serie = m;}
    void setPotencia(int m){potencia = m;}
    
    Motor(std::string m)
    {
        marca = m;
    }
};

class Alas
{
private:
    std::string marca;
    int num_serie;
    int hipersustentador;
public:
    void setMarca(std::string m){marca = m;}
    void setNumSerie(int m){num_serie = m;}
    void setHipersustentador(int m){hipersustentador = m;}
    Alas(std::string m)
    {
        marca = m;
    }
};

class Piloto
{
    
};

class Avion
{
private:
    std::string marca;
    std::string modelo;
    
    int num_serie;
    Motor *motor;
    Alas  *alas;
    Piloto *pilot;
public:
    void setMarca(std::string m){marca = m;}
    void setNumSerie(int m){num_serie = m;}
    void setModelo(std::string m){modelo = m;}
    void setAlas(Alas* a){alas = a;}
    void setPiloto(Piloto* p){pilot = p;}
    void setMotor(Motor* m){motor = m;}
    
    std::string getMarca(){return marca;}
};