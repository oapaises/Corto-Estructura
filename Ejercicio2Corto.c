#include <stdlib.h>
#include <stdio.h>

/**
 * Declaramos una estructura nodo que define cada elemento
 * que componen nuestra pila
*/
typedef struct nodo 
{
    int dato;
    struct nodo *siguiente;
} nodo;

/**
 * Declaramos la variable global que apunta al primer elemento
 * iniciandolo en nulo, cuando esta vacia la pila
*/
nodo *primero = NULL;

int main(void){
    
/**
 * Mostrar los dígitios ingresados tal cual(En orden),
*/
int tamanio;
    printf("\nCuantos Digitos ingresará?:\n");
    scanf("%d", &tamanio);
    /**Se usara un arreglo y para mostrar los dígitos ingresados para la pila
     *  en forma invertida haremos uso de "Pilas".
	*/
	//declaramos el vector con su tamaño
    int vector[tamanio];

	/** 
	* Se llenará automaticamente el arreglo y la pila 
	* cuando se ingresen datos
    */
    //bucle para el llenado de la pila y vector
    for(int i = 0; i <tamanio; i++){
		
		//Declaramos el nodo con el puntero nuevo que hara la funcion de nuevos 
		// elementos, se hace uso de la funcion malloc por trabajar una memoria dinamica
		
		nodo *nuevo = (nodo *)malloc(sizeof(nodo));
		//Se piden los datos
		printf("Ingrese el dígito %d :\n", i+1);
		scanf("%d", &nuevo->dato);
		//se llena el vector con el dato
		vector[i]=nuevo->dato;
		//El dato "primero" sera el siguiente que extraeremos despues del que acabamos de ingresar
		nuevo->siguiente = primero;
		//El dato ingresado pasa a ser primero, y a estar en la cima de la pila
		primero = nuevo;
    }
    printf("\nLos dígitos ordenados son:\n");
    //Impresion de los digitos ordenados con un bucle
    for(int i = 0; i < tamanio; i++){
        printf("%d\t", vector[i]);
    }   
    //Se llama la funcion mostrarPila para mostrar la pila
    mostrarPila();
    return 0;
}

/**Creamos una funcion mostrarPila para mostrar la pila 
*/
void mostrarPila(){
    struct nodo *actual=primero;
        printf("\nLos dígitos normales (Invertidos) en la pila son :\n");
        //Mientras la pila aun tenga datos que mostrar se recorrera el bucle
        while (actual != NULL){
			//Se imprimime la pila, para invertir los dígitos
            printf("%d\t", actual->dato);
            actual = actual->siguiente;
        }
        printf("\n");
}

