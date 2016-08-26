//
//  Product.h
//  tarea_1
//
//  Created by Ruben Cuadra on 8/18/16.
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

class Product
{
public:
    virtual void set_components() =0;
    virtual void assemble_components()=0;
    virtual void install_software()=0;
    virtual void configure_software()=0;
    virtual void package_product()=0;
    void create_device()
    {
        set_components();
        assemble_components();
        install_software();
        configure_software();
        package_product();
    }
};

class Laptop : public Clon<Product,Laptop>
{
    void set_components()
    {std::cout<<"Buscando componentes para una LAPTOP\n";}
    void assemble_components()
    {std::cout<<"Ensamblando los componentes\n";}
    void install_software()
    {std::cout<<"Instalando MAC OS X\n";}
    void configure_software()
    {std::cout<<"Configurando software\n";}
    void package_product()
    { std::cout<<"Empaquetando\n";}
    friend class ConcreteFactory;
    private: Laptop(){};
};
class Netbook : public Clon<Product,Netbook>
{
    void set_components()
    {std::cout<<"Buscando componentes para una NETBOOK\n";}
    void assemble_components()
    {std::cout<<"Ensamblando los componentes\n";}
    void install_software()
    {std::cout<<"Instalando LUBUNTU\n";}
    void configure_software()
    {std::cout<<"Configurando software\n";}
    void package_product()
    { std::cout<<"Empaquetando\n";}
    friend class ConcreteFactory;
    private: Netbook(){};
};
class Tablet :public Clon<Product,Tablet>
{
    void set_components()
    {std::cout<<"Buscando componentes para una TABLET\n";}
    void assemble_components()
    {std::cout<<"Ensamblando los componentes\n";}
    void install_software()
    {std::cout<<"Instalando Android 6.0\n";}
    void configure_software()
    {std::cout<<"Configurando software\n";}
    void package_product()
    { std::cout<<"Empaquetando\n";}
    friend class ConcreteFactory;
    private: Tablet(){};
};
class Desktop: public Clon<Product,Desktop>
{
    void set_components()
    {std::cout<<"Buscando componentes para una DESKTOP\n";}
    void assemble_components()
    {std::cout<<"Ensamblando los componentes\n";}
    void install_software()
    {std::cout<<"Instalando WINDOWS 10\n";}
    void configure_software()
    {std::cout<<"Configurando software\n";}
    void package_product()
    { std::cout<<"Empaquetando\n";}
    friend class ConcreteFactory;
    private: Desktop(){};
};




