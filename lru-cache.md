[https://oj.leetcode.com/problems/lru-cache/](https://oj.leetcode.com/problems/lru-cache/)

SB解法：
``` cpp
class LRUCache
{
public:
	LRUCache(int capacity_) :capacity(capacity_){}

	int get(int key)
	{
		int value = -1;
		bool bang = false;
		for (deque<pair<int, int> >::iterator i = cache.begin(); i != cache.end(); i++)
		{
			if ((*i).first == key)
			{
				value = (*i).second;
				bang = true;
			}
		}
		if (bang){
			this->set(key, value);
		}
		return value;
	}

	void set(int key, int value)
	{
		// if key in cache
		bool in = false;
		for (deque<pair<int, int> >::iterator i = cache.begin(); i != cache.end(); i++)
		{
			if ((*i).first == key)
			{
				i = cache.erase(i);
				if (i == cache.end())
					break;
				in = true;
			}

		}

		if (!in){
			if (cache.size() == capacity)
				cache.pop_front();
		}

		cache.push_back(make_pair(key, value));
	}

	deque<pair<int, int> > cache;
	unsigned int capacity;
};

```
用unorder map（hash）和list做的较好解法

``` cpp
#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class LRUCache
{
public:
	LRUCache(int capacity_) :capacity(capacity_){}

	void touch(int key)
	{
		pair<int, int> i = *(index[key]);
		elem.erase(index[key]);
		elem.push_front(i);
		index[key] = elem.begin(); 
	}

	int get(int key)
	{
		if (!index.count(key))
			return -1;
		touch(key);
		return elem.begin()->second;
	}

	void set(int key, int value)
	{
		if (index.count(key))
		{
			touch(key);
			elem.begin()->second = value;
		}
		else{
			if (elem.size() >= capacity)
			{
				index.erase(elem.rbegin()->first);
				elem.pop_back();
			}
			elem.push_front(make_pair(key, value));
			index[key] = elem.begin();
		}
	}
private:
	unordered_map<int, list<pair<int, int> >::iterator > index;
	list<pair<int, int > > elem;
	unsigned int capacity;
};

int main(){
	LRUCache cache(1);
	cache.set(2, 1);

	cout << cache.get(2) << endl;
	cache.set(3, 2);
	cout << cache.get(2) << endl;
	cout << cache.get(3) << endl;
	getchar();

	return 0;
}
```
