#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

struct Country
{
    string name;
    string capital;
    double area;
    double gdp;
};

void process_data()
{
    ifstream file("countries.csv");

    if (!file.is_open())
    {
        cout << "ERROR!" << endl;
        return;
    }

    string line;
    int count = 0;

    while (getline(file, line))
    {
        if (!line.empty())
        {
            count++;
        }
    }

    if (count == 0)
    {
        cout << "File is empty" << endl;
        file.close();
        return;
    }

    file.clear();
    file.seekg(0);

    Country *countries = new Country[count];
    int i = 0;

    while (getline(file, line) && i < count)
    {
        if (line.empty())
            continue;

        stringstream ss(line);
        ss >> countries[i].name >> countries[i].capital >> countries[i].area >> countries[i].gdp;
        i++;
    }
    file.close();

    double totalArea = 0;
    for (int j = 0; j < count; j++)
    {
        totalArea += countries[j].area;
    }
    cout << "Total area of all countries: " << totalArea << endl;

    int maxAreaIndex = 0;
    for (int j = 1; j < count; j++)
    {
        if (countries[j].area > countries[maxAreaIndex].area)
        {
            maxAreaIndex = j;
        }
    }
    cout << "Country with the largest area: " << countries[maxAreaIndex].name
         << " (" << countries[maxAreaIndex].area << ")" << endl;

    for (int j = 0; j < count - 1; j++)
    {
        for (int k = 0; k < count - j - 1; k++)
        {
            if (countries[k].gdp < countries[k + 1].gdp)
            {
                Country temp = countries[k];
                countries[k] = countries[k + 1];
                countries[k + 1] = temp;
            }
        }
    }

    cout << "\nCountries sorted by GDP" << endl;
    for (int j = 0; j < count; j++)
    {
        cout << countries[j].name << "\t" << countries[j].capital << "\t"
             << countries[j].area << "\t" << countries[j].gdp << endl;
    }

    ofstream outfile("sorted_countries.txt");
    if (outfile.is_open())
    {
        for (int j = 0; j < count; j++)
        {
            outfile << countries[j].name << "\t" << countries[j].capital << "\t"
                    << countries[j].area << "\t" << countries[j].gdp << endl;
        }

        outfile << "Country with the largest area: " << countries[maxAreaIndex].name << endl;

        outfile << "Total area of ​​all countries: " << totalArea << endl;

        outfile.close();
        cout << "\nSaved to sorted_countries.txt" << endl;
    }
    else
    {
        cout << "Failed to create a file for writing." << endl;
    }

    delete[] countries;
}

int main()
{
    process_data();
    return 0;
}