#ifndef HOTEL_H
#define HOTEL_H
#include <iostream>
using namespace std;
#include"customer.h"
#include"bookingdetails.h"
#include"json.hpp"
using json=nlohmann::json;

class Hotel
{
public:
    Hotel();
    ~Hotel();
    string getm_name() const;
    void setm_name(const string );
    string getm_address() const;
    void setm_address(const string );
    int getm_phoneNumber() const;
    void setm_phoneNumber(int );
    void hotelFileReadDetails();
    void hotelfileWrite();
    int getm_HotelId() const;
    void setm_HotelId(int );
    string getm_RoomStaus() const;
    void setm_RoomStaus(const string );

    void hotelObjdet();   
private:
    string m_name;
    string m_address;
    int m_phoneNumber;
    int m_HotelId;
    string m_RoomStaus;
    Customer *newcxobj;
  //  json *jsonRmObj=nullptr;
};

#endif // HOTEL_H
