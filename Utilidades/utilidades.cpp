#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <limits>
#include <string.h>

using namespace std;

int leerEntero(string mensaje)
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

char leerChar(string mensaje)
{
    char a, b;
    cout << mensaje;
    cin.get(b);
    do
    {
        cin.get(a);
    } while (a != '\n');
    return b;
}

int contarLineas(string archivo)
{
    ifstream ifs;
    ifs.open(archivo);
    if (ifs.fail())
        return -1;
    int lineas = 0;
    while (!ifs.eof())
    {
        if (ifs.get() == '\n')
            lineas++;
    }
    ifs.close();
    return lineas;
}
