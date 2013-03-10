/* 
 * File:   naryexpressionmodel.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:22
 */

#ifndef NARYEXPRESSIONMODEL_H
#define	NARYEXPRESSIONMODEL_H

#include "expression.h"
#include "naryexpression.h"

namespace core {

    template <class T>
    class NaryExpressionModel : Expression<T>, NaryExpression<T> {
    public:
        virtual T& evalutate() const;
        virtual T& evaluate(const Expression<T>& o) const;

    private:
        NaryExpression<T>& m_operator;
        Expression<T>& m_operand;
    };

    template <class T>
    T& NaryExpressionModel<T>::evalutate() const {
        if (&m_operand != 0)
            return evaluate(m_operand);
    }

    template <class T>
    T& NaryExpressionModel<T>::evaluate(const Expression<T>& o) const {
        if (&m_operator != 0)
            return m_operator.evaluate(o);
    }

}

#endif	/* NARYEXPRESSIONMODEL_H */

