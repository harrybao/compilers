#include <cstring> 
#include <cstdlib> 
#include <iostream>
using namespace std;

char str[10];  
int j=0;  
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
    cout <<"正确语句！"<<endl;  
    strcpy(str,"");  
    j=0;   
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
    	cout<<"E'--->+TE'   " <<endl;
    	cout<<"    匹配+"<<endl;
        j++;  
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
    	cout<<"T--->*FT'    " <<endl;
    	cout<<"    匹配*"<<endl;
        j++;  
        F();  
        Y();  
    } else
		cout<<"T'--->ε       " <<endl; 
}  
void F()  
{  
    if(str[j]=='i')  
    {  
    	cout<<"F--->i       " <<endl;
    	cout<<"    匹配i"<<endl;
        j++;  
    }  
    else if (str[j]=='(')  
    {   
		cout<<"F--->(E)    " <<endl;   
        j++;  
        E();
		while(str[j]!=')'){
			cout<<"error:never find ')'"<<endl;
			exit(0);
		}  
        if(str[j]==')')  
        {  
            j++;   
        }else{  
            cout<<"\n分析失败!"<<endl;  
            exit (0);  
        }  
    }   
    else{  
        cout<<"分析失败!"<<endl;   
        exit(0);  
    }  
 }  
