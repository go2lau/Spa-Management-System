#ifndef TREATMENT_H
#define TREATMENT_H
#include <string>
using namespace std;

class Treatment{

    protected: 
        string serviceName; 
        float duration; 
        float basePrice; 
        string time;

    public: 
        Treatment();
        Treatment(string, float, float, string);
        void setDuration(float);
        void setPrice(float);
        virtual string getInfo()=0; 

};




#endif
