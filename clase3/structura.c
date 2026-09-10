#include <stdio.h>
#include <string.h>

// Definir la estructura
struct Persona {
    char nombre[32];
    int edad;
    float altura;
};

// Definir la estructura
union PersonaU {
    char nombre[32];
    int edad;
    float altura;
};

int main() {
    // Declarar una variable de tipo struct Persona
    struct Persona p1[20];
    union PersonaU p2;

    // Asignar valores a los miembros usando el operador punto (.)
    strcpy(p1.nombre, "Carlos");
    p1.edad = 28;
    p1.altura = 1.75;

    // Mostrar los valores en pantalla
    printf("Nombre: %s\n", p1.nombre);
    printf("Edad: %d años\n", p1.edad);
    printf("Altura: %.2f metros\n", p1.altura);
    printf("Tamaño estructura: %lu \n",sizeof(p1));
    printf("Tamaño union: %lu \n",sizeof(p2));

    return 0;
}

