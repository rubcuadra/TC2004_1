//
//  main.cpp
//  Command
//
//  Created by Ruben Cuadra on 10/14/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "cmd.h"


int main(int argc, const char * argv[])
{
    //Command orientado a Objetos
    double *arrD = new double[5]{2.1,3.2,4.4,5.1,2.1};
    Operaciones<double> op;
    op.insert("suma", new Sum<double>);
    Command<double> * c = op.getOp("suma");
    std::cout << c->execute(arrD,5)<<"\n";
    
    return 0;
}
