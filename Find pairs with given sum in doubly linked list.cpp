#include <bits/stdc++.h>
using namespace std;
class Node {
  public:
    int data;
    Node *next;
    Node(int value) {
        data = value;
        next = nullptr;
    }
};
void findPairsWithGivenSum(Node *head, int target) {
    unordered_map<int, Node *> visited;
    Node *currNode = head;
    bool found = false;
    while (currNode != nullptr) {
        int x = target - currNode->data;
        if (visited.find(x) != visited.end()) {
            cout << x << " " << currNode->data << endl;
            found = true;
        }
        visited[currNode->data] = currNode;
        currNode = currNode->next;
    }
    if (!found) {
        cout << "No pairs found." << endl;
    }
}
int main() {
    Node *head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(4);
    head->next->next->next = new Node(5);
    int target = 7;
    findPairsWithGivenSum(head, target);
    return 0;
}
