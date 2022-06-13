#include "sub_CAN_Observer.h"

#include <iostream>
#include <string>

using namespace std;

int sub_CAN_Observer::number_of_observer = 0;

sub_CAN_Observer::sub_CAN_Observer(PublisherIF* publisher) : pub_object(publisher)
{
    cout << "ctor: " << __func__ << endl;
}

sub_CAN_Observer::~sub_CAN_Observer()
{
    cout << "dtor: " << __func__ << endl;
}

void sub_CAN_Observer::update(const std::string& what_is_changed, int value_change)
{
    cout << "Entering func: " << __func__ << endl;
    cout << "Receiving from CAN change for observer: \"" << m_number << "\".\n";
    cout << "--> What is change: " << what_is_changed << endl;
    cout << "--> Value change  : " << value_change << endl;
    cout << "Leaving func: " << __func__ << endl;
}

void sub_CAN_Observer::RegisterToCANObject()
{
    cout << "Entering func: " << __func__ << endl;
    pub_object->RegisterToCANObject(this);
    cout << "Hi, I'm the Observer \"" << ++number_of_observer << "\".\n";
    m_number = number_of_observer;
    cout << "Leaving func: " << __func__ << endl;
}

void sub_CAN_Observer::UnRegisterToCANObject()
{
    cout << "Entering func: " << __func__ << endl;
    pub_object->UnregisterToCANObject(this);
    cout << "Observer: \"" << m_number << "\" removed from the list\n";
    cout << "Leaving func: " << __func__ << endl;
}
