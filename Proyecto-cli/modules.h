#ifndef MODULES_H
#define MODULES_H
#include "libss.h"

using namespace std;

class Modules
{
private:
    vector<string> images;  //VECTOR QUE CONTIENE EL NOMBRE DE CADA IMAGEN-> PATRON DEFINIDO
    double schedule;        //Cada cuanto se refrescara en segundos :D
    int cantidad;           //Total de imagenes
public:
    Modules(vector<string> im);
    void setSchedule(double a);
    int getTotal();
};

#endif // MODULES_H
