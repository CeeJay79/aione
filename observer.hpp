#ifndef OBSERVER_H
#define OBSERVER_H

enum NotificationType
{
    NODE_UPDATE,
    EDGE_UPDATE
};

class Observer
{
public:
    Observer();

    virtual void notify() = 0;
    virtual void notify(int,NotificationType) = 0;
};

#endif // OBSERVER_H
