import java.util.*;
import java.io.*;
public class LinkedList
{
   int n;
   ListNode start;
   ListNode rear;

// You can set debug=true when you are debugging and want
// to print out what your program is doing.
// Please leave your debugging messages in your code when
// you submit it. Change debug back to false before
// submitting your code.
   static final boolean debug= true;

   public LinkedList()
   {
       n= 0;
       start= null;
       rear= null;
   }
   public LinkedList(int size, ListNode first, ListNode last)
   {
       n= size;
       start= first;
       rear= last;
   }

   public static LinkedList readBigInteger(Scanner in)
   {
       LinkedList x;
       x= new LinkedList();
       int sizeN = readInteger(in);
        if (sizeN==-1){ //illegal integer input
             return null;
        }                            
        x.n = sizeN;
        for (int i=0; i<sizeN;i++){
            if (x.start==null){
                ListNode first = new ListNode(readInteger(in),null);
                x.start = first;
                x.rear = first;
            }else{
                ListNode nodeFrontAppend = new ListNode(readInteger(in),x.start);
                x.start = nodeFrontAppend;
            }
        }
        return(x);
   }
   public void reverse(int level)
   {
      Test.checkList(this); // Do not remove or move this statement.
        if (this.n<=1){ //list is down to base level
            return;
        }else{      // we got some breaking up to do!
            LinkedList l1 = new LinkedList(this.n/2,this.start,null);
            LinkedList l2 = new LinkedList(this.n/2 + this.n%2, null, this.rear);
            ListNode current = this.start;
            for (int i = 1; i < this.n/2; i++){
                current = current.next; 
            }
            l1.rear = current;
            l2.start = current.next;
            l1.rear.next = null; //fully separates the two lists

            l1.reverse(level + 1);
            l2.reverse(level + 1);

            this.start = l2.start;
            this.rear = l1.rear;
            l2.rear.next = l1.start;
        }
   }

   public int compare(LinkedList y){  
    int differenceFlag = 0;               
    ListNode currentX = this.start;
    ListNode currentY = y.start;
    
    //iterate through both lists, until you reach the end of one or both
    while (currentX != null && currentY != null){ 
      if (currentX.data > currentY.data){
        differenceFlag = 1;
      }
      if (currentX.data < currentY.data){
        differenceFlag = -1;
      }
      currentX = currentX.next;
      currentY = currentY.next;
    }
    /*
    iterates through the list from least significant to most significant digit value.
    differenceFlag variable remembers the last comparison and it's result
    as you iterate through, if the value of difference flag needs to change, it forgets the
    past value and replaces it with the more siginificant digit's result
    */
    
    /*
    The following two if statements will run if one list is longer than the other.
    Then it will iterate through that longer list, checking if any of the value's more 
    significant digits are nonzero. If one of them is non zero, return
    */

    if (currentY != null && currentX == null){
      while(currentY != null){
         if (currentY.data > 0){
            return -1;
          }
          currentY = currentY.next;
      }
    }
    if (currentX != null && currentY == null){
      while(currentX != null){
        if(currentX.data > 0){
          return 1;
        }
        currentX = currentX.next;
      }  
    }
  return differenceFlag;
  }

/*
    This method returns:
    -1 if the bigInteger associated with the method is less than y
     0 if the bigInteger associated with the method is equal to y
    +1 if the bigInteger associated with the method is greater than y
*/ 

// Tries to read in a non-negative integer from the input stream.
// If it succeeds, the integer read in is returned. 
// Otherwise the method returns -1.
   public static int readInteger(Scanner in)
   {
       int n;

       try{
           n= in.nextInt();
           if (n >=0) return(n);
           else return(-1);
       }
       catch(Exception e)
       {
//        We are assuming legal integer input values are >= zero.
          return(-1);
       }
   }

// You can use this in order to get nicer output
// (lined up in columns).

   public void printBigInteger(int nDigit)
   {
        boolean leadingZero;
        ListNode current;
        int i;
        int n_extra;

        reverse(0);
        leadingZero= true;
        if (n < nDigit)
        {
            for (i=n; i < nDigit; i++)
                System.out.print(" ");
        }
        n_extra= n- nDigit;
        current= start;
        while (current != null)
        {
            if (leadingZero)
            {
                if (current.data != 0)
                   leadingZero= false;
            }
            if (leadingZero)
            {
               if (current.next == null) // value is 0.
                   System.out.print(current.data);
               else if (n_extra <= 0)
                   System.out.print(" ");
            }
            else
            {
                System.out.print(current.data);
            }
            n_extra--;
            current= current.next;
        }
        reverse(0);
   }
} 
