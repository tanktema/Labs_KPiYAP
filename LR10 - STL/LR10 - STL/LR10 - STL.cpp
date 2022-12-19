#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

int main()
{
    system("chcp 1251");
    ifstream paramfile("Params.txt");
    ofstream paramoutput("FileParams.txt");
    vector<string> param_lines;
    string strtmp;
    char check = ' ';
    int strctr = 0, checkctr = 0;
    while (!paramfile.eof())
    {
        getline(paramfile, strtmp);
        param_lines.push_back(strtmp);
    }
    for (int i = 0; i < param_lines.size(); i++)
    {
        //rewind(stdin);
        strtmp = param_lines[i];
        for (int j = 0; j < strtmp.size(); j++)
        {
            check = strtmp[j];
            if (check == '=')
            {
                checkctr = j;
            }
        }
        char* newstring = new char[checkctr];
        char* paramstring = new char[strtmp.size() - checkctr];
        for (int j = checkctr + 1; j < strtmp.size(); j++)
        {
            paramstring[strtmp.size() - j] = strtmp[j];
            cout << paramstring[strtmp.size() - j];
            paramoutput << paramstring[strtmp.size() - j];
        }
        for (int j = 0; j < checkctr; j++)
        {
            newstring[j] = strtmp[j];
            cout << newstring[j];
            paramoutput << newstring[j];
        }
        cout << endl;
        paramoutput << endl;
       
        //cout << paramstring << newstring << endl;
        
    }
}
