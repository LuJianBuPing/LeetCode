#include "LeetCode.h"

struct Item{
	list<int>::iterator it;
	int data;
};

class LRUCache{
	unordered_map<int, Item> cacheTable;	//存放cache key和cache data的映射
	list<int> cacheList;		//一个FIFO队列
	int cacheSize;		//最大cache元素个数
public:
	LRUCache(int size){
		this->cacheSize = size;
	}

	bool contains(const int& key){
		return cacheTable.find(key) != cacheTable.end();
	}

	int get(int key){
		if (!contains(key))
			return -1;

		auto& item = cacheTable.find(key)->second;
		int val = item.data;

		cacheList.erase(item.it);
		cacheList.push_front(key);
		item.it = cacheList.begin();

		return val;
	}

	void set(int key, int data)
	{
		if (contains(key))
			cacheList.erase(cacheTable[key].it);
		else if (cacheList.size() >= cacheSize)
		{
			int rmkey = cacheList.back();
			cacheTable.erase(cacheTable.find(rmkey));
			cacheList.pop_back();
		}

		cacheList.push_front(key);
		Item item;
		item.it = cacheList.begin();
		item.data = data;
		cacheTable[key] = item;
	}
};
