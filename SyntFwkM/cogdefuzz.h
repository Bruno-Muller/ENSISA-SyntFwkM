/* 
 * File:   cogdefuzz.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 17 mars 2013, 21:59
 */

#ifndef COGDEFUZZ_H
#define	COGDEFUZZ_H

#include "binaryexpression.h"

namespace fuzzy
{
    template <class T>
    class CogDefuzz : public CogDefuzz<T>
    {
        public:
            virtual ~CogDefuzz() {};        
    };
}

#endif	/* COGDEFUZZ_H */

