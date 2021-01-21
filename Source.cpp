#include <iostream>
#include <map>
#include<vector>
#include<fstream>
#include <utility>
#include <string>
using namespace std;
map <string, int> mp;
vector<pair<string, int> > vec;
typedef string Info;
struct Node // вузол дерева
{
	Node* left,
		* right;
	string info;
	int count;
};

Node* CreateTree(int nodeCount, int i)
{
	if (nodeCount == 0)
		return NULL;
	else
	{

		Node* newNode = new Node;
		newNode->info = vec[i++].first;
		newNode->count = vec[i++].second;

		int leftCount = nodeCount / 2;
		int rightCount = nodeCount - leftCount - 1;
		newNode->left = CreateTree(leftCount, i--);
		newNode->right = CreateTree(rightCount, i++);

		return newNode;
	}
}
void PrintTree(Node* root, int level);

int main()
{
	setlocale(0, "");

	ifstream f("1.txt");
	string word;
	int i = 0;
	while (f >> word)
	{
		mp[word]++;

	}

	map <string, int> ::iterator it = mp.begin();
	map <string, int> ::iterator mt = mp.begin();
	for (it = mp.begin(); it != mp.end(); ++it)
	{
		int max = -1;
		string cl;
		for (mt = mp.begin(); mt != mp.end(); ++mt)
		{
			if (mt->second > max) {
				max = mt->second;
				cl = mt->first;
			}

		}
		vec.push_back({ cl,max });
		mp[cl] = -1;
	}
	vec.push_back({ "five",1 });
	Node* root = CreateTree(5, 0);
	PrintTree(root, 0);
	cout << endl;
	system("pause");
	return 0;
}
void PrintTree(Node* root, int level)
{
	if (root != NULL)
	{
		PrintTree(root->right, level + 1);
		for (int i = 1; i <= level; i++)
			cout << " ";
		cout << root->info << ' ' << root->count + 1 << endl;
		PrintTree(root->left, level + 1);
	}
}
