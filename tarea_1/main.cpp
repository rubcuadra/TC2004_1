//
//  main.cpp
//  tarea_1
//
//  Created by Ruben Cuadra on 8/12/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include "Computer.h"
#include <iostream>

int main(int argc, const char * argv[])
{
    Computer *test = new Laptop(); delete test;
    test = new Netbook();          delete test;
    test = new Desktop();          delete test;
    test = new Server();           delete test;
    return 0;
}
