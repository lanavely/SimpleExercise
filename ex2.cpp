#include <iostream>
#include <fstream>
#include <ostream>
#include <stdexcept>
#include <string>

int main()
{
    // input
    auto ifs = std::ifstream("var1.txt");
    if (!ifs.is_open())
        throw std::runtime_error("Can't open file");
    int size;
    ifs >> size;
    auto arr(new int[5]);
    for (int i = 0; i < size; i++)
        ifs >> arr[i];
    ifs.close();

    // castom sort
    [&] {
        for (int i = 0; i < size - 1; i += 2) {
            for (int j = 0; j < size - i - 1; j += 2) {
                if (arr[j] > arr[j + 2]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 2];
                    arr[j + 2] = temp;
                }
                else
                    return;
            }
        }
    }();

    // console out
    for (int i = 0; i < size; i++)
        std::cout << arr[i] << std::endl;

    // file wrap
    std::cout << "Enter file name: ";
    std::string fileName;
    std::cin >> fileName;
    std::ofstream ofs;
    ofs.open(fileName);
    if (!ofs.is_open())
        throw std::runtime_error("Can't write file");
    for (int i = 0; i < size; i++)
        ofs << arr[i] << " ";
    ofs.close();

    delete[] arr;
    system("pause");
    return 0;
}