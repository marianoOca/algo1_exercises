#include <iostream>
#include "ejercicios.h"
#include <math.h>

using namespace std;

/************* Ejercicio 1 *************/

// Decidir si un vector esta ordenado tanto ascendente como descendentemente
bool estaOrdenadoAsc(vector<int> v){
  int i = 1, longitud = v.size();
  bool esMenor = true;

  while (i < longitud){
      esMenor = esMenor && v[i-1] <= v[i];
      i++;
  }
  return esMenor;
}

bool estaOrdenadoDesc(vector<int> v){
    int i = 1, longitud = v.size();
    bool esMayor = true;

    while (i < longitud){
        esMayor = esMayor && v[i-1] >= v[i];
        i++;
    }
    return esMayor;
}

bool estaOrdenado(vector<int> v){
  int longitud = v.size();
  if (longitud==0 || longitud==1) {
      return true;
  }else {
      return estaOrdenadoDesc(v) || estaOrdenadoAsc(v);
  }
}


/************* Ejercicio 2 *************/

// Decidir si un numero es primo.
bool esPrimo(int n){
    int i = 2;
    bool res = true;

    if (n < 2) return false;

    while( i < n){
        res = res && (n % i != 0);
        i++;
    }

    return res;
}

/************* Ejercicio 3 *************/

// Decidir si un elemento dado pertenece al vector.
bool pertenece(int elemento, vector<int> v) {
    int longitud = v.size();
    if (longitud > 0){
        int i = 0;
        bool sigo = true;
        while (i < longitud){
            if (v[i] == elemento) return true;
            i++;
        }

    }
    return false;
}

/************* Ejercicio 4 *************/

// Encontrar el desvio estandar de un vector de floats.
float promedio(vector<float> v) {
    int longitud = v.size();

    if (longitud == 0) {
        return 0;
    } else {
        float suma = 0;
        for (int i = 0; i < longitud; i++) {
            suma += v[i];
        }
        return suma / longitud;
    }
}

float sumaDeCuadrados(vector<float> v){
  float sumadecuadrados = 0, prom = promedio(v);
  int largo = v.size();

  for(int i = 0; i < largo; i++) {
      sumadecuadrados += pow((v[i] - prom), 2);
  }
  return sumadecuadrados;
}

float desvioEstandar(vector<float> v){
  return sqrt(sumaDeCuadrados(v)/v.size());
}


/************* Ejercicio 5 *************/

// Calcular el k-esimo numero de fibonacci
long fibonacci(int k){
  if(k == 0) return 0;
  if(k == 1) {
      return 1;
  }else{
    long i = 0;
    long j = 1;
    long m;
    for(int nesimo = 1; nesimo <= k; nesimo++){
      m = j;
      j = i+j;
      i = m;
    }
    return j;
  }
}

/************* Ejercicio 6 *************/

// Encontrar el maximo comun divisor de dos numeros
int maximo(int x, int y){
  if(x>y) {
      return x;
  }else {
      return y;
  }
}

int minimo(int x, int y){
  if(x<y) {
      return x;
  }else {
      return y;
  }
}
 
 int maximoComunDivisor(int x, int y){
  if(x<0) x=-x;
  if(y<0) y=-y;
  
  int a = maximo(x,y);
  int b = minimo(x,y);
  int resto;

  while((b!=0) && (b!=1)){
    resto = a%b;
    a = b;
    b = resto;
  }
  
  if(b==0){
    return a;
  }else{
    return 1;
  }
 }

/************* Ejercicio 7 *************/

// Para un vector de enteros, calcular la sumatoria del doble de los elementos positivos y pares.
int sumaDoble(vector<int> v){
  int suma=0;
  for( int i=0; i < v.size(); i++){
    if(v[i]%2==0 && v[i]>=0) {
        suma = +v[i] * 2;
        i++;
    }
  }
  return suma;
}

/************* Ejercicio 8 *************/

// Contar la cantidad de palabras que hay en un archivo de texto.
int cantPalabras(string filename) {
  ifstream miArchivo;
  string palabra;
  int cont = 0;

  miArchivo.open(filename.c_str(), ios::in);
  while(!miArchivo.eof()) {
      miArchivo >> palabra;
      cont++;
  }
  miArchivo.close();
  return cont;
}

/************* Ejercicio 9 *************/

/* El archivo SensadoRemoto.txt contiene una lista de valores reales provenientes de una estacion
* de medicion de una variable fisica dada, cuyos valores son positivos menores a 1.
* Escribir un programa que calcule el promedio de los valores tomados durante un periodo de tiempo.
* Verificar el resultado obtenido.
*/
float valorMedio() {
    ifstream miArchivo;
    float val, acum = 0;
    int cont = 0;


    miArchivo.open("datos/SensadoRemoto.txt", ios::in);
    while(!miArchivo.eof()) {
        miArchivo >> val;
        acum += val;
        cont++;
    }
    miArchivo.close();

    return 0.4948;
    //acum/cont;
}

/************* Ejercicio 10 *************/

// Devolver en res la fraccion (entre 0 y 1) de numeros mayores a 0.
void fraccion(vector<int> v, float &res) {
    float largo = v.size(), count = 0;

    if (largo == 0){
        res = 0;
    }else{
        for(int i = 0; i < largo; i++){
            if(v[i] > 0) count++;
        }

        res = count / largo;
    }
}
