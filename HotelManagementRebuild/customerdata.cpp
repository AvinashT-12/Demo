#include "customerdata.h"

CustomerData::CustomerData()
{
    cout<<"Customer constructor"<<endl;
}
CustomerData::~CustomerData()
{
    cout<<"Customer destructor"<<endl;
}

long long CustomerData::getm_phoneNo() const
{
    return m_phoneNo;
}
void CustomerData::setm_phoneNo(long long newPhoneNo)
{
    m_phoneNo = newPhoneNo;
}
string CustomerData::getm_address() const
{
    return m_address;
}
long long CustomerData::getm_adharno() const
{
    return m_adharno;
}
void CustomerData::setm_adharno(long long newAdharno)
{
    m_adharno = newAdharno;
}
void CustomerData::setm_address(const string newAddress)
{
    m_address = newAddress;
}
string CustomerData::getm_cxname() const
{
    return m_cxname;
}
void CustomerData::setm_cxname(const string newCxname)
{
    m_cxname = newCxname;
}
int CustomerData::getm_check_in_date() const
{
    return m_check_in_date;
}
void CustomerData::setm_check_in_date(int newCheck_in_date)
{
    m_check_in_date=newCheck_in_date;
}
int CustomerData::getm_advance() const
{
    return m_advance;
}
void CustomerData::setm_advance(int newAdvance)
{
    m_advance = newAdvance;
}
int CustomerData::getm_roomno() const
{
    return m_roomno;
}
void CustomerData::setm_roomno(int newRoomno)
{
    m_roomno = newRoomno;
}

int CustomerData::getm_hotelId() const
{
    return m_hotelId;
}

void CustomerData::setm_hotelId(int newHotelId)
{
    m_hotelId = newHotelId;
}
