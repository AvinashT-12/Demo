#include <iostream>
using namespace std;
#include"hotelmanagement.h"
int main()
{
    HotelManagement *hotelmanajobj=new HotelManagement;
    hotelmanajobj->ObjectCall();
    delete hotelmanajobj;
    return 0;
}
