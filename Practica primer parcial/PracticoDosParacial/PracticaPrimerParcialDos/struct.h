typedef struct{
    int codigo;
    char nombre[31]
    char descripcion[51];
    int isEmpty;
}Proveedor

typedef struct{
    int codigo;
    int codigoProveedor;
    char nombre[31];
    char descripcion[51];
    int importe;
    int stock;
    int isEmpty;
}Articulo
