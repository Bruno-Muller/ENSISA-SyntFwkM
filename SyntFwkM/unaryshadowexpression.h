/* 
 * File:   unaryshadowexpression.h
 * Author: bruno
 *
 * Created on 9 mars 2013, 18:06
 */

#ifndef UNARYSHADOWEXPRESSION_H
#define	UNARYSHADOWEXPRESSION_H

#include "expression.h"
#include "unaryexpression.h"

namespace core {

    template <class T>
    class UnaryShadowExpression : UnaryExpression<T> {
    public:
        virtual T evaluate(const Expression<T>* o) const=0;
    private:
        UnaryExpression<T>* m_target;
            
    };  
    
    template <class T>
    T UnaryShadowExpression<T>::evaluate(const Expression<T>* o) const {
        if (m_target != 0) {
            return m_target->evaluate(o);
        }
    }
    
}

#endif	/* UNARYSHADOWEXPRESSION_H */

