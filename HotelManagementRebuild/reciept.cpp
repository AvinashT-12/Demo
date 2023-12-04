#include "reciept.h"
#include"sstream"
#include"fstream"
#include"vector"
Reciept::Reciept()
{
    cout<<"Reciept's Constructor"<<endl;
}
Reciept::~Reciept()
{
    cout<<"Reciept's destructor"<<endl;
}

int Reciept::getm_check_out_date() const
{
    return m_check_out_date;
}

void Reciept::setm_check_out_date(int newCheck_out_date)
{
    m_check_out_date = newCheck_out_date;
}

int Reciept::getm_total_amount() const
{
    return m_total_amount;
}

void Reciept::setm_total_amount(int newTotal_amount)
{
    m_total_amount = newTotal_amount;
}
int Reciept::getm_no_of_days() const
{
    return m_no_of_days;
}

void Reciept::setm_no_of_days(int newNo_of_days)
{
    m_no_of_days = newNo_of_days;
}
int Reciept::getm_balance_amount() const
{
    return m_balance_amount;
}

void Reciept::setm_balance_amount(int newBalance_amount)
{
    m_balance_amount = newBalance_amount;
}
void Reciept::dataRetrival(){
    newCustomeObj=new CustomerData;
    ifstream infile("CustomerDetails.csv");
    if (!infile.is_open()) {
        cout <<"File can't be opened"<<std::endl;
        return;
    }
    string line;
    while(getline(infile,line)){
        istringstream iss(line);
        string l_name,l_address;
        long long int l_phone,l_adhar;
        int l_RoomNo,l_CheckInDate,l_Advance,l_HotelId;
        if((iss>>l_HotelId)&&(iss.get()==',')&&getline(iss,l_name,',')&&getline(iss,l_address,',')&&(iss>>l_phone)&&(iss.get()==',')&&
            (iss>>l_adhar)&&(iss.get()==',')&&(iss>>l_RoomNo)&&(iss.get()==',')&&(iss>>l_CheckInDate)
            &&(iss.get()==',')&&(iss>>l_Advance))
        {
            newCustomeObj->setm_hotelId(l_HotelId);
            newCustomeObj->setm_cxname(l_name);
            newCustomeObj->setm_address(l_address);
            newCustomeObj->setm_adharno(l_adhar);
            newCustomeObj->setm_phoneNo(l_phone);
            newCustomeObj->setm_roomno(l_RoomNo);
            newCustomeObj->setm_check_in_date(l_CheckInDate);
            newCustomeObj->setm_advance(l_Advance);
            vec_obj2.push_back(newCustomeObj);
        }
    }
    ifstream infil;
    infil.open("HotelDetails.json");
    if(infil.is_open()==0){
        cout<<"File can't open\n"<<endl;
    }
    vector<json>vecObj1;

//    json *hoteljsonobj[10];
//    for(int i=0;i<2;i++){
//        hoteljsonobj[i]=new json;
//        infil>>*hoteljsonobj[i];
//        vecObj1.push_back(*hoteljsonobj[i]);
//    }
//    infil.close();
    json hoteljsonobj;
    while (!infil.eof()) {
        try{
            infil>>hoteljsonobj;
            vecObj1.push_back(hoteljsonobj);
        }
        catch(const json::exception &e){
          //  cout<<"Json parsing error handling: "<<e.what()<<endl;
        }
        hoteljsonobj.clear();
    }
    infil.close();
    receiptIssue(vec_obj2,vecObj1);
}


void Reciept::receiptIssue(vector<CustomerData* >FnVec_obj,vector<json>vecObj1){
    ofstream outfile,outfile1;
    outfile.open("Receipt.csv",ios::app);

    if(outfile.is_open()==0){
        cout<<"Reciept File can't open\n"<<endl;
        return;
    }
    int flag=0,m_total_amount=0;
    long long int l_adhar1;
    cout<<"Enter customer Adhar number to get Receipt"<<endl;
    cin>>l_adhar1;
    for(int i=0;i!=vec_obj2.size();i++){
        if(l_adhar1==FnVec_obj[i]->getm_adharno())
        {
            cout<<"Enter checkout date"<<endl;
            cin>>m_check_out_date;
            m_no_of_days=(m_check_out_date)-FnVec_obj[i]->getm_check_in_date();
            if(m_no_of_days<0)
            {
                m_no_of_days=(m_no_of_days*(-1));
            }
            if(m_no_of_days==0){
                m_no_of_days=1;
            }
            int j=0,f=0,cost;
            for(auto &obj:vecObj1){
                int id=obj["Hotel Id"];
                j=0;
                for(auto &room:obj["Room Numbers"]){
                if((FnVec_obj[i]->getm_hotelId()==id)&&FnVec_obj[i]->getm_roomno()==obj["Room Numbers"][j]["Room_Number"]){
                   cost=obj["Room Numbers"][j]["Room_Cost"];
                 //   cout<<"Cost is"<<cost<<endl;
                    m_total_amount=m_no_of_days * cost;
                    cout<<"Total amount"<<m_total_amount<<endl;
                 //   cout<<obj["Room Numbers"][j]["Room_Status"]<<endl;
                    obj["Room Numbers"][j]["Room_Status"]="UNOCCUPIED";
                  //      cout<<obj["Room Numbers"][j]["Room_Status"]<<endl;
                    f=1;
                    break;
                    }
                j++;
                }
                if(f==1){
                break;
                }
            }

            m_balance_amount=m_total_amount-FnVec_obj[i]->getm_advance();
            flag=1;
            cout<<"------------------------------------------"<<endl;
            cout<<"              Receipt details     "<<endl;
            cout<<"------------------------------------------"<<endl;
            cout<<"Name: "<<FnVec_obj[i]->getm_cxname()<<"\nAddress: "<<FnVec_obj[i]->getm_address()<<"\nPhone Number: "<<FnVec_obj[i]->getm_phoneNo()
                 <<"\nAdhar number: "<<FnVec_obj[i]->getm_adharno()<<"\nCheck in date: "<<FnVec_obj[i]->getm_check_in_date()<<"\nCheck out date: "<<
                    getm_check_out_date()<<"\nRoom number: "<<FnVec_obj[i]->getm_roomno()<<"\nOne day cost: "<<cost<<"\nNumber of days stayed: "<<getm_no_of_days()<<"\nTotal amount: "<<
                m_total_amount<<"\nAdvance paid: "<<FnVec_obj[i]->getm_advance()<<"\nBalance amount: "<<getm_balance_amount()<<endl;
            cout<<"\nThank you !...... Visit Again!!!!"<<endl;
             cout<<"------------------------------------------"<<endl;
//            outfile<<"Name"<<","<<"Address"<<","<<"PhoneNumber"<<","<<"Adhar Number"<<","<<"Check in Date"<<","<<"Check out date"<<","<<"Room Number"<<","<<
//                 "No Of Days"<<","<<"Total Amount"<<","<<"Advance"<<","<<"Balance amount"<<endl;
            outfile<<FnVec_obj[i]->getm_cxname()<<","<<FnVec_obj[i]->getm_address()<<","<<FnVec_obj[i]->getm_phoneNo()<<","<<FnVec_obj[i]->getm_adharno()<<","
                     <<FnVec_obj[i]->getm_check_in_date()<<","<<getm_check_out_date()<<","<<FnVec_obj[i]->getm_roomno()<<","<<getm_no_of_days()<<","<<
                 m_total_amount<<","<<FnVec_obj[i]->getm_advance()<<","<<getm_balance_amount()<<endl;
             flag=1;
             break;
        }
    }
    if(flag==1){
        outfile1.open("HotelDetails.json");
        if(outfile1.is_open()==0){
             cout<<"Json ReceiptFile can't open\n"<<endl;
        }
    for(auto &obj:vecObj1){
        json outputJson1=obj;
             outfile1<<outputJson1.dump(4)<<endl;
    }

    outfile1.close();
    }
    if(flag==0){
        cout<<"Entered customer is not found,kindly recheck"<<endl;
    }


}
