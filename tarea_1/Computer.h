//
//  Computer.h
//  tarea_1
//
//  Created by Ruben Cuadra on 8/12/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//
#pragma once
#include <iostream>
class Computer
{
protected:
    std::string name;
    std::string software;
    std::string box;
    void set_components();
    void assemble_components();
    void install_software();
    void configure_software();
    void package_product();
    void create_device();
    Computer(std::string n,std::string s);
public:
    ~Computer();
};

Computer::Computer(std::string name,std::string software)
{
    this->name = name;
    this->software = software;
    create_device();
}
Computer::~Computer()
{
    std::cout<<"Destruyendo "<<name<<"\n\n";
}
// MARK: Metodos de ensamble
void Computer::set_components()
{
    std::cout<<"Buscando componentes para una "<<name<<"\n";
}
void Computer::assemble_components()
{
    std::cout<<"Ensamblando los componentes"<<"\n";
}
void Computer::install_software()
{
    std::cout<<"Instalando "<<software<<"\n";
}
void Computer::configure_software()
{
    std::cout<<"Configurando software"<<"\n";
}
void Computer::package_product()
{
    std::cout<<"Empaquetando"<<"\n";
}

void Computer::create_device()
{
    set_components();
    assemble_components();
    install_software();
    configure_software();
    package_product();
}

// MARK: SubClases
class Laptop:  public Computer
{
public:
    Laptop() :Computer("Laptop","Mac OS X"){}
};

class Netbook: public Computer
{
public:
    Netbook():Computer("Netbook","Lubuntu 14"){}
};

class Desktop: public Computer
{
public:
    Desktop():Computer("Desktop","Windows 10"){}
};
class Tablet:public Computer
{
public:
    Tablet() :Computer("Tablet","Android 6.0"){}
};
