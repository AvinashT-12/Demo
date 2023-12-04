#ifndef HOTELMANAGEMENT_H
#define HOTELMANAGEMENT_H
#include <iostream>
using namespace std;
#include"hotel.h"
#include"reciept.h"
class HotelManagement
{
public:
    HotelManagement();
   ~HotelManagement();
    void ObjectCall();
private:
   Hotel *newhotelobj;

};

#endif // HOTELMANAGEMENT_H
