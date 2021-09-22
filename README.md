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
