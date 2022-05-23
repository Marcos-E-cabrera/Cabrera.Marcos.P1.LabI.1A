
#ifndef CLIENTE_H_
#define CLIENTE_H_

typedef struct
{
    int id;
    char nombre[20];
    char sexo[1];
} eCliente;

#endif /* CLIENTE_H_ */

int listarCliente(eCliente cliente[], int tamCliente);

int cargarDescripcionCliente(eCliente cliente[], int tamCliente, int id, char descripcion[]);

int buscarCliente(eCliente cliente[], int tamCliente, int id, int* pIndice);

int validarCliente(eCliente cliente[], int tamCliente, int id);
