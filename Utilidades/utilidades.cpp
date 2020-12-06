#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;

int leerEntero(char mensaje[])
{
    int a;
    cout << mensaje << endl;
    cin >> setw(1) >> a;
    while (!cin.good())
    {
        cout << mensaje << endl;
        cin.clear();
        cin.ignore(INT32_MAX, '\n');
        cin >> setw(1) >> a;
    }
    return a;
}

int contarLineas(string archivo)
{
    ifstream ifs;
    ifs.open(archivo);
    if (ifs.fail())
        return -1;
    cout << "El archivo existe, se contar�n las l�neas" << endl;
    int lineas = 0;
    while (!ifs.eof())
    {
        if (ifs.get() == '\n')
            lineas++;
    }
    ifs.close();
    return lineas;
}
