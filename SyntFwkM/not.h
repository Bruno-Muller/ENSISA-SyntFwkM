/* 
 * File:   not.h
 * Author: bruno
 *
 * Created on 9 mars 2013, 18:15
 */

#ifndef NOT_H
#define	NOT_H

#include "expression.h"
#include "unaryexpression.h"

namespace fuzzy {

    template <class T>
    class Not : core::UnaryExpression  {
    public:
        virtual T evaluate(core::Expression) const=0;
    };  
    
}

#endif	/* NOT_H */
