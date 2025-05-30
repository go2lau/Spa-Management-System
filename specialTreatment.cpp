#include "specialTreatment.h"
using namespace std;

SpecialTreatment::SpecialTreatment(){
    serviceName="";
    duration=0;
    basePrice=0;
    time="";
    surcharge;
    discount;
    
}

SpecialTreatment::SpecialTreatment(string serviceName_, float duration_, float basePrice_, string time_){

    serviceName_= "Personalizewd treatment";
    serviceName=serviceName_;
    duration=duration_;
    basePrice=basePrice_;
    time= time_;
}


void SpecialTreatment:: setPrice(float price, bool returning){

    if (returning){
        basePrice= price-(price*discount);
    } 
    basePrice=price;
}

void SpecialTreatment:: setPrice(bool over60, float price){

    if (over60){
        basePrice= price+surcharge;
    }
    basePrice=price;
}

string SpecialTreatment::getInfo(){

    return "Service: "+ serviceName+ "\n"+ "Duration: "+ to_string(duration)+ "\n"+ "Base Price: "+ to_string (basePrice)+ "\n"+ "Time: "+ time+ "\n";
}

string SpecialTreatment::getInfo(bool over60){

    if (over60){

        return "Service: "+ serviceName+ "\n"+ "Duration: "+ to_string(duration)+ "\n"+ "Base Price: "+ to_string (basePrice)+ "\n"+ "Time: "+ time+ "\n" + "Note: Duration exceeds 60 minurtes. Surcharge applied: $"+ to_string(surcharge);

    }
}


string SpecialTreatment::getInfo(bool returning){

    return "Service: "+ serviceName+ "\n"+ "Duration: "+ to_string(duration)+ "\n"+ "Base Price: "+ to_string (basePrice)+ "\n"+ "Time: "+ time+ "\n"+ "Client Type: Returning \n Note: Returning client discount applied: 10%"+ "Final price: "+ to_string(basePrice- (basePrice*discount));
}

