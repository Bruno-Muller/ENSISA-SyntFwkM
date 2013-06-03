/* 
 * File:   naryshadowexpression.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:28
 */

#ifndef NARYSHADOWEXPRESSION_H
#define	NARYSHADOWEXPRESSION_H

#include <exception>
#include "expression.h"
#include "naryexpression.h"

namespace core {
    
    template <class T>
    class NaryShadowExpression : public NaryExpression<T> {
    public:
        NaryShadowExpression(NaryExpression<T>* t);
        virtual ~NaryShadowExpression() {};
        
        virtual T evaluate(std::vector<const Expression<T>*> *operands) const;
        void setTarget(NaryExpression<T> *t);
    private:
        NaryExpression<T>* m_target;
    };
    
    template <class T>
    NaryShadowExpression<T>::NaryShadowExpression(NaryExpression<T>* t) : m_target(t)
    {
    }
    
    template <class T>
    T NaryShadowExpression<T>::evaluate(std::vector<const Expression<T>*> *operands) const {
        if (m_target != 0) {
            return m_target->evaluate(operands);
        }
        
        throw(std::exception());
    }
    
    template <class T>
    void NaryShadowExpression<T>::setTarget(NaryExpression<T> *target) {
        this->m_target = target;
    }
    
    
}


#endif	/* NARYSHADOWEXPRESSION_H */

