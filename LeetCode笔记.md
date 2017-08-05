# LeetCode笔记

###  查找两个节点的最低公共节点

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
     {
        while(true)
        {
            if(root->val < p->val && root->val < q->val)
                return lowestCommonAncestor(root->right, p, q);
            else if(root->val > p->val && root->val > q->val)
                return lowestCommonAncestor(root->left, p, q);
            else
                return root;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q)
     {
        if(root == nullptr || root == q || root == p) return root;
        TreeNode* left = lowestCommonAncestor(root->right, p, q);
        TreeNode* right = lowestCommonAncestor(root->left, p, q);
        if(left && right) return root;
        if(left == nullptr) return right;
        if(right == nullptr) return left;
    }

### 位操作

    int hammingDistance(int x, int y) {
        int cnt = 0;
        int n = x^y;
        while(n)
        {
            ++cnt;
            n &= n-1;
        }
        return cnt;
    }

> 利用 n & n-1 可以得到删除最低位1后的数字

   

### 判断链表是否回文

    bool isPalindrome(ListNode* head) {
        if(head == nullptr || head->next == nullptr) return true;
        if(head->next->next == nullptr) return head->next->val == head->val;
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        slow->next = reverseList(slow->next);
        slow = slow->next;
        while(slow != nullptr && head != nullptr)
        {
            if(slow->val != head->val) return false;
            slow = slow->next;
            head = head->next;
        }
        return true;
    }
    
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = nullptr;
        while(head)
        {
            ListNode* next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        return pre;
    }


就是利用 fast 和 slow 两个游标，利用步长的差异找到链表的中点，一分为二，翻转其中的一个链表，然后遍历比对查看是否回文

###
