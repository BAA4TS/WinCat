#include <iostream>
#include <fstream>
#include <string>

// Función para limpiar la consola de acuerdo con el sistema operativo
void Limpieza()
{
#ifdef _WIN32
    system("cls"); // Limpia la consola en Windows
#endif
}

// Función para mostrar el contenido de un archivo en la pantalla
void TextoPantalla(const char *File)
{
    std::ifstream Archivo(File); // Abrir el archivo en modo de lectura

    if (!Archivo)
    {
        Limpieza();
        std::cerr << "[!] No se pudo leer: " << File << std::endl; // Mensaje de error si el archivo no se puede abrir
        exit(EXIT_FAILURE);                                        // Termina el programa con un error
    }
    else
    {
        std::string Linea;
        while (std::getline(Archivo, Linea))
        {
            std::cout << Linea << std::endl; // Muestra cada línea en la consola
        }

        std::cout << "\n\n - - cat - -\n"; // Mensaje final
        Archivo.close();                   // Cierra el archivo
    }
}

// Función para mostrar información sobre el archivo: tamaño y número de líneas
void InfoArchivo(const char *File)
{
    std::ifstream Archivo(File, std::ios::binary | std::ios::ate);

    if (Archivo.is_open())
    {
        std::streamsize Tamanio = Archivo.tellg(); // Obtiene el tamaño del archivo
        Archivo.seekg(0, std::ios::beg);           // Vuelve al inicio del archivo

        std::string Linea;
        int Contador = 0;
        while (std::getline(Archivo, Linea))
        {
            Contador++; // Cuenta el número de líneas
        }
        Archivo.close();

        std::cout << "Lineas: " << Contador << "\n";
        std::cout << "Tamanio: " << Tamanio << " bytes\n";
        std::cout << "\n\n - - cat - - \n";
    }
    else
    {
        std::cerr << "[!] No se pudo leer: " << File << "\n";
        exit(EXIT_FAILURE);
    }
}

int main(int argc, char *argv[])
{
    if (argc > 3)
    {
        std::cerr << "[!] - Demasiados argumentos (para ayuda usa -h)\n"; // Mensaje de error si hay demasiados argumentos
    }
    else if (argc == 2 && std::string(argv[1]) == "-h")
    {
        Limpieza();
        std::cout << " -- Ejemplo de uso -- \n";
        std::cout << " cat <archivo>           : Imprime el contenido del archivo.\n";
        std::cout << " cat -i <archivo>        : Muestra el tamaño y número de líneas del archivo.\n";
    }
    else if (argc == 3 && std::string(argv[1]) == "-i")
    {
        Limpieza();
        std::cout << " - - Archivo: " << argv[2] << " - - \n\n";
        InfoArchivo(argv[2]); // Muestra el tamaño y número de líneas del archivo especificado
    }
    else if (argc == 2)
    {
        Limpieza();
        std::cout << " - - Archivo: " << argv[1] << " - - \n\n";
        TextoPantalla(argv[1]); // Muestra el contenido del archivo especificado
    }
    else
    {
        std::cout << "(para ayuda usa -h)\n"; // Mensaje de ayuda si no hay argumentos
    }

    return 0; // Termina el programa exitosamente
}