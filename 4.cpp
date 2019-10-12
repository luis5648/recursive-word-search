#include <unistd.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <cstring>
#include <omp.h>
#include <iostream>
#include <fstream>

using namespace std;

void leer(string nombre, string palabra){
    ifstream archivo;
    string contenido;
    int cont =0;


    archivo.open(nombre.c_str(), ios::in);

/*    if (archivo.fail()){
        cout<<"no se pudo abrir el archivo\n";
        //exit(1);
    }*/

    while (!archivo.eof()){
        getline(archivo,contenido);

        if (contenido == palabra){
            cont++;
        }
        
       // cout<<contenido<<endl;

        
    }

    
    cout<<"palabra encontrada "<<cont<<" veces en el archivo: "<<nombre<<"\n\n";
    
    
}



void listdir(const char *name, int level){

    DIR *dir;
    struct dirent *entry;
    string dirtectorioNombre;
    string complete;
    if (!(dir = opendir(name)))
        return;
    if (!(entry = readdir(dir)))
        return;

    do {
        if (entry->d_type == DT_DIR) {
            char path[1024];
            int len = snprintf(path, sizeof(path)-1, "%s/%s", name, entry->d_name);
            path[len] = 0;
            if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
                continue;
            
            dirtectorioNombre = entry->d_name;

            printf("%*s[%s]\n", level*2, "", entry->d_name);
            listdir(path, level + 1);
        }
        else

            complete = (dirtectorioNombre + "/") + entry->d_name;
            size_t tam = complete.length();
            if (dirtectorioNombre == "")
            {
                complete.substr(0);
            }
            
            //no pude implementar la función para leer los archivos 
            //recursivamente ya que me toma el slash '/' al inicio de la ruta
            //En teoría debería funcionar, solo fue ese detalle.

            //printf("%*s- %s\n", level*2, "", entry->d_name);
           // leer(complete);


            //cout<<dirtectorioNombre;
            cout<<complete<<endl;


    } while (entry = readdir(dir));
    closedir(dir);
}
int main(void)
{
    listdir(".", 0);
    return 0;
}