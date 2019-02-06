#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "string_matching.h"

void print_array(int *arr, int size){
  for (int i=0; i<size; i++){
    printf("%d ",arr[i]);
  }
  printf("\n");
}

void short_test (char *text, int N, char * pattern, int M){
	printf("text='%s', pattern='%s'\n", text, pattern);
	int result1 = string_matching_naive(text, N, pattern, M, 1);
	int result2 = string_matching_kmp(text, N, pattern, M, 1);
	printf("Number of occurrences: result1=%d, result2=%d\n", result1, result2);
}
void performance_test(){
	static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
	printf("You are getting into performance test!\n");
	for (int k = 0; k < 10; k ++){
		int n = rand() % (1000000 - 10000) + 10000; //generate an integer from 10000 to 1000000
		int m = 400;
	
		char * text =  malloc(n);
		for (int i = 0; i < n; i ++){
			int pos = rand() % (int)(sizeof(charset) - 1);
			text[i] = charset[pos];
		}

		char * pattern = malloc(m);
		for (int j = 0; j < m; j ++){
			int pos = rand() % (int)(sizeof(charset) - 1);
			pattern[j] = charset[pos];
		}
	
		int times1 = string_matching_naive(text, n, pattern, m, 2);
		int times2 = string_matching_kmp(text, n, pattern, m, 2);
		printf("The length of text is %d\n", n);
		printf("The length of pattern is %d\n", m);
		printf("The naive algorithm runs %d times\n", times1);
		printf("The kmp algorithm runs %d times\n\n", times2);
	
		free(text);
		free(pattern);
	}
}
void stress_test(int N, int M){
  static char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
  srand(time(NULL));   // Initialization, should only be called once.
  
  while (1) {
    int n = rand() % (N-3) + 3;      // Returns a pseudo-random integer between 3 and N.
	int m = rand() % M + 1; 
    
	char *text = malloc(n);
    for (int i=0; i<n; i++){
	  int pos = rand() % (int)(sizeof(charset) -1);
      text[i] = charset[pos];      
    }
	
	char *pattern = malloc(m);
    for (int i=0; i<m; i++){
	  int pos = rand() % (int)(sizeof(charset) -1);
      pattern[i] = charset[pos];      
    }
    
    printf("text='%s', pattern='%s'\n", text, pattern);
	
    int result1 = string_matching_naive(text, n, pattern, m, 1);
    int result2 = string_matching_kmp(text, n, pattern, m, 1);
    
    if (result1==result2)
      printf("OK\n");
    else {
      printf("Wrong answer: correct=%d, got instead=%d\n", result1, result2);
	  exit(0);
	}
	free(text);
	free(pattern);
  }  
}

int main(int argc, char **argv ){
  if ((argc < 4) && (argc != 2)){
    printf("To run: test <1> <text> <N> <pattern> <M>\n or test <2> <N> <M>\n or test <3>\n");
    return 0;
   }
   
   int mode = atoi(argv[1]);
   
   if (mode == 1){
	   if (argc < 6){
			printf("To run: test <1> <text> <N> <pattern> <M>\n");
			return 0;
	   }
	   char *text = argv[2];
	   int N = atoi(argv[3]);
	   char *pattern = argv[4];
	   int M = atoi(argv[5]);
	   printf("M=%d\n",M);
	   short_test(text, N, pattern, M);
	   return 0;
   }
   if (mode == 3){
	performance_test();
	return 0;	
   }	
   int N = atoi(argv[2]);
   int M = atoi(argv[3]);
   
   stress_test(N, M);
   
   return 0;
  
}
