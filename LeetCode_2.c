#include <stddef.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

// Imagine each node as a train car with a value and a link to the next car.
// This function finds the station where two train lines meet, if they meet at all.
struct ListNode *findMeetingPoint(struct ListNode *headA, struct ListNode *headB) {
  // If one train line is empty, there's no meeting point, so we declare it with NULL.
  if (headA == NULL || headB == NULL) {
    return NULL;
  }

  // Let's count the cars in each train line.
  struct ListNode *trainA = headA;
  struct ListNode *trainB = headB;
  int trainALength = 0, trainBLength = 0;
  while (trainA != NULL) {
    trainA = trainA->next;
    trainALength++;
  }
  while (trainB != NULL) {
    trainB = trainB->next;
    trainBLength++;
  }

  // If one train line is longer, we need to move its engine forward
  // to match the starting point of the shorter line.
  int difference = abs(trainALength - trainBLength);
  trainA = headA;
  trainB = headB;
  if (trainALength > trainBLength) {
  	int i;
    for (i = 0; i < difference; i++) {
      trainA = trainA->next; // Move the longer train's engine
    }
  } else {
  	int i;
    for (i = 0; i < difference; i++) {
      trainB = trainB->next; // Move the shorter train's engine
    }
  }

  // Now both trains have the same starting point (virtually).
  // Let them travel together, car by car.
  while (trainA != NULL && trainB != NULL) {
    if (trainA == trainB) {
      return trainA; // Found the meeting point!
    }
    trainA = trainA->next;
    trainB = trainB->next;
  }

  // The trains reached the end without meeting. No intersection!
  return NULL;
}

