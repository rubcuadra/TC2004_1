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

    int find(T e)            //Regresa el index
    {
        return -1;
    }
    bool deleteElement(T e)  //Si lo encontro y lo borro regresa true
    {
        
    }
    
    T* get(int i)
    {
        return list+i;
    }
    int getSize() {return size;}
    
public:
    int getIndex(){return index;}
    ~Aggregate(){delete [] list;}
    void addE(T e)
    {
        if (index==size-1) return; //No se agrega
        list[++index]=e;
    }
    
    Aggregate(int _size): index(-1), size(_size),list(new T[_size]){}
    
    Iterator<T>* getIterator()
    {
        return new Iterator<T>(this);
    }
    void print()
    {
        for (Iterator<T> *iter = this->getIterator(); iter->HasNext();)
        {
            std::cout<<*iter->Next()<<"\n";
        }
        
    }
    friend class Iterator<T>;
};

template <class T>
class Iterator
{
    
private:
    Iterator(){}
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
        return aggregate->getIndex() >= i+1;
    }
    
    Iterator(Aggregate<T> *a)
    {
        aggregate = a;
        i=-1;
    }
    
};