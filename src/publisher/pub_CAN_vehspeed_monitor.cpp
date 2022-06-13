#include "publisher/pub_CAN_vehspeed_monitor.h"

#include <iostream>

using namespace std;

pub_CAN_vehspeed_monitor::pub_CAN_vehspeed_monitor()
{
    cout << "ctor: " << __func__ <<  endl;
}

pub_CAN_vehspeed_monitor::~pub_CAN_vehspeed_monitor()
{
    cout << "dtor: " << __func__ <<  endl;
}

void pub_CAN_vehspeed_monitor::RegisterToCANObject(SubscriberIF* subscriber)
{
    cout << "Entering func: " << __func__ << endl;
    subscriber_list.push_back(subscriber);
    cout << "Leaving func: " << __func__ << endl;
}

void pub_CAN_vehspeed_monitor::UnregisterToCANObject(SubscriberIF* subscriber)
{
    cout << "Entering func: " << __func__ << endl;
    subscriber_list.remove(subscriber);
    cout << "Leaving func: " << __func__ << endl;
}

void pub_CAN_vehspeed_monitor::NotifyToSubscriber(const std::string& what_is_change, int value_change)
{
    cout << "Entering func: " << __func__ << endl;
    auto it = subscriber_list.begin();
    cout << "Number of current subscriber is: " << GetNumberSubcriber() << endl;
    while(it != subscriber_list.end()) {
        (*it)->update(what_is_change, value_change);
        ++it;
    }
    cout << "Leaving func: " << __func__ << endl;
}

/* This is for testing purpose only */
void pub_CAN_vehspeed_monitor::CreateChangeTest(const std::string& mesg, int value_change)
{
    NotifyToSubscriber(mesg, value_change);
}

int pub_CAN_vehspeed_monitor::GetNumberSubcriber()
{
    return subscriber_list.size();
}
