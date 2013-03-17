/* 
 * File:   mamdanidefuzz.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 10:58
 */

#ifndef MAMDANIDEFUZZ_H
#define	MAMDANIDEFUZZ_H

#include "binaryexpression.h"

namespace fuzzy
{
    template <class T>
    class Mamdanidefuzz : public BinaryExpression<T>
    {
        public:
            virtual ~Mamdanidefuzz() {};        
    };
}



#endif	/* MAMDANIDEFUZZ_H */

