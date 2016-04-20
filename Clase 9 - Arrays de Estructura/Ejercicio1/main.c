#include <stdio.h>
#include <stdlib.h>

struct Employe
{
    int legajo;
    float salario;
    char nombre[31];
};

int main()
{
    struct Employe emp;

    printf("Ingresar Legajo: ");
    scanf("%d",&emp.legajo);

    printf("Ingresar Salario: ");
    scanf("%f",&emp.salario);

    printf("Ingresar Nombre: ");
    fflush(stdin);
    gets(emp.nombre);


    printf("\n\nLEGAJO\t\tNOMBRE\t\tSALARIO\n%d\t\t%s\t\t$ %.2f.-\n",emp.legajo,emp.nombre,emp.salario);

    return 0;
}
