/* 
 * File:   binaryshadowexpression.h
 * Author: bruno
 *
 * Created on 18 mars 2013, 21:51
 */

#ifndef BINARYSHADOWEXPRESSION_H
#define	BINARYSHADOWEXPRESSION_H

#include "expression.h"
#include "binaryexpression.h"

namespace core {

    template <class T>
    class BinaryShadowExpression : public BinaryExpression<T> {
    public:
        BinaryShadowExpression(BinaryExpression<T>*);
        //virtual void takeTarget(BinaryExpression<T>*);
        virtual T evaluate(const Expression<T>* l, const Expression<T>* r) const;
    private:
        BinaryExpression<T>* m_target;
    };

    template <class T>
    BinaryShadowExpression<T>::BinaryShadowExpression(BinaryExpression<T>* target) :
    m_target(target) {
    }

    /*
    template <class T>
    void BinaryShadowExpression<T>::takeTarget(BinaryExpression<T>*) {
    }
    */
    
    template <class T>
    T BinaryShadowExpression<T>::evaluate(const Expression<T>* l, const Expression<T>* r) const {
        if (m_target != 0)
            return m_target->evaluate(l, r);
        return 0;
    }

}

#endif	/* BINARYSHADOWEXPRESSION_H */

