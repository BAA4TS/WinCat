# Comando `cat` para Windows

Este programa en C++ emula el comportamiento del comando `cat` de Linux en el entorno de Windows. Permite a los usuarios visualizar el contenido de archivos de texto y obtener información básica sobre ellos.

## Funcionalidades

1. **Visualización de Contenido**: Muestra el contenido de un archivo de texto en la consola.
2. **Información del Archivo**: Proporciona el tamaño del archivo en bytes y el número de líneas.

## Uso

- `cat <archivo>`: Imprime el contenido del archivo especificado.
- `cat -i <archivo>`: Muestra el tamaño y el número de líneas del archivo.
- `cat -h`: Muestra un mensaje de ayuda con instrucciones de uso.

## Ejemplos de Uso

1. Para mostrar el contenido de un archivo:
   ```
   cat ejemplo.txt
   ```

2. Para obtener información sobre el archivo:
   ```
   cat -i ejemplo.txt
   ```

3. Para mostrar ayuda:
   ```
   cat -h
   ```

## Características Técnicas

- **Limpieza de Consola**: La consola se limpia al inicio de cada operación para mejorar la legibilidad.
- **Manejo de Errores**: Se muestran mensajes de error si el archivo no puede ser leído o si se proporcionan argumentos incorrectos.
- **Portabilidad**: Funciona específicamente en Windows debido al uso de la función `system("cls")` para limpiar la consola.
