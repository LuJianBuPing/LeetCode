#include "LeetCode.h"

struct Item{
	list<int>::iterator it;
	int data;
};

class LRUCache{
	unordered_map<int, Item> cacheTable;	//���cache key��cache data��ӳ��
	list<int> cacheList;		//һ��FIFO����
	int cacheSize;		//���cacheԪ�ظ���
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
