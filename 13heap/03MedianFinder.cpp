// 我怎么觉得这个最简单呢(雾)
// 不对, 插入如果是vector+二分, 那么移动就很麻烦; 链表好插入但不好二分查找
// 放进堆里感觉也不对, 中位数不在顶上

// 拆成两个堆！一个小于中位数的大顶堆，一个大于中位数的小顶堆
// 偶数个数时，一边一个；奇数个数时，规定为右边小顶堆的顶为中位数
class MedianFinder {
private:
    priority_queue<int, vector<int>, greater<int>>  minQ;   // 右边的小顶堆
    priority_queue<int, vector<int>, less<int>>     maxQ;   // 左边的大顶堆
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if(minQ.empty())
        {
            minQ.push(num);
        }
        // 现在保证了右边不为空，左边为空或左边数量小，应该左边加一个数
        else if(maxQ.empty() || maxQ.size()<minQ.size())
        {
            if(num<=minQ.top())
            {
                maxQ.push(num);
            }
            else
            {
                maxQ.push(minQ.top());
                minQ.pop();
                minQ.push(num);
            }
        }
        // 现在左右都不为空，且左右数量相等，应该右边加一个数
        else
        {
            if(num>=maxQ.top())
            {
                minQ.push(num);
            }
            else
            {
                minQ.push(maxQ.top());
                maxQ.pop();
                maxQ.push(num);
            }
        }
    }
    
    double findMedian() {
        if(maxQ.empty() || maxQ.size()<minQ.size())
        {
            return minQ.top();
        }
        else
        {
            return (minQ.top() + maxQ.top()) / 2.0;
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

// 法二：multiset，有序集合
// 用红黑树实现的，有序、支持迭代器遍历
// 中位数如上，(左+右)/2 || 右
// 注意！对于相等元素的处理！multiset会把最新的元素，插入到与其相等的元素的末尾
class MedianFinder {
private:
    multiset<int> arr;
    multiset<int> :: iterator left, right;
public:
    MedianFinder() : left(arr.end()), right(arr.end()) {}
    
    void addNum(int num) {
        int sz = arr.size();
        arr.insert(num);
        if(sz==0)
        {
            left = arr.begin();
            right = arr.begin();
        }
        else if(sz&1)
        {
            // 为奇数，加一个之后为偶数，左右要分开
            if(num<*left)   left--;
            else            right++;
        }
        else
        {
            // 为偶数，合拢
            if(num<*left)       right--;
            else if(num>=*right) left++; 
            else
            {
                // left <= num <right 时，是插在left和right之间的
                // left==right的时候反而是right的右边
                left++;
                right--;
            }
        }
    }
    
    double findMedian() {
        return (*left+*right)/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */