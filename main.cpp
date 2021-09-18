#include <iostream>
#include <fstream>

void putOut(string x)
{
    cout << x << endl;
}

void printOutAnswers()
{
    ifstream fin("answers.txt");
    string s;
    vector<string> names;
    while(fin >> s)
    {
        names.push_back(s);
    }
    sort(names.begin(), names.end());
    for(auto x : names)
    {
        putOut(x);
    }
    fin.close();
}

void checkQuestions()
{
    ifstream fin("questions.txt");
    ofstream fout("answers.txt");
    string s;
    string answer;
    for(int i = 0; i < 3; ++i)
    {
        fin >> s;
        cout << s << endl;
        cin >> answer;
        fout << answer << " ";
    }
    fout << endl;
    fin.close();
    fout.close();
}

signed main()
{
    string s;
    cin >> s;
    if(s == "OPROS") checkQuestions();
    else printOutAnswers();
}
