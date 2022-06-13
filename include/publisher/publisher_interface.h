#ifndef PUBLISHER_INTERFACE_H_INCLUDED
#define PUBLISHER_INTERFACE_H_INCLUDED

#include "../subscriber/subscriber_interface.h"

#include <string>
#include <list>

class SubscriberIF;

class PublisherIF {
    public:
        virtual ~PublisherIF() {};
        virtual void RegisterToCANObject(SubscriberIF *subscriber) = 0;
        virtual void UnregisterToCANObject(SubscriberIF * subscriber) = 0;
        virtual void NotifyToSubscriber(const std::string &what_is_change, int value_change) = 0;
    protected:
        std::list<SubscriberIF *> subscriber_list;

};

#endif // PUBLISHER_INTERFACE_H_INCLUDED
