#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
<<<<<<< HEAD
=======
#include <fstream>
#include <iostream>

using namespace std;

void editQuesions(){
    ofstream q("questions.txt");
    string line;
    q.clear();
    while(getline(cin, line)){
        if(line != "")
            q << line << endl;
    }
    ofstream ans("answers.txt");
    ans.clear();
    q.close();
    ans.close();
}

int total = 0;
map<string, int> books;
void putOut(string x)
{
    cout << x << "XX" << endl;
    string space_delimiter = " ";
    vector<string> words{};

    size_t pos = 0;
    while ((pos = x.find(space_delimiter)) != string::npos) {
        words.push_back(x.substr(0, pos));
        x.erase(0, pos + space_delimiter.length());
    }
    string temp = words[words.size() - 1];
    cout << temp << endl;
    cout << books[temp] << endl;
    total = total + 1 - min(books[temp], 1);
    cout << total << endl;
    books[temp]++;
}


void printOutAnswers(int numberOfField) {
    ifstream fin("answers.txt");
    string s;
    vector <string> names;
    names.clear();
    if (numberOfField == 1) {
        while (getline(fin, s)) {
            {
                names.push_back(s);
            }
            sort(names.begin(), names.end());
        }
    }

    if (numberOfField == 2) {
        while (fin >> s)
        {
            int pos = s.find(" ");
            string temp = s.substr(pos, s.rfind(" "));
            names.push_back(s);
        }
        sort(names.begin(), names.end());
    }

    if (numberOfField == 3) {
        while (fin >> s)
        {
            int pos = s.rfind(" ");
            string temp = s.substr(pos, s.size() - pos);
            names.push_back(s);
        }
        sort(names.begin(), names.end());
    }

    books.clear();

    for(auto x : names)
    {
        putOut(x);
    }
    cout << total << endl;
    cout << "Amount of people who passed the survey - " << names.size() << endl;
    cout << "Amount of books present - " << total;
    total = 0;
    fin.close();
}

void checkQuestions()
{
    ifstream fin("questions.txt");
    ofstream fout("answers.txt", std::ios_base::app);
    string s;
    string answer;
    while(getline(fin, s))
    {
        cout << s << endl;
        cin >> answer;
        fout << answer << endl;
    }
    fout << endl;
    fin.close();
    fout.close();
}

signed main()
{
    string s;
    cout << "If you want to complete the survey, print out 'SURVEY' " << endl;
    cout << "If you want to know the results of the survey, print out 'RESULTS'" << endl;
    cin >> s;
    if (s == "SURVEY") checkQuestions();
    if (s == "RESULTS") printOutAnswers(1);
    if(s == "EDIT"){
        cout << "Enter questions line by line. If u want to stop just press Ctrl + Z." << endl;
        editQuesions();
    }
}
