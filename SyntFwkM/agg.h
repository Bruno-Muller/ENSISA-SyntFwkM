/* 
 * File:   agg.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 10:49
 */

#ifndef AGG_H
#define	AGG_H

#include "binaryexpression.h"

namespace fuzzy
{
    template <class T>
    class Agg : public core::BinaryExpression<T>
    {
        public:
            virtual ~Agg() {};
    };
}


#endif	/* AGG_H */

