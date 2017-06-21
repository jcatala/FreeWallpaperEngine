#include "environment.h"

Environment::Environment(string name, string command)
{
    this->name = name;
    this->command = command;
}

string Environment::getCommand(){
    return this->command;
}

string Environment::getName(){
    return this->name;
}
