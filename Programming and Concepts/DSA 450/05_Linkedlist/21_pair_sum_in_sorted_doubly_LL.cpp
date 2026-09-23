#include <bits/stdc++.h>
using namespace std;
#define nline "\n";

class Node {
public:
  int data;
  Node *next;

  Node(int x) {
    data = x;
    next = nullptr;
  }
};

/**
 * Naive Solution:
 *
 * Time complexity : O(n*n)
 * Space complexity : O(1)
 *
 * Brute force all the combinations
 *
 */

vector<vector<int>> givenSumPairs(Node *head, int target) {
  // code here

  vector<vector<int>> ans;

  Node *firstN = head;
  Node *secondN;

  while (firstN != nullptr) {

    secondN = firstN->next;

    while (secondN != nullptr) {

      if (firstN->data + secondN->data == target) {

        ans.push_back({firstN->data, secondN->data});
      }

      secondN = secondN->next;
    }

    firstN = firstN->next;
  }

  return ans;
}

/**
 * Better Solution :
 *
 * Time complexity : O(nLogn)
 * Space complexity : O(n)
 *
 * we use set to store all the node values and use it to search suitable second
 * value whch satisfies the target condition
 *
 */

vector<vector<int>> givenSumPairs2(Node *head, int target) {
  // code here

  vector<vector<int>> ans;

  set<int> st;

  Node *curr = head;

  while (curr != nullptr) {

    st.insert(curr->data);
    curr = curr->next;
  }

  Node *firstN = head;
  Node *secondN;

  while (firstN != nullptr) {

    int firstValue = firstN->data;
    int secondValue = target - firstValue;

    if (secondValue <= firstValue) {

      firstN = firstN->next;
      continue;
    }

    if (st.find(secondValue) != st.end()) {

      ans.push_back({firstValue, secondValue});
    }

    firstN = firstN->next;
  }

  return ans;
}

/**
 *
 * Efficient Solution:
 *
 * Time complexity : O(n)
 * Space complexity : O(1)
 *
 * Using two pointers
 * left and right
 */

vector<vector<int>> givenSumPairs(Node *head, int target) {
  // code here

  Node *left = head;
  Node *right;
  Node *curr = head;
  vector<vector<int>> ans;

  while (curr != nullptr) {

    right = curr;
    curr = curr->next;
  }

  while (left != right && left->prev != right) {

    int sum = left->data + right->data;

    // if sum and target matches the update both pointers
    // as the values are distinct
    if (sum == target) {
      ans.push_back({left->data, right->data});
      left = left->next;
      right = right->prev;
    }

    // if target is smaller than sum
    // we need to reduce the sum value
    // we update the right pointer to its prev
    else if (target < sum) {
      right = right->prev;
    }

    // else target is bigger than sum
    // we need higher values
    // we update the left pointer to its next
    else {
      left = left->next;
    }
  }

  // returning the final ans array
  return ans;
}

int main() { return 0; }