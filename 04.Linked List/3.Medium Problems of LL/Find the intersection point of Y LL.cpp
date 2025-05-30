// Solution 1: Brute-Force

// Time Complexity: O(m*n)
// For each node in list 2 entire lists 1 are iterated. 
// Space Complexity: O(1)
// No extra space is used.

node* intersectionPresent(node* head1,node* head2) {
    while(head2 != NULL) {
        node* temp = head1;
        while(temp != NULL) {
            //if both nodes are same
            if(temp == head2) return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    //intersection is not present between the lists return null
    return NULL;
}

// Solution 2: Hashing

// Time Complexity: O(n+m)
// Iterating through list 1 first takes O(n), then iterating through list 2 takes O(m). 
// Space Complexity: O(n)
// Storing list 1 node addresses in unordered_set.

node* intersectionPresent(node* head1,node* head2) {
     unordered_set<node*> st;
    while(head1 != NULL) {
       st.insert(head1);
       head1 = head1->next;
    }
    while(head2 != NULL) {
        if(st.find(head2) != st.end()) return head2;
        head2 = head2->next;
    }
    return NULL;

}

// Solution 3: Difference in length

// Find the length of both lists.
// Find the positive difference between these lengths.
// Move the dummy pointer of the larger list by the difference achieved. This makes our search length reduced to a smaller list length.
// Move both pointers, each pointing two lists, ahead simultaneously if both do not collide.


// TC : O(2*max(l1, l2)) + O(abs(l1 - l2)) + O(min(l1, l2))
// SC : O(1)

int getDifference(node* head1,node* head2) {
     int len1 = 0,len2 = 0;
        while(head1 != NULL || head2 != NULL) {
            if(head1 != NULL) {
                ++len1; head1 = head1->next;
            }
            if(head2 != NULL) {
                ++len2; head2 = head2->next;
            }
            
        }
        return len1-len2;//if difference is neg-> length of list2 > length of list1 else vice-versa
}

//utility function to check presence of intersection
node* intersectionPresent(node* head1,node* head2) {
 int diff = getDifference(head1,head2);
        if(diff < 0) 
            while(diff++ != 0) head2 = head2->next; 
        else while(diff-- != 0) head1 = head1->next;
        while(head1 != NULL) {
            if(head1 == head2) return head1;
            head2 = head2->next;
            head1 = head1->next;
        }
        return head1;
}

// Solution 4: Optimised 

// TC : O(2*max(l1, l2))
// SC : O(1)

// Take two dummy nodes for each list. Point each to the head of the lists.
// Iterate over them. If anyone becomes null, point them to the head of the opposite lists and continue iterating until they collide.

node* intersectionPresent(node* head1,node* head2) {
    node* d1 = head1;
    node* d2 = head2;
    
    while(d1 != d2) {
        d1 = d1 == NULL? head2:d1->next;
        d2 = d2 == NULL? head1:d2->next;
    }
    
    return d1;
}
