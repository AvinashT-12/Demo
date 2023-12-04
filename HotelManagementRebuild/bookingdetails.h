#ifndef BOOKINGDETAILS_H
#define BOOKINGDETAILS_H
#include <iostream>
#include "customer.h"
using namespace std;
#include"vector"
#include "json.hpp"
using json=nlohmann::json;

//class Customer;
class BookingDetails
{
public:
    BookingDetails();
    ~BookingDetails();
    int getm_check_in_date() const;
    void setm_check_in_date(int );
    int getm_advance() const;
    void setm_advance(int );
    int getm_roomno() const;
    void setm_roomno(int newRoomno);
   // void BookingConfirm(string l_name,string l_address,long long int l_phoneNo,long long int l_adarNo);
    void BookingConfirm(Customer cxobj);
private:
    int m_check_in_date;
    int m_advance;
    int m_roomno;

};

#endif // BOOKINGDETAILS_H
