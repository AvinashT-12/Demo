#include "bookingdetails.h"
#include"fstream"
BookingDetails::BookingDetails()
{
    cout<<"Booking details constructor"<<endl;
}
BookingDetails::~BookingDetails()
{
    cout<<"Booking details destructor"<<endl;
}
int BookingDetails::getm_check_in_date() const
{
    return m_check_in_date;
}
void BookingDetails::setm_check_in_date(int newCheck_in_date)
{
    m_check_in_date=newCheck_in_date;
}
int BookingDetails::getm_advance() const
{
    return m_advance;
}
void BookingDetails::setm_advance(int newAdvance)
{
    m_advance = newAdvance;
}
int BookingDetails::getm_roomno() const
{
    return m_roomno;
}
void BookingDetails::setm_roomno(int newRoomno)
{
    m_roomno = newRoomno;
}
//void BookingDetails::BookingConfirm(string l_name,string l_address,long long int l_phoneNo,long long int l_adarNo){
void BookingDetails::BookingConfirm(Customer cxobj){
    ifstream infil;
    infil.open("HotelDetails.json");
    if(infil.is_open()==0){
        cout<<"File can't open\n"<<endl;
    }
    vector<json>vec_obj;

    json hoteljsonobj;
    while (!infil.eof()) {
        try{
            infil>>hoteljsonobj;
            vec_obj.push_back(hoteljsonobj);
        }
        catch(const json::exception &e){
          //  cout<<"Json parsing error handling: "<<e.what()<<endl;
        }
        hoteljsonobj.clear();
    }
    infil.close();
    cout<<"Enter Hotel Id to select Hotel\n"<<endl;
    int hotelid,hotelFlag=0,i=0,BookingFlag=0;
    cin>>hotelid;

    for (const auto &obj:vec_obj) {
        if(obj["Hotel Id"]==hotelid){
            cout<<"Selected Hotel Information:"<<endl;
            cout<<"Hotel Name: "<< obj["Hotel_Name"]<<endl;
            cout<<"Hotel Address: "<< obj["Hotel_Address"]<<endl;
            cout<<"Phone Number: "<< obj["PhoneNumber"]<< endl;
            for (const auto &room:obj["Room Numbers"]) {
                cout<<"Room Number: "<<obj["Room Numbers"][i]["Room_Number"]<<"\tRoom Status: "<<obj["Room Numbers"][i]["Room_Status"]
                    <<"\tRoom Cost: "<<obj["Room Numbers"][i]["Room_Cost"]<<"\t    Ac Avilability: "<<obj["Room Numbers"][i]["Ac_Availability"]<<endl;
                i++;
            }
            hotelFlag=1;
            i=0;
            break;
        }
    }

    if(hotelFlag==1){
        cout<<"Enter which Room you want in Available Rooms"<<endl;
        cin>>m_roomno;
        int flag=0;
        i=0;
        for( auto &hotel:vec_obj){
            for(auto &room:hotel["Room Numbers"])
            {
                int l_rmNo=hotel["Room Numbers"][i]["Room_Number"];
                string l_status=hotel["Room Numbers"][i]["Room_Status"];

                if((l_rmNo==m_roomno)&&(l_status=="UNOCCUPIED")&&hotel["Hotel Id"]==hotelid)
                {
                    hotel["Room Numbers"][i]["Room_Status"]="OCCUPIED";
                    flag=1;
                    BookingFlag=1;
                    break;
                }
                if((l_rmNo==m_roomno)&&(l_status=="OCCUPIED")&&hotel["Hotel Id"]==hotelid)
                {
                    cout<<"Room is already occupied,Kindly book other Room!!!"<<endl;
                    flag=1;
                    break;
                }
                if(flag==1){
                    break;
                }
                i++;
            }
            if(flag==1){
                break;
            }
            i=0;
        }
        if(flag==0){
            cout<<"Entered room is not available,Kindly see available rooms and proceed!!"<<endl;
        }

    }
    else if(hotelFlag==0){
        cout<<"Entered hotel is not available kindly recheck and proceed,Thank You!"<<endl;
    }

    ofstream out_fil,out_file_Customer;
    out_fil.open("HotelDetails.json");
    if(out_fil.is_open()==0){
        cout<<"Json File can't open\n"<<endl;
    }
    out_file_Customer.open("CustomerDetails.csv",ios::app);
    if(out_file_Customer.is_open()==0){
        cout<<"Customer File can't open\n"<<endl;
    }

    if(BookingFlag==1){
        cout<<"Enter check in date in format"<<endl;
        cin>>m_check_in_date;
        cout<<"Enter How much advance you are paying"<<endl;
        cin>>m_advance;
        cout<<"Room is booked Successfully!,Have a Great Day,Thank you!!!"<<endl;

//        out_file_Customer<<"Hotel Id"<<","<<"Customer Name"<<","<<"Address"<<","<<"Phone number"<<","<<"Adhar Number"<<","<<"Room Number"<<","
//                         <<"Check-in-Date"<<","<<"Advance"<<endl;
        out_file_Customer<<hotelid<<","<<cxobj.getm_cxname()<<","<<cxobj.getm_address()<<","<<cxobj.getm_phoneNo()<<","<<cxobj.getm_adharno()<<","<<getm_roomno()<<","<<getm_check_in_date()
                          <<","<<getm_advance()<<endl;
    }
    infil.close();
    fflush(stdin);
    for(auto &obj:vec_obj){
        json outputJson=obj;
        out_fil<<outputJson.dump(4);
    }
    out_fil.close();
    out_file_Customer.close();
}
