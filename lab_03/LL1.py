#coding:utf-8
from prettytable import PrettyTable

def LL1():
	global c 
	if(c=='E'):
		if(a[i]=='i' or a[i]=='('):
			x.add_row([stack,a[i:], "E -> TE'"])
			stack.append('X')
			stack.append('T')
			c=stack.pop()
		else:
			error()
	elif(c=='X'):
		if(a[i]=='+'):
			x.add_row([stack,a[i:], "E' -> +TE'"])
			stack.append('X')
			stack.append('T')
			stack.append('+')
			c=stack.pop()
		elif(a[i]==')' or a[i]=='$'):
			x.add_row([stack,a[i:], "E' -> ε"])
			c=stack.pop()
		else:
			error()
	elif(c=='T'):
		if(a[i]=='i' or a[i]=='('):
			x.add_row([stack,a[i:], "T -> FT'"])
			stack.append('Y')
			stack.append('F')
			c=stack.pop()
		else:
			error()
	elif(c=='Y'):
		if(a[i]=='*'):
			x.add_row([stack,a[i:], "T' -> *FT'"])
			stack.append('Y')
			stack.append('F')
			stack.append('*')
			c=stack.pop()
		elif(a[i]=='+' or a[i]==')' or a[i]=='$'):
			x.add_row([stack,a[i:], "T' -> ε"])
			c=stack.pop()	
		else:
			error()
	elif(c=='F'):
		if(a[i]=='i'):
			x.add_row([stack,a[i:], "F -> i"])
			stack.append('i')
			c=stack.pop()
		elif(a[i]=='('):
			x.add_row([stack,a[i:], "F -> (E)"])
			stack.append(')')
			stack.append('E')
			stack.append('(')
			c=stack.pop()
		else:
			error()



def error():
	global i 
	x.add_row([i+1,a[i], "error"])
	i+=1

if __name__ == '__main__':
	a=raw_input("Input Expression:")
	a=a+'$'
	i=0
	x = PrettyTable(["Stack", "Input", "Action"])
	x.padding_width = 1
	x.align["Stack"] = "l"
	x.align["Input"] = "r"
	x.align["Action"] = "l"
	stack=[]
	stack.append('E')
	x.add_row([stack,a[i:]," "])
	c=stack.pop()
	while(c!='$'):
		if(c==a[i]):
			if(c=='i'):
				x.add_row([stack,a[i+1:],"Mate i"])
			if(c=='+'):
				x.add_row([stack,a[i+1:],"Mate +"])
			if(c=='*'):
				x.add_row([stack,a[i+1:],"Mate *"])
			if(c=='('):
				x.add_row([stack,a[i+1:],"Mate ("])
			if(c==')'):
				x.add_row([stack,a[i+1:],"Mate )"])
			i+=1
			c=stack.pop()
		elif(a[i]=='$'):
			break
		else:
			LL1()
	print x
