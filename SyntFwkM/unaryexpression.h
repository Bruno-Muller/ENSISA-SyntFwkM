/* 
 * File:   unaryexpression.h
 * Author: bruno
 *
 * Created on 6 mars 2013, 08:23
 */

#ifndef UNARYEXPRESSION_H
#define	UNARYEXPRESSION_H

#include "expression.h"

namespace core {

    template <class T>
    class UnaryExpression {
    public:
        virtual T evaluate(Expression) const=0;
    };  
    
}

#endif	/* UNARYEXPRESSION_H */

