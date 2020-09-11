#ifndef __BST_CPP
#define __BST_CPP
#include "bst.h"
#include <iostream>
#include <queue>
#include <cmath>
// HELPER FUNCTIONS HERE...
template <class T>
BST<T>::BST(){
	root = NULL;
}

template <class T>
BST<T>:: ~BST(){

    node<T> *a = root;

    while (a != NULL){
        if (a->left != NULL) 
        { a =a->left;
        }
        if (a->right != NULL) 
            {a =a->right;
        delete a;
        a=NULL;
    }
    }
    // your destructor code goes here
}

template <class T>
int BST<T> :: height (node<T>* p){
   // your find height code goes here
    /*int l;
    int r;
    if(p->left!=NULL)
    {
        l=height(p->left);
    }
    else
    {
        l=0;
    }
    if(p->right!=NULL)
    {
        r=height(p->right);
    }
    else
    {
        r=0;
    }
    return (1+max(l,r));*/
     if (p == NULL){
    return 1;
   }
    p->height=std::max(height(p->right), height(p->left)) + 1;
    return p->height;
}

template <class T>
int BST<T> :: balanceFactor(node<T>* p){
    if(p==NULL)
    {
        return 0;
    }
	return (height(p->right)-height(p->left));
    // you can use this to find balance factor.
}

template <class T>
void BST<T> :: fixHeight(node<T>* p){
	 //p->height=height(p);
    // use this function to fix height of a node after insertion or deletion.
    //return;
   // int h1 = height(p->left);
    //int h2 = height(p->right);
    if(p==NULL)
    {
        return;
    }
    p->height = height(p);
}

// ROTATING HELPERS 
template <class T>
node<T>* BST<T> :: rotateleft(node<T>* p){
    // Rotate left code goes here.
    node<T> *m=p->right;
    p->right=m->left;
    m->left=p;
    fixHeight(p);
    fixHeight(m);
    p=m;
    return p;
}

template <class T>
node<T>* BST<T> :: rotateright(node<T>* p){
    // Rotate right code goes here
    node<T> *m=p->left;
    p->left=m->right;
    m->right=p;
    fixHeight(p);
    fixHeight(m);
    p=m;

    return p;
}

template <class T>
node<T>* BST<T> :: balance(node<T>* p){    
    fixHeight(p);
    /*node<T>*b=p;
    node<T>*l;
    bool chk=false;
    bool chk2=false;
    while(b!=NULL)
    {
        if(abs(balanceFactor(b))>1)
        { 
        if(abs(balanceFactor(b->left))>1)
        {
            b=b->left;
        }
        else if(abs(balanceFactor(b->right))>1)
        {
            b=b->right;
        }
        else
        {
            chk=true;
            break;
        }
        }
        else
        {
            chk=false;
            break;
        }
    }
    if(chk==true)
    {
    if(b!=p)
        chk2=false;
    else
        chk2=true;*/
    if(p==NULL)
    {
        return NULL;
    }
    if(abs(balanceFactor(p))>1)
    {
        if(balanceFactor(p)>1)
        {
            if(height(p->right->right)>=height(p->right->left))
            {
                return rotateleft(p);
            }
            else
            {
                p->right=rotateright(p->right);
                return rotateleft(p);
            }

        }
        else if(balanceFactor(p)<-1)
        {
            if(height(p->left->left)>=height(p->left->right))
            {
                return rotateright(p);
            }
            else
            {
                p->left=rotateleft(p->left);
                return rotateright(p);
            }
        }
    }
   /* if(chk2==false && chk==true)
    {
        fixHeight(p);
        return p;
    }
    else if(chk2==true && chk==true)
    {
        fixHeight(l);
        return l;
    }
    }*/
    
    else
    {
        return p;
    }
    // Balancing code goes here. You might need to find balance factor and call appropriate rotations.
}
// CLASS FUNCTIONS HERE
template <class T>
void BST<T> :: insert(string value,T k){
    root = insertHelper(value,k,root);
}
// insertion helper
template <class T>
node<T>* BST<T> :: insertHelper(string value,T k, node<T> *p) { // note we need a helper because we need recursive calls
    // Insertion code goes here.
    if(p==NULL)
    {
        node<T> *x=new node<T>(k,value);
        p=x;
    }
    else if(p->key>k)
    {
        p->left=insertHelper(value,k,p->left);
    }
    else if(p->key<k)
    {
        p->right=insertHelper(value,k,p->right);
    }
    //return p;
   return balance(p);
}
template<class T>
node<T>* BST<T> :: search(T key){
    // Search code goes here.
    node<T>* p=root;
    while(p!=NULL)
    {
        if(p->key<key)
        {   
           p=p->right; 
        }
        else if(p->key>key)
        {
            p=p->left;
        }
        else
        {
            return p;
        }
    }
    return NULL;

}
// DELETE HELPER FUNCTIONS
template<class T>
node<T>* BST<T> :: findmin(node<T> *p){
    // This function finds the min node of the tree.
    if(p==NULL)
    {
        return NULL;
    }
    else if(p->left==NULL)
    {
        return p;
    }
    return findmin(p->left);
}

template<class T>
node<T>* BST<T>::removemin(node<T>* p) {
   // return balance(p);
    // This function recursively finds the min node and deletes it.
    if (p == NULL) {
        return NULL;
    }
    else if (p->left == NULL) {
        node<T> *t = p->right;
        delete t;
        return p->right;
    }
    else {
        p->left = removemin(p->left);
    }
    return balance(p);
    //return p;
    
}

template<class T>
void BST<T>::delete_node(T k){
    root = remove(root, k);
}

template<class T>
node<T>*  BST<T>::remove(node<T>* p, T k) // k key deletion from p tree
{
   // return balance(p);
    // This function uses findmin and deletemin to delete arbitrary node in the tree.
   node<T> *cur=root;
    node<T> *prev=NULL;
    while(cur!=NULL)
    {   
        if(k>cur->key)
        {   
            prev=cur;
            cur=cur->right;
        }
        else if(k<cur->key)
        {
            prev=cur;
            cur=cur->left;
        }
        else
        {
            break;
        }
    }
    if(prev!=NULL && cur!=NULL)
    {    
    if(cur->left!=NULL && cur->right!=NULL)
    {
        node<T> *n=findmin(cur->right);
        cur->value=n->value;
        cur->key=n->key;
        if(cur->right->left!=NULL)
        {
            node<T>*b=removemin(cur->right);
        }
        else
        {
            node<T>*temp=cur->right;
            cur->right=cur->right->right;
            delete temp;
        }
    }
    else if(cur->left!=NULL && cur->right==NULL)
    {   
        if(cur->key>prev->key)
        {    
        node<T> *temp=cur;
        prev->right=cur->left;
        delete temp;
        }
        else
        {
        node<T> *temp=cur;
        prev->left=cur->left;
        delete temp;
        }
    }
    else if(cur->left==NULL && cur->right!=NULL)
    {   
        if(cur->key>prev->key)
        {
        node<T> *temp=cur;
        prev->right=cur->right;
        delete temp;
        }
        else
        {
        node<T> *temp=cur;
        prev->left=cur->right;
        delete temp;
        }
    }
    else if(cur->left==NULL && cur->right==NULL)
    {
        if(cur->key>prev->key)
        {
            delete cur;
            prev->right=NULL;
        }
        else
        {
            delete cur;
            prev->left=NULL;
        }
    }
    }
    else if((prev==NULL && cur==NULL))
    {
        return NULL;
    }
    else if(prev==NULL && cur!=NULL)
    {
        if(cur->left!=NULL && cur->right!=NULL)
    {
        node<T> *n=findmin(cur->right);
        cur->value=n->value;
        cur->key=n->key;
        if(cur->right->left!=NULL)
        {
            node<T>*b=removemin(cur->right);
        }
        else
        {
            node<T>*temp=cur->right;
            cur->right=cur->right->right;
            delete temp;
        }
    }
    else if(cur->left!=NULL && cur->right==NULL)
    {   
        
        node<T> *temp=cur;
        p=cur->left;
        delete temp;
    }
     else if(cur->left==NULL && cur->right!=NULL)
    {   
        
        node<T> *temp=cur;
        p=cur->right;
    }
    else if(cur->left==NULL && cur->right==NULL)
    {
        delete cur;
        p=NULL;
    }

    }
    //return balance(cur);
    return balance(p);
    
   /*if (p == NULL) {
        return NULL;
    }
    else if (k < p->key) {
        p->left = remove(p->left, k);
    }
    else if (k > p->key) {
        p->right = remove(p->right, k);
    }
    else if(p==NULL)
    {
        return p;
    }
    if (k == p->key){
        if(p->right != NULL && p->left != NULL){
            node<T> *m = findmin(p->right); 
            m->right = removemin(p->right); 
            m->left = p->left; 
            return balance(m); 
        }
        else if(p->right == NULL) {
            node<T> *t = p->left;
            delete t;
            return p->left;
        }
        else if(p->left == NULL) {
            node<T> *t = p->right;
            delete t;
            return p->right;
        }
        else if (p->left == NULL && p->right == NULL)
        {
            delete p;
            p = NULL;
        }
    }
    return balance(p);
   /* node<T>* l;
    if( p== NULL )
    return NULL; // Item not found; do nothing
    
    if( k < p->key )
    l=remove( p->left,k );
    else if( p->key < k)
    l=remove( p->right,k );
    else if( p->left != NULL && p->right != NULL ) // Two children
    {
    l= findmin( p->right );
    p->key=l->key;
    p->value=l->value;
    l=remove(  p->right ,p->key);
    return balance(l);
    }
    else
    {
    l= p;
    p = ( p->left != NULL ) ? p->left : p->right;
    delete l;
    }/*

    return balance(p);*/
   
}
template<class T>
node<T>* BST<T>::getRoot(){
    return root;
}
#endif
