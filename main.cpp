#include <iostream>
#include <fstream>
map<string, int> books;
int total = 0;
void putOut(string x)
{
    cout << x << endl;
    int pos = x.rfind(" ");
    string temp = x.substr(pos + 1, x.size() - pos - 1);
    total = total + 1 -  min(books[temp], 1);
    books[temp]++;
}

void printOutAnswers()
{
    total = 0;
    ifstream fin("answers.txt");
    string s;
    vector<string> names;
    names.clear();
    while(fin >> s)
    {
        names.push_back(s);
    }
    sort(names.begin(), names.end());
    for(auto x : names)
    {
        putOut(x);
    }

    cout << "Amount of people who passed the survey - " << names.size() << endl;
    cout << "Amount of books present - " << total;
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
