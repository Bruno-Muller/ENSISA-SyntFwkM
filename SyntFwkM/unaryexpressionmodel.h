/* 
 * File:   unaryexpressionmodel.h
 * Author: bruno
 *
 * Created on 6 mars 2013, 08:28
 */

#ifndef UNARYEXPRESSIONMODEL_H
#define	UNARYEXPRESSIONMODEL_H

#include "expression.h"
#include "unaryexpression.h"

namespace core {

    template <class T>
    class UnaryExpressionModel : Expression<T>, UnaryExpression<T> {
    public:
        virtual T evalutate() const;
        virtual T evaluate(const Expression<T>* o) const;

    private:
        UnaryExpression<T>* m_operator;
        Expression<T>* m_operand;
    };

    template <class T>
    T UnaryExpressionModel<T>::evalutate() const {
        if (m_operand != 0)
            return evaluate(m_operand);
    }

    template <class T>
    T UnaryExpressionModel<T>::evaluate(const Expression<T>* o) const {
        if (m_operator != 0)
            return m_operator->evaluate(o);
    }

}

#endif	/* UNARYEXPRESSIONMODEL_H */

