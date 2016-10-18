//
//  main.cpp
//  Proxy
//
//  Created by Ruben Cuadra on 10/18/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#include <iostream>

using namespace std;

class ArrayInts;

class Proxy
{
private:
    ArrayInts& arr;
    int index;
public:
    friend class ArrayInts;
    Proxy(ArrayInts& arr, int index) : arr(arr), index(index){}
    
    Proxy& operator = (int value);
    
    friend ostream& operator << (ostream& op, Proxy& yo);
};

class ArrayInts
{
private:
    int *list;
    int size;
public:
    friend class Proxy;
    ArrayInts()
    {
        size = 100;
        list = new int[size];
    }
    Proxy operator[](int index)
    {
        if(index >= 0)
        {
            return Proxy(*this, index);
        }
        else
        {
            cout << "No se aceptan numeros negativos en el inciso" << endl;
            return Proxy(*this, index);
        }
    }
    int getList(int index)
    {
        return *(list+index);
    }
};

Proxy& Proxy::operator=(int value)
{
    {
        if (value >= 0)
        {
            //arr[index] = value;
            *(arr.list + index) = value;
            return *this;
        }
        else
        {
            cout << "Error, tu numero tiene que ser positivo" <<endl;
            return *this;
        }
    }
};

ostream& operator << (ostream& op, Proxy& yo)
{
    op << yo.arr.getList(yo.index);
    return op;
};

int main()
{
    ArrayInts list;
    list[0] = 10;
    list[1] = -10;
    list[-3] = 15;
}
