#include <stdio.h>
using namespace std;

# define INF 1000000000

struct Node {
    int num;
    Node* next = NULL;
};
//代码应注意细节,链表很容易实现错
int main() {
    int a[5];
    while (scanf("%d%d%d%d%d", &a[0], &a[1], &a[2], &a[3], &a[4]) != EOF) {
        Node* head = new Node(), * first = new Node(), * tail = new Node();
        head->num = -INF;
        first->num = a[0];
        tail->num = INF;
        head->next = first;
        first->next = tail;
        for (int i = 1; i <= 4; i++) {
            Node* before = head, * cur = before->next, * after = cur->next;
            Node* p = new Node();
            p->num = a[i];
            while (cur) {
                if (a[i] >= cur->num) {
                    before = cur;
                    cur = after;
                    after = cur->next;
                }
                else {
                    before->next = p;
                    p->next = cur;
                    break;
                }
            }
        }
        Node* cur = head->next;
        for (int i = 0; i < 5; i++) {
            printf("%d ", cur->num);
            cur = cur->next;
        }
        printf("\n");
    }
    return 0;
}
