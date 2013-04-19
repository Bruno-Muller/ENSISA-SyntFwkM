/* 
 * File:   and.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 10:16
 */

#ifndef AND_H
#define	AND_H

#include "binaryexpression.h"

namespace fuzzy
{
    template <class T>
    class And : public core::BinaryExpression<T> 
    {
        public:
            virtual T evaluate(core::Expression<T>*, core::Expression<T>*) const=0;
            virtual ~And() {};
    };
}


#endif	/* AND_H */

