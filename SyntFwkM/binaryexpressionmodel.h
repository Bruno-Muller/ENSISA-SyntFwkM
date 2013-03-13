#ifndef BINARYEXPRESSIONMODEL_H
#define	BINARYEXPRESSIONMODEL_H

#include "expression.h"
#include "binaryexpression.h"

namespace core {

    template <class T>
    class BinaryExpressionModel : Expression<T>, BinaryExpression<T> {
    public:
        virtual T evalutate() const;
        virtual T evaluate(const Expression<T>* l, const Expression<T>* r) const;

    private:
        BinaryExpression<T>* m_operator;
        Expression<T>* m_left;
        Expression<T>* m_right;
    };

    


    template <class T>
    T BinaryExpressionModel<T>::evalutate() const {
        if (m_left != 0 && m_right != 0)
            return evaluate(m_left,m_right);
    }

    template <class T>
    T BinaryExpressionModel<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const
    {
        if (&m_operator != 0)
            return m_operator.evaluate(l,r);
    }
}

#endif