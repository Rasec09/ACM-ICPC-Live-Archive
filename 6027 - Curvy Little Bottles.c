#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.14159265
#define ERROR 0.00001

int n;
double pol[12], pol_int[22];

void integrar(int n)
{
    int i, j;

    for(i = 0; i<=2*n; i++)
        pol_int[i] = 0;

    for(i = 0; i<=n; i++){
        for(j = 0; j<=n; j++){
            pol_int[i+j] += pol[i]*pol[j];
        }
    }
}

double volumen(double a, double b)
{
    double vol = 0;
    double pot_a = 1, pot_b = 1;
    int i;

    for(i = 0; i<=(2*n); i++){
        pot_b *= b;
        pot_a *= a;
        vol += pol_int[i]/(i+1)*(pot_b - pot_a);
    }

    return PI*vol;
}

double buscar(double low, double high, double inc)
{
    double volume = -1;
    double ini, fin, m;
    ini = low;
    fin = high;

    while(fabs(volume - inc) > ERROR)
    {
        m = (ini + fin)/2.0;
        volume = volumen(low, m);
        if(volume < inc)
            ini = m;
        else
            fin = m;
    }

    return m;
}

int main()
{
    int cont = 0, i, k;
    double xlow, xhigh, inc, vol, ini, next;

    while(scanf("%d", &n) != EOF){

        cont++;
        for(i = 0; i<=n; i++){
            scanf("%lf", &pol[i]);
        }
        scanf("%lf %lf %lf", &xlow, &xhigh, &inc);
        integrar(n);
        vol = volumen(xlow, xhigh);
        printf("Case %d: %0.2lf\n", cont, vol);
        if(vol < inc){
            printf("insufficient volume\n");
        }
        else {
            ini = xlow;
            next = buscar(ini, xhigh, inc);
            ini = next;
            vol = volumen(ini, xhigh);
            printf("%0.2lf", ini-xlow);
            for(k = 1; k < 8 && (vol > inc); k++){
                next = buscar(ini, xhigh, inc);
                ini = next;
                vol = volumen(ini, xhigh);
                printf(" %0.2lf", ini-xlow);
            }
            printf("\n");
        }

        xlow = 0;
        xhigh = 0;
        vol = 0.0;
        ini = 0.0;
        next = 0.0;
    }
    return 0;
}
