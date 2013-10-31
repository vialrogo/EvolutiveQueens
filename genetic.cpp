/* IME-USP
 * Evolutive Queens:
 *      Eight queens by the evolutive way
 *
 * Victor Alberto Romero
 * Universidade de São Paulo
 * Intenigência Artificial
 * Outubro de 2013
 */

#include "genetic.h"

Genetic::Genetic(int nIn)
{
    //Commom values
    population = 20;
    crossBest = 12;
    crossNumberGood = 18;
    mutation = 2;
    
    n = nIn;
    matinPool = new Solution*[population];
}

Genetic::~Genetic()
{
    delete matinPool;
}

void Genetic::solve()
{
    int iterations=0;
    Solution** newPool = new Solution*[population];

    // Create random initial population
    for (int i = 0; i < population; i++)
        matinPool[i] = new Solution(n);

    while(!hasSolution())
    {
        // Sort the population
        mergeSort(0, (population-1), matinPool);
        
        // Generate crossNumberGood sons from the bests
        for (int i = 0; i < crossNumberGood; i++)
            newPool[i] = matinPool[rand()%crossBest]->cross(matinPool[rand()%crossBest]);
       
        // Generate (population - crossNumberGood) sons from the worsts
        for (int i = crossNumberGood; i < population; i++)
            newPool[i] = matinPool[rand()%(population-crossBest) + crossBest]->cross(matinPool[rand()%(population-crossBest) + crossBest]);
        
        // Mutate some of the population
        for (int i = 0; i < mutation; i++)
            newPool[rand()%population]->mutate();

        // Remplace the old pool
        for (int i = 0; i < population; i++)
        {
            delete matinPool[i];
            matinPool[i] = newPool[i];
        }

        iterations++;
    }

    // Print the solution
    mergeSort(0, (population-1), matinPool);
    matinPool[0]->printState();
    cout << endl << "Total Iterations: " << iterations <<endl;

    // Deletes
    for (int i = 0; i < population; i++)
        delete matinPool[i];
    
    delete newPool;
}

bool Genetic::hasSolution()
{
    for (int i = 0; i < population; i++)
        if(matinPool[i]->attacks == 0 )
            return true;

    return false;
}

void Genetic::mergeSort(int start, int end, Solution** array)
{
    int size = end-start+1;

    if(size>1 && size==2)
    {
        if(array[start]->attacks > array[end]->attacks)
        {
            Solution* temp = array[start];
            array[start]=array[end];
            array[end]=temp;
        }
    }
    if(size>2)
    {
        int sizeL =floor(((double)size)/2.0);
        int sizeR =ceil(((double)size)/2.0);

        int start1 = start;
        int end1 = start+sizeL-1;
        int start2 = start+sizeL;
        int end2 = start+sizeL+sizeR-1;

        mergeSort(start1, end1, array);
        mergeSort(start2, end2, array);
        merge(start1, end1, start2, end2, array);
    }
}

void Genetic::merge(int start1, int end1, int start2, int end2, Solution** array)
{
    int startO = start1;
    int sizeTotal = end2-start1+1;
    Solution** temp = new Solution*[sizeTotal];

    for (int i = 0; i < sizeTotal; ++i)
    {
        if(start1 > end1)
        {
            temp[i]=array[start2];
            start2++;
        }
        else if(start2 > end2)
        {
            temp[i]=array[start1];
            start1++;
        }
        else
        {
            if(array[start1]->attacks < array[start2]->attacks)
            {
                temp[i]=array[start1];
                start1++;
            }
            else
            {
                temp[i]=array[start2];
                start2++;
            }
        }
    }

    for (int i = 0; i < sizeTotal; ++i)
    {
        array[i+startO] = temp[i];
    }

    // Deletes
    delete temp;
}

