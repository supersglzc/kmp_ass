#include "string_matching.h"

int string_matching_naive(char *text, int N, char* pattern, int M){
	int occurence = 0;
	int match = 1;
	for (int i = 0; i < N; i ++){
		for (int j = 0; j < M; j ++){
			if (text[i + j] == pattern[j]){
				match = 1;
			}else{
				match = 2;
				break;
			}
		}
		if (match == 1){
			occurence ++;
		}
	}
	return occurence;
}
