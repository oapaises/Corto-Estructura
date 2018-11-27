#include<stdio.h>
#include<stdlib.h>

/**
 * Declaramos una estructura nodo que define cada elemento
 * que componen nuestra pila
*/
struct nodo{
    int info;
    struct nodo *sig;
};

/**
 * Declaramos la variable global que apunta al primer elemento
 * iniciandolo en nulo, cuando esta vacia la pila
*/
struct nodo *raiz=NULL;

/**Creamos una funcion insertar para crear nodo en nuestra pila, y 
 * al mismo tiempo ingresar los datos, 
 * recibiendo de parametro un entero
*/
void insertar(int x){
    //Declaramos el puntero raiz que apunta al nuevo elemento
    struct nodo *nuevo;
    //Hacemos uso de la funcio malloc por trabajar una  memoria dinamica
    nuevo = malloc(sizeof (struct nodo));//Hacemos uso de malloc por trabajar memoria dinamica
    nuevo->info = x;
    //validamos que la raiz sea nula
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
		//decimos que ahora el dato "raiz" sera el siguiente que extraeremos despues del que acabamos de ingresar 
		nuevo->sig = raiz; 
		//el dato ingresado pasa a ser raiz, y a estar en la cima de la pila  
		raiz=nuevo;
    }   
}

/**
 * Creamos una funcion imprimir para imprimir datos de la pila
 */
void imprimir(){
	//decalaramos una variable de tipo entero, para usarla como contador
    int contarNodos=0; 
    //Declaramos una estructura nodo con un puntero igualado a la raiz (el primer elemento)
    struct nodo *reco=raiz;
    printf("Lista Completa de la pila \n");
    
    //Mientras la pila aun tenga datos que mostrar
    while(reco!=NULL){
		//Se imprime la pila
        printf("%i ", reco->info);
        //mientras el bucle siga, aumentara en uno el contador de nodos
        contarNodos++;
        //el puntero tomara el valor de siguiente en la pila
        reco=reco->sig;
    }
    printf("\n");
    //Se imprime la cantidad de nodos de la pila
    printf("\nLa cantidad de nodos es: %d\n\n", contarNodos);
}

/**
 * Creamos la funcion  ecxtraer para extraer el dato deseado en la pila
 * */
int extraer(){
    if(raiz != NULL){
		//Se declara el int informacion que sera igual al valor de info en la pila
        int informacion = raiz->info;
        //Se declara una estructura nodo apuntando a la raiz
        struct nodo *bor =raiz;
        raiz=raiz->sig;
        //libera la memoria dinamica de la variable puntero bor
        free(bor);
        //Se retorna la variable informacion
        return informacion;
    }
    else{
		//Se retornara el valor -1
        return -1;
    }
}

/**
 * Creamos la funcion liberar para eliminar un
 * dato de memoria al igual que el nodo que lo contierne
 */
void liberar(){
    //Se declara la estructura nodo reco que apuntara a la raiz
    struct nodo *reco = raiz;
    struct nodo *bor;
    while(reco != NULL){
        bor =reco;
        //reco sera igual al dato siguiente para eliminar el nodo
        reco = reco->sig;
        //liberamos de la memoria
        free(bor);
    }
}

 
int main(void){
 /**
  * Ingresamos datos a la pila atravez de la funcion insertar  
  */
  insertar(10);
  insertar(40);
  insertar(3);
  //Imprimimos los datos de la pila atravez de la funcion imprimir  
  imprimir();
  printf("Extraemos de la pila:%i\n", extraer());
  printf("\nExtraccion Correcta");
  imprimir();
  //elimininamos el dato extraido, al igual que el nodo
  liberar();
  printf("\nEliminacion Correcta del Nodo \n");
}
