# HELLO WORLD

Everybody hello, welcome to this test commit.

## Updates

// Added function to edit questions(LeftTry)

```cpp
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
```

// Added a function to append to the end of file

```cpp
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
```

// Fixed a function that was responsible for checking the amount of books present in our answers

``cpp 
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
```

