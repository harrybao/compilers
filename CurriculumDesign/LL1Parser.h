#include <iostream>
#include <cstring>
#include <cstdlib>
#include <fstream>
using namespace std;
 
class Parser
{
public:
    Parser();
    Parser(const Parser&);
    friend ostream& operator<<(ostream& output,const Parser& rs);
    friend istream& operator>>(istream& input,Parser& rs);
    int Findid(char);
    int Check();
    string Checkstr(string&);
    string Delchar(char,string);
    int Findchar(char,string);
    int StrNum(const string&);
    char RandChar();
    string GetSub(int,const string&,char);
    Parser& DelLeft(int);
    string First(char);
    string First(const string&);
    string Follow(char);
    Parser& FirstAndFollow();
    Parser& CreateTable();
    ~Parser();
    char Pop();
    int Mate(char,char);
    char Top();
    char Ip();
    Parser& Push(const string&);
    int Analysis();
private:
    int num;
    string ter,non,end,stack,instack;
    string *content;
    string *first;
    string *follow;
    string **table;
};
