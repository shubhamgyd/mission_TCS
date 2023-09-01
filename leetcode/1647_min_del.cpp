#include <iostream>

#ifndef H_binaryTree
#define H_binaryTree
#include <iostream>

template <class elemType>
struct nodeType
{
	elemType info;
	nodeType<elemType> *llink;
	nodeType<elemType> *rlink;
};

template <class elemType>
class binaryTreeType
{
public:
	const binaryTreeType<elemType> &operator=(const binaryTreeType<elemType> &);
	bool isEmpty();
	void inorderTraversal();
	void preorderTraversal();
	void postorderTraversal();
	int treeHeight();
	int treeNodeCount();
	int treeLeavesCount();
	void destroyTree();
	void setRoot(nodeType<elemType> *rootNode); // New member function
	binaryTreeType(const binaryTreeType<elemType> &otherTree);
	binaryTreeType();
	~binaryTreeType();
	void singleParent();
	void singleParent(nodeType<elemType> *p, int &count);

protected:
	nodeType<elemType> *root;

private:
	void copyTree(nodeType<elemType> *&copiedTreeRoot, nodeType<elemType> *otherTreeRoot);
	void destroy(nodeType<elemType> *&p);
	void inorder(nodeType<elemType> *p);
	void preorder(nodeType<elemType> *p);
	void postorder(nodeType<elemType> *p);
	int height(nodeType<elemType> *p);
	int max(int x, int y);
	int nodeCount(nodeType<elemType> *p);
	int leavesCount(nodeType<elemType> *p);
};

// constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType()
{
	root = NULL;
}

template <class elemType>
bool binaryTreeType<elemType>::isEmpty()
{
	return (root == NULL);
}

template <class elemType>
void binaryTreeType<elemType>::inorderTraversal()
{
	inorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::preorderTraversal()
{
	preorder(root);
}

template <class elemType>
void binaryTreeType<elemType>::postorderTraversal()
{
	postorder(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeHeight()
{
	return height(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeNodeCount()
{
	return nodeCount(root);
}

template <class elemType>
int binaryTreeType<elemType>::treeLeavesCount()
{
	return leavesCount(root);
}

template <class elemType>
void binaryTreeType<elemType>::copyTree(nodeType<elemType> *&copiedTreeRoot,
										nodeType<elemType> *otherTreeRoot)
{
	if (otherTreeRoot == NULL)
		copiedTreeRoot = NULL;
	else
	{
		copiedTreeRoot = new nodeType<elemType>;
		copiedTreeRoot->info = otherTreeRoot->info;
		copyTree(copiedTreeRoot->llink, otherTreeRoot->llink);
		copyTree(copiedTreeRoot->rlink, otherTreeRoot->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::inorder(nodeType<elemType> *p)
{
	if (p != NULL)
	{
		inorder(p->llink);
		std::cout << p->info << " ";
		inorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::preorder(nodeType<elemType> *p)
{
	if (p != NULL)
	{

		std::cout << p->info << " ";
		preorder(p->llink);
		preorder(p->rlink);
	}
}

template <class elemType>
void binaryTreeType<elemType>::postorder(nodeType<elemType> *p)
{
	if (p != NULL)
	{
		postorder(p->llink);
		postorder(p->rlink);
		std::cout << p->info << " ";
	}
}

template <class elemType>
const binaryTreeType<elemType> &binaryTreeType<elemType>::
operator=(const binaryTreeType<elemType> &otherTree)
{

	if (this != &otherTree) // avoid self-copy
	{
		if (root != NULL) // if the binary tree is not empty, destroy the binary tree
			destroy(root);
		if (otherTree.root == NULL) // otherTree is empty
			root = NULL;
		else
			copyTree(root, otherTree.root);
	} // end else

	return *this;
}

template <class elemType>
void binaryTreeType<elemType>::destroy(nodeType<elemType> *&p)
{
	if (p != NULL)
	{
		destroy(p->llink);
		destroy(p->rlink);
		delete p;
		p = NULL;
	}
}

template <class elemType>
void binaryTreeType<elemType>::destroyTree()
{
	destroy(root);
}

// copy constructor
template <class elemType>
binaryTreeType<elemType>::binaryTreeType(const binaryTreeType<elemType> &otherTree)
{
	if (otherTree.root == NULL) // otherTree is empty
		root = NULL;
	else
		copyTree(root, otherTree.root);
}

// destructor
template <class elemType>
binaryTreeType<elemType>::~binaryTreeType()
{
	destroy(root);
}

template <class elemType>
int binaryTreeType<elemType>::height(nodeType<elemType> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + max(height(p->llink), height(p->rlink));
}

template <class elemType>
int binaryTreeType<elemType>::max(int x, int y)
{
	if (x >= y)
		return x;
	else
		return y;
}

template <class elemType>
int binaryTreeType<elemType>::nodeCount(nodeType<elemType> *p)
{
	if (p == NULL)
		return 0;
	else
		return 1 + nodeCount(p->llink) + nodeCount(p->rlink);
}

template <class elemType>
int binaryTreeType<elemType>::leavesCount(nodeType<elemType> *p)
{
	if (p == NULL)
		return 0;
	else if ((p->llink == NULL) && (p->rlink == NULL))
		return 1;
	else
		return (leavesCount(p->llink) + leavesCount(p->rlink));
}

template <class elemType>
void binaryTreeType<elemType>::singleParent()
{
	int count = 0;
	singleParent(root, count);
	std::cout << "Number of nodes with only one child: " << count << std::endl;
}

// Implementation of the new member function to set the root node
template <class elemType>
void binaryTreeType<elemType>::setRoot(nodeType<elemType> *rootNode)
{
	root = rootNode;
}

template <class elemType>
void binaryTreeType<elemType>::singleParent(nodeType<elemType> *p, int &count)
{
	if (p == nullptr)
		return;

	if ((p->llink == nullptr && p->rlink != nullptr) || (p->llink != nullptr && p->rlink == nullptr))
		count++;

	singleParent(p->llink, count);
}

#endif

int main()
{
	binaryTreeType<int> tree;

	// Build the binary tree
	nodeType<int> *root = new nodeType<int>;
	nodeType<int> *node1 = new nodeType<int>;
	nodeType<int> *node2 = new nodeType<int>;
	nodeType<int> *node3 = new nodeType<int>;
	nodeType<int> *node4 = new nodeType<int>;

	root->info = 4;
	node1->info = 2;
	node2->info = 5;
	node3->info = 1;
	node4->info = 3;

	root->llink = node1;
	root->rlink = node2;
	node1->llink = node3;
	node1->rlink = node4;
	node2->llink = nullptr;
	node2->rlink = nullptr;
	node3->llink = nullptr;
	node3->rlink = nullptr;
	node4->llink = nullptr;
	node4->rlink = nullptr;

	tree.setRoot(root);

	// Test the singleParent function
	tree.singleParent();

	return 0;
}
