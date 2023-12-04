#include "hotel.h"
#include "json.hpp"
using json=nlohmann::json;
#include"fstream"
#include"string.h"
#include<vector>
#include"customer.h"
int i;
Hotel::Hotel()
{
    cout<<"Hotel constructor,Welcome"<<endl;
}
Hotel::~Hotel()
{
    cout<<"Hotel destructor"<<endl;
}

string Hotel::getm_name() const
{
    return m_name;
}

void Hotel::setm_name(const string newName)
{
    m_name = newName;
}

string Hotel::getm_address() const
{
    return m_address;
}

void Hotel::setm_address(const string newAddress)
{
    m_address = newAddress;
}

int Hotel::getm_phoneNumber() const
{
    return m_phoneNumber;
}
void Hotel::setm_phoneNumber(int newPhoneNumber)
{
    m_phoneNumber = newPhoneNumber;
}
int Hotel::getm_HotelId() const
{
    return m_HotelId;
}

void Hotel::setm_HotelId(int newHotelId)
{
    m_HotelId = newHotelId;
}
string Hotel::getm_RoomStaus() const
{
    return m_RoomStaus;
}

void Hotel::setm_RoomStaus(const string newRoomStaus)
{
    m_RoomStaus = newRoomStaus;
}
void Hotel::hotelfileWrite(){
    ofstream outfil;
    outfil.open("HotelDetails.json",ios::app);
    if(outfil.is_open()==0){
        cout<<"File can't open\n"<<endl;
    }
    int NoOfRms,RmNum[20],RoomCost[20];
    string AcAvailability[20];
    json jsonHotelobj,jsonRmArray;
    cout<<"Enter new hotel name"<<endl;
    cin.ignore();
    getline(cin,m_name);
    cout<<"Enter address"<<endl;
    getline(cin,m_address);
    cout<<"Enter phone number"<<endl;
    cin>> m_phoneNumber;
    cout<<"Enter Hotel Id"<<endl;
    cin>> m_HotelId;
    cout<<"Enter how many rooms your hotel is having"<<endl;
    cin>>NoOfRms;

    m_RoomStaus="UNOCCUPIED";
    for(int i=0;i<NoOfRms;i++){
        cout<<"Enter room numbers\n";
        cin>>RmNum[i];
        cout<<"Enter Room Cost"<<endl;
        cin>>RoomCost[i];
        cout<<"Enter AC for Ac Room or NONAC for Non Ac Room "<<endl;
        cin>>AcAvailability[i];
    }
    jsonRmArray=json::array();
    for (int i=0;i<NoOfRms;i++) {
        //jsonRmObj=new json;
        json jsonRmObj;
        jsonRmObj["Room_Number"]=RmNum[i];
        jsonRmObj["Room_Status"]=getm_RoomStaus();
        jsonRmObj["Room_Cost"]=RoomCost[i];
        jsonRmObj["Ac_Availability"]=AcAvailability[i];
        jsonRmArray.push_back(jsonRmObj);
    }
            jsonHotelobj={
              {"Hotel Id",getm_HotelId()},
              {"Hotel_Name",getm_name()},
              {"Hotel_Address",getm_address()},
              {"PhoneNumber",getm_phoneNumber()},
        {"Room Numbers",jsonRmArray}

        };


    outfil<<jsonHotelobj.dump(4);
    outfil.close();

}

void Hotel::hotelFileReadDetails(){
    ifstream infil;
    infil.open("HotelDetails.json");
    if(infil.is_open()==0){
        cout<<"File can't open\n"<<endl;
    }
    vector<json>vecobj;

//    json *hoteljsonobj[10];
//   for(int i=0;i<2;i++){
//        hoteljsonobj[i]=new json;
//    infil>>*hoteljsonobj[i];
//        vecobj.push_back(*hoteljsonobj[i]);
//    }

    json hoteljsonobj;
    while (!infil.eof()) {
        try{
            infil>>hoteljsonobj;
            vecobj.push_back(hoteljsonobj);
        }
        catch(const json::exception &e){
           // cout<<"Json parsing error handling: "<<e.what()<<endl;
        }
            hoteljsonobj.clear();
        }
     infil.close();

//    infil>>hoteljsonobj;
//    for_each( auto obj1,hoteljsonobj){
//        vecobj.push_back(obj1);
//    }
//    string line;
//    while(getline(infil,line)){
//        if(line.empty()){
//            continue;
//        }
//        try{
//        json hoteljsonobj=json::parse(line);
//        vecobj.push_back(hoteljsonobj);
//        }
//        catch(const json::parse_error& e){
//        cout<<e.what()<<"error handling"<<endl;
//        }
//    }
//    infil.close();
    //json hoteljsonobj;
//    int i=0;
//    while(!infil.eof()){
//        infil>>hoteljsonobj;
//        json hoteljsonobj;
//        vecobj.push_back(hoteljsonobj);
//        //i++;
//    }
//    for(auto &obj:(infil>>hoteljsonobj)){
//        vecobj.push_back(hoteljsonobj);
//    }

    i=0;
    for(const auto &obj:vecobj){
        i=0;
        cout<<"Hotel ID: "<<obj["Hotel Id"]<<"\nHotel :"<<obj["Hotel_Name"]<<"\nAddress: "<<obj["Hotel_Address"]<<
                "\nPhone Number: "<<obj["PhoneNumber"]<<endl;
   cout <<"Room Numbers:\n";
        //cout<<obj["Room Numbers"]<<endl<<endl;
//t<<room["Room_Number"]<<room["Room_Status"]<<endl;
        for (const auto &room:obj["Room Numbers"]) {
            cout<<"Room Number: "<<obj["Room Numbers"][i]["Room_Number"]<<"\tRoom Status: "<<obj["Room Numbers"][i]["Room_Status"]<<
                    "\tRoom Cost: "<<obj["Room Numbers"][i]["Room_Cost"]<<"\t   Ac Avilability: "<<obj["Room Numbers"][i]["Ac_Availability"]<<endl;
            i++;
        }
        cout<<"\n";
        i=0;
         }

    }
void Hotel::hotelObjdet(){
    newcxobj=new Customer;
   newcxobj->cx_detailsentry();
    newcxobj->CustomerConfirm();
    delete newcxobj;
}


