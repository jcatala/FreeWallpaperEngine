#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>

using namespace std;


class Environment
{
private:
    string name;        //NOMBRE DEL AMBIENTE RESPECTIVO
    string command;
public:
    Environment(string name, string command);
    string getCommand();
    string getName();
};

#endif // ENVIRONMENT_H
