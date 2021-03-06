/*============================================*
 * TeorIa bAsica de apuntadores en lenguaje C *
 *============================================*/

#include <stdio.h> // Entrada/salida

int main(void) {
    /* Los apuntadores son variables que almacenan la dirección de memoria *
     * de otras variables. Esta dirección se representa de la misma forma  *
     * en memoria que un entero sin signo por lo que es posible guardar en *
     * una apuntador valores enteros arbitrarios, lo cual sin embargo suele*
     * representar un error lógico (bastante común) que termina casi       *
     * siempre en una violación de segmento Dx.                            *
     *                                                                     *
     * Dado que un apuntador siempre tiene que ser capaz de referenciar a  *
     * toda la memoria es necesario que todos los apuntadores sobre un     *
     * sistema tengan el mismo tamaño el cual estará definido por la       *
     * arquitectura del computador.                                        *
     *                                                                     *
     * La declaración de un apuntador sigue la siguiente sintaxis:         *
     *      <tipo_a_apuntar> * <identificador> [ = dirección ];            */

    int * apuntador_entero = 10u; // Apunta a la dirección 10, seguramente
                                  // genere una advertencia por parte del
                                  // compilador por asignarle valores
                                  // arbitrarios.

    /* La forma correcta de inicializar un apuntador es usando el operador *
     * de referencia sobre una variable del mismo tipo que la firma del    *
     * apuntador.                                                          *
     * El operador referencia se escribe como & (ampersand) y se coloca    *
     * justo antes de una variable para obtener la dirección de memoria    *
     * del INICIO de dicha variable (solo puede apuntar al inicio)         */
    int    variable1 = 10;
    char   variable2 = 'A';
    double variable3 = 2.71828182;

    int * ap_entero = &variable1; // Apuntador a entero que apunta a
                                  // la dirección de variable1.

    char * ap_caracter = &variable2; // Apuntador a carácter que apunta a la
                                     // la dirección de variable2.

    double * ap_doble = &variable3;  // Apuntador a doble que apunta a la
                                     // dirección de variable3.

    _Bool * ap_booleano = &variable3; // Asignación del tipo erróneo de apuntadores.
                                      // Al igual que la asignación arbitraria,
                                      // es posible que esta sentencia cause un
                                      // error en el futuro del programa.

    /* Una vez creado un apuntador, se podrán usar dos operaciones para     *
     * hacer uso de ellos: desreferencia (acceso) y suma/resta (movimiento) */

    /* El acceso se hace mediante el operador * (asterisco), el cual actúa  *
     * sobre un valor apuntador. Dicho operador toma la dirección que se    *
     * le pasa como punto de partida para empezar a leer el contenido, y    *
     * desde ahí avanza el número de bytes necesarios dependiendo del tipo  *
     * de apuntador para leer una variable completa de dicho tipo.          *
     * el resultado de '*dir' (asumiendo que dir apunta a 'var') funciona   *
     * de manera similar a si hubiéramos escrito simplemente 'var'          */

    // Imprimiendo contenidos
    printf("El contenido del entero es: %d\n",   *ap_entero);
    printf("El contenido del carácter es: %c\n", *ap_caracter);
    printf("El contenido del doble es: %f\n",    *ap_doble);

    // Cambiando valores
    *ap_entero = *ap_entero * *ap_entero; // El compilador no se confunde
                                          // entre usar un asterisco como
                                          // multiplicación o desreferencia
                                          // pero un humano si. Hay que poner
                                          // paréntesis para eliminar ambigüedad.
    *ap_caracter = *ap_caracter + 1;

    *ap_doble    = 3.1415926535;

    // Reimprimiendo contenidos
    printf("El contenido del entero es: %d\n",   *ap_entero);
    printf("El contenido del carácter es: %c\n", *ap_caracter);
    printf("El contenido del doble es: %f\n",    *ap_doble);

    /* El movimiento o recorrido de la memoria se puede hacer mediante      *
     * todos los operadores (simples o compuestos) que tenemos disponibles  *
     * para hacer sumas y restas en un entero. Una suma a un apuntador      *
     * representa moverse adelante en la memoria principal mientras que la  *
     * resta significa moverse hacia atrás.                                 *
     * Al hacer sumas o restas y checar las direcciones resultantes         *
     * notaremos que cada unidad sumada/restada actúa a múltiplos de si     *
     * misma dependiendo del tamaño del tipo de dato a apuntar. Es decir,   *
     * si el apuntador hace referencia a variables de 2 bytes cada vez que  *
     * sumes la unidad a un dicho apuntador su valor en aumentará en 2.     */

    puts("\n");
    printf("Cuando sumo uno a un apuntador a char se avanzan %d posiciones\n",
            (int)(ap_caracter + 1) - (int)(ap_caracter));

    printf("Cuando sumo uno a un apuntador a int se avanzan %d posiciones\n",
            (int)(ap_entero + 1) - (int)(ap_entero));

    printf("Cuando sumo uno a un apuntador a double se avanzan %d posiciones\n",
            (int)(ap_doble + 1) - (int)(ap_doble));
    // Nota: Si haces un casteo ascendente solo hace falta efectuarlo una vez
    //       sobre la expresión que quieras convertir pero si haces uno
    //       descendente se tiene que hacer la conversión explicita sobre cada
    //       elemento, de otra forma cualquiera que sobre sin castear convertirá
    //       en cadena a sus compañeros.

    puts("\n");

    // El nombre de un arreglo es un apuntador al primero de sus elementos
    // por lo que se aplican las mismas reglas.
    int arreglo[] = { 1, 2, 3, 4, 5 };

    printf("La dirección del primer elemento es %p y su contenido es %d\n",
            arreglo, *arreglo);

    printf("La dirección del primer elemento es %p y su contenido es %d\n",
            arreglo + 1, *(arreglo + 1));

    printf("La dirección del primer elemento es %p y su contenido es %d\n",
            arreglo + 2, *(arreglo + 2));

    printf("La dirección del primer elemento es %p y su contenido es %d\n",
            arreglo + 3, *(arreglo + 3));

    printf("La dirección del primer elemento es %p y su contenido es %d\n",
            arreglo + 4, *(arreglo + 4));

    // Accediendo a direcciones fuera del arreglo (puede generar violación
    // de segmento aunque generalmente no lo hará a menos que se acceda a
    // una dirección importante)
    printf("La dirección después de la última posición %p y su contenido es %d\n",
            arreglo + 5, *(arreglo + 5));

    int * ultimo = (arreglo + 4);

    puts("");

    printf("El último elemento esta en %p y tiene %d\n",
            ultimo, *ultimo);

    printf("El penúltimo elemento esta en %p y tiene %d\n",
            ultimo - 1, *(ultimo - 1));

    printf("El antepenúltimo elemento esta en %p y tiene %d\n",
            ultimo - 2, *(ultimo - 2));

    printf("El segundo elemento esta en %p y tiene %d\n",
            ultimo - 3, *(ultimo - 3));

    printf("El primer elemento esta en %p y tiene %d\n",
            ultimo - 4, *(ultimo - 4));

    // Inclusive se puede acceder mediante un apuntador a un arreglo
    // multidimensional dado que los elementos de este son contiguos.

    int matriz[5][5] = {
        {  1,  2,  3,  4,  5 },
        {  6,  7,  8,  9, 10 },
        { 11, 12, 13, 14, 15 },
        { 16, 17, 18, 19, 20 },
        { 21, 22, 23, 24, 25 }
    };

    printf("\nLa matriz es:\n");
    ap_entero = (int *)&matriz; // Convertir 'int (*)[5]' a 'int *'
                                // Solamente se puede hacer conversiones
                                // implícitas de apuntadores genéricos.

    // Recorremos la matriz por medio de un apuntador con un solo for
    for (int i = 0; i < 25; i++)
        printf("%2d%c", *ap_entero++, (i + 1) % 5? ' ' : '\n');

    /* Existe un tipo de apuntador especial llamado apuntador universal *
     * o genérico. Dicho apuntador se declara por medio de la palabra   *
     * reservada 'void' seguida de la sintaxis normal de un apuntador.  *
     *                                                                  *
     * El apuntador a void puede transformarse en cualquier tipo de     *
     * apuntador y cualquier otro apuntador se puede transformar a      *
     * apuntador genérico sin perdida de datos. Esto es gracias a que   *
     * este puntero trabaja con la menor resolución (1 byte) gracias a  *
     * lo cual puede referenciar cualquier cosa                         *
     *                                                                  *
     * Estos apuntadores especiales no pueden desreferenciarse (nada de *
     * asteriscos) puesto que no es de ningún tipo en especifico. No    *
     * obstante se suele transformar a otra variante de apuntador que si*
     * pueda referenciarse dada su fiabilidad en los casteos.           */

    ap_entero = &variable1;

    puts("\n");
    void * ap_generico = ap_entero;

    printf("El entero es: %d\n", *(int *) ap_generico);

    ap_generico = ap_doble;
    printf("El doble es: %f\n", *(double *) ap_generico);

    ap_generico = ap_caracter;
    printf("El carácter es: %c\n", *(char *)ap_generico);

    return 0;
}
