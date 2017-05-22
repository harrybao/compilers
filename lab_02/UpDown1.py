#coding:utf-8

def E():
    global k
    if(str1[k]=='i' or str1[k]=='('):
        print "E -->  TE'"
        T()
        X()
    else:
        print "[ERROR]: Alalyzing is Flase!"
        exit(0)

def X():
    global k
    if(str1[k]=='+'):
        print "E' -->  +TE'   Mate to +"
        k+=1
        T()
        X()
    else:
        print "E' -->  ε"

def T():
    global k
    if(str1[k]=='i' or str1[k]=='('):
        print "T -->  FT'"
        F()
        Y()
    else:
        print "[ERROR]: Alalyzing is Flase!"
        exit(0)

def Y():
    global k
    if(str1[k]=='*'):
        print "T' -->  *FT'   Mate to *"
        k+=1
        F()
        Y()
    else:
        print "T' -->  ε"

def F():
    global k
    if(str1[k]=='i'):
        print "F -->  i       Mate to i"
        k+=1
        if(str1[k]!='+' and str1[k]!='*' and str1[k]!=')' and str1[k]!='$'):
            print "[ERROR]: Never find '+' or '*'"
            exit(0)
    elif(str1[k]=='('):
        print "F -->  (E)"
        k+=1
        E()
        while(str1[k]!=')'):
            print "[ERROR]: Never find ')'!"
            exit(0)
        if(str1[k]==')'):
            k+=1
        else:
            print "[ERROR]: Alalyzing errors!"
            exit(0)
    else:
        print "[ERROR}: Alalyzing errors!"
        exit(0)

if __name__=='__main__':
    str1=input('please input string:')
    str1=str1+'$'
    k=0
    E()
    if(str1[k]=='$'):
        print "[RIGHT]: The input is true"
