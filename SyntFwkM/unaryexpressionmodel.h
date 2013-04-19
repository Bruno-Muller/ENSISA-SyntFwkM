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
        UnaryExpressionModel(UnaryExpression<T>* = 0, Expression<T>* = 0);

        virtual T evalutate() const;
        virtual T evaluate(const Expression<T>* o) const;

        UnaryExpression<T>* GetOperator();
        Expression<T>* GetOperand();
        void SetOperator(UnaryExpression<T>*);
        void SetOperand(Expression<T>*);

    private:
        UnaryExpression<T>* m_operator;
        Expression<T>* m_operand;
    };

    template <class T>
    UnaryExpressionModel<T>::UnaryExpressionModel(UnaryExpression<T>* op, Expression<T>* operand) :
    m_operator(op), m_operand(operand) {
    }

    template <class T>
    T UnaryExpressionModel<T>::evalutate() const {
        if (m_operand != 0)
            return evaluate(m_operand);
        return 0;
    }

    template <class T>
    T UnaryExpressionModel<T>::evaluate(const Expression<T>* o) const {
        if (m_operator != 0)
            return m_operator->evaluate(o);
        return 0;
    }

    template <class T>
    UnaryExpression<T>* UnaryExpressionModel<T>::GetOperator() {
        return m_operator;
    }

    template <class T>
    Expression<T>* UnaryExpressionModel<T>::GetOperand() {
        return m_operand;
    }

    template <class T>
    void UnaryExpressionModel<T>::SetOperator(UnaryExpression<T>* op) {
        m_operator = *op;
    }

    template <class T>
    void UnaryExpressionModel<T>::SetOperand(Expression<T>* operand) {
        m_operand = *operand;
    }

}

#endif	/* UNARYEXPRESSIONMODEL_H */

