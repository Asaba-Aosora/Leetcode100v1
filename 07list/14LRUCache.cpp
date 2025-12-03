// 最近最少使用缓存，要求函数 get 和 put 必须以 O(1) 的平均时间复杂度运行。
// 查找为O(1)--想到哈希。而最近最少使用的节点要被逐出，即维护一个链表，最近使用的放在头节点，超出容量时最后一个被逐出
// 维护一个双向链表，便于删除节点时，把前驱和后继连起来

// 双向链表
struct DLinkedList
{
    int key, val;
    DLinkedList* prev;
    DLinkedList* next;
    DLinkedList(): key(0), val(0), prev(nullptr), next(nullptr) {}    // 初始化成员列表
    DLinkedList(int _key, int _val): key(_key), val(_val), prev(nullptr), next(nullptr) {}    // 第二种构造函数等我用到的时候再回来写
};

class LRUCache {
    // 维护一个哈希表
    unordered_map<int, DLinkedList*> cache;
    DLinkedList* head;
    DLinkedList* tail;    // 哑节点，便于维护双向链表
    int capacity;   // 最大容量
    int size;       // 当前

public:
    LRUCache(int _capacity):capacity(_capacity), size(0) {
        head = new DLinkedList;
        tail = new DLinkedList;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        // get不增加节点数
        if(!cache.count(key))
        {
            return -1;
        }
        DLinkedList* cur = cache[key];
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
        return cur->val;
    }
    
    void put(int key, int value) {
        if(cache.count(key))
        {
            DLinkedList* cur = cache[key];
            cur->val = value;
            // 这里访问了，要移到最前面！！
            cur->prev->next = cur->next;
            cur->next->prev = cur->prev;
            cur->next = head->next;
            cur->prev = head;
            head->next->prev = cur;
            head->next = cur;
            return;
        }
        // 现在处理新添加节点
        DLinkedList* cur = new DLinkedList(key, value);
        // 在哈希表里添加这个数据
        cache.insert({key, cur});
        // 添加到最前面
        cur->next = head->next;
        head->next->prev = cur;
        head->next = cur;
        cur->prev = head;
        size++;
        while(size>capacity)
        {
            DLinkedList* tmp = tail->prev;
            tail->prev = tmp->prev;
            tmp->prev->next = tail;
            // 还要删哈希表里的数据！
            cache.erase(tmp->key);
            delete tmp;
            size--;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */