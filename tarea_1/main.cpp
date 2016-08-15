//
//  main.cpp
//  tarea_1
//
//  Created by Ruben Cuadra on 8/12/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include "Computer.h"
#include "Generator.h"
#include <iostream>


int main(int argc, const char * argv[])
{
    Generator factory;
    Computer *test = factory.generate("laptop");  delete test;
    test = factory.generate("tablet");            delete test;
    test = factory.generate("desktop");           delete test;
    test = factory.generate("netbook");           delete test;
    return 0;
}
