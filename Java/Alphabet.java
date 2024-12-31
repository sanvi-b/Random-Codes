import java.util.Scanner;
class Link
{
    public char data;
    public Link next;
    public Link(char d)
    {
        data=d;
        next=null;
    }
}
class LinkedList
{
    private Link first;
    public LinkedList()
    {
        first=null;
    }
    public boolean isEmpty()
    {
        return (first==null);
    }
    public void insertFirst(char d)
    {
        Link nl= new Link(d);
        nl.next= first;
        first=nl;
    }
    public void displayList()
    {
        if (!isEmpty())
        {
            Link cur= first;
            System.out.println("The contents of the list are:");
            while (cur!=null)
            {
               System.out.println(cur.data);
               cur= cur.next;
            }
        }
        else
        System.out.println("List is empty!");
    }
    public void revList()
    {
        if (!isEmpty())
        {
            Link prev = null;
            Link cur = first;
            Link next = null;
            while (cur!= null) 
            {
                next = cur.next;
                cur.next = prev;
                prev = cur;
                cur = next;
            }
        first = prev;
        System.out.println ("Reversed list successfully.");        
        }
        else 
        System.out.println("List is empty!");
    } 
    public void sortList()
    {
        if (!isEmpty())
        {
            Link cur = first;
            Link index = null;
            char temp;
            while (cur!= null) 
            {
                index = cur.next;
                while (index != null) 
                {
                    if (cur.data > index.data) 
                    {
                        temp = cur.data;
                        cur.data = index.data;
                        index.data = temp;
                    }
                index = index.next;
                }
            cur= cur.next;
            }
            System.out.println ("Sorted list successfully.");
        } else
        System.out.println("List is empty!");
    }
}
class Alphabet
{
    public static void main (String st[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println ("Menu:\n0.Exit\n1.Insert First\n2.Reverse List\n3.Sort List\n4.Display ");
        LinkedList obj= new LinkedList();
        int e=1, ch;
        while (e>0)
        {
            System.out.println("Enter choice: ");
            ch= sc.nextInt();
            switch (ch)
            {
                case 0: e=0;
                        System.out.println("Exiting program!");
                        break;
                case 1: System.out.println("Enter data to be inserted as first:");
                        char d= sc.next().charAt(0);
                        obj.insertFirst(d);
                        System.out.println("Inserted first successfully.");
                        break;
                case 2: obj.revList();
                        break;
                case 3: obj.sortList();
                        break;
                case 4: obj.displayList();
                        break;
                default: System.out.println("Invalid choice, choose again!");
            }
        }
        sc.close();
    }
}