#include <iostream>
#include "headers/Array.hpp"

// int main() {
//     try {
//         Array<int> emptyArray;
//         std::cout << "Empty array size: " << emptyArray.size() << std::endl;
//         Array<int> intArray(5);
//         std::cout << "intArray size: " << intArray.size() << std::endl;
//         for (unsigned int i = 0; i < intArray.size(); ++i) {
//             intArray[i] = i * 10;
//             std::cout << intArray[i] << std::endl;
//         }
//         std::cout << intArray[69420];
//     } catch (const std::exception& e) {std::cerr << "Exception caught: " << e.what() << std::endl;}
//     try {
//         Array<char> charArr(10);
//         char z = 'a' ;
//         for (unsigned int i = 0; i < charArr.size(); ++i) {charArr[i] = z; z++;}
//         charArr[0] = 'z';
//         for (unsigned int i = 0; i < charArr.size(); ++i) {std::cout << charArr[i] << " ";}
//         std::cout << std::endl;
//         const Array<char> constCharArr = charArr;
//         for (unsigned int i = 0; i < constCharArr.size(); ++i) {std::cout << constCharArr[i] << " ";}       // using the const operator[]
//         std::cout << std::endl;
//         Array<int> noInt(0);
//         std::cout << noInt[0];
//     } catch (const std::exception& e) {std::cerr << "Exception caught: " << e.what() << std::endl;}
//     return (0);
// }

#define MAX_VAL 750
int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
}