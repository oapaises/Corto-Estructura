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

/**
 * Creamos la funcion insertar para crear nodo en nuestra pila, 
 * y al mismo tiempo ingresar los datos, recibiendo como parametro un entero
*/
void insertar(int x){
    struct nodo *nuevo;
    //Usamos de malloc por trabajar una memoria dinamica en un nuevo nodo sucesivamente
    nuevo = malloc(sizeof (struct nodo));
    nuevo->info = x;
    //validamos que la raiz sea nula
    if (raiz == NULL) {
        raiz=nuevo;
        nuevo->sig=NULL;
    }else{
		//Ahora el dato "raiz" sera el siguiente que extraeremos despues del que acabamos de ingresar
        nuevo->sig = raiz;
        //El dato ingresado pasa a ser raiz, y a estar en la cima de la pila        
        raiz=nuevo;
    }   
}

/**
 * Creamos una funcion imprimir para imprimir datos de la pila
 */
void imprimir(){
    struct nodo *reco=raiz;
    //La funcion funcionará mientras la pila aun tenga datos que mostrar
    while(reco!=NULL){
		//imprimimos la pila
        printf("%i ", reco->info);
        reco=reco->sig; 
    }
    printf("\n");
}


/**
 *Creamos la función Reemplazar que tiene como parametros una pila con
 *tipo de elemento int y dos valores int: nuevo y viejo de forma que si el
 *primer valor aparece en algún lugar de la pila,sea reemplazado por el
 *segundo.
*/
void reemplazar(struct nodo *pila, int viejo, int nuevo ){
    //Validamos la pila sea diferente a nula 
    if(pila != NULL){
		//Mientras la validacion se mantenga se recorrera el bucle
        while(pila!=NULL){
			//validamos que si se encuentra que el valor ingresado esta en la pila
        if(pila->info == viejo){
			//Se guardara el segundo dato es decir el nuevo elemento
            pila->info = nuevo;
        }
        pila = pila->sig;
        }
    }else{
        printf("No se encontro coincidencia con la pila\n");
    }
}

int main(){
	//Se declaran la variables que haran la funcion de nuevo y viejo elemento
    int viejo,nuevo;
    
    //Ingresamos datos a la pila atravez de la funcion insertar
    insertar(10);
    insertar(40);
    insertar(3);
    insertar(7);
    insertar(3);

    printf("\nLista inicial de la pila :\n");
    //Imprimimos los datos de la pila atravez de la funcion imprimir  
    imprimir();
    //Pedimos el dato viejo
    printf("Ingrese el numero viejo:\n");
    scanf("%d", &viejo);
    //Pedimos el dato nuevo
    printf("Ingrese el numero nuevo:\n");
    scanf("%d", &nuevo);
    //llamamos la funcion reemplazar e igualmente pasamos los parametros ingresados a la funcion reemplazar
    reemplazar(raiz,viejo, nuevo);
    printf("\nSe sustituyó el valor viejo = %d por el valor nuevo ingresado = %d",viejo,nuevo);
    printf("\nLa lista queda:\n");
    //Imprimimos los datos de la pila atravez de la funcion imprimir  
    printf("\nLista final de la pila :\n");
    imprimir();
    
  return 0;
}
