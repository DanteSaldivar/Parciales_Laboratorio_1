
#ifndef RELACIONES_H_
#define RELACIONES_H_
#include "Usuarios.h"
#include "Producto.h"
#include "Tracking.h"


int eRelaciones_AltaCompra(eUsuario arrayUsuarios[], int usuariosLen, eProducto arrayProductos[], int productosLen, eTracking arrayTracking[], int trackingLen, int idUsuario);

int eRelaciones_MostrarEstadoCompra(eUsuario arrayUsuarios[], int usuariosLen, eProducto arrayProductos[], int productosLen, eTracking arrayTracking[], int trackingLen, int ID);
int eRelaciones_MostrarEstadoVentas(eUsuario arrayUsuarios[], int usuariosLen, eProducto arrayProductos[], int productosLen, eTracking arrayTracking[], int trackingLen, int ID);
void eRelaciones_ImprimirTracking(eTracking arrayTracking, eProducto arrayProductos[], int productosLen);

#endif /* RELACIONES_H_ */
