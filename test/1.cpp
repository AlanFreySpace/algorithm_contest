#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <stack>
using namespace std;


struct ListNode {
    int val;
 	struct ListNode *next;
 	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    /**
     * Note: 类名、方法名、参数名已经指定，请勿修改
     *
     *
     * 合并两个降序链表为一个升序链表
     * @param l1 ListNode类  降序链表
     * @param l2 ListNode类  降序链表
     * @return ListNode类
     */
    ListNode* MergeList(ListNode* l1, ListNode* l2) {
        // write code here
        ListNode *n1=l1,*n2=l2;
        int si=0;
        stack<int> s;
        while(n1!=NULL&&n2!=NULL){
            if(n1->val>n2->val){
                s.push(n1->val);
                si++;
                n1=n1->next;
            }
            else{
                s.push(n2->val);
                si++;
                n2=n2->next;
            }
        }
        while(n1!=NULL){
            s.push(n1->val);
            si++;
            n1=n1->next;
        }
        while(n2!=NULL){
            s.push(n2->val);
            si++;
            n2=n2->next;
        }
        ListNode *head;
        ListNode *now=head;
        for(int i=0;i<si;i++){
            now->val=s.top();
            s.pop();
            ListNode *next=new ListNode(0);
            now->next=next;
            now=next;
        }
        return head;
    }
};

int main(){
    int a1[4]={4,3,2,1},a2[4]={9,8,7,6};
    ListNode *l1,*l2;
    ListNode *now1=l1,*now2=l2;
    for(int i=0;i<4;i++){
        now1->val=a1[i];
        ListNode *next=new ListNode(0);
        now1->next=next;
        now1=next;
    }
    for(int i=0;i<4;i++){
        now2->val=a1[i];
        ListNode *next=new ListNode(0);
        now2->next=next;
        now2=next;
    }
    Solution sol;
    sol.MergeList(l1,l2);
}
