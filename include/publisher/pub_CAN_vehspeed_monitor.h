#ifndef PUB_CAN_VEHSPEED_MONITOR_H
#define PUB_CAN_VEHSPEED_MONITOR_H

#include "publisher/publisher_interface.h"

class pub_CAN_vehspeed_monitor : public PublisherIF
{
    public:
        pub_CAN_vehspeed_monitor();
        virtual ~pub_CAN_vehspeed_monitor();

        void RegisterToCANObject(SubscriberIF *subscriber) override;
        void UnregisterToCANObject(SubscriberIF * subscriber) override;
        void NotifyToSubscriber(const std::string &what_is_change, int value_change) override;

    public:
        void CreateChangeTest(const std::string& mesg, int value_change);
        int GetNumberSubcriber();

    protected:

    private:
};

#endif // PUB_CAN_VEHSPEED_MONITOR_H
