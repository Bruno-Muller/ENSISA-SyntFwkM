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
        virtual Expression<T>* NewUnary(const UnaryExpression<T>* ope, const Expression<T>* o) const;
        virtual Expression<T>* NewBinary(const UnaryExpression<T>* ope, const Expression<T>* l, const Expression<T>* r) const;
        
    private:
        Expression<T>* m_memory;
    };

    template <class T>
    Expression<T>* ExpressionFactory<T>::Hold(const Expression<T>* e) const {
        return 0; // TODO
    }

    template <class T>
    Expression<T>* ExpressionFactory<T>::NewUnary(const UnaryExpression<T>* ope, const Expression<T>* o) const {
        return 0; // TODO
    }

    template <class T>
    Expression<T>* ExpressionFactory<T>::NewBinary(const UnaryExpression<T>* ope, const Expression<T>* l, const Expression<T>* r) const {
        return 0; // TODO
    }
}


#endif	/* EXPRESSIONFACTORY_H */

