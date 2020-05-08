#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

//****************FUNCTION DECLARATIONS****************
void removeDuplicates(vector<char>* l);
void fetchWords(char c, vector<string>* dict);
void checkWords(char c, vector<string>* dict, vector<string>* words, const vector<char> letters);
bool canRemove(char c, vector<char>* l);
void computeScore(const vector<string> w, vector<int>* s);

//*************************MAIN************************
int main() {
    //**************VARIABLE DECLARATION***************
    bool refine;            //Toggle refine by ending ON/OFF
    bool invalid;           //Invalid input switch
    string str;             //Temp string for holding input
    string end;             //String to hold ending letter combinations
    vector<char> letters;   //Letters that the user inputed
    vector<char> RDletters; //User entered letters w/o duplicate
    vector<int> score;      //Score for each make-able word
    vector<string> words;   //Vector of all make-able words
    vector<string> dict;    //Used to store dictionary words

    //**********************GREET**********************
    cout << "Hello & Welcome to Scrabble Buddy!" << endl
        << "Simply enter your Scrabble letters and preferred ending letter(s)" << endl
        << "to recieve your BEST word plays!" << endl << endl
        << "NOTE: If you do NOT want to refine by ending letters, enter '-'" << endl << endl;

    //******************INFINITE LOOP******************
    while (true) {
        //Resetting Variables
        refine = true;
        invalid = false;
        str.clear();
        end.clear();
        letters.clear();
        RDletters.clear();
        score.clear();
        words.clear();
        dict.clear();
        //Getting user input
        cout << "Enter your letters: ";
        cin >> str;
        for (char c : str) {
            letters.push_back(c);
            RDletters.push_back(c);
        }
        cout << "Ending letters/'-': ";
        cin >> end;
        if (end[0] == '-')
            refine = false;

        if (refine)
            for (char c : end) {
                letters.push_back(c);
                RDletters.push_back(c);
            }

        //Check if all characters are valid ('a' to 'z')
        for (int i = 0; i < letters.size(); ++i) {
            if (letters[i] >= 'A' and letters[i] <= 'Z') {
                letters[i] = RDletters[i] = letters[i] + ('a' - 'A');
            }
            else if (letters[i] >= 'a' and letters[i] <= 'z') {
                //Do Nothing: The character is perfect
            }
            else {
                cout << "One of the letters you entered is INVALID." << endl
                    << "Try Again!" << endl << endl;
                invalid = true;
                break;
            }
        }
        if (invalid)
            continue;

        //Remove duplicates so we don't look up words starting
        //  from the same letter twice
        removeDuplicates(&RDletters);

        //*****All letters are okay and lower case*****
        //**************Start the engine***************
        for (char c : RDletters) {
            dict.clear();
            fetchWords(c, &dict);   //Fetch words starting from c
            checkWords(c, &dict, &words, letters); //Check & add make-able words
        }

        //Refine the words based on the ending letters.
        if (refine) {
            for (int i = 0; i < words.size(); ++i) {
                if (words[i].length() >= end.length()) {
                    string t = words[i].substr(words[i].size() - end.size(), end.size());
                    if (t.compare(end) != 0) {
                        words.erase(words.begin() + i);
                        --i;
                    }
                }
                else {
                    words.erase(words.begin() + i);
                    --i;
                }
            }
        }

        //Calculate the scores
        computeScore(words, &score);
        //Print out the words
        if (words.size() == 0) {
            cout << "No possible words :-[" << endl << endl;
            continue;
        }
        for (int i = 0; i < words.size(); ++i) {
            cout << setw(2) << i + 1 << ". " << setw(8) << words[i] << " " << score[i] << endl;
        }

        cout << endl;
    } //end while
} //end main

//*****************FUNCTION DEFINITIONS****************
void removeDuplicates(vector<char>* l) {
    for (int i = 0; i < l->size(); ++i) {
        for (int j = i + 1; j < l->size(); ++j) {
            if (l->at(j) == l->at(i)) {
                l->erase(l->begin() + j);
            }
        }
    }
}

void fetchWords(char c, vector<string>* dict) {
    ifstream inFile;
    switch (c) {
    case 'a': {
        //Load vector
        inFile.open("a.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'b': {
        //Load vector
        inFile.open("b.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'c': {
        //Load vector
        inFile.open("c.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'd': {
        //Load vector
        inFile.open("d.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
    }
    case 'e': {
        //Load vector
        inFile.open("e.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'f': {
        //Load vector
        inFile.open("f.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'g': {
        //Load vector
        inFile.open("g.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'h': {
        //Load vector
        inFile.open("h.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'i': {
        //Load vector
        inFile.open("i.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'j': {
        //Load vector
        inFile.open("j.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'k': {
        //Load vector
        inFile.open("k.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'l': {
        //Load vector
        inFile.open("l.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'm': {
        //Load vector
        inFile.open("m.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'n': {
        //Load vector
        inFile.open("n.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'o': {
        //Load vector
        inFile.open("o.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'p': {
        //Load vector
        inFile.open("p.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'q': {
        //Load vector
        inFile.open("q.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'r': {
        //Load vector
        inFile.open("r.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 's': {
        //Load vector
        inFile.open("s.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 't': {
        //Load vector
        inFile.open("t.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'u': {
        //Load vector
        inFile.open("u.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'v': {
        //Load vector
        inFile.open("v.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'w': {
        //Load vector
        inFile.open("w.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'x': {
        //Load vector
        inFile.open("x.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'y': {
        //Load vector
        inFile.open("y.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    case 'z': {
        //Load vector
        inFile.open("z.txt");
        string str;
        while (inFile >> str) {
            dict->push_back(str);
        }
        inFile.close();
        break;
    }
    }
}

void checkWords(char c, vector<string>* dict, vector<string>* words, const vector<char> letters) {
    //Try each word in dict and add to words it they work out
    for (int i = 0; i < dict->size(); ++i) {
        string w = dict->at(i);
        vector<char> l = letters;
        bool isWord = true;
        for (char c : w) {
            if (!canRemove(c, &l)) {
                isWord = false;
                break;
            }
        }
        if (isWord) {
            words->push_back(w);
        }
    }
}

bool canRemove(char c, vector<char>* l) {
    for (int i = 0; i < l->size(); ++i) {
        if (l->at(i) == c) {
            l->erase(l->begin() + i);
            return true;
        }
    }
    //Can't find the letter
    return false;
}

void computeScore(const vector<string> w, vector<int>* s) {
    for (int i = 0; i < w.size(); ++i) {
        string word = w[i];
        for (int j = 0; j < word.length(); ++j) {
            s->push_back(0);
            char c = word[j];
            if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u' or
                c == 'l' or c == 'n' or c == 's' or c == 't' or c == 'r') {
                s->at(i) += 1;
            }
            else if (c == 'd' or c == 'g') {
                s->at(i) += 2;
            }
            else if (c == 'b' or c == 'c' or c == 'm' or c == 'p') {
                s->at(i) += 3;
            }
            else if (c == 'f' or c == 'h' or c == 'v' or c == 'w' or c == 'y') {
                s->at(i) += 4;
            }
            else if (c == 'k') {
                s->at(i) += 5;
            }
            else if (c == 'j' or c == 'x') {
                s->at(i) += 8;
            }
            else if (c == 'q' or c == 'z') {
                s->at(i) += 10;
            }
        }
    }
}