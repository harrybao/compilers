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
    Parser& operator =(const Parser&);
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
    Parser& DelSL();
    string First(char);
    string First(const string&);
    string Follow(char);
    Parser& FirstAndFollow();
    Parser& CreateTable();
    ~Parser();
    char Pop();
    int Next(char,char);
    char Top();
    char Ip();
    Parser& Push(const string&);
    int Display();
private:
    int number;
    string ter;
    string non;
    string *content;
    string end;
    string *first;
    string *follow;
    string **table;
    string stack;
    string instack;
};
