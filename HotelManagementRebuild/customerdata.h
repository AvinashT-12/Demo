#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include <iostream>
using namespace std;
#include"string.h"
class CustomerData
{
public:
    CustomerData();
    ~CustomerData();

    string getm_cxname() const;
    void setm_cxname(const string );
    long long getm_phoneNo() const;
    void setm_phoneNo(long long );
    string getm_address() const;
    void setm_address(const string );
    long long getm_adharno() const;
    void setm_adharno(long long );
    int getm_check_in_date() const;
    void setm_check_in_date(int );
    int getm_advance() const;
    void setm_advance(int );
    int getm_roomno() const;
    void setm_roomno(int newRoomno);
    int getm_hotelId() const;
    void setm_hotelId(int newHotelId);

private:
    int m_hotelId;
    int m_check_in_date;
    int m_advance;
    int m_roomno;
    string m_cxname;
    long long int m_phoneNo;
    string m_address;
    long long int m_adharno;
};

#endif // CUSTOMERDATA_H
