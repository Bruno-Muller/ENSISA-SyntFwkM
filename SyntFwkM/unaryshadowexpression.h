/* 
 * File:   unaryshadowexpression.h
 * Author: bruno
 *
 * Created on 9 mars 2013, 18:06
 */

#ifndef UNARYSHADOWEXPRESSION_H
#define	UNARYSHADOWEXPRESSION_H

#include <exception>
#include "expression.h"
#include "unaryexpression.h"

namespace core {

    template <class T>
    class UnaryShadowExpression : public UnaryExpression<T> {
    public:
        UnaryShadowExpression(UnaryExpression<T>* t);
        virtual ~UnaryShadowExpression() {};
        
        void setTarget(const Expression<T>* o) const;
        virtual T evaluate(const Expression<T>* o) const;
    private:
        UnaryExpression<T>* m_target;

    };

    template <class T>
    UnaryShadowExpression<T>::UnaryShadowExpression(UnaryExpression<T>* t) :
    m_target(t) {
    }
    
    template <class T>
    void UnaryShadowExpression<T>::setTarget(UnaryExpression<T> *t) {
        m_target = t;
    }

    template <class T>
    T UnaryShadowExpression<T>::evaluate(const Expression<T>* o) const {
        if (m_target != 0)
            return m_target->evaluate(o);
        
        throw(std::exception());
    }

}

#endif	/* UNARYSHADOWEXPRESSION_H */

