//
//  Roles.h
//  ChainOfR
//
//  Created by Ruben Cuadra on 10/28/16.
//  Copyright © 2016 Cuadra. All rights reserved.
//

#pragma once

class PurchaseRequest
{
private:
    double amount;
    std::string purpose;
    
public:
    PurchaseRequest(double amt, std::string prp):amount(amt),purpose(prp){}
    
    double getAmount() {return amount;}
    void setAmount(double amt)  {amount = amt;}
    std::string getPurpose() {return purpose;}
    void setPurpose(std::string reason) {purpose = reason;}
};

class PurchasePower
{
protected:
    double amount = 500;
    PurchasePower* succesor;
    
    virtual double getAllowable()=0;
    virtual std::string getRole()=0;
public:
    void setSuccessor(PurchasePower *sc){succesor = sc;}
    
    void processRequest(PurchaseRequest request)
    {
        if (request.getAmount() < getAllowable())
        {
            std::cout<<getRole()<<" will approve $"<<request.getAmount()<<"\n";
        }
        else if (succesor != nullptr)
        {
            succesor->processRequest(request);
        }
        else
        {
            std::cout<<"No hay nadie mas en la cadena\n";
        }
    }
};

class ManagerPPower : public PurchasePower
{
protected:
    double getAllowable(){return amount*10;}
    std::string getRole(){return "Manager";}
};

class DirectorPPower : public PurchasePower
{
protected:
    double getAllowable(){return amount*20;}
    std::string getRole(){return "Director";}
};

class VicePresidentPPower : public PurchasePower
{
protected:
    double getAllowable(){return amount*40;}
    std::string getRole(){return "Vice President";}
};

class PresidentPPower : public PurchasePower
{
protected:
    double getAllowable(){return amount*60;}
    std::string getRole(){return "President";}
};








