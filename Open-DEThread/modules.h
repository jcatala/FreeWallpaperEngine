#ifndef MODULES_H
#define MODULES_H
#include <string>
#include <vector>
using namespace std;

class Modules
{
private:
    vector<string> images;
    double schedule;
    int cantidad;
public:
    Modules(vector<string> im, double sche);
    void setSchedule(double a);
    int getTotal();
    string getNameAt(int a);
};

#endif // MODULES_H
