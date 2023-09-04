#include <iostream>
#include <fstream>
#include "lab1.cpp"

void lab1();
void lab2();
void lab3();
void lab4();

int main()
{
    lab1();
    std::cout << "Hello World!" << std::endl;
    return 0;
}

void lab1()
{
    int length = 80;
    double arr[length];
    std::ofstream file_stream;
    file_stream.open("res/lab1_result.txt");
    
    SortingMethods::generateArray(arr, length, 100, 999);
    SortingMethods::combSort(arr, length);
    SortingMethods::displayArray(arr, length, file_stream);
    
    file_stream.close();
}
