# Spell Check

# Estructura
# Algoritmo
# Archivos
* **Main.c** : archivo principal del programa
* **Makefile** : archivo makefile
* **README.md** : archivo con las intrucciones del programa
## Headers
* **check.h**
* **corr.h**
* **ctree.h**
* **dict.h**
* **list.h**
* **metd.h**
* **print.h**
## Source
* **check.c**
* **corr.c**
* **ctree.c**
* **dict.c**
* **list.c**
* **metd.c**
* **print.c**
## Tests
* **test_check.c**
* **test_corr.c**
* **test_ctree.c**
* **test_dict.c**
* **test_list.c**
* **test_metd.c**
* **test_print.c**
# Comandos
Para compilar el programa, correr el siguiente comando:
```bash
make check 
```
Para corregir un texto con un diccionario dado, correr el siguiente comando
```bash
./check <nombre_diccionario> <nombre_texto>
```
Para compilar los tests, correr los siguientes comandos:
```bash
make test_check
make test_corr
make test_ctree
make test_dict
make test_list
make test_metd
```
Para testear, correr los siguientes comandos:
```bash
./test_check
./test_corr
./test_ctree
./test_dict
./test_list
./test_metd
```
