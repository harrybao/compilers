#coding:utf-8

def E():
    print "\033[0mE -->  TE'"
    T()
    X()

def X():
    global k,temp
    if(str1[k]=='+'):
        print "\033[0mE' -->  +TE'   Mate to +"
        k+=1
        if(str1[k]!='i' and str1[k]!='('):
            print '\033[1;35m',k,"[ERROR]: Never find 'i' or '('!"
            temp=1
            k+=1
        T()
        X()
    else:
        print "\033[0mE' -->  ε"

def T():
    print "\033[0mT -->  FT'"
    F()
    Y()

def Y():
    global k,temp
    if(str1[k]=='*'):
        print "\033[0mT' -->  *FT'   Mate to *"
        k+=1
        if(str1[k]!='i' and str1[k]!='('):
            print '\033[1;35m',k,"[ERROR]: Never find 'i' or '('!"
            temp=1
            k+=1
        F()
        Y()
    else:
        print "\033[0mT' -->  ε"

def F():
    global k,temp
    if(str1[k]=='i'):
        print "\033[0mF -->  i       Mate to i"
        k+=1
        if(str1[k]!='+' and str1[k]!='*' and str1[k]!=')' and str1[k]!='$'):
            print '\033[1;35m',k,"[ERROR]: Never find '+' or '*'"
            temp=1
            if(str1[k]=='(' or str1[k]=='i'):
                F()
    elif(str1[k]=='('):
        print "\033[0mF -->  (E)"
        k+=1
        E()
        while(str1[k]!=')'):
            print '\033[1;35m',k,"[ERROR]: Never find ')'!"
            temp=1
            break 
        if(str1[k]==')'):
            k+=1
    else:
        print '\033[1;33m',k,"[ERROR]: Never find 'i' or '('!"
        temp=1
        k+=1
        if(str1[k]=='(' or str1[k]=='i'):
            F()

if __name__=='__main__':
    str1=input('please input string:')
    str1=str1+'$'
    k=0
    temp=0
    E()
    if(str1[k]=='$'):
        if(temp==0):
            print "\033[1;32m[TRUE]: This grammar is correct!"
        else:
            print "\033[1;31m[FLASE]: This grammar is worng!"
