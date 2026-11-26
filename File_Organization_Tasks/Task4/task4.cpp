#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Person {
    string name;
    int age;
};

int main() {
    int n;
    string name;
    int age;
    cout << "How many persons? ";
    cin >> n;

    ofstream out("persons.txt");
    out << n << endl;
    for (int i = 0; i < n; i++) {
        cout << "Enter name and age: ";
        cin >> name >> age;
        out << name << " " << age << endl;
    }
    out.close();

    ifstream in("persons.txt");
    in >> n;
    vector<Person> v(n);
    for (int i = 0; i < n; i++)
        in >> v[i].name >> v[i].age;
    in.close();

    int y = 0, o = 0;
    for (int i = 1; i < v.size(); i++) {
        if (v[i].age < v[y].age) y = i;
        if (v[i].age > v[o].age) o = i;
    }

    ofstream res("results.txt");
    res << "Younger: " << v[y].name << " " << v[y].age << endl;
    res << "Older: " << v[o].name << " " << v[o].age;
    res.close();
    return 0;
}