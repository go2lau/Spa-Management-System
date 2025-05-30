#ifndef SPECIALTREATMENT_H
#define SPECIALTREATMENT_H
#include "treatment.h"
using namespace std; 
#include <string>


class SpecialTreatment: public Treatment{

    private: 
        float surcharge=200;
        float discount=0.1; 

    public:

        SpecialTreatment();
        SpecialTreatment(string, float, float, string);

        string getInfo();
        void setPrice(float, bool); 
        void setPrice(bool,float);
        string getInfo(bool);
        string getInfo(bool);

};

#endif
