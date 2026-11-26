#include <iostream>
#include <fstream>
using namespace std;

int main() {
    int x, del;
    ofstream out("grades.txt");
    for (int i = 0; i < 5; i++) {
        cout << "Enter grade " << i + 1 << ": ";
        cin >> x;
        out << x << endl;
    }
    out.close();

    ifstream in("grades.txt");
    if (in.fail()) {
        cout << "Unable to open the file";
        return 0;
    }
    while (in >> x)
        cout << x << endl;
    in.close();

    cout << "Enter grade to delete: ";
    cin >> del;

    in.open("grades.txt");
    ofstream temp("temp.txt");
    while (in >> x)
        if (x != del)
            temp << x << endl;
    in.close();
    temp.close();

    remove("grades.txt");
    rename("temp.txt", "grades.txt");
    cout << "Deleted successfully";
    return 0;
}