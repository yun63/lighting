/***************************************************************************
 *
 * Copyright © 2017 LT. All Rights Reserved.
 *
 ***************************************************************************/

/**
 *
 * @file: lt_btree.h
 *
 * @breaf: 二叉树的实现
 *
 * @author: Lei Yunfei(towardstheway@gmail.com)
 *
 * @create: 2017/04/04 16时23分48秒
 *
 **/


#ifndef  LT_BTREE_INC
#define  LT_BTREE_INC

#include "basic_types.h"
#include "lt_node.h"
#include "lt_exception.h"

namespace lt {


template<class T>
class BinaryTree : public noncopyable {
public:
    BinaryTree ();
    virtual ~BinaryTree ();

    bool empty() const { return size_ == 0; }
    uint32_t size() const { return size_; }
    uint32_t depth() const;
    void clear();

    void MakeTree(const T &elem, BinaryTree<T> &, BinaryTree<T> &);
    /**
     * @brief 删除二叉树左子树
     *
     * @return 返回删除左子树后的二叉树根结点
     */
    BinaryTree<T> &RemoveLeftSubTree();
    /**
     * @brief 删除二叉树右子树
     *
     * @return 返回删除右子树后的二叉树根结点
     */
    BinaryTree<T> &RemoveRightSubTree();
    /**
     * @brief 先序遍历二叉树
     *
     * @param visit 访问结点函数
     */
    void PreOrder(void (*visit)(BintreeNode<T> *));
    /**
     * @brief 中序遍历二叉树
     *
     * @param visit 访问结点函数
     */
    void InOrder(void (*visit)(BintreeNode<T> *));
    /**
     * @brief 后序遍历二叉树
     *
     * @param visit 访问结点函数
     */
    void PostOrder(void (*visit)(BintreeNode<T> *));
    /**
     * @brief 层序遍历二叉树
     *
     * @param visit 访问结点函数
     */
    void LevelOrder(void (*visit)(BintreeNode<T> *));

    virtual BintreeNode<T> find(const T &elem) const = 0;
    virtual void insert(const T &elem) = 0;
    virtual void erase(const T &elem) = 0;

protected:
    uint32_t depth(const BintreeNode<T> *node) const;
    void destroy(BintreeNode<T> *node);

protected:
    BintreeNode<T> *root_;
    uint32_t size_;
};


} // namespace lt

#endif   // ----- #ifndef LT_BTREE_INC  -----
