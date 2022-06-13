#include <iostream>
#include "publisher/pub_CAN_vehspeed_monitor.h"
#include "sub_CAN_Observer.h"

using namespace std;

int main()
{
    /* Create a publisher */
    pub_CAN_vehspeed_monitor *pub_object = new pub_CAN_vehspeed_monitor();
    sub_CAN_Observer* sub_object = new sub_CAN_Observer(pub_object);
    sub_CAN_Observer* sub_object_2 = new sub_CAN_Observer(pub_object);
    sub_CAN_Observer* sub_object_3 = new sub_CAN_Observer(pub_object);
    sub_CAN_Observer* sub_object_4 = new sub_CAN_Observer(pub_object);

    /* sub register to pub */
    cout << "\n\n";
    sub_object->RegisterToCANObject();
    sub_object_2->RegisterToCANObject();
    sub_object_3->RegisterToCANObject();
    sub_object_4->RegisterToCANObject();

    /* Create a test */
    cout << "\n\n";
    pub_object->CreateChangeTest("Vehicle speed", 100);
    cout << "\n\n";
    pub_object->CreateChangeTest("Vehicle speed", 500);

    /* Unregister and more testing */
    cout << "\n\n";
    sub_object->UnRegisterToCANObject();
    sub_object_3->UnRegisterToCANObject();
    cout << "\n\n";
    pub_object->CreateChangeTest("Vehicle speed", 1500);

    delete pub_object;
    delete sub_object;
    delete sub_object_2;
    delete sub_object_3;
    delete sub_object_4;

    return 0;
}
