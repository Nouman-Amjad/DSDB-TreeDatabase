/*
	Data Structure Semester Project
	Members:
	Nouman Amjad 21i-0853
	Zain Ul Abideen 21i-0747
	Moeez Muslim 21i-0490
*/

#include<iostream>
#include<fstream>
using namespace std;

class TNode
{
	int data;
public:
	TNode(int m, bool isLeaf)
	{
		data = m;
		leaf = isLeaf;
		num = 0;
		keys = new int[2 * data - 1];
		dArray = new TNode * [2 * data];
	}

	void splittingChild(int i, TNode* x) {
		TNode* temp = new TNode(x->data, x->leaf);
		temp->num = data - 1;

		for (int j = 0; j < data - 1; j++)
		{
			temp->keys[j] = x->keys[j + data];
		}
		if (!x->leaf) {
			for (int j = 0; j < data; j++)
				temp->dArray[j] = x->dArray[j + data];
		}

		x->num = data - 1;

		for (int j = num; j >= i + 1; j--)
			dArray[j + 1] = dArray[j];

		dArray[i + 1] = temp;

		for (int j = num - 1; j >= i; j--)
			keys[j + 1] = keys[j];

		keys[i] = x->keys[data - 1];

		num = num + 1;
	}


	void insertNotFull(int a) {
		int i = num - 1;

		if (leaf == true) {
			while (i >= 0 && keys[i] > a) {
				keys[i + 1] = keys[i];
				i--;
			}

			keys[i + 1] = a;
			num = num + 1;
		}
		else {
			while (i >= 0 && keys[i] > a)
				i--;

			if (dArray[i + 1]->num == 2 * data - 1) {
				splittingChild(i + 1, dArray[i + 1]);

				if (keys[i + 1] < a)
					i++;
			}
			dArray[i + 1]->insertNotFull(a);
		}
	}

	void traverse() {
		int i;
		for (i = 0; i < num; i++) {
			if (leaf == false)
				dArray[i]->traverse();
			cout << " " << keys[i];
		}

		if (leaf == false)
			dArray[i]->traverse();
	}

	int* keys;
	int num;
	TNode** dArray;
	bool leaf;

};


class BTree
{
	TNode* root;
	int m;
public:
	BTree(int m) :m(m)
	{
		root = NULL;
	}

	void Insert(int i)
	{
		if (root == NULL)
		{
			root = new TNode(m, true);
			root->keys[0] = i;
			root->num = 1;
		}
		else {
			if (root->num == 2 * m - 1) {
				TNode* temp = new TNode(m, false);

				temp->dArray[0] = root;

				temp->splittingChild(0, root);

				int i = 0;
				if (temp->keys[0] < i)
					i++;
				temp->dArray[i]->insertNotFull(i);

				root = temp;
			}
			else
				root->insertNotFull(i);
		}
	}
	void print()
	{
		root->traverse();
	}
};

template <class T>
class Node
{
public:
	T data;
	bool color; // 0 for black and 1 for red
	Node* left, * right, * parent;
	string leftadd, rightadd;
	string DataAdd;
	Node()
	{
		data = 0;
		color = 1; // by default color = RED
		left = right = parent = NULL;
	}
};


template <class T>
Node<T>* TreeInsertion(Node<T>* root, Node<T>* n)
{
	if (root == NULL)
	{
		return n;
	}
	else if (n->data < root->data)
	{
		root->left = TreeInsertion(root->left, n);
		root->left->parent = root;
	}
	else if (n->data > root->data)
	{
		root->right = TreeInsertion(root->right, n);
		root->right->parent = root;
	}
	return root;
}



template <class T>
class RedBlackTree
{
public:
	Node<T>* head;
	RedBlackTree()
	{
		head = NULL;
	}

	void leftRor(Node<T>* n)
	{
		if (n->right == NULL)
			return;
		else
		{
			Node<T>* m = n->right;
			n->right = m->left;

			if (m->left != NULL)
				m->left->parent = n;

			m->parent = n->parent;

			if (n->parent == NULL)
			{
				head = m;
			}
			else
			{
				if (n->parent->left == n)
					n->parent->left = m;
				else
					n->parent->right = m;
			}
			m->left = n;
			n->parent = m;
		}

	}

	void rightRor(Node<T>* n)
	{
		if (n->left == NULL)
			return;
		else
		{
			Node<T>* m = n->left;
			n->left = m->right;

			if (m->right != NULL)
			{
				m->right->parent = n;
			}

			m->parent = n->parent;

			if (n->parent == NULL)
			{
				head = m;
			}
			else
			{
				if (n->parent->left == n)
					n->parent->left = m;
				else
					n->parent->right = m;
			}
			m->right = n;
			n->parent = m;
		}
	}

	void insert(T n,string str)
	{
		Node<T>* temp= new Node<T>;
		temp->data = n;
		temp->DataAdd = str;
		if (head == NULL)
		{
			temp->color = 0;
			head = temp;
		}
		else
		{
			head = TreeInsertion(head, temp);	// Inserting  new Node

			// Fixing the RED BLACK TREE

			Node<T>* ptemp=NULL;	// parent of Temp
			Node<T>* gptemp = NULL;	// Grand parent of Temp
			Node<T>* utemp = NULL;	// Uncle of Temp
			ptemp = temp->parent;
			if (ptemp->color == 1)
			{
				gptemp = ptemp->parent;
				while ((ptemp != NULL) && (ptemp->color == 1))
				{

					if (ptemp == gptemp->right)
					{
						if (gptemp->left != NULL)
						{
							utemp = gptemp->left;
							if (utemp->color == 1)
							{
								ptemp->color = 0;
								utemp->color = 0;
								gptemp->color = 1;
								temp = gptemp;
							}
							else
							{
								if (ptemp->left == temp)
								{
									temp = ptemp;
									rightRor(temp);
								}
								ptemp->color = 0;
								gptemp->color = 1;
								leftRor(gptemp);
							}
						}
						else
						{
							if (ptemp->left == temp)
							{
								temp = ptemp;
								rightRor(temp);
							}
							ptemp = temp->parent;
							gptemp = ptemp->parent;
							ptemp->color = 0;
							gptemp->color = 1;
							leftRor(gptemp);
						}
					}
					else
					{
						if (gptemp->right != NULL)
						{
							utemp = gptemp->right;
							if (utemp->color == 1)
							{
								ptemp->color = 0;
								utemp->color = 0;
								gptemp->color = 1;
								temp = gptemp;
							}
							else
							{
								if (ptemp->right == temp)
								{
									temp = ptemp;
									leftRor(temp);
								}
								ptemp = temp->parent;
								gptemp = ptemp->parent;
								ptemp->color = 0;
								gptemp->color = 1;
								rightRor(gptemp);
							}
						}
						else
						{
							if (ptemp->right == temp)
							{
								temp = ptemp;
								leftRor(temp);
							}
							ptemp = temp->parent;
							gptemp = ptemp->parent;
							ptemp->color = 0;
							gptemp->color = 1;
							rightRor(gptemp);
						}
					}

				}
				
			}
			head->color = 0;
		}

	}

	void remove(T n)
	{
		
	}
	
};


#include <iostream>
#include <queue>
using namespace std;

template<class T>
struct AVLnode
{
	T data;
	AVLnode<T>* left;
	AVLnode<T>* right;
	int height;
	string DataAdd;
};

template<class T>
class AVL
{
public:
	AVLnode<T>* root;

	AVL()  // Constructor
	{
		this->root = NULL;
	}

	int calculateHeight(AVLnode<T>* nodeTemp)
	{

		if (nodeTemp->left && nodeTemp->right)
		{
			if (nodeTemp->left->height < nodeTemp->right->height)
			{
				return nodeTemp->right->height + 1;
			}
			else
			{
				return  nodeTemp->left->height + 1;
			}
		}
		else if (nodeTemp->left && nodeTemp->right == NULL)
		{
			return nodeTemp->left->height + 1;
		}
		else if (nodeTemp->left == NULL && nodeTemp->right)
		{
			return nodeTemp->right->height + 1;
		}
		return 0;
	}

	int balanceFactor(AVLnode<T>* nodeTemp)
	{
		if(nodeTemp != NULL)
		if (nodeTemp->left != NULL && nodeTemp->right != NULL)  // If both children exists
		{
			return nodeTemp->left->height - nodeTemp->right->height;
		}
		else if (nodeTemp->left && nodeTemp->right == NULL)  // If only left child exists
		{
			return nodeTemp->left->height;
		}
		else if (nodeTemp->left == NULL && nodeTemp->right)   // If only right child exists
		{
			return nodeTemp->right->height;
		}
		return 0 ;
	}

	AVLnode<T>* doubleLeftRotation(AVLnode<T>* nodeTemp)
	{
		AVLnode<T>* node1;
		AVLnode<T>* node2;

		node1 = nodeTemp;
		node2 = node1->left;

		node1->left = node2->right;
		node2->right = node1;

		return node2;
	}


	AVLnode<T>* doubleRightRotation(AVLnode<T>* nodeTemp)
	{
		AVLnode<T>* node1;
		AVLnode<T>* node2;

		node1 = nodeTemp;
		node2 = node1->right;

		node1->right = node2->left;
		node2->left = node1;

		return node2;
	}


	AVLnode<T>* rightLeftRotation(AVLnode<T>* nodeTemp)
	{
		AVLnode<T>* node1;
		AVLnode<T>* node2;
		AVLnode<T>* node3;

		node1 = nodeTemp;
		node2 = node1->right;
		node3 = node1->right->left;

		node1->right = node3->left;
		node2->left = node3->right;
		node3->left = node1;
		node3->right = node2;

		return node3;
	}

	AVLnode<T>* leftRightRotation(AVLnode<T>* nodeTemp)
	{
		AVLnode<T>* node1;
		AVLnode<T>* node2;
		AVLnode<T>* node3;

		node1 = nodeTemp;
		node2 = node1->left;
		node3 = node1->left->right;

		node1->left = node3->right;
		node2->right = node3->left;
		node3->right = node1;
		node3->left = node2;

		return node3;
	}

	AVLnode<T>* insertNode(AVLnode<T>* nodeTemp, T data,string s)
	{
		if (nodeTemp == NULL)  // create new node
		{
			AVLnode<T>* nodeCreated;
			nodeCreated = new AVLnode<T>;
			nodeCreated->data = data;
			nodeCreated->DataAdd = s;
			nodeTemp = nodeCreated;
			//cout << "Helloo " << endl;
			// Leaf Node
			nodeTemp->left = NULL;
			nodeTemp->right = NULL;

			nodeTemp->height = 1;
			/*if (root == NULL)
				root = nodeTemp;*/

			return nodeTemp;
		}
		else   // If node exists already
		{
			if (data < nodeTemp->data)
				nodeTemp->left = insertNode(nodeTemp->left, data,s);  // Left Traversal using recursion
			else
				nodeTemp->right = insertNode(nodeTemp->right, data,s);  // Left Traversal using recursion
		}

		nodeTemp->height = calculateHeight(nodeTemp);  // return height of node passed

		if (balanceFactor(nodeTemp) == 2 && balanceFactor(nodeTemp->left) == 1)
			nodeTemp = doubleLeftRotation(nodeTemp);

		else if (balanceFactor(nodeTemp) == -2 && balanceFactor(nodeTemp->right) == -1)
			nodeTemp = doubleRightRotation(nodeTemp);

		else if (balanceFactor(nodeTemp) == -2 && balanceFactor(nodeTemp->right) == 1)
			nodeTemp = rightLeftRotation(nodeTemp);

		else if (balanceFactor(nodeTemp) == 2 && balanceFactor(nodeTemp->left) == -1)
			nodeTemp = leftRightRotation(nodeTemp);

		return nodeTemp;
	}

	void levelorder()
	{
		if (this->root == NULL)
		{
			cout << "Tree is empty. Nothing to display\n";
			return;
		}
		else
			levelOrderFromNode(this->root);  // Pass root to the level order form node to treaverse complete tree
	}

	void levelOrderFromNode(AVLnode<T>* nodePassed)
	{
		queue <AVLnode<T>*> q;
		AVLnode<T>* current;
		q.push(nodePassed);
		q.push(NULL);

		while (!q.empty())
		{
			current = q.front();
			q.pop();
			if (current == NULL && q.size() != 0)
			{
				cout << "\n";

				q.push(NULL);
				continue;
			}
			if (current != NULL)
			{
				cout << " " << current->data;

				if (current->left != NULL)
					q.push(current->left);

				if (current->right != NULL)
					q.push(current->right);

			}
		}
	}

	AVLnode<T>* deleteNode(AVLnode<T>* nodeToDelete, T data)
	{
		if (nodeToDelete->left == NULL && nodeToDelete->right == NULL)  // Tree only has one node
		{
			if (nodeToDelete == this->root)
				this->root = NULL;
			delete nodeToDelete;
			return NULL;
		}

		AVLnode<T>* temp;

		if (nodeToDelete->data < data)
			nodeToDelete->right = deleteNode(nodeToDelete->right, data);

		else if (nodeToDelete->data > data)
			nodeToDelete->left = deleteNode(nodeToDelete->left, data);

		else
		{
			if (nodeToDelete->left != NULL)
			{
				temp = goRight(nodeToDelete->left);
				nodeToDelete->data = temp->data;
				nodeToDelete->left = deleteNode(nodeToDelete->left, temp->data);
			}
			else
			{
				temp = goLeft(nodeToDelete->right);
				nodeToDelete->data = temp->data;
				nodeToDelete->right = deleteNode(nodeToDelete->right, temp->data);
			}
		}

		// Cases for Deletion

		if (balanceFactor(nodeToDelete) == 2 && balanceFactor(nodeToDelete->left) == 1)
			nodeToDelete = doubleLeftRotation(nodeToDelete);
		else if (balanceFactor(nodeToDelete) == 2 && balanceFactor(nodeToDelete->left) == -1)
			nodeToDelete = leftRightRotation(nodeToDelete);
		else if (balanceFactor(nodeToDelete) == 2 && balanceFactor(nodeToDelete->left) == 0)
			nodeToDelete = doubleLeftRotation(nodeToDelete);
		else if (balanceFactor(nodeToDelete) == -2 && balanceFactor(nodeToDelete->right) == -1)
			nodeToDelete = doubleRightRotation(nodeToDelete);
		else if (balanceFactor(nodeToDelete) == -2 && balanceFactor(nodeToDelete->right) == 1)
			nodeToDelete = rightLeftRotation(nodeToDelete);
		else if (balanceFactor(nodeToDelete) == -2 && balanceFactor(nodeToDelete->right) == 0)
			nodeToDelete = doubleLeftRotation(nodeToDelete);

		return nodeToDelete;
	}

	AVLnode<T>* goRight(AVLnode<T>* nodeTemp)
	{
		while (nodeTemp->right != NULL)
			nodeTemp = nodeTemp->right;

		return nodeTemp;
	}

	AVLnode<T>* goLeft(AVLnode<T>* nodeTemp)
	{
		while (nodeTemp->left != NULL)
			nodeTemp = nodeTemp->left;

		return nodeTemp;
	}

};


