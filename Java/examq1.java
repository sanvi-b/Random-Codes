import java.util.Scanner;
class Link 
{
    int data;
    Link next, prev;
    Link(int d) 
    {
        data = d;
        next = prev = null;
    }
}
class List 
{
    Link first, last;
    List() 
    {
        first = last = null;
    }
    public void insertFirst(int d) 
    {
        Link nl = new Link(d);
        if (last == null) 
        {
            first = nl;
            last = nl;
        } else {
            nl.prev = last;
            last.next = nl;
            last = nl;
        }
    }
    public void deleteLast() 
    {
        last = last.prev;
        if (last != null)
            last.next = null;
    }
    public void deleteFirst() 
    {
        first = first.next;
        if (first != null)
            first.prev = null;
    }
    public void question(List a, List b, List c) 
    {
        Link cur1 = a.first;
        Link cur2 = b.last;
        while (cur1 != null && cur2 != null) 
        {
            if (cur1.data > cur2.data) 
            {
                b.deleteLast();
                c.insertFirst(1);
            } 
            else if (cur2.data > cur1.data) 
            {
                a.deleteFirst();
                c.insertFirst(0);
            } else {
                a.deleteFirst();
                b.deleteLast();
                c.insertFirst(2);
            }
            cur1 = cur1.next;
            cur2 = cur2.prev;
        }
    }
    public void display() 
    {
        Link cur = first;
        while (cur != null) {
            System.out.print(cur.data + " ");
            cur = cur.next;
        }
    }
}
class examq1 
{
    public static void main(String[] st) 
    {
        Scanner sc = new Scanner(System.in);
        List A = new List();
        List B = new List();
        List C = new List();
        A.insertFirst(5);
        A.insertFirst(6);
        A.insertFirst(7);
        A.insertFirst(8);
        A.insertFirst(9);
        B.insertFirst(1);
        B.insertFirst(11);
        B.insertFirst(2);
        B.insertFirst(6);
        B.insertFirst(14);
        A.display();
        System.out.println();
        B.display();
        System.out.println();
        C.question(A, B, C);
        C.display();
        System.out.println();
        A.display();
        System.out.println();
        B.display();
    }
}