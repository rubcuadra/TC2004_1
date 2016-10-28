//
//  main.cpp
//  ChainOfR
//
//  Created by Ruben Cuadra on 10/28/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "Roles.h"

int main(int argc, const char * argv[])
{
    ManagerPPower *manager = new ManagerPPower();
    DirectorPPower *director = new DirectorPPower();
    VicePresidentPPower *vp = new VicePresidentPPower();
    PresidentPPower *president = new PresidentPPower();
    
    manager->setSuccessor(director);
    director->setSuccessor(vp);
    vp->setSuccessor(president);
    
    PurchaseRequest *current;
    double amount = 29000;
    
    current = new PurchaseRequest(amount,"general");
    manager->processRequest(*current);
    
    return 0;
}
