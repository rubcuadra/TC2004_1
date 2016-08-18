//
//  Generator.h
//  tarea_1
//
//  Created by Ruben Cuadra on 8/15/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//


#pragma once
#include <iostream>
#include "Computer.h"
class Generator
{
    public:
    Computer* generate(std::string t);
};
Computer* Generator::generate(std::string type)
{
    if (type == "laptop")
    {
        return new Laptop();
    }
    else if (type == "tablet")
    {
        return new Tablet();
    }
    else if (type == "desktop")
    {
        return new Desktop();
    }
    else if (type == "netbook")
    {
        return new Netbook();
    }
    else
    {
        std::cout<<"No se encontro esa opcion\n";
        return nullptr;
    }
}