
/* This class defines a list node for a singly linked list of big integers.
   Do not insert any code into this class.
   The automated testing of your program will include this code as
   it is given here.
*/
class BigIntegerNode{

   public LinkedList x;
   public BigIntegerNode next;

   public BigIntegerNode(LinkedList y, BigIntegerNode ptr)
   {
       x= y;
       next= ptr;
   }
}

