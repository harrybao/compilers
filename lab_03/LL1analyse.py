#coding:utf-8
from prettytable import PrettyTable

def LL1():
	global c,flag
	if(c=='E'):
		if(a[k]=='i' or a[k]=='('):
			table.add_row([a[k:], "E -> TE'"])
			stack.append('X')
			stack.append('T')
			print stack
			c=stack.pop()
		else:
			error()
			flag=1
	elif(c=='X'):
		if(a[k]=='+'):
			table.add_row([a[k:], "E' -> +TE'"])
			stack.append('X')
			stack.append('T')
			stack.append('+')
			print stack
			c=stack.pop()
		elif(a[k]==')' or a[k]=='$'):
			table.add_row([a[k:], "E' -> ε"])
			print stack
			c=stack.pop()
		else:
			error()
			flag=1
	elif(c=='T'):
		if(a[k]=='i' or a[k]=='('):
			table.add_row([a[k:], "T -> FT'"])
			stack.append('Y')
			stack.append('F')
			print stack
			c=stack.pop()
		else:
			error()
			flag=1
	elif(c=='Y'):
		if(a[k]=='*'):
			table.add_row([a[k:], "T' -> *FT'"])
			stack.append('Y')
			stack.append('F')
			stack.append('*')
			print stack
			c=stack.pop()
		elif(a[k]=='+' or a[k]==')' or a[k]=='$'):
			table.add_row([a[k:], "T' -> ε"])
			print stack
			c=stack.pop()	
		else:
			error()
			flag=1
	elif(c=='F'):
		if(a[k]=='i'):
			table.add_row([a[k:], "F -> i"])
			stack.append('i')
			print stack
			c=stack.pop()
		elif(a[k]=='('):
			table.add_row([a[k:], "F -> (E)"])
			stack.append(')')
			stack.append('E')
			stack.append('(')
			print stack
			c=stack.pop()
		else:
			error()
			flag=1



def error():
	global k 
	table.add_row([a[k], "Error"])
	print stack
	k+=1

if __name__ == '__main__':
	a=raw_input("Input Etablepression:")
	a=a+'$'
	for temp in a:
		if(temp!='i' and temp!='+' and temp!='*' and temp!='(' and temp!=')' and temp!='$'):
			print "You input is wrong!"
			exit(0)
	table = PrettyTable(["Input", "Action"])
	table.padding_width = 1
	table.align["Input"] = "r"
	table.align["Action"] = "l"
	stack=[]
	k=0
	flag=0
	stack.append('$')
	stack.append('E')
	table.add_row([a[k:]," "])
	print stack
	c=stack.pop()
	while(c!='$'):
		if(c==a[k]):
			table.add_row([a[k+1:],'{'+a[k]+'}'+" Matching"])
			print stack
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
