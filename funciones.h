#include <iostream>
#include <windows.h>

//Funciones para el manejo de clientes
void crear_cliente();
void listar_cliente();
void editar_cliente();
//Funciones para el manejo de productos
void crear_producto();
void listar_productos();
void editar_productos();
//Funciones para el manejo de facturas
void crear_facturas();
void listar_facturas();
void editar_facturas();

struct Cliente{
	unsigned short idc;
	char cedula[10];
	char nombre [25];
	char dir [20];
	char tel [10];
}cliente, *pcliente=&cliente;

struct Producto{
	unsigned short idp;
	char nombre [15];
	float valor;
}producto, *pproducto=&producto;

struct Factura{
	unsigned short idf;
	unsigned short id_cliente;
	unsigned short id_producto[100];
	unsigned short cant[100];
	float total;
	char estado;
}factura, *pfactura=&factura;

FILE *datos_clientes;
FILE *datos_productos;
FILE *facturas;
FILE *facturas_productos;
unsigned short i, bandera, np, consulta, *pconsulta=&consulta;
float acumu_precio=0,*pacumu_precio=&acumu_precio;

void gotoxy( int x, int y ){
COORD coord;
coord.X=x;
coord.Y=y;
SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

void crear_cliente(){
	datos_clientes=fopen("datos_clientes.txt", "rb");
	rewind(datos_clientes);
	fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_END);
	fread(pcliente, sizeof(*pcliente), 1, datos_clientes);
	pcliente->idc=pcliente->idc+1;
	rewind(datos_clientes);
	fclose(datos_clientes);
	fflush(stdin);	
	gotoxy(3,3); printf("Ingrese la cedula: ");
	fgets(pcliente->cedula, 10, stdin);
	fflush(stdin);
	gotoxy(3,4); printf("Ingrese el nombre: ");
	fgets(pcliente->nombre, 25, stdin);
	fflush(stdin);
	gotoxy(3,5); printf("Ingrese la direccion: ");
	fgets(pcliente->dir, 20, stdin);
	fflush(stdin);
	gotoxy(3,6); printf("Ingrese el telefono: ");
	fgets(pcliente->tel, 10, stdin);
	fflush(stdin);
	
	datos_clientes=fopen("datos_clientes.txt", "a+b");
	if(datos_clientes == NULL){
		datos_clientes=fopen("datos_clientes.txt", "w+b");
	}
	fwrite(pcliente, sizeof(*pcliente), 1, datos_clientes);
	rewind(datos_clientes);
	fclose(datos_clientes);
	gotoxy(20,23); printf(" ");
}

void listar_cliente(){
	gotoxy(3,3); printf("ID");
	gotoxy(7,3); printf("CEDULA");
	gotoxy(18,3); printf("NOMBRE");
	gotoxy(44,3); printf("DIRECCION");
	gotoxy(65,3); printf("TELEFONO\n");
	datos_clientes=fopen("datos_clientes.txt", "r+b");
	rewind(datos_clientes);
	while(fread(pcliente, sizeof(*pcliente), 1, datos_clientes)){
		gotoxy(3,4+i); printf("%d", pcliente->idc);
		gotoxy(7,4+i); printf("%s", pcliente->cedula);
		gotoxy(18,4+i); printf("%s", pcliente->nombre);
		gotoxy(44,4+i); printf("%s", pcliente->dir);
		gotoxy(65,4+i); printf("%s", pcliente->tel);
		i++;
	}i=0;
	gotoxy(20,23); printf(" ");
	fclose(datos_clientes);
}

void editar_cliente(){
	bandera=0;
	i=0;
	datos_clientes=fopen("datos_clientes.txt", "r+b");
	rewind(datos_clientes);
	gotoxy(3,3); printf("Ingrese el ID del cliente a consultar: ");
	scanf("%d", &(*pconsulta));
	while(fread(pcliente, sizeof(*pcliente), 1, datos_clientes)){
		if(*pconsulta==pcliente->idc){
			bandera=1;
			break;
		}i++;
	}
	if(bandera==0){
		gotoxy(24,8); printf("NO SE ENCONTRO NINGUN DATO");
		gotoxy(20,23); printf(" ");
		system("pause");
	}
	else{
		int opc=1;
		while(opc!=0){
			system("cls");
			gotoxy(28,1); printf("EDITAR CLIENTE");
			gotoxy(3,3); printf("ID");
			gotoxy(7,3); printf("CEDULA");
			gotoxy(18,3); printf("NOMBRE");
			gotoxy(44,3); printf("DIRECCION");
			gotoxy(65,3); printf("TELEFONO\n");
			if(*pconsulta==pcliente->idc){
				gotoxy(3,4); printf("%d", pcliente->idc);
				gotoxy(7,4); printf("%s", pcliente->cedula);
				gotoxy(18,4); printf("%s", pcliente->nombre);
				gotoxy(44,4); printf("%s", pcliente->dir);
				gotoxy(65,4); printf("%s", pcliente->tel);
			}
			gotoxy(3,9); printf("1. Cedula");
			gotoxy(3,10); printf("2. Nombre");
			gotoxy(3,11); printf("3. Direccion");
			gotoxy(3,12); printf("4. Telefono");
			gotoxy(3,13); printf("0. Salir");
			gotoxy(3,15); printf("Seleccione el dato que quiere modificar: ");
			scanf("%d", &opc);
			
			switch(opc){
				case 1:{
					system("cls");
					char n_cedula[10], *pn_cedula=n_cedula;
					gotoxy(28,1); printf("EDITAR CLIENTE");
					fflush(stdin);
					gotoxy(3,3); printf("Digite el nuevo numero de cedula: ");
					fgets(pn_cedula, 10, stdin);
					fflush(stdin);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fread(pcliente, sizeof(*pcliente), 1, datos_clientes);
					strcpy(pcliente->cedula, pn_cedula);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fwrite(pcliente, sizeof(*pcliente), 1, datos_clientes);
					break;
				}
				case 2:{
					system("cls");
					char n_nombre[25], *pn_nombre=n_nombre;
					gotoxy(28,1); printf("EDITAR CLIENTE");
					fflush(stdin);
					gotoxy(3,3); printf("Ingrese el nuevo nombre del cliente: ");
					fgets(pn_nombre, 25, stdin);
					fflush(stdin);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fread(pcliente, sizeof(*pcliente), 1, datos_clientes);
					strcpy(pcliente->nombre, pn_nombre);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fwrite(pcliente, sizeof(*pcliente), 1, datos_clientes);
					break;
				}
				case 3:{
					system("cls");
					char n_dir[20], *pn_dir=n_dir;
					gotoxy(28,1); printf("EDITAR CLIENTE");
					fflush(stdin);
					gotoxy(3,3); printf("Ingrese la nueva direccion del cliente: ");
					fgets(pn_dir, 20, stdin);
					fflush(stdin);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fread(pcliente, sizeof(*pcliente), 1, datos_clientes);
					strcpy(pcliente->dir, pn_dir);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fwrite(pcliente, sizeof(*pcliente), 1, datos_clientes);
					break;
				}
				case 4:{
					system("cls");
					char n_tel[10], *pn_tel=n_tel;
					gotoxy(28,1); printf("EDITAR CLIENTE");
					fflush(stdin);
					gotoxy(3,3); printf("Ingrese el nuevo numero de telefono: ");
					fgets(pn_tel, 10, stdin);
					fflush(stdin);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fread(pcliente, sizeof(*pcliente), 1, datos_clientes);
					strcpy(pcliente->tel, pn_tel);
					fseek(datos_clientes, ftell(datos_clientes)-sizeof(*pcliente), SEEK_SET);
					fwrite(pcliente, sizeof(*pcliente), 1, datos_clientes);
					break;
				}
				case 0:{
					system("cls");
					break;
				}	
				default :{
					system("cls");
					gotoxy(28,1); printf("OPCION INVALIDA \n");
					system("pause");
					break;
				}
			}
		}
	}fclose(datos_clientes);
}

void crear_producto(){
	datos_productos = fopen("datos_productos","rb");
	rewind(datos_productos);
	fseek(datos_productos,ftell(datos_productos)-sizeof(*pproducto),SEEK_END);
	pproducto->idp=pproducto->idp+1;
	fclose(datos_productos);
	fflush(stdin);
	gotoxy(3,5);printf("Ingrese el nombre del producto: ");
	fgets(pproducto->nombre,15,stdin);
	fflush(stdin);
	gotoxy(3,6);printf("Ingrese el valor del producto: ");
	scanf("%f",&pproducto->valor);
	fflush(stdin);
	datos_productos=fopen("datos_productos.txt","a+b");
	if (datos_productos==NULL)
	{	
		datos_productos=fopen("datos_productos.txt","w+b");
	}
	fwrite(pproducto,sizeof(*pproducto),1,datos_productos);
	rewind(datos_productos);
	fclose(datos_productos);
}

void listar_productos(){
	gotoxy(3,4); printf("ID");
	gotoxy(18,4);printf("PRODUCTO");
	gotoxy(39,4);printf("VALOR");
	datos_productos=fopen("datos_productos.txt","r+b");
	rewind(datos_productos);
	i=0;
	while(fread(pproducto,sizeof(*pproducto),1,datos_productos))
	{	
		gotoxy(3,5+i);printf("%d",pproducto->idp);
		gotoxy(18,5+i);printf("%s",pproducto->nombre);
		gotoxy(39,5+i);printf("%.0f",pproducto->valor);
		i++;
	}
	gotoxy(20,23);printf(" ");
}

void editar_productos(){
	unsigned short opcion_modificar=1;
	char nuevo_nombre[15];
	float nuevo_valor;
	fflush(stdin);
	gotoxy(3,3);printf("Ingrese el ID del producto:  ");
	scanf("%d",&consulta);
	datos_productos=fopen("datos_productos.txt","r+b");
	rewind(datos_productos);
	bandera=0;
	while(fread(pproducto,sizeof(*pproducto),1,datos_productos)){
		if (*pconsulta == pproducto->idp){
			bandera=1;
			break;
		}i++;
	}
	if (bandera == 0){
		gotoxy(28,10);printf("El id del producto no existe \n");
	}
	else
	{
		while(opcion_modificar!=0){
			system("cls");
			gotoxy(28,1);printf("EDITAR PRODUCTO");
			gotoxy(3,3); printf("ID");
			gotoxy(18,3);printf("PRODUCTO");
			gotoxy(39,3);printf("VALOR");
			if(*pconsulta == pproducto->idp){
				gotoxy(3,4); printf("%d",pproducto->idp);
				gotoxy(18,4); printf("%s",pproducto->nombre);
				gotoxy(39,4); printf("%.0f",pproducto->valor);
			}
			gotoxy(3,9); printf("MENU MODIFICACIONES");
			gotoxy(3,10); printf("1. Nombre");
			gotoxy(3,11); printf("2. Valor");
			gotoxy(3,12); printf("0. Salir");
			gotoxy(3,13); printf("Seleccione el dato a modificar: ");
			scanf("%d",&opcion_modificar);
			fflush(stdin);
			switch(opcion_modificar){
				case 1:{
					system("cls");
					fflush(stdin);
					gotoxy(28,1);printf("EDITAR PRODUCTO");
					gotoxy(3,3); printf("Ingrese el nuevo nombre: ");
					fgets(nuevo_nombre,15,stdin);
					fseek(datos_productos,ftell(datos_productos)-sizeof(*pproducto),SEEK_SET);
					fread(pproducto,sizeof(*pproducto),1,datos_productos);
					strcpy(pproducto->nombre,nuevo_nombre);
					fseek(datos_productos,ftell(datos_productos)-sizeof(*pproducto),SEEK_SET);
					fwrite(pproducto,sizeof(*pproducto),1,datos_productos);
					break;
				}
				case 2:{
					system("cls");
					fflush(stdin);
					gotoxy(28,1);printf("EDITAR PRODUCTO");
					gotoxy(3,3); printf("Ingrese el nuevo valor: ");
					scanf("%f",&nuevo_valor);
					fseek(datos_productos,ftell(datos_productos)-sizeof(*pproducto),SEEK_SET);
					fread(pproducto,sizeof(*pproducto),1,datos_productos);
					pproducto->valor = nuevo_valor;
					fseek(datos_productos,ftell(datos_productos)-sizeof(*pproducto),SEEK_SET);
					fwrite(pproducto,sizeof(*pproducto),1,datos_productos);
					break;
				}
				case 0:{
					break;
				}
				default:{
					system("cls");
					gotoxy(28,1);printf("EDITAR PRODUCTO");
					gotoxy(28,5);printf("OPCION INVALIDA");
					gotoxy(20,23);printf(" ");
					system("pause");
					break;
				}
			}
		}
	}fclose(datos_productos);
}

void crear_facturas(){
	gotoxy(3,3); printf("ID");
	gotoxy(7,3); printf("NOMBRE");
	datos_clientes=fopen("datos_clientes.txt", "r+b");
	rewind(datos_clientes);
	i=0;
	while(fread(pcliente, sizeof(*pcliente), 1, datos_clientes)){
		gotoxy(3,4+i); printf("%d", pcliente->idc);
		gotoxy(7,4+i); printf("%s", pcliente->nombre);
		i++;
	}
	fclose(datos_clientes);
	gotoxy(35,3); printf("ID");
	gotoxy(39,3);printf("PRODUCTO");
	gotoxy(55,3);printf("VALOR");
	datos_productos=fopen("datos_productos.txt","r+b");
	rewind(datos_productos);
	i=0;
	while(fread(pproducto,sizeof(*pproducto),1,datos_productos))
	{	
		gotoxy(35,4+i);printf("%d",pproducto->idp);
		gotoxy(39,4+i);printf("%s",pproducto->nombre);
		gotoxy(55,4+i);printf("%.0f",pproducto->valor);
		i++;
	}
	fclose(datos_productos);
	facturas=fopen("facturas.txt", "rb");
	datos_productos=fopen("datos_productos.txt", "rb");
	rewind(datos_productos);
	rewind(facturas);
	fseek(facturas, ftell(facturas)-sizeof(*pfactura), SEEK_END);
	fread(pfactura, sizeof(*pfactura), 1, facturas);
	pfactura->idf=pfactura->idf+1;
	rewind(facturas);
	fclose(facturas);
	fflush(stdin);	
	gotoxy(3,15); printf("Ingrese el id del cliente: ");
	scanf("%d", &(pfactura->id_cliente));
	fflush(stdin);
	gotoxy(3,16); printf("Ingrese el numero de productos a llevar: ");
	scanf("%d", &np);
	*pacumu_precio=0;
	for(i=0; i<np; i++){
		gotoxy(3,17+i); printf("Ingrese el id del producto: ");
		scanf("%d", &(pfactura->id_producto[i]));
		gotoxy(40,17+i); printf("Cantidad a llevar: ");
		scanf("%d", &(pfactura->cant[i]));
		while(fread(pproducto, sizeof(*pproducto), 1, datos_productos)){
			if(pfactura->id_producto[i] == pproducto->idp){
				*pacumu_precio = *pacumu_precio + ( pproducto->valor * pfactura->cant[i] );
			}
		}
	}
	pfactura->total = *pacumu_precio + *pacumu_precio;
	fflush(stdin);
	gotoxy(3,23); printf("Estado de factura: P. Pagada  S. Sin pagar: ");
	scanf("%s", &(pfactura->estado));
	fflush(stdin);
	
	facturas=fopen("facturas.txt", "a+b");
	if(facturas == NULL){
		facturas=fopen("facturas.txt", "w+b");
	}
	fwrite(pfactura, sizeof(*pfactura), 1, facturas);
	rewind(facturas);
	fclose(facturas);
}

void listar_facturas(){
	datos_clientes=fopen("datos_clientes.txt", "r+b");
	datos_productos=fopen("datos_productos.txt","r+b");
	facturas=fopen("facturas.txt", "r+b");
	gotoxy(3,3); printf("ID FACTURA");
	gotoxy(15,3); printf("ID CLIENTE");
	gotoxy(26,3); printf("CEDULA");
	gotoxy(37,3); printf("NOMBRE");
	rewind(datos_clientes);
	rewind(datos_productos);
	rewind(facturas);
	i=0;
	bandera=0;
	while(fread(pfactura, sizeof(*pfactura), 1, facturas)){
		gotoxy(3,4+i); printf("%d", pfactura->idf);
		gotoxy(15,4+i); printf("%d", pfactura->id_cliente);
		rewind(datos_clientes);
		while(fread(pcliente, sizeof(*pcliente), 1, datos_clientes)){
			if(pfactura->id_cliente==pcliente->idc){
				gotoxy(26,4+i); printf("%s", pcliente->cedula);
				gotoxy(37,4+i); printf("%s", pcliente->nombre);
				i++;
			}
		}
	}
	rewind(facturas);
	rewind(datos_clientes);
	gotoxy(3,23);printf("Ingrese el id de la factura a visualizar: ");
	scanf("%d", &(*pconsulta));
	while(fread(pfactura, sizeof(*pfactura), 1, facturas)){
		if(*pconsulta == pfactura->idf){
			bandera=1;
			break;
		}
	}
	if(bandera==0){
		system("cls");
		gotoxy(24,8); printf("NO SE ENCONTRO NINGUN DATO");
		gotoxy(20,23); printf(" ");
		system("pause");
	}
	else{
		system("cls");
		gotoxy(28,1); printf("DETALLE FACTURA");
		gotoxy(3,3); printf("IdFACT");
		gotoxy(11,3); printf("IdCLIENTE");
		gotoxy(21,3); printf("CEDULA");
		gotoxy(32,3); printf("NOMBRE");
		gotoxy(58,3); printf("DIRECCION");
		gotoxy(69,3); printf("TELEFONO");
		gotoxy(3,6); printf("PRODUCTOS");
		gotoxy(3,7); printf("ID");
		gotoxy(7,7); printf("PRODUCTO");
		gotoxy(24,7); printf("VALOR");
		gotoxy(30,7); printf("CANT");
		gotoxy(3,20);printf("ESTADOFACT");
		gotoxy(20,20); printf("TOTAL");
		i=0;
		while(fread(pcliente, sizeof(*pcliente), 1, datos_clientes)){
			if(pfactura->id_cliente == pcliente->idc){
				gotoxy(3,4); printf("%d", pfactura->idf);
				gotoxy(11,4); printf("%d", pcliente->idc);
				gotoxy(21,4); printf("%s", pcliente->cedula);
				gotoxy(32,4); printf("%s", pcliente->nombre);
				gotoxy(58,4); printf("%s", pcliente->dir);
				gotoxy(69,4); printf("%s", pcliente->tel);
				while(fread(pproducto, sizeof(*pproducto), 1, datos_productos)){
					if(pfactura->id_producto[i] == pproducto->idp){
						gotoxy(3,8+i); printf("%d", pproducto->idp);
						gotoxy(7,8+i); printf("%s", pproducto->nombre);
						gotoxy(24,8+i); printf("%.0f", pproducto->valor);
						gotoxy(30,8+i); printf("%d", pfactura->cant[i]);
						gotoxy(20,21); printf("%.0f", pfactura->total);
						//gotoxy(3,30); printf("%s",pfactura->estado);
						i++;
					}
				}i++;
			}
		}
	}gotoxy(28,23); printf(" ");
	rewind(facturas);
	fclose(facturas);
	rewind(datos_productos);
	fclose(datos_productos);
	rewind(datos_clientes);
	fclose(datos_clientes);
}
