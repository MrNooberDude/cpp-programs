// theoretical element namer
#include <iostream>
#include <string>
#include <vector>
#include <locale>
using namespace std;

string atomicNumber;
string name = "";
string symbol = "";
//these are all the prefixes for each number according to the official guidelines (really)
//specific rules are applied later
const vector<string> nameTable = {
    "nil",
    "un",
    "bi",
    "tri",
    "quad",
    "pent",
    "hex",
    "sept",
    "oct",
    "enn"
};

//used for 1 thing
int stringToInt(string string)
{
    int output = 0;
    for (int i = 0; i<string.length(); ++i)
    {
        output += ((int)string[i]-48) * pow(10, string.length()-1-i);
        
        //cout << "<" << pow(10, string.length()-1-i) << ">" << endl;
        
        //cout << "<" << output << ">" << endl;
    }
    return output;
}

int main()
{
    cout << "Enter atomic number (no symbols or anything): ";
    getline(cin, atomicNumber);
    
    //might make it give you the normal element another time
    if (stringToInt(atomicNumber) < 119)
    {
        cout << "That element is not theoretical and has an official name. Try a different one above 118" << endl;
        return 1;
    }
    for (int i = 0; i<atomicNumber.length(); ++i)
    {
        //increased readability
        int digit = (int)atomicNumber[i]-48;
        int nextDigit = (int)atomicNumber[i+1]-48;
        
        //add the prefix and symbol for every digit
        symbol = symbol + nameTable[digit][0];
        name = name + nameTable[digit];
        
        //special rules for fixing up any improper english
        if (digit == 9 && nextDigit == 0)
            name.erase(name.length()-1);
        if ((digit == 2 || digit == 3) && i == atomicNumber.length()-1)
            name.erase(name.length()-1);
    }
    name = name + "ium";
    
    //capitalize first letter of name and symbol
    locale loc;
    name[0] = toupper(name[0], loc);
    symbol[0] = toupper(symbol[0], loc);
    
    //print result
    cout << name + " - " + symbol << endl;
    return 0;
}
