/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (head == nullptr || head->next == nullptr)
      return head;
    // first i need the length of the linked list and the last node
    int len = 0;
    ListNode *curr = head, *last;
    while (curr) {
      len++;
      last = curr;
      curr = curr->next;
    }
    // make sure the k is modded len
    k = k % len;
    ListNode *fast = head;
    ListNode *prev = nullptr;
    int diff = len - k;
    while (fast != nullptr && diff > 0) {
      prev = fast;
      fast = fast->next;
      diff--;
    }
    // the fast pointer is currently pointing to the node which will be the head
    // node now
    if (fast == nullptr)
      return head;
    // just change some node links and you will have your answer
    prev->next = nullptr;
    last->next = head;
    head = fast;

    return head;
  }
};