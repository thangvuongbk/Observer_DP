#ifndef SUB_CAN_OBSERVER_H
#define SUB_CAN_OBSERVER_H

#include "subscriber_interface.h"

class sub_CAN_Observer : public SubscriberIF
{
    public:
        sub_CAN_Observer();
        virtual ~sub_CAN_Observer();
        void update(const std::string& what_is_changed, int value_change) override;

    public:
        void RegisterToCANObject(PublisherIF *publisher);
        void UnRegisterToCANObject(PublisherIF *publisher);

    protected:

    private:
        static int number_of_observer;
        int m_number;
};

#endif // SUB_CAN_OBSERVER_H
