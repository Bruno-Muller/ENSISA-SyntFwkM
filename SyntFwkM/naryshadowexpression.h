/* 
 * File:   naryshadowexpression.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:28
 */

#ifndef NARYSHADOWEXPRESSION_H
#define	NARYSHADOWEXPRESSION_H

#include "expression.h"
#include "naryexpression.h"

namespace core {
    
    template <class T>
    class NaryShadowExpression : NaryExpression<T> {
    public:
        virtual T evaluate(const Expression<T> operands[]) const;
    private:
        NaryExpression<T>* m_target;
    };
    
    template <class T>
    T NaryShadowExpression<T>::evaluate(const Expression<T> operands[]) const {
        if (m_target != 0) {
            return m_target->evaluate(operands);
        }
    }
    
    
}


#endif	/* NARYSHADOWEXPRESSION_H */

