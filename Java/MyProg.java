import java.util.Scanner;
class Array
{
    int n, i;
    int arr[]=new int[50];
    Scanner sc= new Scanner (System.in);
    public void data ()
    {
        System.out.println ("Enter the size of the Ordered Array: ");
        n=sc.nextInt();
        System.out.print ("Enter the elements of the Ordered Array: ");
        for (i=0; i<n; i++)
        arr[i]=sc.nextInt();
        System.out.println ("The Ordered Array is: ");
        for (i=0; i<n; i++)
        System.out.print( arr[i] + " ");
    }
    public void insert (int element)
    {
        i = n - 1;
        while (i >= 0 && arr[i] > element)
        {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = element;
        System.out.println ("The Ordered Array after Insertion is: ");
        for (i=0; i<=n; i++)
        System.out.print( arr[i] + " ");    
    }
    public int search(int element) 
    {
        int low = 0;
        int high = n;
        while (low <= high) 
        {
            int mid = (low + high) / 2;
            if (arr[mid] == element) 
            return mid;
            else if (arr[mid] < element) 
            low = mid + 1;
            else 
            high = mid - 1;    
        }
        return -1;  
    }
    public void delete (int element)
    {
        i= search (element);
        if (i == -1) 
        {
            System.out.println("Element not found in the Array!");
            return;
        }
        for (int j = i; j < n; j++) 
        arr[j] = arr[j + 1];
        System.out.println ("The Ordered Array after Deletion is: ");
        for (i=0; i<n; i++)
        System.out.print( arr[i] + " ");
    }
}
class UnArray
{
    int n, i;
    int arr[]=new int[50];
    Scanner sc= new Scanner (System.in);
    public void data ()
    {
        System.out.println ("\n\nEnter the size of the Unordered Array: ");
        n=sc.nextInt();
        System.out.print ("Enter the elements of the Unordered Array: ");
        for (i=0; i<n; i++)
        arr[i]=sc.nextInt();
        System.out.println ("The Unordered Array is: ");
        for (i=0; i<n; i++)
        System.out.print( arr[i] + " ");
    }
    public void insert(int element)
    {
        arr[n] = element;
        System.out.println ("The Unordered Array after Insertion is: ");
        for (i=0; i<=n; i++)
        System.out.print( arr[i] + " ");
    }
    public int search(int element) 
    {
        for (i = 0; i <= n; i++) 
        {
            if (arr[i] == element)
            return i;
        }
        return -1;
    }
    public void delete (int element)
    {
        i= search (element);
        if (i == -1) 
        {
            System.out.println("Element not found in the Array!");
            return;
        }
        for (int j = i; j < n; j++)
        arr[j] = arr[j + 1];
        System.out.println ("The Unordered Array after Deletion is: ");
        for (i=0; i<n; i++)
        System.out.print( arr[i] + " ");
    }
}
class MyProg 
{
    public static void main (String st[])
    {
        int pos;
        Scanner oc= new Scanner (System.in);
        int element;
        Array ary= new Array();
        ary.data();
        System.out.print ("\nEnter the element to be inserted: ");
        element= oc.nextInt();
        ary.insert(element);
        System.out.print ("\nEnter the element to be searched: ");
        element= oc.nextInt();
        pos= ary.search(element);
        if (pos != -1)
        System.out.print ("The position of the element is: " + (pos+1));
        else System.out.print ("Element not found in the Array!");
        System.out.print ("\nEnter the element to be deleted: ");
        element= oc.nextInt();
        ary.delete(element);
        UnArray una= new UnArray() ;
        una.data();
        System.out.print ("\nEnter the element to be inserted: ");
        element= oc.nextInt();
        una.insert(element);
        System.out.print ("\nEnter the element to be searched: ");
        element= oc.nextInt();
        pos= una.search(element);
        if (pos != -1)
        System.out.print ("The position of the element is: " + (pos+1));
        else System.out.print ("Element not found in the Array!");
        System.out.print ("\nEnter the element to be deleted: ");
        element= oc.nextInt();
        una.delete(element);
        oc.close();
    }
}