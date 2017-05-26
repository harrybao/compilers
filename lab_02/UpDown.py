#coding:utf-8

def E():
    print "E -->  TE'"
    T()
    X()

def X():
    global k,temp
    if(str1[k]=='+'):
        print "E' -->  +TE'   Mate to +"
        k+=1
        if(str1[k]!='i' and str1[k]!='('):
            print k,"[ERROR]: Never find 'i' or '('!"
            temp=1
            k+=1
        T()
        X()
    else:
        print "E' -->  ε"

def T():
    print "T -->  FT'"
    F()
    Y()

def Y():
    global k,temp
    if(str1[k]=='*'):
        print "T' -->  *FT'   Mate to *"
        k+=1
        if(str1[k]!='i' and str1[k]!='('):
            print k,"[ERROR]: Never find 'i' or '('!"
            temp=1
            k+=1
        F()
        Y()
    else:
        print "T' -->  ε"

def F():
    global k,temp
    if(str1[k]=='i'):
        print "F -->  i       Mate to i"
        k+=1
        if(str1[k]!='+' and str1[k]!='*' and str1[k]!=')' and str1[k]!='$'):
            print k,"[ERROR]: Never find '+' or '*'"
            temp=1
            if(str1[k]=='(' or str1[k]=='i'):
                F()
    elif(str1[k]=='('):
        print "F -->  (E)"
        k+=1
        E()
        while(str1[k]!=')'):
            print k,"[ERROR]: Never find ')'!"
            temp=1
            break 
        if(str1[k]==')'):
            k+=1
    else:
        print k,"[ERROR]: Never find 'i' or '('!"
        temp=1
        k+=1

if __name__=='__main__':
    str1=input('please input string:')
    str1=str1+'$'
    k=0
    temp=0
    E()
    if(str1[k]=='$'):
        if(temp==0):
            print "[RIGHT]: The input is true!"
        else:
            print "[FLASE]: This is error string!"
