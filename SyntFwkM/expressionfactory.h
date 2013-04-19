/* 
 * File:   expressionfactory.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:31
 */

#ifndef EXPRESSIONFACTORY_H
#define	EXPRESSIONFACTORY_H

#include "expression.h"
#include "unaryexpression.h"

namespace core {

    template <class T>
    class ExpressionFactory {
    public:
        virtual Expression<T>* Hold(const Expression<T>* e) const;
        virtual UnaryExpressionModel<T>* NewUnary(const UnaryExpression<T>* ope = 0, const Expression<T>* o = 0) const;
        virtual BinaryExpressionModel<T>* NewBinary(const BinaryExpression<T>* ope = 0, const Expression<T>* l = 0, const Expression<T>* r = 0) const;

    private:
        Expression<T>* m_memory;
    };

    template <class T>
    Expression<T>* ExpressionFactory<T>::Hold(Expression<T> *e) {
        *m_memory = *e;
        return m_memory;
    }

    template <class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::NewUnary(UnaryExpression<T>* ope, Expression<T>* o) {
        return new UnaryExpressionModel<T>(ope, o);
    }

    template <class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::NewBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
        return new BinaryExpressionModel<T>(ope, l, r);
    }
}


#endif	/* EXPRESSIONFACTORY_H */

