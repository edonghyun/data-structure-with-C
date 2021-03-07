int StrToCmpFun(void* ptr1, void* ptr2);

int StrToCmpFun(void* ptr1, void* ptr2)
{
   char *c = (char*)ptr1;
   char *d = (char*)ptr2;
   
   int a = strlen(c);
   int b = strlen(d);
   
   if( a>= b)
      return 1;
   else
      return -1;
   
}