#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ArrayEmployees.h"
#include "Funciones.h"

#define MAX 1001

int initEmployees(eEmployee list[], int len)
{
    int ret = 0;

    if(list != NULL && len > 0)
    {

        for(int i=0; i < len; i++)
        {

            list[i].isEmpty = 1;
        };
    }
    else
    {
        ret = -1;
    };

    return ret;
};
int findEmpty(eEmployee list[],int len)
{
    int index = -1;
    for(int i=0; i< len ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        };
    };
    return index ;
};
int findEmployee(eEmployee list[],int len, int id)
{
    int index = -1;

    for(int i=0; i < len; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            index = i;
            break;
        }
    }
    return index;

};

void viewEmployee(eEmployee aEmployee)
{

    printf(" \nID:%d - Nombre:%s -  Apellido:%s-  Salario:%.2f-  Sector:%d \n ", aEmployee.id, aEmployee.name, aEmployee.lastName, aEmployee.salary, aEmployee.sector);
};

void viewEmployees(eEmployee list[], int len)
{

    system("cls");
    printf(" ID NAME LASTNAME SALARY SECTOR \n\n");

    for(int i=0; i < len; i++)
    {

        if( list[i].isEmpty == 0)
        {
            viewEmployee(list[i]);
        }
    }

};
int addEmployee(eEmployee list[], int len)

{
    eEmployee newEployee;

    int index;
    char auxName[31];
    char auxLastName[31];
    char auxSalary[10];
    char auxSector[10];
    int ret;

    int nombre=0,apellido=0,salario=0,sector=0;

    if(list != NULL && MAX > 0 )
    {
        system("cls");
        fflush(stdin);
        index = findEmpty (list, len);
        printf("*** ALTA EMPLEADO ***\n\n");
        if( index == -1)
        {

            printf("NO HAY ESPACIO EN EL SISTEMA\n\n");
            ret = -1;
            system("pause");
        }
        else
        {


            printf("Empleado Nuevo, su ID es : %d \n",index);
            newEployee.id = index ;




            if(nombre == 0 )
            {
                while(!funcion_getStringLetras("Ingrese Nombre: ", auxName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    nombre=1;


                };
                 nombre=1;

            }


            printf("\nNombre: %s \n",auxName);

            if(apellido==0)
            {
                while(!funcion_getStringLetras("Ingrese Apellido: ", auxLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s \n",auxName);
                    apellido=1;

                };
                apellido=1;

            }
            printf("\nNombre: %s - Apellido: %s \n\n",auxName,auxLastName);
            if(salario == 0)
            {
                while(!funcion_getStringNumerosFlotantes("Ingrese Salario: ", auxSalary))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s \n",auxName,auxLastName);
                    salario=1;
                };
                salario=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s \n",auxName,auxLastName,auxSalary);
            if(sector == 0)
            {
                while(!funcion_getStringNumeros("Ingrese Sector: ", auxSector))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                    system("pause");
                    system("cls");
                    printf("\nNombre: %s - Apellido: %s - Salario: %s \n\n",auxName,auxLastName,auxSalary);
                    sector=1;
                };
                sector=1;

            }
            printf("\nNombre: %s - Apellido: %s - Salario: %s - Sector %s \n\n",auxName,auxLastName,auxSalary,auxSector);
            while((nombre == 1) && (apellido == 1) && (salario == 1) && (sector == 1) )
            {
                strcpy(newEployee.name,auxName);
                strcpy(newEployee.lastName,auxLastName);
                newEployee.sector = atoi(auxSector);
                newEployee.salary = atof(auxSalary);
                newEployee.isEmpty=0;
                list[index] = newEployee ;
                system("cls");
                printf("\n\n********NUEVO EMPLEADO, BIENVENIDO*********\n\n");
                viewEmployee(list[index]);
                printf("\n\n\n");
                ret=0;
                break;

            }
        }
    }
    else
    {
        ret =-1;
    }
    return ret;

};

int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- INFORMAR \n");
    printf(" 5- SALIR \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};

int funcion_opcionesModificacion()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES *******");
    printf("\n Que desea modificar?\n");
    printf(" 1- NOMBRE \n");
    printf(" 2- APELLIDO \n");
    printf(" 3- SUELDO \n");
    printf(" 4- SECTOR \n");
    printf(" 5- NO MODIFICAR NADA \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
};
int removeEmployee(eEmployee* list, int len)
{

    int index;
    char next[3];
    int id;
    char auxId[4];



    system("cls");
    printf("  *** BAJA EMPLEADO ***\n\n");

    while(!funcion_getStringNumeros("Ingrese ID: ", auxId))
    {
        printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findEmployee(list, len, id);

    while (index == -1)
    {
        printf("NO HAY NINGUN EMPLEADO CON ESE ID %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un ID existente: ", auxId))
        {
            printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findEmployee(list, len, id);

    }



    while (index == 0)
    {
        viewEmployee(list[index]);

        while(!funcion_getStringLetras("\nQUIERE BORRAR USUARIO DEL SISTEMA? si/no: ",next))
        {
            printf("\n ERROR DEBE CONTENER SOLO LETRAS");
        }

        fflush(stdin);



        if(strcmp(next,"si") && strcmp(next,"SI"))
        {
            printf("NO SE REALIZO LA BAJA\n\n");
            break;


        }
        else if(strcmp(next,"no")&& strcmp(next,"NO"))
        {

            list[index].isEmpty = 1;
            printf("SE HIZO LA BAJA DEL EMPLEADO CORRECTAMENTE\n\n");
            break;


        }

    }
    return -1;
}

void modifyEmployee(eEmployee list[], int len)
{
    int id;
    char auxId[5];
    int index;
    char newSalary[10];
    char newSector[3];
    char newName[31];
    char newLastName[31];
    char seguir='s';
    int exit = 1;

    system("cls");
    printf("  *** Modificar  empleado ***\n\n");

    while(!funcion_getStringNumeros("Ingrese ID: ", auxId))
    {
        printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
        system("pause");
        system("cls");
    };

    id=atoi(auxId);

    index = findEmployee(list, len, id);

    while (index == -1)
    {
        printf("NO HAY NINGUN EMPLEADO CON ESE ID %d\n\n", id);
        while(!funcion_getStringNumeros("Ingrese un ID existente: ", auxId))
        {
            printf("ERROR- EL ID TIENE QUE TENER SOLO NUMEROS \n\n");
            system("pause");
            system("cls");
        };
        id=atoi(auxId);
        index = findEmployee(list, len, id);

    }


    while ((index >= 0) && (index <=1000))
    {
        viewEmployee(list[index]);

        do
        {
            switch (funcion_opcionesModificacion())
            {
            case 1:
                fflush(stdin);
                viewEmployee(list[index]);

                while(!funcion_getStringLetras("Ingrese nombre nuevo: ", newName))
                {
                    printf("ERROR- EL NOMBRE TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].name,newName);
                exit = 0;
                break;
            case 2:
                fflush(stdin);
                viewEmployee(list[index]);
                while(!funcion_getStringLetras("Ingrese apellido nuevo: ",newLastName))
                {
                    printf("ERROR- EL APELLIDO TIENE QUE CONTENER SOLO LETRAS\n\n ");
                    system("pause");
                    system("cls");
                };
                strcpy(list[index].lastName,newLastName);
                exit = 0;

                break;
            case 3:
                fflush(stdin);
                viewEmployee(list[index]);

                while(!funcion_getStringNumerosFlotantes("Ingrese Salario: ", newSalary))
                {
                    printf("ERROR- EL SALARIO TIENE QUE CONTENER SOLO NUMEROS \n\n");
                    system("pause");
                    system("cls");

                };

                list[index].salary = atof(newSalary);
                exit = 0;
                break;
            case 4:
                fflush(stdin);
                viewEmployee(list[index]);
                while(!funcion_getStringNumeros("Ingrese sector nuevo: ", newSector))
                {
                    printf("ERROR- EL SECTOR TIENE QUE CONTENER SOLO NUMEROS ENTEROS \n\n");
                    system("pause");
                    system("cls");
                };
                list[index].sector=atoi(newSector);
                exit = 0;
                break;
            case 5:
                printf("Volviendo a menu principal");
                exit = 0;
                break;
            default:
                printf("\n\nOpcion ingresada incorrecta, por favor ingrese una opcion del 1 al 5\n\n");
                system("pause");
                break;


            }

            if(exit==0)

            {
                printf("\n*** MODIFICACCION EXITOSA ***");
                printf("\n  Desea continuar modificando? \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");
                break;
            }

            else
            {
                printf("\n\n esta por salir de modificacion esta seguro? s/n \n\n");
                scanf("%c",&seguir);

                fflush(stdin);
                system("cls");

            }
            return;
        }
        while (seguir == 's' || seguir == 'S');


    }



};

void harcodeoEmpleados(eEmployee* list)
{

    eEmployee x[]={
    {0,"Tomas", "Zorzano",23.00,2},
    {1,"Camila", "Cacciavillani",30.00,1},
    {2,"Cristian", "Zorzano",90.00,2},
    {3,"Federico", "Zorzano",42.00,2},
    {4,"Carolina", "Zorzano",8.00,2},
    };
    for(int i = 0; i< 5;i++)
    {
        list[i] = x[i];
    }
};

int sortEmployees(eEmployee list[], int len)
{
    eEmployee auxEmployee;
    char auxOrder[1] ;
    int ret,order;


    if(list != NULL && len > 0)
    {
        while(!funcion_getStringNumeros("\n Ingrese 1 para ordenar Apellido de forma ascendente o ingrese 2 para ordenar de forma descendente: ",auxOrder))
        {
            printf("*** ERROR DEBE INGRESAR UN NUMERO ***");

        }
        order = atoi(auxOrder);
        switch(order)
        {
        case 1:
            for(int i = 0; i < len - 1; i++)
            {
                for(int j = i + 1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) < 0  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector < list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }
            printf("\n\nSe ordeno correctamente.\n");
            system("pause") ;
            system("cls") ;
            break;
        case 2:
            for(int i = 0; i < len-1; i++)
            {
                for(int j = i+1; j < len; j++)
                {
                    if(strcmp(list[j].lastName, list[i].lastName) > 0 && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                    else if(strcmp(list[j].lastName, list[i].lastName) == 0 && list[j].sector > list[i].sector  && list[j].isEmpty == 0 && list[i].isEmpty == 0)
                    {
                        auxEmployee = list[i];
                        list[i] = list[j];
                        list[j] = auxEmployee;
                    }
                }
            }

            system("pause") ;
            system("cls") ;
            break;
        default:
            printf("No ingreso 1 o 2");
        }

    }
    else
    {
        ret = -1;
    }


    return ret;

};

void reports (eEmployee list[],int len)
{
    float acum,promedio,contador;
    int contSuperan;

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            acum = acum + list[i].salary;
            contador++;
        }
    }

    promedio = funcion_Division(acum,contador);

    for(int i = 0; i < len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary > promedio)
        {
            contSuperan++;
        }
    }

    printf("\nEl total de todos los salarios es de: %.2f \nEl promedio de los salarios es: %.2f \nLa cantidad de empleados que superan el promedio es de: %d\n\n",acum,promedio,contSuperan);

}








