#include <cstring> 
#include <cstdlib> 
#include <iostream>
using namespace std;

char str[100];  
int j=0,temp=0;  
void E();           //E->TE';  
void X();           //E'->+TE' | e  
void T();           //T->FT'  
void Y();           //T'->*FT' | e  
void F();           //F->(E) | i  
int main()  
{  
    int len;  
    cout <<"请输入算数表达式：";  
    cin>>str;  
    len=strlen(str);  
    str[len]='#';  
    str[len+1]='\0';  
    E();
    if(str[j]=='#')
    {
        if(temp==0)
            cout <<"输入的语法是正确的！"<<endl;
        else
            cout <<"输入的语法是错误的！" <<endl;
    }  
 
}  
void E()  
{  
	cout <<"E--->TE'    " <<endl;
    T();  
    X();  
}  
void X()  
{  
    if(str[j]=='+')  
    {  
    	cout<<"E'--->+TE'       匹配+" <<endl;
        j++; 
        if(str[j]!='i' && str[j]!='(')
        {
            cout<<"缺少运算量'i'或者'('"<<endl;
            temp=1;
            j++;
        }
        T();  
        X();  
    }
	else
		cout<<"E'--->ε       " <<endl;   
}  
void T()  
{  
	cout<<"T--->FT'    " <<endl;
    F();  
    Y();  
}  
void Y()  
{  
    if(str[j]=='*')  
    {  
    	cout<<"T--->*FT'        匹配*" <<endl;
        j++; 
        if(str[j]!='i' && str[j]!='(')
        {
            cout<<"缺少运算量'i'或者'('"<<endl;
            temp=1;
            j++;
        }
        F();  
        Y();  
    } else
		cout<<"T'--->ε       " <<endl; 
}  
void F()  
{  
    if(str[j]=='i')  
    {  
    	cout<<"F--->i           匹配i" <<endl;
        j++;
        if(str[j]!='+' and str[j]!='*' and str[j]!=')' and str[j]!='#')
        {
            cout<<"缺少运算符'+'或'*'或')'"<<endl;
            temp=1;
            if(str[j]=='(' ||str[j]=='i')
                F();
        }  
    }  
    else if (str[j]=='(')  
    {   
		cout<<"F--->(E)         匹配(" <<endl;   
        j++;  
        E();
		while(str[j]!=')'){
			cout<<"没有匹配到')'"<<endl;
            temp=1;
			break;
		}  
        if(str[j]==')')  
        {  
			cout<<"F--->(E)         匹配)" <<endl;   
            j++;   
        }
    }   
    else{  
        cout<<"没有找到'i'或者'('"<<endl;
        temp=1;   
        j++;  
    }  
 }  
