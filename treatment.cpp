#include "treatment.h"
using namespace std;

Treatment::Treatment(){

    serviceName="";
    duration=0;
    basePrice=0;
    time= "";

}

Treatment::Treatment(string serviceName_, float duration_, float basePrice_, string time_){

    serviceName= serviceName_;
    duration=duration_;
    basePrice=basePrice_;
    time= time_;

}

void Treatment:: setDuration(float duration_){

    duration=duration_;

}

