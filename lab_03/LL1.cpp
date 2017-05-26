#include <cstring> 
#include <cstdlib> 
#include <iostream>
using namespace std;

char str[100];  
int j=0,temp=0;  
void E();            
void X();            
void T();           
void Y();           
void F();           
int main()  
{  
    int len;  
    cout <<"请输入算数表达式：";  
    cin>>str;  
    len=strlen(str);  
    str[len]='#';  
    str[len+1]='\0';  
    E(); 
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
            cout<<"never find 'i'or '('"<<endl;
            exit(0);
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
            cout<<"never find 'i'or '('"<<endl;
            exit(0);
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
            cout<<"Never find '+'or'*'or')'"<<endl;
            exit(0);
        }  
    }  
    else if (str[j]=='(')  
    {   
		cout<<"F--->(E)    " <<endl;   
        j++;  
        E();
		while(str[j]!=')'){
			cout<<"error:never find ')'"<<endl;
			break;
		}  
        if(str[j]==')')  
        {  
            j++;   
        }
    }   
    else{  
        cout<<"分析失败!"<<endl;
        exit(0);
    }  
 }  
