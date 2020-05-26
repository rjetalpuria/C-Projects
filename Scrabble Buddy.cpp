#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;
//******************GLOBAL VARIABLES*******************
const int letterPoints[] = { 1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10 };
//                           A B C D E F G H I J K L M N O P Q  R S T U V W X Y Z 


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
        for (unsigned int i = 0; i < letters.size(); ++i) {
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
            fetchWords(c, &dict);                  //Fetch words starting from c
            checkWords(c, &dict, &words, letters); //Check & add make-able words
        }

        //Refine the words based on the ending letters.
        if (refine) {
            for (unsigned int i = 0; i < words.size(); ++i) {
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
        for (unsigned int i = 0; i < words.size(); ++i) {
            cout << setw(2) << i + 1 << ". " << setw(8) << words[i] << " " << score[i] << endl;
        }

        cout << endl;
    } //end while
} //end main

//*****************FUNCTION DEFINITIONS****************
void removeDuplicates(vector<char>* l) {
    for (unsigned int i = 0; i < l->size(); ++i) {
        for (unsigned int j = i + 1; j < l->size(); ++j) {
            if (l->at(j) == l->at(i)) {
                l->erase(l->begin() + j);
            }
        }
    }
}

void fetchWords(char c, vector<string>* dict) {
    ifstream inFile;
    string fileName;
    fileName.push_back(c);
    fileName.append(".txt");
    inFile.open(fileName);
    string temp;
    while (inFile >> temp) {
        dict->push_back(temp);
    }
    inFile.close();
}

void checkWords(char c, vector<string>* dict, vector<string>* words, const vector<char> letters) {
    //Try each word in dict and add to words it they work out
    for (unsigned int i = 0; i < dict->size(); ++i) {
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
    for (unsigned int i = 0; i < l->size(); ++i) {
        if (l->at(i) == c) {
            l->erase(l->begin() + i);
            return true;
        }
    }
    //Can't find the letter
    return false;
}

void computeScore(const vector<string> w, vector<int>* s) {
    for (unsigned int i = 0; i < w.size(); ++i) {
        string word = w[i];
        int sum = 0;
        for (unsigned int j = 0; j < word.length(); ++j) {
            sum += letterPoints[word[j] - 'a'];
        }
        s->push_back(sum);
    }
}