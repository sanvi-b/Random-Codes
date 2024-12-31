import java.util.Scanner;
class Stack 
{
    private int capacity;
    private int top;
    private int[] stack;
    public Stack(int capacity) 
    {
        this.capacity = capacity;
        this.top = -1;
        this.stack = new int[capacity];
    }
    public boolean isEmpty()
    {
        return (top==-1);
    }
    public boolean isFull()
    {
        return (top+1==capacity);
    }
    public void push(int item)
    {
        if (!isFull()) 
        {
            stack[++top]= item;
            System.out.println("Pushed " + item + " onto the stack.");
        } else 
        System.out.println("Stack overflow! Cannot push item.");
    }
    public void pusher(int item)
    {
        stack[++top]=item;
    }
    public void pop() 
    {
        if (!isEmpty()) 
        {
            int poppedItem = stack[top--];
            System.out.println("Popped " + poppedItem + " from the stack.");
        } else 
        System.out.println("Stack underflow! Cannot pop item.");
    }
    public void peek() 
    {
        if (!isEmpty()) 
        System.out.println("Top item on the stack: " + stack[top]);
        else 
        System.out.println("Stack is empty.");
    }
    public void display() 
    {
        if (!isEmpty()) 
        {
            System.out.println("Stack contents:");
            for (int i = top; i >= 0; i--) 
            System.out.println(stack[i]);
            
        } else 
        System.out.println("Stack is empty.");
    }
}
class StackOp 
{
    public static void main(String[] args) 
    {
        Scanner scanner = new Scanner(System.in);
        System.out.print("Enter the capacity of the stack: ");
        int capacity = scanner.nextInt();
        Stack stack = new Stack(capacity);
        if (capacity-2>0){
        System.out.println("Enter the first " + (capacity-2) + " elements:");
        for (int i=0; i<capacity-2; i++)
        {
            int y=scanner.nextInt();
            stack.pusher(y);    
        }
        stack.display();
        }
        while (true) 
        {
            System.out.println("\nMenu:\n1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\nEnter your choice:");
            int choice = scanner.nextInt();
            switch (choice) {
                case 1:
                    System.out.print("Enter item to push: ");
                    int item = scanner.nextInt();
                    stack.push(item);
                    break;
                case 2:
                    stack.pop();
                    break;
                case 3:
                    stack.peek();
                    break;
                case 4:
                    stack.display();
                    break;
                case 5:
                    System.out.println("Exiting program.");
                    scanner.close();
                    System.exit(0);
                default:
                    System.out.println("Invalid choice. Please select a valid option.");
            }
        }
    }
}