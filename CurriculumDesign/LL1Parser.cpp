#include "LL1Parser.h"

Parser::Parser()
{
    content=new string[255];
    first=new string[255];
    follow=new string[255];
    table=new string *[255];
}
 
Parser::Parser(const Parser& rs)
{
     ter=rs.ter;
     non=rs.non;
     end=rs.end;
     num=rs.num;
     content=new string[255];
     first=new string[255];
     follow=new string[255];
     table=new string *[255];
     for(int i=0;i<=num;i++)
        content[i]=rs.content[i];
     FirstAndFollow();
     CreateTable();
}
 
ostream& operator<<(ostream& output,const Parser& rs)
{
	output<<"文法内容(共"<<rs.num<<"条):"<<endl;
	int i=0;
	while(i<rs.num)
	{
		output<<rs.content[i++]<<endl;
	}
	output<<"结 终 符:"<<rs.ter<<endl;
	output<<"非结终符:"<<rs.non<<endl;
	cout<<"非终结符的FIRST集合 "<<endl;
	for(unsigned int j=0;j<rs.non.size();j++)
		cout<<"FIRST("<<rs.non[j]<<") = {"<<rs.first[j]<<"}\t"<<endl;
	cout<<"非终结符的FOLLOW集合 "<<endl;
	for(unsigned int j=0;j<rs.non.size();j++)
		cout<<"FOLLOW("<<rs.non[j]<<") = {"<<rs.follow[j]<<"}\t"<<endl;
	output<<"预测分析表:"<<endl<<"\t";
	for(unsigned int j=0;j<rs.ter.size();j++)
		output<<rs.ter[j]<<"\t";
	output<<"$"<<endl;
	for(unsigned int j=0;j<rs.non.size();j++)
	{
		output<<rs.non[j]<<"\t";
		for(unsigned int k=0;k<=rs.ter.size();k++)
			cout<<rs.table[j][k]<<"\t";
		output<<endl;
	}
	return output;
}
istream& operator>>(istream& input,Parser& rs)
{
	unsigned int j=0;
	char filename[255];
	cout<<"请输入文件名:";
	input>>filename;
	ifstream infile(filename,ios::in);
	if(!infile){
		cout<<"无法打开文件！"<<endl;
		exit(0);
	}
	while(1)
	{   
		unsigned int i=0;
		infile>>rs.end;   
		rs.content[j++]=rs.end;
		if(infile.eof()) break;
		while(i<rs.end.size())
		{
			if(rs.end[i]=='|'||rs.end[i]=='^');
			else if(i==1||i==2) i++;
			else if(rs.end[i]>='A'&&rs.end[i]<='Z'){
				if(std::string::npos==rs.non.find(rs.end[i])) rs.non.append(1,rs.end[i]);
			}
			else if(std::string::npos==rs.ter.find(rs.end[i])) rs.ter.append(1,rs.end[i]);
			i++;
		}
	}
	rs.num=j-1;
	if(rs.Check()==0)
	{
		exit(0);
	}
	rs.FirstAndFollow();
	rs.CreateTable();
	return input;
} 
 
int Parser::Findid(char a)
{
    int i=0;
    while(i<num)
    {
        if(content[i][0]==a) return i;
        i++;
    }
    return -1;
}
 
char Parser::RandChar()
{
    switch(rand()%3)
    {
    case 0:return 'A';
    case 1:return 'B';
    case 2:return 'C';
    case 3:return 'D';
    }
    return 'D';
}
 
int Parser::Check()
{
    unsigned int j=0;
    int i=0;
    while(i<num)
    {
        if(content[i].size()<=3)
        {
            cout<<"文法句"<<content[i]<<"长度不对!"<<endl;
            return 0;
        }
        if(content[i][1]!='-'||content[i][2]!='>')   
        {
            cout<<"文法句"<<content[i]<<"未来使用推导符\"->\"!"<<endl;
            return 0;
        }
        int n=StrNum(content[i]);
        int s=0;
        char z=content[i][0];
        int m=0;
        for(int k=1;k<=n;k++)
        {
            string tmp=GetSub(k,content[i],'|');
            if(z==tmp[0])
            {
                s=1;
                m++;
            }
        }
        if(m==n)
        {
            cout<<"文法句"<<content[i]<<"将形成无穷推导！"<<endl;
            return 0;
        }
        if(s==1)
            DelLeft(i); 
        i++;
    }
    return 1;
}
  
Parser& Parser::DelLeft(int i)
{
    int n=StrNum(content[i]);
    char c=RandChar();
    char z=content[i][0];
    int s=0;
    for(int k=1;k<=n;k++)
        {
            string tmp=GetSub(k,content[i],'|');
            if(z==tmp[0])   s=1;
        }
    if(s==0) return *this;
    cout<<"文法句"<<content[i]<<"含有直接左递归,";
    while(1)
    {
        if(Findchar(c,non)==-1) break;
        else c=RandChar();
    }
    cout<<"随机产生非终结符为:"<<c<<endl;
    non.append(1,c);
    string temp;
    temp+=z;
    temp+="->";
    string next;
    next+=c;
    next+="->";
    for(int k=1;k<=n;k++)
    {
        string t=GetSub(k,content[i],'|');
        if(z==t[0]) 
        {
            t.erase(0,1);
            t+=c;
            next+=t;
            next+='|';
        }
        else
        {
            if(t=="^")  t.clear();
            t+=c;
            temp+=t;
            temp+='|';
        }
    }
    next+='^';
    temp.erase(temp.size()-1,1);
    content[i]=temp;
    num=num+1;
    content[num]=end;
    for(int j=num-1;j>i;j--)
        content[j]=content[j-1];
    content[i+1]=next;
    return *this;
}
 
string Parser::Checkstr(string & a)
{
    unsigned int i=0,j=0;
    for(;i<a.size();i++){
        for(j=i+1;j<a.size();j++){
            if(a[i]==a[j]){ 
                a.erase(j,1);
            }
        }
    }
    return a;
}
 
string Parser::Delchar(char x,string a)
{
    int j,i=int(a.size());
    for(j=0;j<i;j++)
        if(a[j]==x)
            a.erase(j,1);
    return a;
}
 
int Parser::Findchar(char x,string a)
{
    unsigned int i=0;
    while(i<a.size())
    {
        if(a[i]==x) return i;   
        i++;
    }
    return -1;
}
 
string Parser::GetSub(int i,const string& a,char c='|')
{
    string ch;
    int j[255];
    int n=1;
    j[0]=2;
    if(i>=int(a.size())) return ch;
    for(unsigned int k=3;k<a.size();k++)
        if(a[k]==c) j[n++]=k;
    for(unsigned int k=j[i-1]+1;k<a.size();k++)
    {
        if(a[k]==c) break;
        else if(std::string::npos==ch.find(a[k])) ch.append(1,a[k]);
    }
    return ch;
}
 
int Parser::StrNum(const string& a)
{
    int n=0;
    for(unsigned int i=3;i<a.size();i++)
        if(a[i]=='|') n++;
    return n+1;
}
 
string Parser::First(char x)
{
    string ch="";
    if(Findchar(x,ter)!=-1)   
    {   ch.append(1,x);
        ch.append(1,' ');
    }
    else if(Findchar(x,non)!=-1)
    {
        int i=Findid(x);
        if(i!=-1)
        {
            string q=content[i];
            unsigned int k=3;
            while(k<q.size())
            {
                if(q[k-1]=='|'||k==3)
                {
                    if(Findchar(q[k],ter)!=-1||q[k]=='^') 
                    {
                        ch.append(1,q[k]);  
                        ch.append(1,' ');
                    }         
                    else 
                    {
                        if(k==3||q[k+1]=='|'||k==q.size()-1)    ch+=First(q[k]);
                        else
                        {
                            string temp=First(q[k-1]);
                            if(Findchar('^',temp)!=-1) ch+=First(q[k]);
                        }
                    }
                    k++;
                }               
                else k++;
            }
        }
    }
    return ch;
}
 
string Parser::First(const string& a)
{
    return First(a[0]);
}
 
string Parser::Follow(char x)
{
    string ch;
    if(Findchar(x,non)!=-1)
    {
        if(!Findid(x))
        {
            ch+="$";
            ch+=' ';
        }
        int i=0;
        while(i<num)
        {
            string q=content[i];
            unsigned int k=3;
            char c=content[i][0];           
            while(k<q.size())
            {
                while(q[k]==x)
                {
                    if(k<q.size()-1&&q[k+1]!='|')
                    {
                        string temp=Delchar('^',First(q[k+1]));
                        if(ch.find(temp)==string::npos) ch+=temp;
                        if(Findchar('^',First(q[k+1]))!=-1)
                        {   
                            string follow_c =  Follow(c);
                            if(ch!=follow_c&&ch.find(follow_c)==std::string::npos)  
                                ch+=follow_c;
                        }
                    }
                    else if(k==q.size()-1)
                    {   
                        string follow_c =  Follow(c);
                        if(ch.find(follow_c)==std::string::npos) ch+=follow_c;
                    }       
                    k++;
                }
                k++;
            }
            i++;
        }
    }
    return ch;
}
 
Parser& Parser::FirstAndFollow()
{
    unsigned int i=0;
    while(i<non.size())
    {
        first[i]=First(non[i]);
        follow[i]=Follow(non[i]);
        i++;
    }
    return *this;
}
 
Parser& Parser::CreateTable()
{
    for(unsigned int i=0;i<=non.size();i++)
        table[i]=new string[255];
    for(unsigned int i=0;i<non.size();i++)
        {
            string temp=content[i];
            int w=Findchar(temp[0],this->non);
            int n=StrNum(temp);
            for(int k=1;k<=n;k++)
            {
                string tmp=GetSub(k,temp);
                string fir=First(tmp);
                for(unsigned int j=0;j<fir.size();j++)
                {
                    int idz=Findchar(fir[j],ter);
                    if(idz!=-1) 
                        table[w][idz]=tmp;
                }             
                if(Findchar('^',fir)!=-1||tmp[0]=='^') 
                {                   
                    string fol=Follow(temp[0]);
                    for(unsigned int j=0;j<fol.size();j++)
                    {
                        int z=Findchar(fol[j],ter);
                        if(z==-1) z=int(ter.size());
                        table[w][z]=tmp;
                    }   
                }
            }
        }
    return *this;
}
 
Parser::~Parser()
{
    delete[] content;
    delete[] first;
    delete[] follow;
    delete[] table;
}
  
char Parser::Pop()
{
    char x=stack[stack.size()-1];
    stack.erase(stack.size()-1,1);
    return x;
}
 
int Parser::Mate(char x,char ip)
{
    if(Findchar(x,ter)!=-1)
    {
        if(x==ip)
        {
            Pop(); 
            instack.erase(0,1);
            return 1;
        }
        else return 0;
    }
    return 0;
}
 
char Parser::Top()
{
    return stack[stack.size()-1];
}
 
char Parser::Ip()
{
    return instack[0];
}
 
Parser& Parser::Push(const string& rs)
{
    if(rs.empty()) return *this;
    string temp=rs;
    temp.replace(temp.begin(),temp.end(),temp.rbegin(),temp.rend());
    stack.append(temp);
    return *this;
}
 
int Parser::Analysis()
{
    stack.append("$");
	char chose;
	cout<<"是否输入分析串(y or n):";
	cin>>chose;
	while(chose=='y')
	{
		stack+=non[0];
		cout<<"请输入分析串<退出(q)>：";
		cin>>instack;
		if (instack=="q") exit(0);
		if(instack[instack.size()-1]!='$') instack+="$";
		int k=1,flag=0; 
		char x=Top();
		char c=Ip();
		cout<<"分析栈\t当前输入\t动作"<<endl;
		while(x!='$')
		{
			x=Top();
			c=Ip();
			cout<<stack<<"\t"<<instack<<"\t\t";
			if(Findchar(x,ter)!=-1)
			{
				if(Mate(x,c))
				{ 
					k++;
					cout<<"匹配"<<c<<endl;
				}
				else
				{
					cout<<"["<<k<<"]出错(终结符不匹配)！"<<endl;
					flag=1;
					if(x==')') Pop();
					else instack.erase(0,1);
                    k++;
				}
			}
			else if(Findchar(x,non)!=-1)
			{
				int idf=Findchar(x,non);
				int idz=Findchar(c,ter);
				if(idz==-1) idz=int(ter.size());
				string temp=table[idf][idz];
				if(temp.empty()) 
				{
					cout<<"["<<k<<"]出错（"<<c<<"不属于FIRST("<<x<<")）！"<<endl;
					flag=1;
					instack.erase(0,1);
                    k++;
				}
				else
				{
					Pop();
					if(temp!="^")   
					{
						Push(temp);
						cout<<x<<"->"<<temp<<endl;
					}
					else cout<<x<<"->"<<temp<<endl;

				}
				
			}
			else if(x=='$'&&c=='$')
			{
				if(flag==0) cout<<"正确"<<endl;
				else cout<<"错误"<<endl;
			}
			else
			{
				cout<<"["<<k<<"]出错(未能识别的字符)！"<<endl;
				flag=1;
				instack.erase(0,1);
                k++;
			}
		}
	}
}
 
int main()
{
    Parser LL1;
    cin>>LL1;
    cout<<LL1;
    LL1.Analysis();
    return 0;
}
