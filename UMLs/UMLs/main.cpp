//
//  main.cpp
//  UMLs
//
//  Created by Ruben Cuadra on 8/26/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "Builder.h"
#include "Avion.h"
int main(int argc, const char * argv[])
{
    Director *dir = new Director();
    dir-> setBuilder(new BuilderBoeing());
    dir->construct();
    
    Avion* miAvion = dir->getAvion();
    std::cout<< miAvion->getMarca();
    //std::cout << "Hello, World!\n";
    return 0;
}
