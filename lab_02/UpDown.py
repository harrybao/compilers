#coding:utf-8

def E():
    global j
    if(str1[j]=='i' or str1[j]=='('):
        print "E -->  TE'"
        T()
        X()
    else:
        print "[ERROR]: Alalyzing is Flase!"

def X():
    global j
    if(str1[j]=='+'):
        print "E' -->  +TE'   Mate to +"
        j+=1
        T()
        X()
    else:
        print "E' -->  ε"

def T():
    global j
    if(str1[j]=='i' or str1[j]=='('):
        print "T -->  FT'"
        F()
        Y()
    else:
        print "[ERROR]: Alalyzing is Flase!"

def Y():
    global j
    if(str1[j]=='*'):
        print "T' -->  *FT'   Mate to *"
        j+=1
        F()
        Y()
    else:
        print "T' -->  ε"

def F():
    global j
    if(str1[j]=='i'):
        print "F -->  i       Mate to i"
        j+=1
    elif(str1[j]=='('):
        print "F -->  (E)"
        j+=1
        E()
        while(str1[j]!=')'):
            print "[ERROR]: Never find ')'!"
            exit(0)
        if(str1[j]==')'):
            j+=1
        else:
            print "[ERROR]: Alalyzing errors!"
            exit(0)
    else:
        print "[ERROR}: Alalyzing errors!"
        exit(0)

if __name__=='__main__':
    str1=input('please input string:')
    str1=str1+'$'
    j=0
    E()
    if(str1[j]=='$'):
        print "[RIGHT]: The input is true"
