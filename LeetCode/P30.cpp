#include "LeetCode.h"

class Solution {
	static const int radix = 257;
	unsigned* hashS1 = NULL;
	unsigned* hashS2 = NULL;
	unsigned* hashL = NULL;
	unsigned* hashSub = NULL;
public:
	vector<int> findSubstring(string S, vector<string> &L) {
		int lenL = L[0].length(), sizeL = L.size(), len = lenL*sizeL;
		hashSub = new unsigned[L.size()];
		unsigned hashL = hashForL(L);
		hashForS(S, lenL, sizeL);

		sort(this->hashL, this->hashL + sizeL);
		vector<int> result;
		for (int i = 0; i < S.length(); ++i)
		{
			if (hashS1[i] == hashL && (i + len) <= S.length() && validate(i, lenL, sizeL))
				result.push_back(i);
		}
		return std::move(result);
	}

	bool validate(int Si, int lenL, int sizeL)
	{
		for (int i = 0; i < sizeL; ++i)
		{
			hashSub[i] = hashS2[Si];
			Si += lenL;
		}
		sort(hashSub, hashSub + sizeL);

		for (int i = 0; i < sizeL; ++i)
			if (hashSub[i] != hashL[i])
				return false;
		return true;
	}

	unsigned hashForL(vector<string> &L)
	{
		unsigned result = 0;
		unsigned * hash = new unsigned[L.size()];
		for (int i = 0; i < L.size();++i)
		{
			unsigned h = 0;
			for (auto ch : L[i])
			{
				h = h * radix + ch;
			}
			result += h;
			hash[i] = h;
		}
		this->hashL = hash;
		return result;
	}

	void hashForS(string& S, int lenL, int sizeL)
	{
		unsigned* hash1 = new unsigned[S.length() + 1];
		unsigned* hash2 = new unsigned[S.length() + 1];
		unsigned* hash3 = new unsigned[S.length() + 1];
		unsigned gap = 1, h = 0;
		for (int i = 0; i < lenL; ++i)
			gap *= radix;

		for (int i = 0; i < S.length(); ++i)
		{
			h = h*radix + S[i];
			hash1[i] = h;
		}

		for (int i = 0; i < S.length(); ++i)
		{
			int j = i + lenL - 1;
			if (j < S.length())
				hash2[i] = hash1[j] - (i > 0 ? hash1[i - 1] : 0) * gap;
			else
				hash2[i] = 0;
		}

		int len = lenL*sizeL;
		for (int i = 0; i < S.length(); ++i)
		{
			if (i + len <= S.length())
			{
				if (i < lenL)
				{
					h = 0;
					for (int j = i; j < i + len; j += lenL)
						h += hash2[j];
					hash3[i] = h;
				}
				else
				{
					int j = i - lenL;
					hash3[i] = hash3[j] - hash2[j] + hash2[j + len];
				}
			}
			else
				hash3[i] = 0;
		}

		this->hashS1 = hash3;
		this->hashS2 = hash2;
		delete hash1;
	}

	unsigned* hashForS2(string& S, int lenL)
	{
		unsigned* hash1 = new unsigned[S.length() + 1];

		for (int i = 0; i < S.length(); ++i)
		{
			int end = i + lenL;
			if (end <= S.length())
			{
				unsigned h = 0;
				for (int j = i; j < end; ++j)
				{
					h = h*radix + S[j];
				}
				hash1[i] = h;
			}
			else
				hash1[i] = 0;
		}
		return hash1;
	}
};


//int main()
//{
//	Solution sl;
//
//	string S("barfoothefoobarman");
//	vector<string> L = {"foo","bar"};
//
//	displayVector(sl.findSubstring(S,L));
//
//	string S2("aaaadabac");
//	vector<string> L2 = {"aa","ad"};
//	displayVector(sl.findSubstring(S2, L2));
//	//displayArray(sl.hashForS(S, 2, 2), S.length());
//	//cout << endl;
//	//displayArray(sl.hashForS2(S, 2), S.length());
//
//	PAUSE;
//}