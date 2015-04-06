#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

bool repetido(int a)
{
    string cadena;
    stringstream stream;

    stream << a;
    cadena = stream.str();

    for(int i = 0; i < cadena.size(); i++){
        for(int j = i+1; j < cadena.size(); j++){
            if(cadena[i] == cadena[j]){
                return true;
            }
        }
    }
    return false;
}

int main()
{
    int n, m, cont;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        cont = 0;
        for(int i = n; i <= m; i++){
            if(!repetido(i))
                cont++;
        }
        printf("%d\n", cont);
    }
    return 0;
}
