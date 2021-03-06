/*
 * BStree.h
 *
 *  Created on: 2014-5-9
 *      Author: casa
 */

#ifndef BSTREE_H_
#define BSTREE_H_

#include <iostream>
using namespace std;

#include <malloc.h>

/*
 * 二叉树性质（二叉搜索树）：
 * 1，若节点的左子树不空，左子树中所有节点值均小于根节点
 * 2，若节点的右子树不空，右子树中所有节点值均大于根节点
 * 3，左右子树都是二叉树
 * 4，没有键值相等的节点
 * */

template <class Value>
class BStree {
public:
	//在此是相当于两个数据结构，外部数据结构和类是不一样的模板参数
	template <typename V>
	struct node{
		V value;
		node * left;
		node * right;
	};

public:
	BStree():root(0){
		cout<<"用特定的数据类型构造了空树！"<<endl;
		/* for test */
//		node<Value> *l1=(node<Value> *)malloc(sizeof(node<Value>));
//		l1->left=0;
//		l1->right=0;
//		l1->value=1;
//
//		node<Value> *r1=(node<Value> *)malloc(sizeof(node<Value>));
//		r1->left=0;
//		r1->right=0;
//		r1->value=4;
//
//		root=(node<Value> *)malloc(sizeof(node<Value>));
//		root->value=3;
//		root->left=l1;
//		root->right=r1;

	};

	virtual ~BStree(){};

public:
	node<Value> *getRoot(){
		return root;
	};

	bool Insert(node<Value> *p, Value value);
	bool Delete(Value value);
	bool Search(node<Value> *treenode,Value value,node<Value> *pa,node<Value> *&rt);

	int Display(node<Value> *root);

	void Recurse_PreorderTraverse(node<Value> *root);
	void Recurse_PostorderTraverse(node<Value> *root);
	void Recurse_InorderTraverse(node<Value> *root);

	void Iterate_PreorderTraverse(node<Value> *root);
	void Iterate_PostorderTraverse(node<Value> *root);
	void Iterate_InorderTraverse(node<Value> *root);

private:
	node<Value> * root;
};

//template <typename Value>
//BStree::node<Value> * BStree<Value>::
//getRoot(){
//	return root;
//}

//C++编译器不支持对模板的分离式编译，将成员函数的实现放在.h文件中
template <typename Value>
bool BStree<Value>::
Insert(node<Value> * p, Value value){
	node<Value> *n;
	if(!Search(p,value,0,n)){
		if(n==0){
			cout<<"给root节点存值！"<<endl;
			root=(node<Value> *)malloc(sizeof(node<Value>));
			root->value=value;
			root->left=0;
			root->right=0;
		}
		else{
			cout<<"I can't find the value"<<endl<<"now the node value is: "<<n->value<<endl;
			if(value<n->value){
				/* 加入到n的左孩子 */
				node<Value> *l=(node<Value> *)malloc(sizeof(node<Value>));
				l->value=value;
				l->left=0;
				l->right=0;
				n->left=l;
			}
			else{
				node<Value> *r=(node<Value> *)malloc(sizeof(node<Value>));
				r->value=value;
				r->left=0;
				r->right=0;
				n->right=r;
			}
		}
	}
	else{
		cout<<"the tree already has the value "<<value<<endl;
	}
	return true;
}

template <typename Value>
bool BStree<Value>::
Delete(Value value){
	return true;
}

/* 插入和删除都是先查找 */
template <typename Value>
bool BStree<Value>::
Search(node<Value> *treenode, Value value, node<Value> *pa, node<Value> *&rt){
	cout<<"search the tree!"<<endl;
	/* 如果树的节点为空，返回false */
	if(treenode==0){
		rt=pa;
//		cout<<"parent is: "<<rt->value<<endl;
		return false;
	}
	/* 如果等于树的根节点，返回成功 */
	else if(treenode->value==value){
		cout<<"find the tree node value!"<<endl;
		return true;
	}
	else{
		if(value<treenode->value){
			cout<<value<<"<"<<treenode->value<<endl;
			Search(treenode->left,value,treenode,rt);
		}
		else{
			cout<<value<<">"<<treenode->value<<endl;
			Search(treenode->right,value,treenode,rt);
		}
	}
}

template <typename Value>
int BStree<Value>::
Display(node<Value> *root){
	if(root==0){
		return 0;
	}
	else{
		cout<<"=========== tree node value is: "<<root->value<<endl;
		if(root->left!=0){
			Display(root->left);
		}
		if(root->right!=0){
			Display(root->right);
		}
	}
}

/* 二叉搜索树的遍历一般分为迭代方式和递归方式两种
 * 在迭代方式中，需要用栈模拟出递归的效果，其中前序和中序相似，但是后序有点不同
 *  */
template <typename Value>
void BStree<Value>::
Recurse_PreorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Recurse_InorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Recurse_PostorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Iterate_PreorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Iterate_InorderTraverse(node<Value> *root){

}

template <typename Value>
void BStree<Value>::
Iterate_PostorderTraverse(node<Value> *root){

}

#endif /* BSTREE_H_ */
