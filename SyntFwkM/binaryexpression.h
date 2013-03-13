#ifndef BINARYEXPRESSION_H
#define	BINARYEXPRESSION_H

#include "expression.h"

namespace core {

    template <class T>
    class BinaryExpression {
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const;
    };

    template <class T>
    T Expression<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
    	T l=left->evaluate();
    	T r=right->evaluate();
    }
}

#endif	/* BINARYEXPRESSION_H */
