// Author: Dylan Chohan
// Created on Oct 4, 2026
//
#define _POSIX_C_SOURCE 200809L
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
  char *text = NULL;
  size_t size = 0;
  char *arr[5] = {NULL};
  int total = 0;

  while (1) {
    // get text frome user
    printf("Please enter some text: ");
    ssize_t num_char = getline(&text, &size, stdin);

    // error handling
    if (num_char == -1) {
      perror("getline failed");
      exit(EXIT_FAILURE);
    }

    // remove \n and replace with null terminator
    text[num_char - 1] = '\0';

    // put the inputted text into the correct index in array
    int currentIndex = 0;
    currentIndex = total % 5;

    // making sure spot is open for new text
    free(arr[currentIndex]);

    // put in the new line into corresponding index
    arr[currentIndex] = strdup(text);
    total++;

    // if "print" is inputted, print out the array
    if (strcmp(text, "print") == 0) {
      // checking how "full' the curent array is to determine size of for-loop
      int currentSize = 0;
      if (total < 5) {
        currentSize = total;
      } else {
        currentSize = 5;
      }

      // printing the array
      for (int i = 0; i < currentSize; i++) {
        printf("%s\n", arr[i]);
      }
    }
  }

  // free buffers
  for (int i = 0; i < 5; i++) {
    free(arr[i]);
  }
  free(text);
  return 0;
}
