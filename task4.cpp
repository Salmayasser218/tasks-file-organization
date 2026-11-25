#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Person
{
    string name;
    int age;
};

int main()
{
    int n;
    cout << "How many persons do you want to add? ";
    cin >> n;
    cin.ignore();

    ofstream out("persons.txt");
    if (!out.is_open())
    {
        cout << "Error opening the file";
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        Person p;
        cout << "Enter name of person " << i + 1 << ": ";
        getline(cin, p.name);
        cout << "Enter age: ";
        cin >> p.age;
        cin.ignore();
        out << p.name << endl;
        out << p.age << endl;
    }
    out.close();

    ifstream in("persons.txt");
    if (!in.is_open())
    {
        cout << "Error opening the file";
        return 1;
    }
    vector<Person> people;
    Person p;
    while (getline(in, p.name))
    {
        in >> p.age;
        in.ignore();
        people.push_back(p);
    }
    in.close();

    if (people.empty())
    {
        cout << "No data found";
        return 1;
    }

    int youngest = 0, oldest = 0;
    for (int i = 1; i < people.size(); i++)
    {
        if (people[i].age < people[youngest].age)
            youngest = i;
        if (people[i].age > people[oldest].age)
            oldest = i;
    }

    ofstream result("results.txt");
    result << "Youngest: " << people[youngest].name << ", " << people[youngest].age << endl;
    result << "Oldest: " << people[oldest].name << ", " << people[oldest].age << endl;
    result.close();

    cout << "Results saved to results.txt" << endl;

    cin.get();
    return 0;
}