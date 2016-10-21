//
//  models.h
//  examen_segundo
//
//  Created by Ruben Cuadra on 10/21/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <iostream>

using namespace std;

class Person
{
protected:
    std::string name;
public:
    std::string getName(){return name;}
    Person(std::string n): name(n){}
    Person(){}
};

class Nieto : public Person{public:Nieto():Person("Peña Nieto"){}};
class Hillary: public Person{public:Hillary():Person("Hillary Clinton"){}};
class Trump : public Person{public:Trump():Person("Trump"){}};

class NoticeObserver
{
    std::string noticieroName;
public:
    //constructor
    NoticeObserver(std::string name): noticieroName(name)
    {}
    //update function es llamada por observer cuando haya algún cambio en valores
    void post(std::string from,std::string note)
    {
        cout <<noticieroName<<" reportando : "<<"Noticia de "<<from<<" "<<note<<"\n";
    }
};

class Noticiero
{
protected:
    string name;
    string *news;
    Person *who;
    int index;
    int size;
    //objetos de tipo observers son parte de Subject. para extender funcionalidad sería un arreglo dinámico de objetos observadores
    NoticeObserver *notesObserver;
    Noticiero(std::string nm) : index(0),size(20),name(nm)
    {
        news = new std::string[size];
        who = new Person[size];
        notesObserver = new NoticeObserver(name);
    }
    void notify() {notesObserver->post(who[index].getName(),news[index]);}
public:
    //asignar valor guarda el valor deseado y manda llamar notify
    virtual void addNew(Person _who,std::string _note) = 0;
};

class MVS : public Noticiero
{
public:
    MVS() : Noticiero("MVS Noticias"){}
    
    void addNew(Person _who,std::string _note)
    {
        news[index]=_note;
        who[index] = _who;
        notify();
        index++;
    }
};
class Televisa : public Noticiero
{
public:
    Televisa() : Noticiero("Televisa"){}
    
    void addNew(Person _who,std::string _note)
    {
        news[index]=_note;
        who[index] = _who;
        notify();
        index++;
    }
};
class Azteca : public Noticiero
{
public:
    Azteca() : Noticiero("Azteca"){}
    
    void addNew(Person _who,std::string _note)
    {
        news[index]=_note;
        who[index] = _who;
        notify();
        index++;
    }
};
class Formula : public Noticiero
{
public:
    Formula() : Noticiero("Formula"){}
    
    void addNew(Person _who,std::string _note)
    {
        news[index]=_note;
        who[index] = _who;
        notify();
        index++;
    }
};

class CNN : public Noticiero
{
public:
    CNN() : Noticiero("CNN Noticias"){}
    void addNew(Person _who,std::string _note)
    {
        //Aqui la ida era un proxy
        if (_who.getName()=="Hillary Clinton" || _who.getName() == "Trump" )
        {
            news[index]=_note;
            who[index] = _who;
            notify();
            index++;
        }
    }
};





