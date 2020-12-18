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
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return a;
}

char leerChar(string mensaje)
{
    char a;
    cout << mensaje;
    cin.get(a);
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return a;
}

int contarLineas(string archivo)
{
    ifstream ifs;
    ifs.open(archivo);
    if (ifs.fail())
    {
        ifs.close();
        return -1;
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
