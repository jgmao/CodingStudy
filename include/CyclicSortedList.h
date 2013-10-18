//
//  CyclicSortedList.h
//  CodingStudy
//
//  Created by Guoxin Jin on 10/2/13.
//  Copyright (c) 2013 Guoxin Jin. All rights reserved.
//

#ifndef CodingStudy_CyclicSortedList_h
#define CodingStudy_CyclicSortedList_h
namespace study {
    class ListNode
    {
    public:
        int value;
        ListNode* next;
        
    };
    class CyclicSortedList
    {
    public:
        ListNode* head;
        int length;
        CyclicSortedList(){length=0;head = nullptr;}
        void insert(ListNode* item, int value)
        {
            ListNode* nd = new ListNode();
            nd->value = value;
            nd->next = nullptr;
            
            //empty case
            if (item==nullptr)
            {
                this->head = nd;
                this->length++;
                head->next = nd;
                return;
            }
            ListNode* prev = item;
            ListNode* cur = item->next;
            /*
            if (cur==nullptr)
            {
                if (prev->value>value)
                {
                    nd->next= prev;
                    prev->next = nd;
                }
                else
                {
                    prev->next = nd;
                    nd->next  = prev;
                }
                this->length++;
                return;
            }
            */
            while (cur!=item) {
                if (prev->value<= value && cur->value> value) break;
                if (prev->value> cur->value && (prev->value<= value || cur->value>value)) break;
            }
            nd->next =  cur;
            prev->next = nd;
            this->length++;
        }
    };
    
}


#endif
