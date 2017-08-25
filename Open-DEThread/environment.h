#ifndef ENVIRONMENT_H
#define ENVIRONMENT_H
#include <string>

using namespace std;

/**
  * @brief Clase Environment
  *
  * Clase que insertar los comando en el sistema.
  */

class Environment
{
private:
    string name;
    string command;
public:
    Environment(string name, string command);
    string getCommand();
    string getName();
};

#endif // ENVIRONMENT_H
