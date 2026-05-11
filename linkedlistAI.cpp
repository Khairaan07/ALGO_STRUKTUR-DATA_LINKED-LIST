#include <iostream>
using namespace std;

// Definisi struktur node untuk Singly-Linked List
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Selama fast belum mencapai ujung (null) dan masih ada node berikutnya
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;          // slow maju 1 langkah
            fast = fast->next->next;    // fast maju 2 langkah
        }

        // Ketika fast sampai di ujung, slow pasti berada di tengah
        return slow;
    }
};

void printList(ListNode* node) {
    cout << "[";
    while (node != nullptr) {
        cout << node->val;
        if (node->next != nullptr) cout << ", ";
        node = node->next;
    }
    cout << "]" << endl;
}

// Fungsi utama untuk menjalankan program
int main() {
    Solution solusi;

    // Test Case 1: Jumlah node ganjil [1, 2, 3, 4, 5]
    ListNode* head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);

    cout << "Test Case 1 (Ganjil)" << endl;
    cout << "Input  : [1, 2, 3, 4, 5]" << endl;
    ListNode* hasil1 = solusi.middleNode(head1);
    cout << "Output : ";
    printList(hasil1); // Output yang diharapkan: [3, 4, 5]
    cout << "------------------------" << endl;

    // Test Case 2: Jumlah node genap [1, 2, 3, 4, 5, 6]
    ListNode* head2 = new ListNode(1);
    head2->next = new ListNode(2);
    head2->next->next = new ListNode(3);
    head2->next->next->next = new ListNode(4);
    head2->next->next->next->next = new ListNode(5);
    head2->next->next->next->next->next = new ListNode(6);

    cout << "Test Case 2 (Genap)" << endl;
    cout << "Input  : [1, 2, 3, 4, 5, 6]" << endl;
    ListNode* hasil2 = solusi.middleNode(head2);
    cout << "Output : ";
    printList(hasil2); // Output yang diharapkan: [4, 5, 6]
    cout << "------------------------" << endl;

    return 0;
}