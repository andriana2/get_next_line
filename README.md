# Get next line
## Descripción
Este proyecto consiste en codificar una función que devuelva una línea a la vez de un archivo de texto
Devuelve las líneas de código cada vez que se ejecute y, si ya no queda nada que leer, devuelve NULL

## Uso
Incluye la línea a continuación:
```C
#include "get_next_line.h"
```
También puedes modificar el número de letras que se leen del archivo, pero si no quieres hay un valor preestablecido:
```C
get_next_line.c get_next_line_utils.c -D BUFFER_SIZE=<size>
```
