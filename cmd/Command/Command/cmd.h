//
//  cmd.h
//  Command
//
//  Created by Ruben Cuadra on 10/14/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <map>
#include <iostream>
#include <string>

template <class T, class Func>
class Command
{
public:
    virtual T execute(T* , int, Func)=0;
};

template <class T, class Func>
class Sum: public Command<T,Func>
{
    T execute(T* arr, int size, Func f)
    {
        T acum = 0;
        for (int i = 0; i<size; ++i)
        {
            acum += arr[i];
        }
        return acum;
    }
};

template <class T,class Func>
class Operaciones
{
    std::map<std::string,Command<T,Func>*> operaciones;
public:
    Operaciones()
    {
        operaciones.insert( std::make_pair("suma",new Sum<T,Func>()));
    }
    
    Command<T,Func>* getOp(std::string op)
    {
        typename std::map<std::string,Command<T,Func>*>::iterator it = operaciones.find(op);
        
        if (operaciones.find(op)!=operaciones.end())
        {
            return it->second;
        }
        return NULL;
    }
};

