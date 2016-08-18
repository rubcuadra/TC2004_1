//
//  main.cpp
//  tarea_1
//
//  Created by Ruben Cuadra on 8/12/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "Factory.h"

int main(int argc, const char * argv[])
{
    ConcreteFactory *f = ConcreteFactory::GetInstance();
    Product *p = f->createProduct(1);
    f->createProduct(2);
    f->createProduct(3);
    f->createProduct(4);
    f->createProduct(5);
    return 0;
}
