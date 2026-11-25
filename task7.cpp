#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ofstream output("names.txt");
    output << "Hadeer Mahmoud" << endl;
    output << "Youssef Ali" << endl;
    output << "Ahmed Mostafa" << endl;
    output << "Esraa Ebrahim" << endl;
    output.close();

    ifstream input("names.txt");
    string line;
    vector<string> data;
    while (getline(input, line))
    {
        data.push_back(line);
    }
    input.close();

    sort(data.begin(), data.end());

    cout << "Names sorted Successfully" << endl;
    for (int i = 0; i < data.size(); i++)
    {
        cout << data[i] << endl;
    }

    cin.get();
    return 0;