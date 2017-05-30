import java.io.IOException;
import java.util.Scanner;
import java.util.Stack;

public class test3{
	static char[] a=new char[20];
	static int n=0,i=0;
	static char c;
	static String s;
	static Stack<Character> sk = new Stack<Character>();
	public static void main(String[] args){
		System.out.println("input:");
		Scanner in = new Scanner(System.in);
		char z = 0;
		try {
			z = (char)System.in.read();
		} catch (IOException e) {
			e.printStackTrace();
		}
		while(z!='$'){
			   a[n]=z;
			   try {
				z=(char)System.in.read();
			} catch (IOException e) {
				e.printStackTrace();
			}
			   n++;
			   a[n]='$';
		}
		sk.push('$');
		sk.push('E');
		c=sk.pop();
		do{
			if(c==a[i]){ i++;c=sk.pop();}
			else if(a[i]=='$') break;
			else ll1();
		}
	    while(c!='$');
	}
	private static void ll1() {
		if(c=='E'){
			if(a[i]=='i'||a[i]=='('){
				System.out.println("E->TE'");
				sk.push('e');
				sk.push('T');
				c=sk.pop();
			}
			else error();
		}
		else if(c=='e'){
			if(a[i]=='+'){
				System.out.println("E'->+TE'");
				sk.push('e');
				sk.push('T');
				sk.push('+');
				c=sk.pop();
			}
			else if(a[i]==')'||a[i]=='$'){
				System.out.println("E'->&");
				c=sk.pop();
			}
			else error();
		}
		else if(c=='T'){
			if(a[i]=='i'||a[i]=='('){
				System.out.println("T->FT'");
				sk.push('t');
				sk.push('F');
				c=sk.pop();
			}
			else error();
		}
		else if(c=='t'){
			if(a[i]=='+'||a[i]==')'||a[i]=='$'){
				System.out.println("T'->&");
				c=sk.pop();
			}
			else if(a[i]=='*'){
				System.out.println("T'->*FT'");
				sk.push('t');
				sk.push('F');
				sk.push('*');
				c=sk.pop();
			}
			else error();
		}
		else if(c=='F'){
			if(a[i]=='i'){
				System.out.println("F->i");
				sk.push('i');
				c=sk.pop();
			}
			else if(a[i]=='('){
				System.out.println("F->(E)");
				sk.push(')');
				sk.push('E');
				sk.push('(');
				c=sk.pop();
			}
			else error();
		}
	}
	private static void error() {
		System.out.println((i+1)+":"+a[i]+"  error!");
		i++;
	}
}