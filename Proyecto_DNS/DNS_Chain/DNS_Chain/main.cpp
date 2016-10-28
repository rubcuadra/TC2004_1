//
//  main.cpp
//  DNS_Chain
//
//  Created by Ruben Cuadra on 10/28/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "Servers.h"

int main(int argc, const char * argv[])
{
    MXServer *mx = new MXServer();
    USServer *us = new USServer();
    
    mx->setSuccessor(us);
    //us->setSuccessor(vp);
    
    NameResolutionRequest *current;
    
    std::string to_resolve_name = "hola";
    std::string to_resolve_extension = "ru";
    
    current = new NameResolutionRequest(to_resolve_name,to_resolve_extension);
    mx->processRequest(current);
    
    return 0;
}
