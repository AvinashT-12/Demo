#include "hotelmanagement.h"

HotelManagement::HotelManagement()
{
    cout<<"Hotel Management Constructor"<<endl;

}
HotelManagement::~HotelManagement(){
    cout<<"Hotel Management destructor"<<endl;
}
void HotelManagement::ObjectCall(){
    newhotelobj=new Hotel;
    Reciept *newRecObj=new Reciept;
    while(1){
    cout<<"\n-----For Admin-------\nEnter password to add hotel details\n\n-----For Customer-----\nEnter 1 to see all available hotel details\nEnter 2 for Customer Entry\nEnter 3 for receipt\nEnter 4 for exit"<<endl;
    int num;
    cin>>num;
    enum choose{
        ADMIN=1204,HOTELDETAILS=1,CUSTOMERENTRY=2,RECIEPT=3,EXIT=4
    };

    switch(num){
    case ADMIN:
        newhotelobj->hotelfileWrite();
        exit(2);
        break;
    case HOTELDETAILS:
        newhotelobj->hotelFileReadDetails();
        break;
    case CUSTOMERENTRY:
        newhotelobj->hotelObjdet();
        break;
    case RECIEPT:
        newRecObj->dataRetrival();
        break;
    case EXIT:
        exit(0);

    }
    }
    delete newhotelobj;
}
