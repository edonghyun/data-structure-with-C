int int_compare(void* ptr1, void* ptr2);

int int_compare(void* ptr1, void* ptr2)
{
   if(*(int*)ptr1 >= *(int*)ptr2)
      return 1;
   
   else
      return -1;
      
} // integer compare