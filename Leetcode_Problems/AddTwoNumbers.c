//PREPROCESSOR DIRECTORIES/MAIN FUCCTION NOT PRESENT//

https://leetcode.com/problems/add-two-numbers/description/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    
    struct ListNode *temp1=l1;
    struct ListNode *temp2=l2;
    struct ListNode *sum;
    struct ListNode *temp3;
    struct ListNode *temp4=NULL;

    int carry=0,x,flag=0;

    while(temp1!=NULL&&temp2!=NULL)
    {
        temp3=malloc(sizeof(struct ListNode));
        x=(temp1->val+temp2->val+carry);
        if(x<10)
        {
            temp3->val=x;
            carry=0;
        }
        else
        {
            temp3->val=x%10;
            carry=1;
        }

        if(flag!=1)
        {
            sum=temp3;
            flag=1;
        }
        
        if(temp4!=NULL)
        {
            temp4->next=temp3;
        }
        temp3->next=NULL;
        temp1=temp1->next;
        temp2=temp2->next;
        temp4=temp3;

    }
    while(temp1!=NULL)
    {
        temp3=malloc(sizeof(struct ListNode));
        x=(temp1->val+carry);
        if(x<10)
        {
            temp3->val=x;
            carry=0;
        }
        else
        {
            temp3->val=0;
            carry=1;
        }
        temp4->next=temp3;
        temp4=temp3;
        temp3->next=NULL;
        temp1=temp1->next;
    }
    while(temp2!=NULL)
    {
        temp3=malloc(sizeof(struct ListNode));
        x=(temp2->val+carry);
        if(x<10)
        {
            temp3->val=x;
            carry=0;
        }
        else
        {
            temp3->val=0;
            carry=1;
        }
        temp4->next=temp3;
        temp4=temp3;
        temp3->next=NULL;
        temp2=temp2->next;
    }
    if(carry==1)
    {
        temp3=malloc(sizeof(struct ListNode));
        temp3->val=1;
        temp4->next=temp3;
        temp3->next=NULL;
    }
    return sum;
}
