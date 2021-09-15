#include <iostream>
#include <fstream>
void printOutAnswers()
{
    ifstream fin("answers.txt");
    string s;
    for(int i = 0; i < 3; ++i)
    {
        fin >> s;
        cout << s << endl;
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
        fout << answer << endl;
    }
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
