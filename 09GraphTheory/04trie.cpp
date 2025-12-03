// 前缀树 || 字典树

// "26叉树" + 结束标志
class Trie {
    vector<Trie*> children;
    bool is_end;

    Trie* searchPrefix(const string& word)
    {
        Trie* node = this;
        for(char ch: word)
        {
            ch = ch - 'a';
            if(node)
            {
                node = node->children[ch];
            }
            else
            {
                break;
            }
        }
        return node;
    }
public:
    Trie(): children(26), is_end(false) {}
    
    void insert(string word) {
        Trie* node = this;
        for(char ch: word)
        {
            ch = ch - 'a';
            if(node->children[ch]==nullptr)
            {
                Trie* tmp = new Trie();
                node->children[ch] = tmp;
                node = tmp;
            }
            else
            {
                node = node->children[ch];
            }
        }
        node->is_end = true;
    }
    
    // 以下两个函数有很大的相似之处, 区别仅在于 "是否到末尾"
    // 所以可以写一个函数, 返回查找的最后一个节点, 再判断
    bool search(string word) {
        Trie* node = searchPrefix(word);
        if(node && node->is_end)    return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        return searchPrefix(prefix) ? true : false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */