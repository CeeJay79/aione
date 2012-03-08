#include "observable.hpp"

Observable::Observable()
{
}


void Observable::registerObserver(Observer* o){

    observers.push_back(o);

}

void Observable::unresgisterObserver(Observer* o){

    observers.remove(o);

}

void Observable::notifyObservers(int __in,NotificationType nType)
{
    std::list<Observer*>::iterator it;
    for (it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->notify(__in,nType);
    }
}

void Observable::notifyObservers()
{
    std::list<Observer*>::iterator it;
    for (it = observers.begin(); it != observers.end(); it++)
    {
        (*it)->notify();
    }
}
