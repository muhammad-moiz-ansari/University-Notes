#include <iostream>
#include <chrono>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    // Start measuring time
    auto start = std::chrono::high_resolution_clock::now();

    // The code you want to measure
    int n = 1000;
    string str = "", stars = "";// , spaces = "";
    
    for (int i = 0; i < n; ++i) 
    {
        stars.append("*");
        str.append(stars);
        str.append("\n");
        cout << str;
    }
    /*for (int i = 0; i < n; ++i)
        spaces.append(" ");
    for (int i = n; i > 0; --i)
    {
        stars.append("*");
        str.append(spaces);
        str.append(stars);
        str.append("\n");
        remove(spaces.begin(), spaces.end(), ' ');
        cout << str;
    }*/
    cout << str;

    // Stop measuring time
    auto stop = std::chrono::high_resolution_clock::now();

    // Calculate the duration (in microseconds)
    auto duration1 = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    auto duration2 = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    auto duration3 = std::chrono::duration_cast<std::chrono::seconds>(stop - start);

    std::cout << "Time taken: " << duration1.count() << " microseconds" << std::endl;
    std::cout << "Time taken: " << duration2.count() << " milliseconds" << std::endl;
    std::cout << "Time taken: " << duration3.count() << " seconds" << std::endl;

    return 0;
}