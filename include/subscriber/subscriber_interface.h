#ifndef SUBSCRIBER_INTERFACE_H_INCLUDED
#define SUBSCRIBER_INTERFACE_H_INCLUDED

#include <string>
#include "../publisher/publisher_interface.h"

class PublisherIF;

class SubscriberIF {

    public:
        virtual ~SubscriberIF() {};
        virtual void update(const std::string& what_is_changed, int value_change) = 0;
};

#endif // SUBSCRIBER_INTERFACE_H_INCLUDED
