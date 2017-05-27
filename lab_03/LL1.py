#coding:utf-8


def LL1():
	global c 
	if(c=='E'):
		if(a[i]=='i' or a[i]=='('):
			print stack,"E->TE'",a[i:]
			stack.append('e')
			stack.append('T')
			c=stack.pop()
		else:
			error()
	elif(c=='e'):
		if(a[i]=='+'):
			print stack,"E'->+TE'",a[i:]
			stack.append('e')
			stack.append('T')
			stack.append('+')
			c=stack.pop()
		elif(a[i]==')' or a[i]=='$'):
			print stack,"E'->&",a[i:]
			c=stack.pop()
		else:
			error()
	elif(c=='T'):
		if(a[i]=='i' or a[i]=='('):
			print stack,"T->FT'",a[i:]
			stack.append('t')
			stack.append('F')
			c=stack.pop()
		else:
			error()
	elif(c=='t'):
		if(a[i]=='+' or a[i]==')' or a[i]=='$'):
			print stack,"T'->&",a[i:]
			c=stack.pop()
		elif(a[i]=='*'):
			print stack,"T'->*FT'",a[i:]
			stack.append('t')
			stack.append('F')
			stack.append('*')
			c=stack.pop()
		else:
			error()
	elif(c=='F'):
		if(a[i]=='i'):
			print stack,"F->i",a[i:]
			stack.append('i')
			c=stack.pop()
		elif(a[i]=='('):
			print stack,"F->(E)",a[i:]
			stack.append(')')
			stack.append('E')
			stack.append('(')
			c=stack.pop()
		else:
			error()

def error():
	global i 
	print i+1,a[i],"error"
	i+=1

if __name__ == '__main__':
	a=raw_input("Input Expression:")
	a=a+'$'
	i=0
	stack=[]
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
	