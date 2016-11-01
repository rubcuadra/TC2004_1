//
//  Servers.h
//  DNS_Chain
//
//  Created by Ruben Cuadra on 10/28/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once
#include <map>
#include <set>

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
    DomainNameServer* succesor;
    std::string serverName;
    std::map<std::string,std::string> name_ip_relation;
    std::set<std::string> known_extensions;
    DomainNameServer(std::string sName):serverName(sName){}

    virtual void loadDomainsIps()=0; //Wut?

public:
    void setSuccessor(DomainNameServer *sc){succesor = sc;}
    
    bool inKnownExtensions(std::string extens)
    {
        return known_extensions.find(extens) != known_extensions.end();
    };
    
    void addDomainIP(std::string domain_name_without_extension,std::string extens,std::string ip)
    {
        
        if (!inKnownExtensions(extens)) known_extensions.insert(extens);
        name_ip_relation.insert(make_pair(domain_name_without_extension+"."+extens,ip));
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
        if ( inKnownExtensions(request->getExtension()) )
        {
            std::cout<<"Buscando en "<<serverName<<"\n";
            std::string ip = getIP(  request->getFullName()  );
            
            if (ip!="")
            {
                std::cout<<"La IP ligada al dominio: "<<request->getFullName()<<" es "<<ip<<"\n";
            }
            else
            {
                if (succesor != nullptr) //Significa que teniamos la extension pero no el dominio
                    succesor->processRequest(request); //Que otro intente
                else
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
    MXServer():DomainNameServer("Server mexicano"){ loadDomainsIps(); }
protected:
    void loadDomainsIps()
    {
        addDomainIP("hola","mx","192.168.1.34");
        addDomainIP("hola","com","192.168.1.35");
        addDomainIP("hola","ru","192.168.1.35");
    }
};

class USServer : public DomainNameServer
{
public:
    USServer():DomainNameServer("Server Gringo"){ loadDomainsIps(); }
protected:
    void loadDomainsIps()
    {
        addDomainIP("hola","us","192.168.1.39");
        addDomainIP("adios","ru","192.168.1.39");
    }
    
};



