#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main()
{
    ifstream in("fruit.txt");
    if (in.fail())
    {
        cout << "Unable to open the file";
        return 1;
    }

    string fruit;
    cout << "Fruits in file:" << endl;
    while (getline(in, fruit))
    {
        cout << fruit << endl;
    }
    in.close();

    ofstream out("fruit.txt", ios::app);
    out << "Fresh Fruits" << endl;
    out.close();

    cout << "Message added to the file" << endl;

    cin.get();
    return 0;
}