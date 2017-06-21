#include "modules.h"

Modules::Modules(vector<string>img, double sche)
{
    this->images = img;
    this->schedule = sche;
    this->cantidad = this->images.size();
}

void Modules::setSchedule(double a){
    this->schedule = a;
}

int Modules::getTotal(){
    return this->cantidad;
}

string Modules::getNameAt(int a){
    return this->images[a];
}
