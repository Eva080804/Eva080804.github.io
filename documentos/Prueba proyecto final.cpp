/*
	Hemos creado una biblioteca online en la que el usuario podrá añadir, eliminar, buscar y reservar sus libros preferidos.
	Todo el proceso que haga con los libros quedará guardado en un registro interno al cual podrá acceder pulsando la tecla 
	correspondiente al registro de administrador.
*/

#include <iostream>
#include <string>
#include <fstream>
using namespace std;

//Creamos la estructura de Libro.
struct Libro{
	string titulo;
	string autor;
	string isbn;
	string genero;
	char reservado;
};

//Inicializamos las funciones.
Libro anadir_libro (Libro, int, int, int, Libro);
Libro eliminar_libro (Libro, int);
Libro buscar_libro (Libro, int);
int reservar_libro (Libro, int);
int registro_admin (Libro, int, int);

Libro biblioteca[100];
Libro biblioteca_registro[200];
int i, j;
char a, b;

int main ()
{
	cout << "Bienvenidos a nuestra biblioteca online" << endl;
	cout << "A continuacion les mostraremos la oferta de libros que podemos ofrecerle" << endl;

	//Abrimos el documento de lectura.
	ifstream f;
	f.open("datosBiblioteca.txt");
		if (f.fail())
	{
		cout << "La ruta no exixte" << endl;
	}

	int i = 0, r, n = 1;
	
	//Asignamos cada linea acuerdo a la estructura de Libro que esta predeterminada.
	while (f.eof())
	{
		getline (f, biblioteca[i].titulo);
		getline (f, biblioteca[i].autor);
		f >> biblioteca[i].isbn;
		getline (f, biblioteca[i].genero);
		f >> r;
		
		// "a" se refiere a no reservado y "b" a reservado.
		if (r == a)
		{
			biblioteca[i].reservado = a;
		}
		else
		{
			biblioteca[i].reservado = b;
		}
		
		i++;
		n++;
	}
	
	//Mostramos los libros que se encuentran en el docuemento.
	for (int i = 0; i <= 100; i++)
	{
		cout << "El libro " << i << "corresponde a: " << endl;
		cout << biblioteca[i].titulo << endl;
		cout << biblioteca[i].autor << endl;
		cout << biblioteca[i].isbn << endl;
		cout << biblioteca[i].genero << endl;
	}
	
	f.close();
	
	biblioteca [i] = biblioteca_registro [i];
	
	// Leer registro de administrador.
	ofstream g;
	g.open("datosBiblioteca_registro.txt");
		if (f.fail())
	{
		cout << "La ruta no existe" << endl;
	}

	int j = 0, e, t = 1;
	
	while (g.eof())
	{
		g << biblioteca_registro[j].titulo;
		g << biblioteca_registro[j].autor;
		g << biblioteca_registro[j].isbn;
		g << biblioteca_registro[j].genero;
		g << t;
		
		if (e == a)
		{
			biblioteca_registro[j].reservado = a;
		}
		else
		{
			biblioteca_registro[j].reservado = b;
		}
		
		j++;
		t++;
	}
	
	
	int valor;
	
	//Asignamos un valor a cada una de las secciones de la biblioteca con un switch-case.
	cout << "Porfavor introduzca un numero para realizar la funcion correspondiente: " << endl;
	cout << "0. Cerrar la biblioteca." << endl;
	cout << "1. Añadir un libro a la biblioteca." << endl;
	cout << "2. Eliminar un libro de la biblioteca." << endl;
	cout << "3. Buscar un libro en la biblioteca." << endl;
	cout << "4. Reservar un libro de la biblioteca." << endl;
	cout << "5. Acceder al registro de administrador de la biblioteca." << endl;
	cin >> valor;
	
	do
	{
		switch (valor)
		{
			case 0:
				cout << "¿Esta usted seguro que quiere cerrar la biblioteca?" << endl;
				cout << "En caso que quiera cerrarla, pulse 0, para otras acciones pulse del 1-5." << endl;
				break;
			case 1:
				anadir_libro (biblioteca_registro[200], i, t, n, biblioteca[100]);
				cout << "Si desea seguir navegando entre nuestros libros, pulse una tecla del 1-5. En caso contrario pulse 0." << endl;
				break;
			case 2:
				eliminar_libro (biblioteca[i], i);
				cout << "Si desea seguir navegando entre nuestros libros, pulse una tecla del 1-5. En caso contrario pulse 0." << endl;
				break;
			case 3:
				buscar_libro (biblioteca[i], i);
				cout << "Si desea seguir navegando entre nuestros libros, pulse una tecla del 1-5. En caso contrario pulse 0." << endl;
				break;
			case 4:
				reservar_libro (biblioteca[i], i);
				cout << "Si desea seguir navegando entre nuestros libros, pulse una tecla del 1-5. En caso contrario pulse 0." << endl;
				break;
			case 5:
				registro_admin (biblioteca_registro[i], i, j);
				cout << "Si desea seguir navegando entre nuestros libros, pulse una tecla del 1-5. En caso contrario pulse 0." << endl;
				break;
			default:
				cout << "Seleccione un valor que aparezca en el menu (0-5)" << endl;
				break;
		}
		
		cin >> valor;
		
	} while (valor != 0);
	
	cout << "¡Gracias por su visita!" << endl;
	f.close();
	g.close();
	
	return 0;
}

Libro anadir_libro (Libro biblioteca_registro[200], int i, int t, int n, Libro biblioteca[100])
{
	//Abrimos el documento anterior pero de forma que podamos editarlo.
	ofstream f;
	f.open("datosBiblioteca.txt");
	
	if (f.fail())
	{
		cout << "La ruta es incorrecta" << endl;
	}
	
	cout << "Usted ha seleccionado la seccion de añadir libros" << endl;
	cout << "Para añadir un libro nuevo necesitara introducir respectivamente los siguientes \n datos: el titulo, el autor, el isbn y el genero al caual pertenece." << endl;
	
	cin >> biblioteca[n].titulo >> biblioteca[n].autor >> biblioteca[n].isbn >> biblioteca[i].genero;
	
	biblioteca[n].reservado = 0;
	
	//Escribimos los datos que el usuario nos ha transmitido en el documento.
	f << biblioteca[n].titulo;
	f << biblioteca[n].autor;
	f << biblioteca[n].isbn;
	f << biblioteca[n].genero;
	f << biblioteca[n].reservado;

	biblioteca_registro[t] = biblioteca[n];
	
	f.close();
	
	cout << "Se ha añadido su libro correctamente a la biblioteca." << endl;
	
	return biblioteca[i];
}

Libro eliminar_libro (Libro biblioteca[100], int i)
{
	string titulo, autor, isbn, genero;
	
	//Abrimos el documento para modificar.
	ofstream f;
	f.open("datosBiblioteca.txt");
	if (f.fail())
	{
		cout << "La ruta es incorrecta" << endl;
	}
	
	cout << "Usted ha seleccionado la seccion de eliminar un libro" << endl;
	cout << "De los libros anteriormente mostrados, elija el libro que quiera elimnar." << endl;
	cin >> i;
	cout << "El libro que usted ha seleccionado corresponde a: " << endl;
	cout << biblioteca[i].titulo << endl;
	cout << biblioteca[i].autor << endl;
	cout << biblioteca[i].isbn << endl;
	cout << biblioteca[i].genero << endl;
	
	//Borramos los datos referentes al libro escogido a partir de las funciones de los strings.
	biblioteca[i].titulo.erase(1, biblioteca[i].titulo.length());
	biblioteca[i].autor.erase(1, biblioteca[i].autor.length());
	biblioteca[i].isbn.erase(1, biblioteca[i].isbn.length());
	biblioteca[i].genero.erase(1, biblioteca[i].genero.length());
	
	f.close();
	
	cout << "El libro se ha borrado correctamente." << endl;
	
	return biblioteca[i];
}

Libro buscar_libro (Libro biblioteca[100], int i)
{
	cout << "Usted ha seleccionado la seccion de busqueda de libros" << endl;
	cout << "De los libros anteriormente mostrados, elija el numero de libro que desea buscar." << endl;
	cin >> i;
	
	cout << "El libro que ha seleccionado corresponde a: " << endl;
	cout << biblioteca[i].titulo << endl;
	cout << biblioteca[i].autor << endl;
	cout << biblioteca[i].isbn << endl;
	cout << biblioteca[i].genero << endl;
	
	return biblioteca[i];
}

int reservar_libro (Libro biblioteca[100], int i)
{
	//Abrimos el documento para que el usuario pueda pasar de tener un libro sin reservar a uno reservado.
	ofstream f;
	f.open("datosBiblioteca.txt");
	if (f.fail())
	{
		cout << "La ruta es incorrecta" << endl;
	}
	
	cout << "Usted ha seleccionado la seccion de reservar un libro" << endl;
	cout << "De los libros anteriormente mostrados, elija el numero de libro que desea reservar." << endl;
	cin >> i;
	cout << "El libro que usted ha seleccionado corresponde a: " << endl;
	cout << biblioteca[i].titulo << endl;
	cout << biblioteca[i].autor << endl;
	cout << biblioteca[i].isbn << endl;
	cout << biblioteca[i].genero << endl;
	
	string cadena;
	
	if (biblioteca[i].reservado = a)
	{
		cout << "El libro que usted ha escogido no esta reservado" << endl;
		cadena = biblioteca[i].reservado;
		cadena.replace (1, 1, "b");
		cout << "Su libro ha sido reservado satisfactoriamente" << endl;
	}
	else 
	{
		cout << "El libro que usted ha escogido esta reservado, lo sentimos." << endl;
	}
	
	f.close();
	
	return 0;
}

int registro_admin (Libro biblioteca_registro[200], int i, int j)
{
	cout << "Usted ha accedido al registro de administrador de la biblioteca" << endl;
	
	//Mostramos todos los libros inscritos en el registro de la biblioteca.
	for (j = 0; j <= 200; j++);
	{
		cout << biblioteca_registro[j].titulo << endl;
		cout << biblioteca_registro[j].autor << endl;
		cout << biblioteca_registro[j].isbn << endl;
		cout << biblioteca_registro[j].genero << endl;
		cout << biblioteca_registro[j].reservado << endl;
	}
	
	return 0;
}
