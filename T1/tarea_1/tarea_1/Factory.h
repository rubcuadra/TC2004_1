//
//  Factory.h
//  tarea_1
//
//  Created by Ruben Cuadra on 8/18/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include "Product.h"
class Factory
{
public:
    virtual Product* factoryMethod(int)=0;
    
    Product* createProduct(int tipo)
    {
        Product* myProduct = factoryMethod(tipo);
        if(myProduct)myProduct->create_device();
        return myProduct;
    }
};

class ConcreteFactory : public Factory
{
    Product* factoryMethod(int tipo)
    {
        switch (tipo)
        {
            case 1:
                return new Laptop;
            case 2:
                return new Desktop;
            case 3:
                return new Tablet;
            case 4:
                return new Netbook;
            default:
                return nullptr;
        }
    }
    public:
        static ConcreteFactory* GetInstance()
        {
            static ConcreteFactory* instance = new ConcreteFactory;
            return instance;
        }
    private: //Obligamos a que NO existan copias
        ConcreteFactory(){};
        ConcreteFactory(const ConcreteFactory &old);
        const ConcreteFactory &operator=(const ConcreteFactory &old);
    
};