#include <iostream>
#include<set>

using namespace std;

//快慢指针
//142. Linked List Cycle II (Medium)
/*
* 给定一个链表，如果有环路，找出环路的开始点
* 
* 输入样例：
*	3 → 2 → 0 → -4
*		 ↑			↓
*		 ↑←———←
* 输出：
*	节点2
*/


///Definition for singly - linked list.
struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) 
		: val(x),
		next(NULL)
	{}
};

/*
方法一：哈希表
思路：
	使用哈希表的方式来解决，
	每次遍历都放到哈希表里面,第一次出现重复的地方就是环的起点
*/

//时间复杂度：O(n), 空间复杂度O(n)
ListNode* detectCycle_1(ListNode* head)
{
	std::set<ListNode*> set;
	while (head)
	{
		if (set.count(head))
			return head;

		set.insert(head);
		head = head->next;
	}

	return nullptr;
}



//方法二：快慢指针 【慢慢理解】
/*
基本思路：
	slow走一步，fast走两步，如果有环，必定在环内slow==fast
	此时重置fast=head，slow已经在环里了，fast速度也改为走一步
	第二次相遇的节点就是环的起点

数学逻辑：
	链表长度 = 环入口前节点数a + 环的长度b;
	f的速度是s的两倍， 所以 f = 2s;
	第一次相遇f比s多走过n个环长度，所以 f = s + nb;
	=> f = 2nb, s = nb
	=> f和s分别走了 2nb，nb步

	而走到链表节点入口的步数为 a + nb,也就是我们的目标;
	第一次相遇后，s在环内的步数就是nb了，我们只需要在走a步就可以找到环的入口节点了
	此时从head到换的节点就是a步，将fast指向head，然后再次和s相遇则是环的起点
*/


ListNode* detectCycle_2(ListNode* head)
{
	if (!head)
		return nullptr;

	ListNode* slow = head;
	ListNode* fast = head;
	
	//是否存在环
	do
	{
		if (!fast || !fast->next)
			return nullptr;
		slow = slow->next;
		fast = fast->next->next;

	} while (slow != fast);

	//存在环，重置fast
	fast = head;

	//再次相遇
	while (fast !=  slow)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return fast;
}


