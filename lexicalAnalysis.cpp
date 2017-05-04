#include <stdio.h>
#include "string.h"

int main(int argc,char *argv[])
{
	int i=0,j;
	int k1=0,k2=0;
    char table[13][13]={"var","if","then","else","while","for","begin","writeln","procedure","end","do","call","const"};
    char c;
	char t[20]={"\0"};			
    freopen(argv[1],"r",stdin);
    c=getchar();
    while(c!=EOF){
        if(c==' '||c=='\n'||c=='\t'){
            c=getchar();
        }
        else if((c>='a'&&c<='z')||(c>='A'&&c<='Z')){
			t[i++]=c;
            c=getchar();
            while((c>='a'&&c<='z')||(c>='A'&&c<='Z')||(c>='0'&&c<='9')){ 
                t[i++]=c;
                c=getchar();
            }
			if(!(c>='0'&&c<='9')&&!(c>='a'&&c<='z')&&!(c>='A'&&c<='Z')){
				for(j=0;j<13;j++){
					if(strcmp(t,table[j])==0){
						printf("%d -| %s \n",j+21,t);
						k1=1;	
						break;
					}
			}
			if(k1==0)
				printf("1  -| %s \n",t);
			if(c==';')
				printf("17 -| ; \n");
			if(c==',')
				printf("18 -| , \n");
			if(c=='.'||c=='$'||c=='#'||c=='"'||c=='!'||c=='@'||c=='|'||c=='?'||c=='$'||c=='%'||c=='^'||c=='&')
				printf("100-| error\n");
			c=getchar();
			}
			else
				printf("100-| error\n");
			for(j=0;j<=i;j++)
				t[j]='\0';
			k1=0;
			i=0;
		}
        else if((c>='0'&&c<='9')){
			t[i++]=c;
			c=getchar();
			while((c>='0'&&c<='9')||c=='.'){ 
				t[i++]=c;
				c = getchar();
			}
			if(c==' '||c=='\n'||c=='\t'||c==';'){
				printf("2  -| %s \n",t);
			}
			else if(c==';')
				printf("17 -| ; \n");
			for(j=0;j<=i;j++)
				t[j]='\0';
			i=0;
		}
		else if(c=='>'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("8  -| > \n");
			}
			else if(c=='='){
				c=getchar();
				if(c==' '||c=='\n'||c=='\t')
					printf("12 -| >= \n");
				else
					printf("100-| error\n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='<'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("9  -| < \n");
			}
			else if(c=='>'||c=='='){
				if(c=='=')
					k2=1;
				c=getchar();
				if(c==' '||c=='\n'||c=='\t'){
					if(k1==0)
						printf("10 -| <> \n");
					else
						printf("11 -| <= \n");
				}
				else
					printf("100-| error\n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='+'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("3  -| + \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='-'){
			t[i++]=c;
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("4  -| - \n");
				i=0;
			}
        else if((c>='0'&&c<='9')||c=='-'){
			t[i++]=c;
			c=getchar();
			while((c>='0'&&c<='9')||c=='.'){ 
				t[i++]=c;
				c = getchar();
			}
			if(c==' '||c=='\n'||c=='\t'||c==';'){
				printf("2  -| %s \n",t);
			}
			else if(c==';')
				printf("17 -| ; \n");
			for(j=0;j<=i;j++)
				t[j]='\0';
			i=0;
		}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='*'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("5  -| * \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='/'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("6  -| / \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='='){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("7  -| = \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='('){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("13 -| ( \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c==')'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("14 -| ) \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='{'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("15 -| { \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c=='}'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("16 -| } \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c==';'){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("17 -| ; \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c==','){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("18 -| , \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c==' '){
			c=getchar();
			if(c==' '||c=='\n'||c=='\t'){
				printf("19 -|   \n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else if(c==':'){
			c=getchar();
			if(c=='='){
				c=getchar();
				if(c==' '||c=='\n'||c=='\t')
					printf("20 -| := \n");
				else
					printf("100-| error\n");
			}
			else{ 
				printf("100-| error\n");
			}
		}
		else{
			printf("100-| error\n");
			c=getchar();
		}
	}
	fclose(stdin);
}

