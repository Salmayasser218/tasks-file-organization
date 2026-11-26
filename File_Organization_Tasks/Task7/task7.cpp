#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    ifstream input("names.txt");
    string line;
    vector<string> data;
    while (getline(input, line))
        data.push_back(line);
    input.close();

    sort(data.begin(), data.end());

    for (int i = 0; i < data.size(); i++)
        cout << data[i] << endl;

        system("pause");
    return 0;
}