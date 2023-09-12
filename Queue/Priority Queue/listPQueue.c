// #include<stdio.h>
// #include<stdlib.h>


// void sortAssending(LList *ptr, int ele)
// {
//     NODE *temp = creatnode(ele);
//     if (ptr->head == NULL || ele < ptr->head->data)
//     {
//         temp->link = ptr->head;
//         ptr->head = temp;
//     }
//     else
//     {
//         NODE *cur = ptr->head;
//         NODE *pre = NULL;
//         while (cur != NULL && ele >= cur->data)
//         {
//             pre = cur;
//             cur = cur->link;
//         }
//         temp->link = pre->link;
//         pre->link = temp;
//     }
// }