/*
*------------------------------------------
* Parte 4 Laboratorio 2.cpp
* -----------------------------------------
* UNIVERSIDAD DEL VALLE DE GUATEMALA
* FACULTAD DE INGENIERÍA
* DEPARTAMENTO DE CIENCIA DE LA COMPUTACIÓN
* CC3086 - Programacion de Microprocesadores
* Fabian Juárez 21440
*------------------------------------------
* Descripción: Crear 2 hilos posix realizando
* el cálculo para que cada uno recorra la
* mitad del array y que sume los valores
* que encuentre.
*------------------------------------------
*/ 
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
using namespace std;
//Creacion de variables que se utilizaran de manera global
void *subtotal1(void *ptr);
void *subtotal2(void *ptr);
int vector[] = {1,2,3,4,10,9,80,70,19,20};
int vector_completo = sizeof vector/sizeof vector[0];
int mitad_vector = vector_completo/2;

int main()
{
    // Declaramos las variables tipo pthread_t
     pthread_t thread1, thread2;
     char const *message1 = "Thread 1";
     char const *message2 = "Thread 2";
    // Se crean los hilos de manera independiente el cual ejecutara la misma funcion
     pthread_create( &thread1, NULL, subtotal1, (void*) message1);
     pthread_create( &thread2, NULL, subtotal2, (void*) message2);
    // Esperar a que cada thread termine en orden
     pthread_join( thread1, NULL);
     pthread_join( thread2, NULL); 
     exit(0);
}
// Funcion para el primer thread el cual se encarga de recorrer el array e 
// imprimir sus valores que posee cada espacio del array y al final sumarlos
void *subtotal1(void *ptr){
    char *message;
    message = (char *) ptr;
    printf("%s \n",message);
    int arr[mitad_vector];
    int total1;
//Ciclo para recorrer el array y realizar la impresion de cada dato
    for (int i = 0; i < mitad_vector; i++){
        arr[i] = vector[i];
        printf("numero dentro del arreglo del thread1: %d\n", arr[i]);
        total1 = total1 + arr[i];
    }
    printf("El total del thread1 es de: %d\n\n", total1);
    return 0;
}
// Funcion para el segundo thread el cual se encarga de recorrer el array e 
// imprimir sus valores que posee cada espacio del array y al final sumarlos 
void *subtotal2(void *ptr){
    char *message;
    message = (char *) ptr;
    printf("%s \n",message);
    int arr2[mitad_vector];
    int contador = 0;
    int total2;
    //Ciclo para recorrer el array y realizar la impresion de cada dato
    for (int i = mitad_vector; i < vector_completo; i++){
        arr2[contador] = vector[i];
        printf("numero dentro del arreglo del thread2: %d\n", arr2[contador]);
        total2 = total2 + arr2[contador];
        contador++;
    }
    printf("El total del thread2 es de: %d\n\n", total2);
    return 0;
}