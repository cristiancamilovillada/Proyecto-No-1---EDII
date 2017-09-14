/*
** MENU PRICIPAL, CON LOS SUBMENUS
*/
#include<windows.h>
#include"funciones.h"
void menu();

void menu(){
	int opc=1;
	while(opc!=0){
		system("cls");
		gotoxy(25,1); printf("M E N U   F A C T U R A C I O N");
		gotoxy(3,3); printf("1. Clientes ");
		gotoxy(3,4); printf("2. Productos ");
		gotoxy(3,5); printf("3. Facturas ");
		gotoxy(3,6); printf("0. Salir ");
		gotoxy(3,7); printf("Seleccione una opcion: ");
		scanf("%d", &opc);
		
		switch(opc){
			case 1:{
				int opc=1;
				while(opc!=0){
					system("cls");
					gotoxy(28,1); printf("C L I E N T E S");
					gotoxy(3,3); printf("1. Crear clientes ");
					gotoxy(3,4); printf("2. Listar todos los clientes ");
					gotoxy(3,5); printf("3. Editar cliente ");
					gotoxy(3,6); printf("0. Salir ");
					gotoxy(3,7); printf("Seleccione una opcion: ");
					scanf("%d", &opc);
					
					switch(opc){
						case 1:{
							system("cls");
							gotoxy(28,1); printf("CREAR CLIENTES");
							crear_cliente();
							system("pause");
							break;
						}
						case 2:{
							system("cls");
							gotoxy(28,1); printf("LISTAR TODOS LOS CLIENTES");
							listar_cliente();
							system("pause");
							break;
						}
						case 3:{
							system("cls");
							gotoxy(28,1); printf("EDITAR CLIENTE");
							editar_cliente();
							system("pause");
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
				break;
			}
			case 2:{
				int opc=1;
				while(opc!=0){
					system("cls");
					gotoxy(28,1); printf("P R O D U C T O S");
					gotoxy(3,3); printf("1. Crear producto");
					gotoxy(3,4); printf("2. Listar todos los productos");
					gotoxy(3,5); printf("3. Editar producto");
					gotoxy(3,6); printf("4. Mostrar productos y cantidad vendida");
					gotoxy(3,7); printf("0. Salir");
					gotoxy(3,8); printf("Seleccione una opcion: ");
					scanf("%d", &opc);
					
					switch(opc){
						case 1:{
							system("cls");
							gotoxy(28,1); printf("CREAR PRODUCTO");
							crear_producto();
							system("pause");
							break;
						}
						case 2:{
							system("cls");
							gotoxy(28,1); printf("LISTAR TODOS LOS PRODUCTOS");
							listar_productos();
							system("pause");
							break;
						}
						case 3:{
							system("cls");
							gotoxy(28,1); printf("EDITAR PRODUCTO");
							editar_productos();
							system("pause");
							break;
						}
						case 4:{
							system("cls");
							gotoxy(28,1); printf("MOSTRAR PRODUCTOS Y CANTIDAD VENDIDA");
							
							system("pause");
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
				break;
			}
			case 3:{
				int opc=1;
				while(opc!=0){
					system("cls");
					gotoxy(28,1); printf("F A C T U R A S");
					gotoxy(3,3); printf("1. Crear factura \n");
					gotoxy(3,4); printf("2. Listar todas las facturas \n");
					gotoxy(3,5); printf("3. Editar factura \n");
					gotoxy(3,6); printf("4. Facturas generadas por un cliente \n");
					gotoxy(3,7); printf("5. Facturas pagadas y sin pagar \n");
					gotoxy(3,8); printf("0. Salir \n");
					gotoxy(3,9); printf("Seleccione una opcion: ");
					scanf("%d", &opc);
					
					switch(opc){
						case 1:{
							system("cls");
							gotoxy(28,1); printf("CREAR FACTURA");
							crear_facturas();
							system("pause");
							break;
						}
						case 2:{
							system("cls");
							gotoxy(28,1); printf("LISTAR TODAS LAS FACTURAS");
							listar_facturas();
							system("pause");
							break;
						}
						case 3:{
							system("cls");
							gotoxy(28,1); printf("EDITAR FACTURA");
							
							system("pause");
							break;
						}
						case 4:{
							system("cls");
							gotoxy(28,1); printf("FACTURAS GENERADAS POR UN CLIENTE");
							
							system("pause");
							break;
						}
						case 5:{
							system("cls");
							gotoxy(28,1); printf("FACTURAS PAGADAS Y SIN PAGAR");
							
							system("pause");
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
}
