/* 
 * File:   is.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:07
 */

#ifndef IS_H
#define	IS_H

#include "expression.h"
#include "unaryexpression.h"

namespace fuzzy {

    template <class T>
    class Is : core::UnaryExpression<T>  {
    public:
        virtual T evaluate(const core::Expression<T>* o) const=0;
    };  
    
}

#endif	/* IS_H */

