#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

class Gauss{
private:
    double **matriz;
    int filas, columnas;
    double aux, op;
public:
    Gauss(double **matriz = NULL, int filas = 3, int columnas =0, double aux=0, double op=0);
    void generaMatriz();
    void muestraMtariz();
    void pideleLosDatosAlUsuario();
    void calculos();
    void muestraMatrizFinal();
};
Gauss::Gauss(double **matriz, int filas, int columnas, double aux, double op){
    this->matriz = matriz;
    this->filas = filas;
    this->columnas = columnas;
    this->aux = aux;
    this->op = op;
}
void Gauss::generaMatriz(){
    int i;
    if(filas >0 && columnas > 0){
        matriz = new double*[filas];
        for(i=0; i< filas; i++){
            matriz[i] = new double[columnas];
        }
    }
    else
        cout<<"Ingresaste un numero de incognitas invalido."<<endl<<endl;
}
void Gauss::pideleLosDatosAlUsuario(){
    //cout<<"Ingresa el numero de incognitas: ";
    ///cin>>filas;
    cout<<"Matriz 3x3"<<endl;
    columnas = filas + 1;
    this->generaMatriz();
    int i, j;
    cout<<endl<<endl;
    for(i=0; i< filas; i++){
        for(j=0; j<columnas; j++){
           cout<<"Ingresa la posicion ["<<i+1<<"]["<<j+1<<"]: ";
            cin>>matriz[i][j];
        }
    }
}

void Gauss::muestraMtariz(){
    int i, j;
    for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
            cout<<setprecision(3)<<matriz[i][j]<<"\t"; //imprimimos la primer fila separando cada numero por un tabulador
        }
        cout<<endl;
    }
}
void Gauss::calculos(){
    int i, j;
    cout<<"PASO 1"<<endl;
    for(i=0; i< 1; i++){ //haciendo uno la primer posicion
        for(j=0; j< columnas; j++){
            if(i == j ){
                aux = matriz[i][j];
                op = aux / aux;
                matriz[i][j] = op;
            }
            else
                matriz[i][j] = matriz[i][j] / aux;
        }
    }
    this->muestraMtariz();
    cout<<"----------------------------------"<<endl;
    cout<<"PASO 2"<<endl<<endl;
    aux = matriz[1][0];
    for(i =1; i<2; i++){    // haciendo cero la primer posicion de la segunda fila
        for(j=0; j< columnas; j++){
              op = (matriz[0][j]*-aux) + matriz[i][j] ;
              matriz[i][j] = op;
        }
    }
     this->muestraMtariz();
    cout<<"----------------------------------"<<endl;
    cout<<"PASO 3"<<endl<<endl;
    aux = matriz[2][0]; // haciendo cero la primer posicion de tercera fila
    for(i =2; i<filas; i++){
        for(j=0; j< columnas; j++){
              op = (matriz[0][j]*-aux) + matriz[i][j] ;
              matriz[i][j] = op;
        }
    }
    this->muestraMtariz();
    cout<<"----------------------------------"<<endl;
    cout<<"PASO 4"<<endl<<endl;
    aux = matriz[1][1];
    for(i =1; i<=1; i++){  // converitr en uno la segunda posicion de la segunda fila
        for(j=1; j< columnas; j++){

                matriz[i][j] = matriz[i][j] / aux;
        }
    }
    this->muestraMtariz();
    cout<<"----------------------------------"<<endl;
    cout<<"PASO 5"<<endl<<endl;
    aux = matriz[2][1];
    for(i =2; i<=2; i++){  // converitr en cerp la segunda posicion de la tercera fila
        for(j=1; j< columnas; j++){
                op = (matriz[1][j]*-aux) + matriz[i][j] ;
                matriz[i][j] = op;
        }
    }
    this->muestraMtariz();
    cout<<"----------------------------------"<<endl;

    aux = matriz[2][2];
    for(i =2; i<=2; i++){  // converitr en uno la tercera posicion de la tercera fila
        for(j=2; j< columnas; j++){

                matriz[i][j] = matriz[i][j] / aux;
        }
    }

    double z = matriz[2][3];
    double y,x;
    y= matriz[1][2]*z;
    if( y >0)
        y= matriz[1][3] - (matriz[1][2]*z) ;
    else
        y= matriz[1][3] + ((matriz[1][2]*z)*-1);

    if(matriz[0][1]*y >0 && matriz[0][2]*z > 0)
        x = matriz[0][3] - matriz[0][1]*y - matriz[0][2]*z;
    else if(matriz[0][1]*y <0 && matriz[0][2]*z < 0)
        x = matriz[0][3] + matriz[0][1]*y*-1 + matriz[0][2]*z*-1;
    else if(matriz[0][1]*y <0 && matriz[0][2]*z > 0)
        x = matriz[0][3] + (matriz[0][1]*y*-1) - matriz[0][2]*z;
    else if(matriz[0][1]*y >0 && matriz[0][2]*z < 0)
        x = matriz[0][3] - (matriz[0][1]*y) + matriz[0][2]*z *-1;




     cout<<"Matriz Final"<<endl<<endl;
     for(i=0; i<filas; i++){
        for(j=0; j<columnas; j++){
            cout<<matriz[i][j]<<"\t"; //imprimimos la primer fila separando cada numero por un tabulador
        }
        cout<<endl;
    }

    cout<<"\nResultado:\n\tx = "<<x<<endl;
    cout<<"\ty = "<<y<<endl;
    cout<<"\tz = "<<z<<endl;

}



int main(){

    Gauss A;
    A.pideleLosDatosAlUsuario();
    cout<<endl<<endl;
    system("Pause");
    system("cls");
    cout<<"Matriz Ingresada"<<endl<<endl;
    A.muestraMtariz();
    cout<<endl;
    cout<<"----------------------------------"<<endl;

    A.calculos();




    return 0;
}
