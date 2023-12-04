#include "customer.h"
#include "fstream"
#include"bookingdetails.h"
Customer::Customer()
{
    cout<<"Customer constructor"<<endl;
}
Customer::~Customer()
{
    cout<<"Customer destructor"<<endl;
}

long long Customer::getm_phoneNo() const
{
    return m_phoneNo;
}
void Customer::setm_phoneNo(long long newPhoneNo)
{
    m_phoneNo = newPhoneNo;
}
string Customer::getm_address() const
{
    return m_address;
}
long long Customer::getm_adharno() const
{
    return m_adharno;
}
void Customer::setm_adharno(long long newAdharno)
{
    m_adharno = newAdharno;
}
void Customer::setm_address(const string newAddress)
{
    m_address = newAddress;
}
string Customer::getm_cxname() const
{
    return m_cxname;
}
void Customer::setm_cxname(const string newCxname)
{
    m_cxname = newCxname;
}
void Customer::cx_detailsentry(){
    cin.ignore();
    cout<<"Enter Customer name"<<endl;
    getline(cin,m_cxname);
    cout<<"Enter Customer Address"<<endl;
    getline(cin,m_address);
    cout<<"Enter Customer phone number"<<endl;
    cin>>m_phoneNo;
    cout<<"Enter Customer Adhar number"<<endl;
    cin>>m_adharno;
}
void Customer::CustomerConfirm(){
    cout<<"Enter 1 to continue with Booking\nEnter 2 for exit"<<endl;
    int num;
    cin>>num;
    Customer cxobj;
    cxobj.setm_cxname(m_cxname);
    cxobj.setm_phoneNo(m_phoneNo);
    cxobj.setm_phoneNo(m_phoneNo);
    cxobj.setm_address(m_address);
//    ofstream outfile;
//    outfile.open("CustomerDetails.csv",ios::app);
    if(num==1){
//        outfile<<getm_cxname()<<","<<getm_address()<<","<<getm_phoneNo()<<","<<getm_adharno()<<endl;
//        outfile.close();
        BookingDetails *newbookingobj=new BookingDetails;
newbookingobj->BookingConfirm(cxobj);
        //newbookingobj->BookingConfirm(getm_cxname(),getm_address(),getm_phoneNo(),getm_adharno());
    }
    else{
        return;
    }

}
