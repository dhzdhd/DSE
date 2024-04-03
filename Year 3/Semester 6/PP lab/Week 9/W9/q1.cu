#include <stdio.h>
#include <cuda_runtime.h>
#include <device_launch_parameters.h>
#include <string.h>

#define MAX_SENTENCE_LENGTH 100
#define WORD_LENGTH 20

__global__ void wordCount(char* sentence, char* word, int* result, int SentenceLength, int wordLength) {
    int index = threadIdx.x + blockIdx.x * blockDim.x;
    int stride = blockDim.x * gridDim.x;
    int localCount = 0;

    for (int i = index; i <= SentenceLength - wordLength; i += stride) {
        bool wordFound = true;
        for (int j = 0; j < wordLength; j++) {
            if (sentence[i + j] != word[j]) {
                wordFound = false;
                break;
            }
        }
        if (wordFound) {
            localCount++;
        }
    }

    atomicAdd(result, localCount);
}

int main() {
    char sentence[MAX_SENTENCE_LENGTH] = "hello world hello hi hi hi hello";
    char word[WORD_LENGTH] = "hello";
    
    int result = 0;
    int senLen = strlen(sentence);
    int worLen = strlen(word);

    char* d_sentence, * d_word;
    int* d_result;

    cudaMalloc((void**)&d_sentence, MAX_SENTENCE_LENGTH * sizeof(char));
    cudaMalloc((void**)&d_word, WORD_LENGTH * sizeof(char));
    cudaMalloc((void**)&d_result, sizeof(int));

    cudaMemcpy(d_sentence, sentence, MAX_SENTENCE_LENGTH * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_word, word, WORD_LENGTH * sizeof(char), cudaMemcpyHostToDevice);
    cudaMemcpy(d_result, &result, sizeof(int), cudaMemcpyHostToDevice);

    wordCount << <(MAX_SENTENCE_LENGTH + 255) / 256, 256 >> > (d_sentence, d_word, d_result, senLen, worLen);

    cudaMemcpy(&result, d_result, sizeof(int), cudaMemcpyDeviceToHost);

    printf("The word '%s' appears %d times in the sentence.\n", word, result);

    cudaFree(d_sentence);
    cudaFree(d_word);
    cudaFree(d_result);

    return 0;
}