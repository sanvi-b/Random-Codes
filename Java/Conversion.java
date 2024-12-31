import java.util.Scanner;
class Stack
{
    private int top;
    private char stack[];
    public Stack(int cap)
    {
        this.top=0;
        this.stack= new char[cap];
    }
    public boolean isEmpty()
    {
        return (top==0);
    }
    public void push (char item)
    {
        stack[++top]=item;
    }
    public char pop()
    {
        if (isEmpty())
        return '\0';
        else
        return (stack[top--]);
    }
    public char peek()
    {
        return (stack[top]);
    }
}
class Stackpp
{
    private int top;
    private String stack[];
    public Stackpp(int cap)
    {
        this.top=0;
        this.stack= new String[cap];
    }
    public boolean isEmpty()
    {
        return (top==0);
    }
    public void push (String item)
    {
        stack[++top]=item;
    }
    public String pop()
    {
        if (isEmpty())
        return null;
        else
        return (stack[top--]);
    }
    public String peek()
    {
        return (stack[top]);
    }
}
class Conversion
{
    static Scanner sc= new Scanner (System.in);
    public static void main (String str[])
    {
        int e =1;
        System.out.println("Conversion Menu\n0.Exit\n1.Infix to Postfix\n2.Infix to Prefix\n3.Prefix to Postfix");
        while (e>0)
        {
            System.out.println("Enter choice: ");
            int choc = sc.nextInt();
            switch (choc)
            {
                case 0: e=0;
                        System.out.println("Exiting program!");
                        break;
                case 1: InfixtoPostfix();
                        break;
                case 2: InfixtoPrefix();
                        break;
                case 3: PrefixtoPostfix();
                        break;
                default: System.out.println ("Invalid choice! Choose again.");
            }
        }
    } 
    public static void InfixtoPostfix ()
    {
        Stack st= new Stack(25);
        String result = "";
        System.out.println ("Enter a Infix expression for conversion to Postfix expression:");
        String exp= sc.next();
        int l= exp.length();
        for (int i=0; i<l; i++)
        {
            char ch = exp.charAt(i); 
            if ((ch>= 'a' && ch<= 'z') || (ch>= 'A' && ch<= 'Z') || (ch>='0' && ch<='9'))
            result = result+ ch; 
            else if (ch == '(')
            st.push(ch);
            else if (ch == ')') 
            {
                while (!st.isEmpty() && st.peek() != '(') 
                result=result+st.pop();
                if (!st.isEmpty() && st.peek() == '(')
                st.pop(); 
            } else { 
                while (!st.isEmpty() && precedence(ch)<= precedence(st.peek()))
                result=result+ st.pop();
                st.push(ch);
            }
        }    
        while (!st.isEmpty()) 
        result=result +st.pop();
        System.out.println ("The Postfix expression is: " + result);       
    }     
    public static void InfixtoPrefix()
    {
        Stack tc= new Stack(25);
        String revstr= "";
        String result = "";
        System.out.println ("Enter a Infix expression for conversion to Prefix expression:");
        String exp= sc.next();
        int l= exp.length();
        for (int i=l-1; i>= 0; i--)
        {
            char ch= exp.charAt(i);
            if (isOperator(ch))
            {
                while(!tc.isEmpty() && precedence(ch)< precedence(tc.peek()))
                result = result + tc.pop();
                tc.push(ch);
            }
            else if (ch == ')')
            tc.push (ch);
            else if (ch == '(')
            {
                while (!tc.isEmpty() && tc.peek()!= ')')
                result = result + tc.pop();
                if (!tc.isEmpty() && tc.peek() == ')')
                tc.pop();
            }
            else 
            result = result + ch;
        }
        while (!tc.isEmpty())
        result = result + tc.pop();
        for (int i=result.length()-1; i>= 0; i--)
        revstr= revstr + result.charAt(i);
        System.out.println ("The Prefix expression is: " + revstr);       
    } 
    public static void PrefixtoPostfix()
    {   Stackpp so= new Stackpp(25);
        System.out.println ("Enter a Prefix expression for conversion to Postfix expression:");
        String exp= sc.next();
        int l= exp.length();  
        for (int i=l-1; i>=0; i--)
        {
            char ch= exp.charAt(i);
            if (isOperator(ch))
            {
                String op1= so.pop();
                String op2= so.pop();
                String temp= op1+ op2+ ch;
                so.push(temp);
            }
            else so.push(ch+ "");
        }    
        System.out.println ("The Postfix expression is: " + so.pop());
    }
    public static int precedence (char operator)
    {
        switch (operator)
        {
            case '+': 
            case '-': return 1;
            case '*':
            case '/': return 2;
            case '^': return 3;
            default: return -1;
        }
    }
    private static boolean isOperator(char ch) 
    {
        return ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^';
    }
}