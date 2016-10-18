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

template<class T>
class Command
{
public:
    virtual T execute(T*, int) = 0;
};

template<class T>
class Sum : public Command<T>
{
    T execute(T* arr, int size)
    {
        T  acum = 0;
        for (int i = 0; i < size; i++)
        {
            acum += arr[i];
        }
        return acum;
    }
};

template <class T>
class Operaciones
{
    std::map<std::string,Command<T>*> operaciones;
public:
    Operaciones()
    {}
    
    void insert(std::string s, Command<T>* func)
    {
        operaciones.insert(make_pair(s, func));
    }
    
    Command<T>* getOp(std::string op)
    {
        typename std::map<std::string,Command<T>*>::iterator it = operaciones.find(op);
        
        if (it!=operaciones.end())
        {
            return it->second;
        }
        return NULL;
    }
};

