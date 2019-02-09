#include "string_matching.h"

int string_matching_naive(char *text, int N, char* pattern, int M){
	int occurence = 0;
	for (int i = 0; i < N; i ++){
		for (int j = 0; j < M; j ++){
			//printf("%d %d\n", i, j);
			//printf("%d\n", times);
			if (text[i + j] == pattern[j]){
				if(j == M - 1){
					occurence ++;
				}
			}else{
				break;
			}

		}
	
	}

	return occurence;
}
