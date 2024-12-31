import java.util.Scanner;
class Link
{
    public int data;
    public Link next;
    public Link(int d)
    {
        data=d;
        next=null;
    }
}
class LinkedList
{
    Scanner so= new Scanner(System.in);
    private Link first;
    public LinkedList()
    {
        first=null;
    }
    public boolean isEmpty()
    {
        return (first==null);
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
    public void insertNode(int d, int p)
    {
        Link nel= new Link(d);
        if (p==1)
        {
            nel.next=first;
            first= nel;
        } else
        {
            Link prev= first;
            for (int i=1; i < p-1 && prev != null; i++)
            prev= prev.next;
            if (prev==null)
            {
                System.out.println("Inavlid position!");
                return;            
            }
            nel.next= prev.next;
            prev.next= nel;
        }
        System.out.println("Node inserted successfully.");
    }
    public void deleteFirst()
    {
        if (!isEmpty())
        {
            first= first.next;
            System.out.println("First node deleted successfully.");
        } else 
        System.out.println("List is empty!");
    }
    public void replaceNode(int p, int d)
    {
        Link cur= first;
        int count=1;
        while (cur != null && count<p)
        {
            cur= cur.next;
            count++;
        }
        if (cur==null)
        {
            System.out.println("Inavlid position!");
            return;
        }
        cur.data= d;
        System.out.println("Value replaced successfully.");
    }
}
class Node
{
    public static void main (String st[])
    {
        Scanner sc= new Scanner(System.in);
        LinkedList obj= new LinkedList();
        System.out.println ("Menu:\n0.Exit\n1.Insert Node\n2.Delete First\n3.Replace Node\n4.Display ");  
        int e=1, ch, d, p;
        while (e>0)
        {
            System.out.println("Enter choice: ");
            ch= sc.nextInt();
            switch (ch)
            {
                case 0: e=0;
                        System.out.println("Exiting program!");
                        break;
                case 1: System.out.println("Enter data to be inserted:");
                        d= sc.nextInt();
                        System.out.println ("Enter position to be inserted at:");
                        p= sc.nextInt();
                        obj.insertNode(d, p);
                        break;
                case 2: obj.deleteFirst();
                        break;
                case 3: System.out.println("Enter position of node to be replaced:");
                        p= sc.nextInt();
                        System.out.println ("Enter new data:");
                        d= sc.nextInt();
                        obj.replaceNode(p, d);
                        break;
                case 4: obj.displayList();
                        break;
                default: System.out.println("Invalid choice, choose again!");
            }
        }
        sc.close();
    }
}