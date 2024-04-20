#include <stdbool.h>


bool canTrust(int** trustNetwork, int whispersCount, int rows, int from, int to) {
  return trustNetwork[from][to] == 1; 
}

int findTheJudge(int townSize, int** trustNetwork, int whispersCount, int* unusedArray) {
  // How many people trust each other.
  int trustCounts[townSize + 1];
  int i;
  for (i = 0; i <= townSize; i++) {
    trustCounts[i] = 0;
  }

  // For each whisper, one is added to the trusted person's popularity count.
  
  for (i = 0; i < whispersCount; i++) {
    trustCounts[trustNetwork[i][1]]++; 
  }

  for (i = 1; i <= townSize; i++) {
    if (trustCounts[i] == townSize - 1 && unusedArray[i - 1] == 0) {
      return i; // Found the judge!
    }
  }

  // No judge found. The town gossip might be wrong!
  return -1;
}

