/* 
 * File:   then.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 10:38
 */

#ifndef THEN_H
#define	THEN_H

#include "binaryexpression.h"

namespace fuzzy
{
    template <class T>
    class Then : public core::BinaryExpression<T>
    {
        public:
            virtual ~Then() {};
    };
}

#endif	/* THEN_H */

