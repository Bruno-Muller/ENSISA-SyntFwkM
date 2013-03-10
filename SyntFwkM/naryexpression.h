/* 
 * File:   naryexpression.h
 * Author: bruno
 *
 * Created on 9 mars 2013, 18:03
 */

#ifndef NARYEXPRESSION_H
#define	NARYEXPRESSION_H

#include "expression.h"

namespace core {

    template <class T>
    class NaryExpression {
    public:
        virtual T& evaluate(const Expression<T> operands[]) const=0;
    };  
    
}


#endif	/* NARYEXPRESSION_H */

