#include "lab1.h"

class SortingMethods
{
public:
/* 
    * Implemenation of Comb Sorting algorythm.
    * Modifies passed array.
    * 
    * @param arr - pointer to unsorted array.
    * @param length of passed array.
    * @param shrink factor of gap
    * @return void
    */
    static void combSort(double *arr, int length, double shrink=1.27)
{
    double temp;
    int gap = length;
    bool sorted = false;
    while (!sorted)
    {
        gap = std::floor(gap / shrink);
        if (gap < 1)
        {
            gap = 1;
            sorted = true;
        }
        for (int i=0; i < length-gap; i++)
        {   
            if (arr[i] > arr[i+gap])
            {
                std::swap(arr[i], arr[i+gap]);
            }
        }
    }
}
    
/* 
    * Populate array with random values
    * 
    * @param arr - pointer to unsorted array.
    * @param length of passed array.
    * @param min_val - lower bound for random values
    * @param max_val - upper bound for random values
    * @return void
    */
    static void generateArray(double *arr, int length, double min_val=DBL_MIN, double max_val=DBL_MAX)
{
    
    srand(time(0));
    for (int i=0; i<length; i++)
    {
        arr[i] = min_val + ((double) rand() / RAND_MAX) * (max_val - min_val);
    }
}
    
/* 
    * Print array values to stdout
    * 
    * 
    * @param arr - pointer to unsorted array.
    * @param length of passed array.
    * @param stream pointer to redirect output
    * @return void
    */
    static void displayArray(double *arr, int length, std::ostream& stream=std::cout)
{
    for (int i=0; i<length; i++)
    {
        stream << arr[i] << std::endl;
    }
}
};
