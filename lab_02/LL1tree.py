#coding:utf-8

def E():
    print "\033[0mE -->  TE'"
    T()
    X()

def X():
    global k,temp
    if(a[k]=='+'):
        print "\033[0mE' -->  +TE'   Mate to +"
        k+=1
        if(a[k]!='i' and a[k]!='('):
            print '\033[1;35m',k+1,"[ERROR]: Never find 'i' or '('!"
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
    if(a[k]=='*'):
        print "\033[0mT' -->  *FT'   Mate to *"
        k+=1
        if(a[k]!='i' and a[k]!='('):
            print '\033[1;35m',k+1,"[ERROR]: Never find 'i' or '('!"
            temp=1
            k+=1
        F()
        Y()
    else:
        print "\033[0mT' -->  ε"

def F():
    global k,temp
    if(a[k]=='i'):
        print "\033[0mF -->  i       Mate to i"
        k+=1
        if(a[k]!='+' and a[k]!='*' and a[k]!=')' and a[k]!='$'):
            print '\033[1;35m',k+1,"[ERROR]: Never find '+' or '*'"
            temp=1
            if(a[k]=='(' or a[k]=='i'):
                F()
            else:
                k+=1
                F()
    elif(a[k]=='('):
        print "\033[0mF -->  (E)"
        k+=1
        E()
        while(a[k]!=')'):
            print '\033[1;35m',k+1,"[ERROR]: Never find ')'!"
            temp=1
            break 
        if(a[k]==')'):
            k+=1
    else:
        print '\033[1;33m',k+1,"[ERROR]: Never find 'i' or '('!"
        temp=1
        k+=1
        if(a[k]=='(' or a[k]=='i'):
            F()

if __name__=='__main__':
    a=raw_input('Please input expression:')
    a=a+'$'
    k=0
    temp=0
    E()
    if(a[k]=='$'):
        if(temp==0):
            print "\033[1;32m[TURE]: This grammar is correct!"
        else:
            print "\033[1;31m[FLASE]: This grammar is worng!"
