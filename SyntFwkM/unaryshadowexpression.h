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
    class UnaryShadowExpression : UnaryExpression {
    public:
        virtual T evaluate(Expression) const=0;
    private:
        UnaryExpression m_target;
            
    };  
    
    template <class T>
    T UnaryShadowExpression::evaluate(Expression o) const {
        if (m_target != 0) {
            return m_target.evaluate(o);
        }
    }
    
}

#endif	/* UNARYSHADOWEXPRESSION_H */

