// advent-of-code-2024-03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::string a;
    std::string b;
    std::ifstream file("input.txt");
    if (!file.is_open()) {
        std::cout << "failed to open" << std::endl;
        return 1;
    }
    std::string content((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    int s = 0;
    int maxlength = content.size();
    for (int i = 0; i < maxlength; i++)
    {
        std::string motMul;
        int j;
        for (j = i;j<maxlength && j < i + 4;j++) {
            motMul = motMul + content[j];
        }
        if (motMul == "mul(" && content[j] <= '9' && content[j] >= '0') {
            while (j< maxlength && content[j] <= '9' && content[j] >= '0') {
                a += content[j];
                j++;
            }if (j + 1 < maxlength && content[j] == ',' && content[j+1] <= '9' && content[j+1] >= '0')
            {
                j++;
                while (j < maxlength && content[j] <= '9' && content[j] >= '0') {
                    b += content[j];
                    j++;
                }
                if (content[j] == ')')
                {
                    s += stoi(a) * stoi(b);
                    i = j - 1;
                    a = "";
                    b = "";
                }
                else {
                    b = "";
                    a = "";
                }
            }
            else a = "";
        }
    }
    std::cout << s << std::endl;
    std::cout << "Hello World!\n";
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
