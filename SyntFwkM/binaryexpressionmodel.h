/* 
 * File:   binaryexpressionmodel.h
 * Author: bruno
 *
 */

#ifndef BINARYEXPRESSIONMODEL_H
#define	BINARYEXPRESSIONMODEL_H

#include "expression.h"
#include "binaryexpression.h"

namespace core {

    template <class T>
    class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
    public:
        BinaryExpressionModel(BinaryExpression<T>* = 0, Expression<T>* = 0, Expression<T>* = 0);
        ~BinaryExpressionModel() {};

        virtual Expression<T>* GetLeft() const;
        virtual Expression<T>* GetRight() const;
        virtual BinaryExpression<T>* GetOperator();
        virtual void SetLeft(Expression<T>*);
        virtual void SetRight(Expression<T>*);
        virtual void SetOperator(BinaryExpression<T>*);

        virtual T evalutate() const;
        virtual T evaluate(const Expression<T>* l, const Expression<T>* r) const;

    private:
        BinaryExpression<T>* m_operator;
        Expression<T>* m_left;
        Expression<T>* m_right;
    };

    template <class T>
    BinaryExpressionModel<T>::BinaryExpressionModel(BinaryExpression<T>* op, Expression<T>* left, Expression<T>* right) :
    m_operator(op), m_left(left), m_right(right) {
    }

    template <class T>
    Expression<T>* BinaryExpressionModel<T>::GetLeft() const {
        return m_left;
    }

    template <class T>
    Expression<T>* BinaryExpressionModel<T>::GetRight() const {
        return m_right;
    }

    template <class T>
    BinaryExpression<T>* BinaryExpressionModel<T>::GetOperator() {
        return m_operator;
    }

    template <class T>
    void BinaryExpressionModel<T>::SetLeft(Expression<T>* left) {
        m_left = left;
    }

    template <class T>
    void BinaryExpressionModel<T>::SetRight(Expression<T>* right) {
        m_right = *right;
    }

    template <class T>
    void BinaryExpressionModel<T>::SetOperator(BinaryExpression<T>* op) {
        m_operator = *op;
    }

    template <class T>
    T BinaryExpressionModel<T>::evalutate() const {
        if (m_left != 0 && m_right != 0)
            return evaluate(m_left, m_right);
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const {
        if (m_operator != 0)
            return m_operator->evaluate(l, r);
    }
}

#endif