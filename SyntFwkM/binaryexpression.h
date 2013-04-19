#ifndef BINARYEXPRESSION_H
#define	BINARYEXPRESSION_H

#include "expression.h"

namespace core {

    template <class T>
    class BinaryExpression {
    public:
        virtual T evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const =0;
    };

}

#endif	/* BINARYEXPRESSION_H */
