# Spell Check

## Estructura
La estructura Principal, el CTree, es un arbol de caracteres, inspirado en la estrcutura conocida como "Trie" https://en.wikipedia.org/wiki/Trie. 
\
El mismo es usado para representar la colección de palabras que es el lemario para después poder usarlo como diccionario.
\
\
Funciona de manera que cada caracter de una palabra es representado por un nodo del mismo, manteniendo el orden de la misma con la interconección por hijo entre los nodos. Por ejemplo si una palabra posee la letra 'a' después de la 'b', entonces el nodo que representa la 'b', tendra como hijo el nodo que representa el caracter 'a'. 
\
\
Tambien permite la interconección entre palabras que sean iguales hasta cierto caracter, por ejemplo si tengo las palabras 'gato' y 'gata', ambas palabras son representadas por los mismos nodos hasta el caracter final, donde seran separadas entre los nodos que representan tanto a 'a' como 'o'. 
\
\
El nodo además del dato y sus hijos, posee una bandera la cual indica si la palabra terminó en tal caracter
\
\
Además cabe destacar que el primer nodo, la raíz, es un nodo especial que posee un dato en específico y que cada uno de sus respetivos hijos serán las primeras letras de cada palabra agregada.
\
\
Con todo esto, es posible crear un arbol el cual pueda representar un lemario con intersección de palabras y la capacidad de reconocer las mismas a través de su navegación.

## Algoritmo
El algoritmo utilizado para conseguir las sugerencias, se basa en la construcción de una palabra auxiliar a través de las modificaciones realizadas, un sistema de posicionamiento y la navegación en un CTree.
\
\
El algoritmo va utilizando los cinco métodos dados por la consigna; intercambiar letras, agregar una letra, eliminar una letra, cambiar una letra y separar la palabra
para ir formando en un string auxiliar una posible sugerencia. Además se agrega un nuevo método, el método nulo, el cual no hara modificiones.
\
\
El sistema de posicionamiento lleva registrado las posiciones de tanto de la palabra original como de la modificada, permitiendo así poder modificar la palabra auxiliar con mayor facilidad y reconocer el caracter actual, mientras iteramos sobre la palabra original.
\
\
Pero el verdadero objetivo del algoritmo, es la capacidad de navegar sobre el árbol creado mientras vamos aplicando los diversos métodos utilizando una serie de funciones recursivas. Siempre empezamos sobre la raíz, sobre la cual comenzaremos a aplicar los diversos métodos sobre los siguientes caracteres, las cuales no solo realizarán modificaciones sobre el string auxiliar, si no que también se iran moviendo sobre el árbol. Cabe aclarar que solo se podrá agregar un caracter al string auxiliar si existe un nodo hijo en el nodo actual donde nos encontramos que lo represente. Por ejemplo el método cambiar palabra itera sobre cada uno de los hijos del nodo actual, permitiendo así dar todas las posibilidades, osea todos los posibles caracteres siguientes. 
\
\
De tal forma después de cada método aplicado se habrá creado una ramificación del programa sobre la cuál se seguiran ejecutando modificaciones hasta superar cierto cupo, después del mismo solo se podra realizar el método nulo, el cual simplemente copia el caracter actual. Así se iran creando diversos caminos hasta que se llegue al final, el cual ocurre al terminarse la palabra original y no al no haber más modificaciones posibles a hacer. Incluso la ramificación puede parar a mitad de camino, cuando el árbol no de un camino a seguir, lo cual ocurrira en la mayoría de ocasiones.
\
\
Cuando se llega al final de una ramificación, se comprueba si la palabra pertenece al diccionario verificando la bandera perteneciente al nodo donde nos ubicamos actualmente, el cual representa el ultimo caracter agregado al string auxiliar. De tal forma, vamos consiguiendo las sugerencias de una forma rápida gracias a las propias restricciones que dá el árbol y hayando todas las posibilidad debido a la recursión de las diversas funciones utilizadas por el algoritmo.

## Archivos
* **Main.c** : archivo principal del programa
* **Makefile** : archivo makefile con los comandos predefinidos
* **README.md** : archivo con las intrucciones del programa
### Headers
* **aux.h** : header con las declaraciones de las funciones auxiliares
* **check.h** : header con las declaraciones de las funciones que chequean el texto
* **corr.h** : header con las estructuras y declaraciones de las funciones de correccion
* **ctree.h** : header con las estructuras y declaraciones de las funciones del ctree
* **dict.h** : header con las declaraciones de funciones de funciones de obtención del diccionario
* **list.h** : header con las estructuras y declaraciones de las funciones de lista
* **metd.h** : header con las estructuras y declaraciones de los métodos del algoritmo
* **print.h** : header con las declaraciones de funciones de impresión de archivo de salida
### Source
* **aux.c** : archivo con las definiciones de funciones auxiliares
* **check.c** : archivo con las definiciones de de las funciones que chequean el texto
* **corr.c** : archivo con las definiciones de funciones de de las funciones de correccion
* **ctree.c** : archivo con las definiciones de funciones de las funciones del ctree
* **dict.c** : archivo con las definiciones de funciones de las funciones de obtención del diccionario
* **list.c** : archivo con las definiciones de funciones de las funciones de lista
* **metd.c** : archivo con las definiciones de funciones de los métodos del algoritmo
* **print.c** : archivo con las definiciones de funciones de impresión de archivo de salida
### Tests
* **test_aux.c** : archivo con funciones auxiliares
* **test_check.c** : archivo con los tests de check.c
* **test_corr.c** : archivo con los tests de corr.c
* **test_ctree.c** : archivo con los tests de ctree.c
* **test_dict.c** : archivo con los tests de dict.c
* **test_list.c** : archivo con los tests de list.c
* **test_metd.c** : archivo con los tests de metd.c
* **test_print.c** : archivo con los tests de print.c
## Comandos 
Para compilar el programa, correr el siguiente comando:
```bash
make check 
```
Para corregir un texto con un diccionario dado, correr el siguiente comando
```bash
./check <nombre_diccionario> <nombre_archivo_texto> <nombre_archivo_de_salida>
```
Para compilar los tests, correr los siguientes comandos:
```bash
mek test_aux
make test_check
make test_corr
make test_ctree
make test_dict
make test_list
make test_metd
```
Para testear, correr los siguientes comandos:
```bash
./test_aux
./test_check
./test_corr
./test_ctree
./test_dict
./test_list
./test_metd
```
