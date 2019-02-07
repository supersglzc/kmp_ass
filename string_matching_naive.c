#include "string_matching.h"

int string_matching_naive(char *text, int N, char* pattern, int M){
	int occurence = 0;
	int match = 1;
	for (int i = 0; i < N; i ++){
		match = 1;
		for (int j = 0; j < M; j ++){
			//printf("%d %d\n", i, j);
			//printf("%d\n", times);
			if (text[i + j] != pattern[j]){
				match = 2;
				break;
			}else{
				match = 1;
			}

		}
		if (match == 1){
			occurence ++;
		}
	}

	return occurence;
}
