/*
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#include "genetic.h"

int main(int argc, char* archv[])
{
    int n = 8; //For now only
    Genetic* g = new Genetic(n);
    g->solve();

    // Deletes
    delete g;
}
