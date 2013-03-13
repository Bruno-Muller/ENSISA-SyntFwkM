/* 
 * File:   and.h
 * Author: Simon
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
            virtual ~And() {};
    };
}


#endif	/* AND_H */

