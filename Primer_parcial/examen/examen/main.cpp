//
//  main.cpp
//  iterators
//
//  Created by Ruben Cuadra on 9/2/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "Aggregate.h"
#include "Sucursal.h"
#include "Factory.h"

int main(int argc, const char * argv[]) {
    
    //Selecciona Fabrica -> 1 Fabrica por ciudad, puede tener muchas sucursales
    DF_Factory *f = DF_Factory::GetInstance();  //(1 -> Sacher 2 -> Imp)
    Aguascalientes_Factory *a = Aguascalientes_Factory::GetInstance();
    //Listas con iteradores
    Sucursal *aguascalientes_centro = new Sucursal();
    Sucursal *DF_SantaFe = new Sucursal();
    //Agregarlos
    aguascalientes_centro->addCake("Tres leches", a->createPastel(1));
    aguascalientes_centro->addCake("Tres leches", a->createPastel(1));
    //Iteramos
    aguascalientes_centro->printCakes("Tres leches");
    
    return 0;
}
