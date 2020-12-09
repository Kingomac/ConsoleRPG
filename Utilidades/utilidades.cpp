#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <string.h>

using namespace std;

int leerEntero(char mensaje[])
{
    int a;
    cout << mensaje;
    cin >> setw(1) >> a;
    while (!cin.good())
    {
        cout << mensaje;
        cin.clear();
        cin.ignore(numeric_limits<int>::max(), '\n');
        cin >> setw(1) >> a;
    }
    return a;
}

char leerChar(char mensaje[])
{
    char a;
    cout << mensaje;
    cin >> a;
    return a;
}

int contarLineas(string archivo)
{
    ifstream ifs;
    ifs.open(archivo);
    if (ifs.fail()) {
        cout << "Error con el archivo " << archivo << endl;
        exit(1);
    }
    int lineas = 0;
    while (!ifs.eof())
    {
        if (ifs.get() == '\n')
            lineas++;
    }
    ifs.close();
    return lineas;
}
