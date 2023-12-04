#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
using namespace std;
class Customer
{
public:
    Customer();
    ~Customer();
    string getm_cxname() const;
    void setm_cxname(const string );
    long long getm_phoneNo() const;
    void setm_phoneNo(long long );
    string getm_address() const;
    void setm_address(const string );
    long long getm_adharno() const;
    void setm_adharno(long long );

    void CustomerConfirm();
    void cx_detailsentry();
private:
    string m_cxname;
    long long int m_phoneNo;
    string m_address;
    long long int m_adharno;
};

#endif // CUSTOMER_H
