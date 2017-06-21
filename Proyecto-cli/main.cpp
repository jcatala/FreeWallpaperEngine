#include <iostream>
#include <unistd.h>
#include "environment.h"
#include "modules.h"
#include "libss.h"

using namespace std;

int main()
{
    system("pwd > path.txt");
    cout << " - DESKTOP ENVIORMENT SUPPORTED:" << endl;
    cout << "|\t\t[1] GNOME" << endl;
    cout << "|\t\t[2] KDE/PLASMA5" << endl;

    int selected;
    cin >> selected;


    cout << " -  Select modules to use:" << endl << endl << endl;
    system("ls modules | grep mod");


    /*MODULO A USAR*/
    string inuse;
    cin >> inuse;

    string dir_module = "modules/" + inuse; //direccion del modulo

    string com = "ls " + dir_module + "| wc -l > total.txt";

    system(com.c_str());                    //crea archivo con el total de imagenes del modulo seleccionado

    //AHORA YA SE TIENE UN ARCHIVO CON EL TOTA DEL IMAGENES EN EL MODULO... SE ABRIRA
    ifstream file;
    file.open("total.txt");
    string total_de_img;
    if(file.is_open()){
        getline(file,total_de_img);
    }
    file.close();

    int total_img_int = stoi(total_de_img);
    vector<string> vec_img;


    for(int i = 1; i < total_img_int + 1; i++){
        if(i < 10){
            string stmp = "thumb00"+to_string(i)+".png";
            vec_img.push_back(stmp);
        }
        if(i >= 10 && i < 100){
            string stmp = "thumb0"+to_string(i)+".png";
            vec_img.push_back(stmp);
        }
        if(i >= 100){
            string stmp = "thumb"+to_string(i)+".png";
            vec_img.push_back(stmp);
        }
    }

    for(int i = 0; i < total_img_int; i++){
        cout << vec_img[i] << endl;
        usleep(10000);
    }


    if(selected == 1){
        Environment* env = new  Environment("GNOME", "gsettings set org.gnome.desktop.background picture-uri ");
        cout << endl << env->getCommand();

        Modules* mod = new Modules(vec_img);

        while(true){
            //to code...
        }

    }

    if(selected == 2){
        ifstream patharch;              //PATHARCHIVO
        patharch.open("path.txt");
        string path;
        if(patharch.is_open()){
            getline(patharch,path);
        }
        patharch.close();
        string command = "python3 ksetwallpaper/ksetwallpaper.py "+path+"/modules/"+inuse+"/";
        Environment* env = new Environment("KDE", command);
        Modules* mod = new Modules(vec_img);        //se le da un vector con el nombre de cada imagen del modulo
        int contador = 1;
        int maximo = vec_img.size();
        while(true){
            string core = env->getCommand() + vec_img[contador-1];
            system(core.c_str());
            contador++;
            if(contador == vec_img.size()){
                contador = 1;
            }
            usleep(10000000);
        }
    }








    return 0;
}
