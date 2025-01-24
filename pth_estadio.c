#include <stdio.h>
#include <stdlib.h>
#include <pthread.h> 
#include <unistd.h>
#include <string.h> 

int publico = 0;
pthread_mutex_t mutex;

void *addPublico() { 
   int i; 
   
   for  (i = 1; i <= 200000; i++){
      pthread_mutex_lock(&mutex);
      publico++; 
      pthread_mutex_unlock(&mutex);
   } 
   return NULL;
} 

/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   printf("Gerenciador de entrada!!\n");
   printf("====================================\n");

   pthread_t t1, t2, t3, t4;
   
   pthread_mutex_init(&mutex, NULL);
   
   // Criação e execução das threads
   pthread_create(&t1, NULL, addPublico, NULL);  
   pthread_create(&t2, NULL, addPublico, NULL);  
   pthread_create(&t3, NULL, addPublico, NULL); 
   pthread_create(&t4, NULL, addPublico, NULL); 
   
   // Espera pela finalização das threads
   pthread_join(t1, NULL); 
   pthread_join(t2, NULL); 
   pthread_join(t3, NULL); 
   pthread_join(t4, NULL); 

   printf("=====================================\n");
   printf("Publico total: %d\n", publico);
   printf("Gerenciador de entrada finalizado!!\n");
   
   pthread_mutex_destroy(&mutex);
   return 0;
}  /* main */

 

