// File:  redblacktree.cpp

#ifdef _REDBLACKTREE_H_

template <class T>
Node<T>* RedBlackTree<T>::CopyTree(Node<T>* thisnode, Node<T>* sourcenode, Node<T>* parentnode)
{
  if (sourcenode == NULL)
  {
    return NULL;
  }

  thisnode = new Node<T>(sourcenode->data);
  thisnode->p = parentnode;
  thisnode->is_black = sourcenode->is_black;
  //if (thisnode->p != NULL)
  //  cout << "current node " << thisnode->data << " is black " << thisnode->is_black << " parent is " << thisnode->p->data <<endl;
  thisnode->left = CopyTree(thisnode->left, sourcenode->left, thisnode);
  thisnode->right = CopyTree(thisnode->right, sourcenode->right, thisnode);

  return thisnode;
}

template <class T>
void RedBlackTree<T>::RemoveAll(Node<T>* node)
{
  if (node == NULL)
  {
    return;
  }
  RemoveAll(node->left);
  RemoveAll(node->right);
  if (node->p == NULL)
  {
    delete node;
  }
  if (node == node->p->left)
  {
    node->p->left = NULL;
    delete node;
  }
  else
  {
    node->p->right = NULL;
    delete node;
  }
}

template <class T>
void RedBlackTree<T>::RBDeleteFixUp(Node<T>* x, Node<T>* xparent, bool xisleftchild)
{
  Node<T>* y;
  while (x != root && x->is_black == true)
  {
    if (xisleftchild)
    {
      y = x->p->right;
      if (y->is_black == false)
      {
        y->is_black = true;
        x->p->is_black = false;
        LeftRotate(x->p);
        y = x->p->right;
      }
      if ((y->left == NULL && y->right == NULL) || ((y->left != NULL && y->left->is_black == true) && (y->right != NULL && y->right->is_black == true)))
      {
        y->is_black = false;
        x = x->p;
      }
      else
      {
        if (y->right != NULL && y->right->is_black == true)
        {
          y->left->is_black = true;
          y->is_black = false;
          RightRotate(y);
          y = x->p->right;
        }
        y->is_black = x->p->is_black;
        x->p->is_black = true;
        y->right->is_black = true;
        LeftRotate(x->p);
        x = root;
      }
    }
    else
    {
      y = x->p->left;
      if (y->is_black == false)
      {
        y->is_black = true;
        x->p->is_black = false;
        RightRotate(x->p);
        y = x->p->left;
      }
      if ((y->left == NULL && y->right == NULL) || ((y->left != NULL && y->left->is_black == true) && (y->right != NULL && y->right->is_black == true)))
      {
        y->is_black = false;
        x = x->p;
      }
      else
      {
        if (y->left != NULL && y->left->is_black == true)
        {
          y->right->is_black = true;
          y->is_black = false;
          LeftRotate(y);
          y = x->p->left;
        }
        y->is_black = x->p->is_black;
        x->p->is_black = true;
        y->left->is_black = true;
        RightRotate(x->p);
        x = root;
      }
    }
  }
  x->is_black = true;
}

template <class T>
unsigned int RedBlackTree<T>::CalculateHeight(Node<T>* node) const
{

}

template <class T>
RedBlackTree<T>::RedBlackTree()
{
  root = NULL;
  size = 0;
}

template <class T>
RedBlackTree<T>::RedBlackTree(const RedBlackTree<T>& rbtree)
{
  root = CopyTree(root, rbtree.root, NULL);
}

template <class T>
RedBlackTree<T>::~RedBlackTree()
{

}

template <class T>
RedBlackTree<T>& RedBlackTree<T>::operator=(const RedBlackTree<T>& rbtree)
{
  RedBlackTree<T>* operate_rbt;
  operate_rbt = new RedBlackTree<T>(rbtree);
  return operate_rbt;
}

template <class T>
bool RedBlackTree<T>::Insert(T item)
{
  if (!Search(item))
  {
    Node<T>* newNode = BSTInsert(item);
    Node<T>* nodeY;
    newNode->is_black = false;
    while (newNode->p != NULL and newNode->p->is_black == false)
    {
      if (newNode->p == newNode->p->p->left)
      {
        nodeY = newNode->p->p->right;
        if (nodeY == NULL || nodeY->is_black == false)
        {
          newNode->p->is_black = true;
          if (nodeY != NULL)
          {
            nodeY->is_black = true;
          }
          newNode->p->p->is_black = false;
          newNode = newNode->p->p;
        }
        else
        {
          if (newNode == newNode->p->right)
          {
            newNode = newNode->p;
            LeftRotate(newNode);
          }
          newNode->p->is_black = true;
          newNode->p->p->is_black = false;
          RightRotate(newNode->p->p);
        }
      }
      else //newNode->p == newNode->p->p->right
      {
        nodeY = newNode->p->p->left;
        if (nodeY == NULL || nodeY->is_black == false)
        {
          newNode->p->is_black = true;
          if (nodeY != NULL)
          {
            nodeY->is_black = true;
          }
          newNode->p->p->is_black = false;
          newNode = newNode->p->p;
        }
        else
        {
          if (newNode == newNode->p->left)
          {
            newNode = newNode->p;
            RightRotate(newNode);
          }
          newNode->p->is_black = true;
          newNode->p->p->is_black = false;
          LeftRotate(newNode->p->p);
        }
      }
    }
    root->is_black = true;
    size++;
    return true;
  }
  else
  {
    return false;
  }
}

template <class T>
bool RedBlackTree<T>::Remove(T item)
{
  Node<T>* x;
  Node<T>* y;
  Node<T>* z = root;
  bool isLeftChild;

  // Look for the node to be deleted.
  while (z != NULL)
  {
    if (item == z->data)
      break;
    else if (item < z->data)
      z = z->left;
    else
      z = z->right;
  }

  if (z->left == NULL || z->right == NULL)
  {
    y = z;
  }
  else
  {
    y = Predecessor(z);
  }

  if (y->left != NULL)
  {
    x = y->left;
  }
  else
  {
    x = y->right;
  } 
  if (y->left != NULL || y->right != NULL)
  {
    x->p = y->p;
  }

  if (y->p == NULL)
  {
    root = x;
  }
  else
  {
    if (y == y->p->left)
    {
      y->p->left = x;
      isLeftChild = true;
    }
    else
    {
      y->p->right = x;
      isLeftChild = false;
    }
  }

  if (y != z)
  {
    z->data = y->data;
  }

  if (x != NULL && y->is_black == true)
  {
    RBDeleteFixUp(x, x->p, isLeftChild);
  }
  delete x;
  size--;
  return true;
}

template <class T>
void RedBlackTree<T>::RemoveAll()
{
  RemoveAll(root);
}

template <class T>
unsigned int RedBlackTree<T>::Size() const
{
  return this->size;
}

template <class T>
unsigned int RedBlackTree<T>::Height() const
{
  Node<T>* tmp = root;
  unsigned int height = 0;
  while (tmp != NULL)
  {
    if (tmp->is_black == true)
    {
      height++;
    }
    tmp = tmp->left;
  }
  height++;
  return height;
}

#endif