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
    private Link first;
    public LinkedList()
    {
        first=null;
    }
    public boolean isEmpty()
    {
        return (first==null);
    }
    public void insertFirst(int d)
    {
        Link nl= new Link(d);
        nl.next= first;
        first=nl;
    }
    public void deleteFirst()
    {
        if (!isEmpty())
        {
            Link temp=first;
            first= first.next;
            System.out.println ("The first value " + temp.data + " of List was deleted successfully.");
        }
        else 
        System.out.println("List is empty!");
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
}
class LMain
{
    public static void main (String st[])
    {
        Scanner sc= new Scanner(System.in);
        System.out.println ("Menu:\n0.Exit\n1.Insert First\n2.Delete First\n3.Display ");
        LinkedList obj= new LinkedList();
        int e=1, ch, d;
        while (e>0)
        {
            System.out.println("Choice: ");
            ch= sc.nextInt();
            switch (ch)
            {
                case 0: e=0;
                        System.out.println("Exiting program!");
                        break;
                case 1: System.out.println("Enter data to be inserted as first:");
                        d= sc.nextInt();
                        obj.insertFirst(d);
                        System.out.println("Inserted first successfully.");
                        break;
                case 2: obj.deleteFirst();
                        break;
                case 3: obj.displayList();
                        break;
            }
        }
        sc.close();
    }
}