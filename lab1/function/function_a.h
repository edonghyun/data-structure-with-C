void* larger(void* dataPtr1, void* dataPtr2, int (*ptrToCmp)(void* ,void*));


void* larger(void* dataPtr1, void* dataPtr2, int (*ptrToCmp)(void* ,void*))
{
   if((*ptrToCmp)(dataPtr1,dataPtr2)>0)

      return dataPtr1;
   else
      return dataPtr2;
}//larger
