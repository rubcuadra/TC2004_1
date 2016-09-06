//
//  main.cpp
//  iterators
//
//  Created by Ruben Cuadra on 9/2/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>
#include "it.h"

int main(int argc, const char * argv[]) {
    // insert code here...
    
    Aggregate<int> *a = new Aggregate<int>(3);
    
    a->addE(1); a->addE(3); a->addE(4); a->addE(5);
    
    
    for (Iterator<int> *iter = a->getIterator(); iter->HasNext();)
    {
         std::cout<<*iter->Next()<<"\n";
    }
    return 0;
}
