//
//  Servers.h
//  DNS_Chain
//
//  Created by Ruben Cuadra on 10/28/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <map>

class NameResolutionRequest
{
private:
    std::string extension;
    std::string domain_name;
    
public:
    NameResolutionRequest(std::string domainName, std::string _extension):
    extension(_extension),domain_name(domainName){}
    
    std::string getExtension(){return extension;}
    void setExtension(std::string ext){extension = ext;}
    
    std::string getDomainName(){return domain_name;}
    void setDomainName(std::string dn){domain_name=dn;}
    
    std::string getFullName(){return domain_name+"."+extension;}
};

class DomainNameServer
{
protected:
    std::string extension; //Deberia ser un array?
    DomainNameServer* succesor;
    
    DomainNameServer(std::string x):extension(x){}
    std::map<std::string,std::string> name_ip_relation;
    
    virtual void loadDomainsIps()=0; //Wut?

public:
    void setSuccessor(DomainNameServer *sc){succesor = sc;}
    
    void addDomainIP(std::string domain_name_without_extension,std::string ip)
    {
        name_ip_relation.insert(make_pair(domain_name_without_extension,ip));
    }
    
    std::string getIP(std::string domain_name)
    {
        typename std::map<std::string,std::string>::
        iterator it = name_ip_relation.find(domain_name);
        
        if (it!=name_ip_relation.end())
        {
            return it->second; //Existe
        }
        return ""; //No lo encontramos
    }
    
    void processRequest(NameResolutionRequest *request)
    {
        //Este servidor debe conocer todos los que tienen esa extension
        if (request->getExtension() == extension)
        {
            std::cout<<"Buscando en el servidor dedicado a las extensiones: "<<extension<<"\n";
            std::string ip = getIP(request->getDomainName());
            
            if (ip!="")
            {
                std::cout<<"La IP ligada al dominio: "<<request->getFullName()<<" es "<<ip<<"\n";
            }
            else
            {
                std::cout<<"La IP ligada al dominio: "<<request->getFullName()<<" no se encontro\n";
            }
        }
        else if (succesor != nullptr) //Se lo rolamos al que sigue a ver si lo conoce
        {
            succesor->processRequest(request);
        }
        else
        {
            std::cout<<"No hay servidor que conozca "<<request->getFullName()<<"\n";
        }
    }
};

class MXServer : public DomainNameServer
{
public:
    MXServer():DomainNameServer("mx"){ loadDomainsIps(); }
protected:
    void loadDomainsIps()
    {
        addDomainIP("hola","192.168.1.34");
    }
};

class USServer : public DomainNameServer
{
public:
    USServer():DomainNameServer("us"){ loadDomainsIps(); }
protected:
    void loadDomainsIps()
    {
        addDomainIP("hola","192.168.1.39");
    }
    
};



