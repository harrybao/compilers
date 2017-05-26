#coding:utf-8


def LL1():
	if(c=='E'):
		if(a[i]=='i' or a[i]=='('):
			print "E->TE'"
			stack.append('e')
			stack.append('T')
			c=stack.pop()
		else:
			error()
	elif(c=='e'):
		if(a[i]=='+'):
			print "E'->+TE'"
			stack.append('e')
			stack.append('T')
			stack.append('+')
			c=stack.pop()
		elif(a[i]==')' or a[i]=='$'):
			print "E'->&"
			c=stack.pop()
		else:
			error()
	elif(c=='T'):
		if(a[i]=='i' or a[i]=='('):
			print "T->FT'"
			stack.append('t')
			stack.append('F')
			c=stack.pop()
		else:
			error()
	elif(c=='t'):
		if(a[i]=='+' or a[i]==')' or a[i]=='$'):
			print "T'->&"
			c=stack.pop()
		elif(a[i]=='*'):
			print "T'->*FT'"
			stack.append('t')
			stack.append('F')
			stack.append('*')
			c=stack.pop()
		else:
			error()
	elif(c=='F'):
		if(a[i]=='i'):
			print "F->i"
			stack.append('i')
			c=stack.pop()
		elif(a[i]=='('):
			print "F->(E)"
			stack.append(')')
			stack.append('E')
			stack.append('(')
			c=stack.pop()
		else:
			error()

def error():
	print i+1,a[i],"error"
	i+=1

if __name__ == '__main__':
	in1=raw_input("Input the syant:")
	z=chr(in1)
	i=0
	z=0
	n=0
	a=""
	while(z!='$'):
		a[n]=z
		n+=1
		a[n]='$'
	stack.append('$')
	stack.append('E')
	c=stack.pop()
	while(c!='$'):
		if(c==a[i]):
			i+=1
			c=stack.pop()
		elif(a[i]=='$'):
			break
		else:
			LL1()
	