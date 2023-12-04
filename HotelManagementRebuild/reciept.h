#ifndef RECIEPT_H
#define RECIEPT_H
#include <iostream>
using namespace std;
#include"vector"
#include"bookingdetails.h"
#include"customerdata.h"
class Reciept:public BookingDetails
{
public:
    Reciept();
    ~Reciept();
    int getm_no_of_days() const;
    void setm_no_of_days(int );
    int getm_check_out_date() const;
    void setm_check_out_date(int );
    int getm_total_amount() const;
    void setm_total_amount(int );
    int getm_balance_amount() const;
    void setm_balance_amount(int );

    void receiptIssue(vector<CustomerData* >,vector<json>);
    void dataRetrival();

private:
    int m_check_out_date;
    int m_total_amount;
    int m_balance_amount;
     int m_no_of_days;
    CustomerData *newCustomeObj;
    vector<CustomerData* >vec_obj2;
};

#endif // RECIEPT_H
