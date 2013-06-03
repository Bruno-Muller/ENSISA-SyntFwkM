#ifndef BINARYEXPRESSIONMODEL_H
#define	BINARYEXPRESSIONMODEL_H

#include <exception>
#include "expression.h"
#include "binaryexpression.h"

namespace core {

    template <class T>
    class BinaryExpressionModel : public Expression<T>, public BinaryExpression<T> {
    public:
        BinaryExpressionModel(BinaryExpression<T>*, Expression<T>*, Expression<T>*);
        ~BinaryExpressionModel() {};
 
        virtual BinaryExpression<T>* getOperator();

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
    BinaryExpression<T>* BinaryExpressionModel<T>::getOperator() {
        return m_operator;
    }

    template <class T>
    T BinaryExpressionModel<T>::evalutate() const {
        if (m_left != 0 && m_right != 0)
            return evaluate(m_left, m_right);
        
        throw(std::exception());
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const {
        if (m_operator != 0)
            return m_operator->evaluate(l, r);
        
        throw(std::exception());
    }
}

#endif