#include "modules.h"

Modules::Modules(vector<string> asdf)
{
    this->images = asdf;
    this->cantidad = this->images.size();
}

void Modules::setSchedule(double a){
    this->schedule = a;
}

int Modules::getTotal(){
    return this->cantidad;
}
