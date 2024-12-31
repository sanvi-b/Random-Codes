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
    public void insertFirst(int d)
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
    public void noCount()
    {
        if (!isEmpty())
        {
            System.out.println("Enter a number to find it's Frequency in the List:");
            int key= so.nextInt();
            int count=0;
            Link cur=first;
            while (cur!=null)
            {
                if (cur.data==key)
                count++;
                cur=cur.next;
            }
            System.out.println("The number " + key + " occurs " + count + " times in the List.");
        } else
        System.out.println("List is empty!");
    }
    public void remDup()
    {
        if(!isEmpty())
        {
            Link cur=first;
            while (cur!=null)
            {
                Link temp= cur;
                while (temp.next!=null)
                {
                    if (temp.next.data==cur.data)
                    temp.next= temp.next.next;
                    else 
                    temp= temp.next;
                }
                cur= cur.next;
            }
            System.out.println ("Duplicates have been removed successfully.");
        } else
        System.out.println("List is empty!");
    }
}
class Frequency
{
    public static void main (String st[])
    {
        Scanner sc= new Scanner(System.in);
        LinkedList obj= new LinkedList();
        System.out.println ("Menu:\n0.Exit\n1.Insert First\n2.Frequency\n3.Delete Duplicate\n4.Display ");  
        int e=1, ch, d;
        while (e>0)
        {
            System.out.println("Enter choice: ");
            ch= sc.nextInt();
            switch (ch)
            {
                case 0: e=0;
                        System.out.println("Exiting program!");
                        break;
                case 1: System.out.println("Enter data to be inserted: ");
                        d= sc.nextInt();
                        obj.insertFirst(d);
                        break;
                case 2: obj.noCount();
                        break;
                case 3: obj.remDup();
                        break;
                case 4: obj.displayList();
                        break;
                default: System.out.println("Invalid choice, choose again!");
            }
        }
        sc.close();
    }
}