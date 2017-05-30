#coding:utf-8
from prettytable import PrettyTable

def LL1():
	global c,flag
	if(c=='E'):
		if(a[k]=='i' or a[k]=='('):
			table.add_row([stack,a[k:], "E -> TE'"])
			stack.append('X')
			stack.append('T')
			c=stack.pop()
		else:
			error()
			flag=1
	elif(c=='X'):
		if(a[k]=='+'):
			table.add_row([stack,a[k:], "E' -> +TE'"])
			stack.append('X')
			stack.append('T')
			stack.append('+')
			c=stack.pop()
		elif(a[k]==')' or a[k]=='$'):
			table.add_row([stack,a[k:], "E' -> ε"])
			c=stack.pop()
		else:
			error()
			flag=1
	elif(c=='T'):
		if(a[k]=='i' or a[k]=='('):
			table.add_row([stack,a[k:], "T -> FT'"])
			stack.append('Y')
			stack.append('F')
			c=stack.pop()
		else:
			error()
			flag=1
	elif(c=='Y'):
		if(a[k]=='*'):
			table.add_row([stack,a[k:], "T' -> *FT'"])
			stack.append('Y')
			stack.append('F')
			stack.append('*')
			c=stack.pop()
		elif(a[k]=='+' or a[k]==')' or a[k]=='$'):
			table.add_row([stack,a[k:], "T' -> ε"])
			c=stack.pop()	
		else:
			error()
			flag=1
	elif(c=='F'):
		if(a[k]=='i'):
			table.add_row([stack,a[k:], "F -> i"])
			stack.append('i')
			c=stack.pop()
		elif(a[k]=='('):
			table.add_row([stack,a[k:], "F -> (E)"])
			stack.append(')')
			stack.append('E')
			stack.append('(')
			c=stack.pop()
		else:
			error()
			flag=1



def error():
	global k 
	table.add_row([k+1,a[k], "Error"])
	k+=1

if __name__ == '__main__':
	a=raw_input("Input Etablepression:")
	a=a+'$'
	for temp in a:
		if(temp!='i' and temp!='+' and temp!='*' and temp!='(' and temp!=')' and temp!='$'):
			print "You input is wrong!"
			etableit(0)
	table = PrettyTable(["Stack", "Input", "Action"])
	table.padding_width = 1
	table.align["Stack"] = "l"
	table.align["Input"] = "r"
	table.align["Action"] = "l"
	stack=[]
	k=0
	flag=0
	stack.append('$')
	stack.append('E')
	table.add_row([stack,a[k:]," "])
	c=stack.pop()
	while(c!='$'):
		if(c==a[k]):
			table.add_row([stack,a[k+1:],'{'+a[k]+'}'+" Matching"])
			k+=1
			c=stack.pop()
		elif(c==')' and c!=a[k]):
			error()
			flag=1
			break
		elif(flag==1):
			break
		elif(a[k]=='$' and c=='$'):
			break
		else:
			LL1()

	print table
	if(flag==0):
		print "Analyse success!"
	else:
		print "Analyse fail!"
