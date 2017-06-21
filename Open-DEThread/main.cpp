#include <iostream>
#include <unistd.h>
#include <thread>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <pthread.h>
#include <chrono>
#include "environment.h"
#include "modules.h"

using namespace std;





int main(int argc, char *argv[])
{
    /*
     *   USO DEL PROGRAMA ./OPen-DEThread <entorno> <modulo>
                                 */
    cout << "Entorno: " << argv[1] << "\nModulo: " << argv[2] << "\nRefresco: " << argv[3]<< endl;
    system("pwd > path.txt");               //crea un archivo con el path ESENCIAL

    string entorno = argv[1];
    string module = argv[2];
    string module_path = "modules/" + module;       //direccion al modulo
    string wordcountcommand = "ls " + module_path + "|wc -l > total.txt";
    system(wordcountcommand.c_str());
    /*CON ESTO SE CREARÁ UN ARCHIVO CON EL TOTAL DE ARCHIVOS EN EL MODULO*/

    ifstream getTotal;
    string numIMG;      //STRING CON EL TOTAL DE IMAGENES DEL MODULO CARGADO
    getTotal.open("total.txt");
    if(getTotal.is_open()){
        getline(getTotal,numIMG);
    }
    getTotal.close();
    int maxIMG = stoi(numIMG);
    vector<string> img_name;
    /*VECTOR CON EL NOMBRE DE LAS IMAGENES RESPECTIVAS
                  FORMATO DEL NOMBRE -> thumbxxx.png*/
    for(int i = 1; i < maxIMG + 1; i++){
        if(i < 10){
            string stmp = "thumb00"+to_string(i)+".png";
            img_name.push_back(stmp);
        }
        if(i >= 10 && i < 100){
            string stmp = "thumb0"+to_string(i)+".png";
            img_name.push_back(stmp);
        }
        if(i >= 100){
            string stmp = "thumb"+to_string(i)+".png";
            img_name.push_back(stmp);
        }
    }

    if(entorno == "KDE" || entorno == "KDE4" || entorno == "plasma5"){
        ifstream pathlocal;
        pathlocal.open("path.txt");
        string path;
        if(pathlocal.is_open()){
            getline(pathlocal,path);
        }
        pathlocal.close();
        /*
         *CON ESTO SE LOGRA CONSEGUIR EL PATH DONDE SE UBICA TODO EL PROGRAMA
         */
        string command = "python3 ksetwallpaper/ksetwallpaper.py "+path+"/modules/"+module+"/";
        Environment* env = new Environment(entorno, command);
        double schedule = stod(argv[3]);
        Modules* mod = new Modules(img_name, schedule);

       /*####### CORE #########*/
        int flag = 1;
        int maximo = img_name.size();
        int slip = stoi(argv[3]);
        chrono::seconds sche(stoi(argv[3]));
        while(true){
            string core = env->getCommand() + mod->getNameAt(flag-1);
            system(core.c_str());
            flag++;
            if(flag == mod->getTotal()){
                flag = 1;
            }
            this_thread::sleep_for(sche);
            //sleep(slip);
        }

    }

















    return 0;
}
