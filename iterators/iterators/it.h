//
//  it.h
//  iterators
//
//  Created by Ruben Cuadra on 9/2/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once

template <class T>
class Iterator;

template <class T>
class Aggregate
{
private:
    T* list;
    int index;
    int size;

    void add(T e)
    {
        ++index;
        list[index]=e;
    }
    int find(T e)            //Regresa el index
    {
        return -1;
    }
    bool deleteElement(T e)  //Si lo encontro y lo borro regresa true
    {
        
    }
    int getIndex(){return index;}
    
    T* get(int i)
    {
        return (list+i);
    }
    int getSize() {return size;}
    
public:
    void addE(T e)
    {
        if (index==size-1)
        {
            //NO SE AGREGO
            return;
        }
        ++index;
        list[index]=e;
    }
    
    Aggregate(int _size)
    {
        size = _size;
        index = -1;
        list = new T[size];
    }
    Iterator<T>* getIterator()
    {
        return new Iterator<T>(this);
    }
    friend class Iterator<T>;
};

template <class T>
class Iterator
{
    
private:
    Aggregate<T>* aggregate;
    int i;
    
public:
    T* first(){ return aggregate->get(0); }

    T* Next()
    {
        ++i;
        return aggregate->get(i);
    }
    
    bool HasNext()
    {
        return aggregate->getSize() > i+1;
    }
    
    T* CurrentItem(){ return aggregate->get(i);}
    
    Iterator(Aggregate<T> *a)
    {
        aggregate = a;
        i=-1;
    }
    
};