
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


// 主要是复制random指针时，要建立原node和新node的对应关系
// 哈希表

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> map;    // 键：原node地址。值：新node地址。
        Node* cur = head;
        Node hair(0);
        Node* prev = &hair;

        // 先复制next部分
        while(cur)
        {
            Node* tmp = new Node(cur->val);
            map.insert({cur, tmp});
            prev->next = tmp;
            prev = tmp;
            cur = cur->next;
        }

        // 然后复制random部分
        Node* curOld = head;
        Node* curNew = hair.next;
        while(curOld)
        {
            Node* randomNew = 0;
            if(curOld->random)
            {
                auto it = map.find(curOld->random);
                randomNew = it->second;
            }
            
            curNew->random = randomNew;
            curOld = curOld->next;
            curNew = curNew->next;
        }

        return hair.next;
    }
};


// 不用遍历两次，遇到没建立的节点，就直接递归建立新节点
// 居然比我的遍历两遍还慢
class Solution {
public:
    unordered_map<Node*, Node*> map;

    Node* copyRandomList(Node* head) {
        // copy head这个节点
        if(head==0)
        {
            return nullptr;
        }

        if(map.count(head))
        {
            return map[head];
        }

        Node* cur = new Node(head->val);
        map.insert({head, cur});    // 要记得存啊喂

        cur->next = copyRandomList(head->next);
        cur->random = copyRandomList(head->random);

        return cur;
    }
};