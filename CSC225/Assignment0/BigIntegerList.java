import java.util.*;
import java.io.*;
/* This class is for creating a singly linked class of big integer nodes. */
/* Hand this in together with your LinkedList.java. */
class BigIntegerList
{
   int n; // Number of items in the list.
   BigIntegerNode start;
   BigIntegerNode rear;

// You can set debug=true when you are debugging and want
// to print out what your program is doing.
// Please leave your debugging messages in your code when
// you submit it. Change debug back to false before
// submitting your code.
   static final boolean debug= true;

   public BigIntegerList()
   {
       n=0;
       start= null;
       rear= null;
   }
   public static BigIntegerList readBigIntegerList(Scanner in)
   {
       int bIntListSize = LinkedList.readInteger(in);
       if (bIntListSize == -1){
        return null;
       }
       BigIntegerList problem = new BigIntegerList();
       problem.n = bIntListSize;
       BigIntegerNode bin = new BigIntegerNode(null,null);
       problem.start = bin;
       problem.rear = bin;
       bin.x = bin.x.readBigInteger(in);              // initalizes the first value of 
       BigIntegerNode current = bin;
       for(int i = 0; i < bIntListSize-1; i++){
          current.next = new BigIntegerNode(LinkedList.readBigInteger(in), null);
          current = current.next;
       }
       current.next = null;
       problem.rear = current;
       return(problem);
   }
   public void printBigIntegerList()
   {
    BigIntegerNode current = start;
    for (int i = 0; i < n; i++){
      if((i % 10 == 0) && i > 0){
        System.out.println();
      }
      current.x.printBigInteger(8);
      current = current.next;
    }
    System.out.println();
   }

   //pivot element is supposed to be in l2
   public void quickSort(int level)
   {
    if (this.n <= 1){
      return;
    }
    // The following block of code extracts the pivot from the list and null terminates it
    BigIntegerNode pivotNode = this.start;
    LinkedList pivot = pivotNode.x;
    this.start = start.next;
    pivotNode.next = null;
    BigIntegerNode currentThis = this.start;
    n--;
    /* 
       Create three new BigIntLists to store the Nodes
       l1 holds values less than the pivot,
       l2 holds values equal to the pivot,
       l3 holds values greater than the pivot

       These three Lists initially have only one item in them, a BigIntegerNode with the proper
       start and rear values for the node set up
    */
    BigIntegerList l1 = new BigIntegerList();
    BigIntegerList l2 = new BigIntegerList();
    BigIntegerList l3 = new BigIntegerList();

    // populate l2 with the pivotNode
    l2.start = pivotNode;
    l2.rear = pivotNode;
    l2.rear.next = null;
    l2.n = 1;

    // iterate through the intial list, sorting the respective Nodes into their proper sublists
    while (currentThis != null){
      int compareOutput = pivot.compare(currentThis.x);
      /* if the start points to the next item in the list, then does the former start item
      get garbage collected because nothing is pointing to it?
      */
      switch(compareOutput){
        case 1: //x is greater than y
          if (l1.start == null){
            l1.start = currentThis;
            l1.rear = currentThis;
            l1.n=1;
          }else{
            l1.rear.next = currentThis;
            l1.rear = currentThis;
            l1.n++;
          }
          break;
        case 0: // y and x are equal
          l2.rear.next = currentThis;
          l2.rear = currentThis;
          l2.n++;
          break;
        case -1: // y is greater than x
          if (l3.start == null){ 
            l3.start = currentThis;
            l3.rear = currentThis;
            l3.n=1;
          }else{
            l3.rear.next = currentThis;
            l3.rear = currentThis;
            l3.n++;
          }
          break;
      }
      if (currentThis.next == null){
        currentThis = null;
      }else{
      currentThis = currentThis.next;
      start = currentThis;
      n--;
      // null terminate rear values of the lists
      l1.rear.next = null;
      l2.rear.next = null;
      l3.rear.next = null;
      }
    }
    if (debug){
        System.out.println();
        debug(l1, l2, l3, level, pivot);
        System.out.println();
    }

    // recursive quicksort calls.      
    l1.quickSort(level+1);
    l3.quickSort(level+1);

    //new marriage code
    if(l1.start != null){
      currentThis = l1.start;
      l1.rear.next = l2.start;
      this.rear = l2.rear;
    }else{
      this.start = l2.start;
      this.rear = l2.rear;
    }
    if(l3.start != null){
      this.rear.next = l3.start;
      this.rear = l3.rear;
    }




    /*old marriage code
    if(l1.start.x == null && l2.start.x == null && l3.start.x == null){     //all empty lists
      start = pivotNode;                                               // unreachable
      rear = pivotNode;
      n = 1;
    }
    if(l1.start.x != null && l2.start.x == null && l3.start.x == null){    //only l1
      start = l1.start;
      l1.start.next = pivotNode;
      pivotNode.next = null;
      rear = pivotNode;
      n = l1.n + 1;
    }
    if(l1.start.x == null && l2.start.x != null && l3.start.x == null){   // only l2
      start = pivotNode;
      start.next = l2.start;
      rear = l2.rear;
      n = l2.n + 1;
    }
    if(l1.start.x == null && l2.start.x == null && l3.start.x !=null){   // only l3
      start = pivotNode;
      start.next = l3.start;
      rear = l3.rear;
      n = l3.n + 1;
    }
    if(l1.start.x != null && l2.start.x != null && l3.start.x == null){   // 1 & 2
      start = l1.start;
      start.next = pivotNode;
      pivotNode.next = l2.start;
      rear = l2.rear;
      n = l1.n + l2.n + 1;
    }
    if(l1.start.x != null && l2.start.x == null && l3.start.x != null){   // 1 & 3
      start = l1.start;
      start.next = pivotNode;
      pivotNode.next = l3.start;
      rear = l3.rear;
      n = l1.n + l3.n + 1;
    }
    if(l1.start.x == null && l2.start.x != null && l3.start.x != null){   // 2 & 3
      start = pivotNode;
      pivotNode.next = l2.start;
      l2.rear.next = l3.start;
      rear = l3.rear;
      n = l2.n + l3.n + 1;
    }
    if(l1.start.x != null && l2.start.x != null && l3.start.x != null){   // 1 & 2 & 3
      start = l1.start;
      start.next = pivotNode;
      pivotNode.next = l2.start;
      l2.start.next = l3.start;
      rear = l3.rear;
      n = l1.n + l2.n + l3.n + 1;
    }
    */
   }

   public static void debug(BigIntegerList l1, BigIntegerList l2, BigIntegerList l3, int level, LinkedList pivot){
      System.out.print("Pivot value ");
      pivot.printBigInteger(8);
      System.out.println();
      System.out.println("Level : " + level);
      System.out.print("Printing out List 1. List1.n = " + l1.n + "  ");
      l1.printBigIntegerList();
    
      System.out.print("Printing out List 2. List2.n = " + l2.n + "  ");
      l2.printBigIntegerList();

      System.out.print("Printing out List 3. List3.n = " + l3.n + "  ");
      l3.printBigIntegerList();
   }
}
