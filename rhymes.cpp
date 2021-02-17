#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <cstring> 
using namespace std;

string LastWord(string input);
string RemovePunct(string input);
void compare(string lastWord, string lastWord1);
int countLines(string filename);

int main() {
    string filename;
    string lastWord, lastWord1, input;

    lastWord = "";
    lastWord1 = "";
    int count =0;

    cout << "Enter filename: ";
    cin >> filename;
    
    ifstream iostream(filename.c_str());
    
    if(iostream.is_open()){

        while(!iostream.eof()){
            
            if(iostream.eof())
                break;

            lastWord1 = lastWord;
            getline(iostream, input);
            
            lastWord = LastWord(input);

            compare(lastWord, lastWord1);

            if (lastWord1.length() >1){
                
                if (lastWord.substr(lastWord.length() - 2). compare(lastWord1.substr(lastWord1.length()-2)) == 0){
                    count++;
                }
            }

            
        }
        if (count==0){
            cout << "No rhymes found." << endl;

        
        }

        else if(count==1){
            cout << "There is 1 pair of rhyming words."<< endl;
        
        }

        else{
            cout << "There are "<<count<<" pairs of rhyming words." << endl;
        }
    }
        else{
            cerr << "Input file opening failed.";
            exit(1);
        }

    int n(0);
    n = countLines(filename);
    double LineDensity;
    LineDensity = (double)count/(double)n;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    if (count == 0){
        cout << "There are " << n << " lines in this poem." << endl;
    }

    else {
    cout << "There are " << n << " lines in this poem, so the rhyme-line density is: " << LineDensity <<endl;
    }

        iostream.close();
        return 0;
    }
    

string LastWord(string line){

       line.erase(line.find_last_not_of(" \t\n\r\f\v") + 1); // removes whitespace characters at the end

       size_t lastWordIndex = line.find_last_of(' ');
       string lastWord = RemovePunct(line.substr(lastWordIndex+1));
       return lastWord;

}

string RemovePunct (string input){

    string input1 = "";
    for (size_t i =0; i< input.length(); i++){
        if(tolower(input.at(i))>='a' && tolower(input.at(i))<='z'){
            input1 = input1 + input.at(i);
        }
    }
    return input1;
}

void compare(string lastWord, string preLastWord){
    int n =0;
    if(preLastWord.length()>1){
        if(lastWord.substr(lastWord.length()-2).compare(preLastWord.substr(preLastWord.length()-2)) == 0){
            n++;
            cout<<preLastWord <<" and "<<lastWord<<endl;

        }
    }
}


int countLines(string filename){
   string s;
    int sTotal;

ifstream in;
in.open(filename);

while(!in.eof()) {
	getline(in, s);
	sTotal ++;	
}


in.close();	
return sTotal;
}

    