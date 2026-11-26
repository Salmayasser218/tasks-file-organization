#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    string line;
    ifstream in("fruit.txt");
    while (getline(in, line))
        cout << line << endl;
    in.close();

    ofstream out("fruit.txt", ios::app);
    out << "\nFresh Fruits";
    out.close();

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}