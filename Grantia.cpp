// Grantia.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <time.h>
#include <stdio.h>
#include <sys/types.h>
/*#include <sys/select.h>
#include <sys/socket.h>*/
#include <WinSock2.h>
#include "microhttpd.h"
#include <stdlib.h>
#include <string.h>



#define PORT 8888

class Fibo 
{
    public:
        int value;
        int gene_out;

        Fibo(int);
        ~Fibo();        
        void fibo_position();
    private:
        int initial = 0;
        int initial2 = 1;
        int generate = 0;
};

Fibo::Fibo(int value_in) {
    value = value_in;
}
Fibo::~Fibo() {

}
void Fibo::fibo_position() {
    int i=1;
    /*for (i = 1; i < value; ++i){
        initial = initial2;
        initial2 = generate;
        generate = initial + initial2;
    }*/
    if (value == 1) {
        gene_out = 2;
    }
    else {
        while (generate < value) {
            initial = initial2;
            initial2 = generate;
            generate = initial + initial2;
            i++;
        }
        if (generate != value)
            gene_out = -1;
        else
            gene_out = i;// generate;
    }
}
#define PAGE "<html><head><title>libmicrohttpd demo</title>"\
             "</head><body>libmicrohttpd demo</body></html>"

int main() {
    int lim;

/*********************************************************************************************/

/*********************************************************************************************/
    std::cout << "Ingrese un numero para la sucesion de fibonacci: ";
    std::cin >> lim;
    Fibo SerieFibo(lim);
    SerieFibo.fibo_position();
    std::cout << "el valor es:" << SerieFibo.gene_out << std::endl;
    system("pause");
}
