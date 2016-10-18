//
//  main.cpp
//  Command_Apuntadores
//
//  Created by Ruben Cuadra on 10/18/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//
/*
 Patrón Command aplicado a un arreglo genérico
 *Esta implementación corresponde
 a una implementación de plantillas y funciones (apuntadores a funciones)
 */

#include<map>
#include<string>
#include<iostream>

class Command
{
public:
    template<class T, class Func>
    T execute(T* arr , int size, Func fun)
    {
        return fun(arr, size);
    }
};


template<class T>
T sum(T* arr, int size)
{
    T acum = 0;
    for(int i=0; i<size; i++)
        acum+= arr[i];
    return acum;
}

typedef int(*signature)(int*, int);
typedef char(*sumarChars)(char*,int);

int main(int argc, const char * argv[])
{
    double* arrD = new double[5]{2.1,3.5, 2.3,4.3,1.4};
    char* arrC = new char[5]{'R','U','B','E','N'};
    int* arrI = new int[2]{12, 22};
    
    Command c;
    
    //Aplicar la función a un arreglo de enteros
    std::cout << c.execute<double, double(*)(double*,int)>(arrD, 5, sum) << "\n";
    //Aplicar la función a un arreglo de chars
    std::cout << c.execute<char,sumarChars>(arrC, 5, sum)<< "\n";
    //Aplicar la función a un arreglo de ints, pero guardando la definición de la función en un typedef
    std::cout << c.execute<int, signature>(arrI, 5, sum)<<"\n";
    
    //Guardar una funcion usando el typedef
    signature f = &sum<int>;
    std::cout<<f( arrI ,2)<<"\n";
    return 0;
}
