#include<iostream>
#include<list>
#include<unordered_set>
using namespace std;

class Solution1 {
public:
	class NfaState{

		list<pair<char, NfaState*>> links;
		list<NfaState*> elinks;
	public:
		int id;

		list<NfaState*> shift(char ch)
		{
			list<NfaState*> result;
			for (auto& link : links)
			{
				if (link.first == ch || (link.first == '.' && ch != 0))
					result.push_back(link.second);
			}
			return std::move(result);
		}

		list<NfaState*> shiftEpsilon()
		{
			list<NfaState*> result(elinks);
			list<NfaState*> result2;
			for (auto s : result)
			{
				if (s != this)
					result2.splice(result2.begin(), s->shiftEpsilon());
			}
			result.splice(result.begin(), result2);
			return std::move(result);
		}

		void addLink(char ch, NfaState* nextState)
		{
			links.push_back(pair<char, NfaState*>(ch,nextState));
		}

		void addEpsilonLink(NfaState* nextState)
		{
			elinks.push_back(nextState);
		}

		bool isTerminal()
		{
			return links.empty()&&elinks.empty();
		}
	};

	NfaState* makeNfa(const char* partten)
	{
		NfaState* rootState = new NfaState;
		NfaState* curState = rootState, *nextState;
		int i = 0;
		for (const char* p=partten;; ++p)
		{
			if (*p != '*')
			{
				nextState = new NfaState;
				nextState->id = ++i;
				curState->addLink(*p, nextState);

				if (*p == 0)
					break;
				else if (*(p + 1) == '*')
				{
					curState->addLink(*p, curState);
					curState->addEpsilonLink(nextState);
				}
				curState = nextState;
			}
		}
		return rootState;
	}

	bool isMatch(const char *s, const char *p) {
		NfaState* nfa_root= makeNfa(p);
		unordered_set<NfaState*> states = {nfa_root};

		for (const char* q = s;; ++q)
		{
			for (auto s : states)
			{
				list<NfaState*> sl = std::move(s->shiftEpsilon());
				for (auto s : sl)
					states.insert(s);
			}

			list<NfaState*> nextSteps;
			for (auto s : states)
				nextSteps.splice(nextSteps.begin(), std::move(s->shift(*q)));
			states.clear();
			for (auto s : nextSteps)
			{
				states.insert(s);
			}

			if (*q == 0) break;
		}

		bool match = false;
		for (auto s : states)
		{
			if (s->isTerminal())
				match = true;
		}
		return match;
	}
};

class Solution2 {
public:
	bool isMatch(const char *s, const char *p) {
		if (*p == 0)
			return *s == 0;

		if (*s == *p || (*p == '.'&&*s != 0))
		{
			if (*(p + 1) == '*')
				return isMatch(s, p + 2) || isMatch(s + 1, p);
			else
				return isMatch(s + 1, p + 1);
		}
		else
		{
			if (*(p + 1) == '*')
				return isMatch(s, p + 2);
			else
				return false;
		}
	}
};

class Solution {
	int lens = 0;
	int* matched;
	const char* s, *p;
public:
	int count;

	bool isMatch(const char *s, const char *p) {
		lens = strlen(s) + 1;
		int lenp = strlen(p) + 1;
		matched = new int[lens*lenp];
		memset(matched, 0, lens*lenp*sizeof(matched[0]));
		this->s = s; this->p = p;
		return tryMatch(0, 0);
	}

	bool tryMatch(int i, int j)
	{
		int pos = lens*j + i;
		if (matched[pos])
			return matched[pos] == 1;
		++count;
		if (p[j] == 0)
		{
			matched[pos] = s[i] ? 2 : 1;
			return s[i] == 0;
		}

		bool result;
		if (s[i] == p[j] || (p[j] == '.'&&s[i] != 0))
		{
			if (p[j+1] == '*')
				result = tryMatch(i, j + 2) || tryMatch(i + 1, j);
			else
				result = tryMatch(i + 1, j + 1);
		}
		else
		{
			if (p[j+1] == '*')
				result = tryMatch(i, j + 2);
			else
				result = false;
		}
		matched[pos] = result ? 1 : 2;
		return result;
	}
};

//int main()
//{
//	Solution sl;
//	cout << sl.isMatch("aca", "ab*a") << endl;
//	cout << sl.isMatch("aa", "a") << endl;
//	cout << sl.isMatch("aa", "aa") << endl;
//	cout << sl.isMatch("aaa", "a*") << endl;
//	cout << sl.isMatch("aab", "a*") << endl;
//	cout << sl.isMatch("aaa", "ab*a") << endl;
//	cout << sl.isMatch("aa", "a*b*c*d*e*f*h*i*") << endl;
//	cout << sl.isMatch("aa", ".*.*.*.*.*.*.*.*.*.*.*") << endl;
//	sl.count;
//	cout << sl.isMatch("baccbbcbcacacbbc", "c*.*b*c*ba*b*b*.a*") << endl;
//	cout << sl.count << endl;
//	system("pause");
//}