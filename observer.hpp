#ifndef OBSERVER_H
#define OBSERVER_H

class Observer
{
public:
    Observer();

    virtual void notify() = 0;
    virtual void notify(int) = 0;
};

#endif // OBSERVER_H
