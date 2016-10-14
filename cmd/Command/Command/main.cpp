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
    Operaciones<double,int> op;
    double *arrD = new double[5]{2.1,3.2,4.4,5.1,2.1};
    Command<double, int> * c = op.getOp("suma");
    std::cout << c->execute(arrD,5,0);
    return 0;
}
