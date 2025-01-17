#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>

void *Hello(void* param);  /* Thread function */
void *Hello2(void* param);  /* Thread function */
/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   long t_param = 10;
   pthread_t t1, t2;
    
   
   pthread_create(&t1, NULL, Hello, (void*) t_param);  
   pthread_create(&t2, NULL, Hello2, (void*) t_param);
   
   for(int i = 0;i < 5; i++){
      printf("%dM\n", i);
      sleep(1);
   }

   pthread_join(t1, NULL); //espera a thread terminar
   pthread_join(t2, NULL); //espera a thread terminar
   return 0;
}  /* main */

/*-------------------------------------------------------------------*/
void *Hello(void* param) { 
   long my_id = (long)param;
  
   for(int i = 0;i < my_id; i++){
      printf("%d Thread 1\n", i);
      sleep(1);
   }
   
   return NULL;
}  /* Hello */

void *Hello2(void* param) {  
   
   long my_id = (long)param;
   
   for(int i = 0;i < my_id; i++){
      printf("%d  Thread 2\n", i);
      sleep(1);
   }
   
   return NULL;
}  /* Hello */