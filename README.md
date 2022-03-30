# 算法笔记

### 线性表算法题总结
**双指针法**
- 删除给定值或重复值：定义两个指针，一个指向第一个元素，另一个指向第二个元素，均从左往右扫描，然后通过赋值覆盖掉要删除的元素
- 删除单链表的倒数第k个节点：指针p从左往右遍历，当遍历到第k个节点时，指针q开始从左往右遍历；当p遍历完链表时，此时q正好指向倒数第k个节点（此方法用于实现在未知链表长度时，使用双指针遍历链表一遍解决问题）；若已知链表长度n，则删除倒数第k个节点即删除第n-k+1个节点
- 删除单链表的中间节点：定义快慢指针，慢指针每移动一步，快指针移动两步。当快指针到达链表末尾时，慢指针就到达了中间节点
- 判断链表是否包含环：定义快慢指针，慢指针每移动一步，快指针移动两步。当快指针指向空指针时，说明链表中没有环；当快指针与慢指针相遇时，则说明快指针超过了慢指针一圈，说明链表中含有环
- 找到两条链表的相交节点：指针p和q分别遍历链表1和链表2，当指针p和q不相等时，循环执行：p遍历链表1，当链表1遍历完时，开始遍历链表2；q遍历链表2，当链表2遍历完时，开始遍历链表1；当p和q相等，即指向同一个节点时，说明两条链表相交，此时返回其中一个指针即可（寻找两个链表相交节点的核心在于：两个遍历的指针同时到达相交的节点）
- 合并两个有序单链表：指针p和q分别遍历链表A和B，若要构造非递减有序单链表，可使用尾插法，逐个比较p和q指向节点的数据域，将较小的节点用尾指针r链接到新链表的尾部。若一个链表遍历完，另一个链表存在未遍历的剩余节点，则将剩余节点直接链接在尾指针的尾部即可；若要构造非递增有序的单链表，可使用头插法实现

**单链表逆置问题**
- 主要通过改变指针的指向实现，主要方法：递归、迭代
- 整条单链表的逆置：本质就是开始节点和空指针之间的逆置，可定义三个指针pre、cur、nxt，pre指向cur的前驱节点，cur指向当前节点，nxt指向cur的后继节点。不断地移动这三个指针，将cur的指针域next指向pre，以实现逆转；注意逆置后，原来的开始节点变成尾节点，指针域为空
- 部分单链表的逆置：本质就是开始节点和另一个节点之间的逆置
- 每K个节点之间的逆置：部分单链表的逆置+递归

**回文串问题**
- 寻找回文串是从中间向两端扩展，判断回文串从两端向中间收缩
- 对于单链表，无法直接倒序遍历，可以先将链表逆置，然后再遍历

### 二叉树算法题总结
1. 二叉树的算法基本都是基于DFS和BFS，基本方法：通过栈进行迭代、使用递归
2. 是否能通过遍历一遍二叉树得到结果？
3. 是否可以定义一个递归函数，通过子问题（子树）的答案推导出原问题的答案？若涉及到子树信息，建议使用后续遍历
4. 凡是和递归相关的问题，基本都和二叉树相关
