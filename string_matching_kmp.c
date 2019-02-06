#include "string_matching.h"

int string_matching_kmp(char *text, int N, char* pattern, int M, int type){
	int count = 0;
	int times = 0;
	int value = 0;
	int *overlap_list = overlap_array(pattern, M);
	if (type == 1){
		printf("overlap function: ");
		print_array(overlap_list,M);
	}
	//TODO - implement kmp search
	int j = 0;
	for(int i = 0; i < N; i ++){
		times ++;
		//printf("%d\n", times);
		if(text[i] != pattern[j]){
			if(j != 0){
				j = overlap_list[j - 1];
			
				i --;
				continue;
			}
			
		}else{
			if (j == M - 1){
				count ++;
				i -= overlap_list[j - 1] + 1;
				j = 0;
			}else{
				j ++;
			}
		}
	}

	


	free(overlap_list);
	if (type == 1){
		value = count;
	}else{
		value = times;
	}
	return value;
}


 /*
    General computation of an overlap function in linear time:
    overlap function of position i is a length
    of the longest suffix in substring pattern[0:i]
    which is at the same time a prefix of pattern[0:i]
    parameters - pattern: string to be preprocessed, M: pattern length
    return: an array with the values of an overlap function for each pattern position
 */
int * overlap_array(char* pattern, int M){
	int *ol_list = calloc(M, sizeof(int));    

    int pos = 1;  // first is always zero
    while (pos < M){
        int ol_prev = ol_list[pos - 1];

        if (pattern[pos] == pattern[ol_prev])
            ol_list[pos] = ol_prev + 1;
        else {
            int found = 0;
            int j = ol_prev;
            int curr_overlap = ol_prev;
            while (!found && j >= 1){
                if (pattern[pos] == pattern[j]){
                    found = 1;
                    ol_list[pos] = curr_overlap + 1;
				}
                else {// try extend a smaller prefix - based on pattern [ol[pos-1]]
                    curr_overlap = ol_list[j-1];
                    j = ol_list[j-1];
				}
			}
            if (!found) { // compare with the first
                if (pattern[pos] == pattern[0])
                    ol_list[pos] = 1;
			}
		}
        pos++;
	}
    return ol_list;
}
