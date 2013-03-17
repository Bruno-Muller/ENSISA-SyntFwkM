/* 
 * File:   cogdefuzz.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 17 mars 2013, 21:59
 */

#ifndef COGDEFUZZ_H
#define	COGDEFUZZ_H

#include "binaryexpression.h"
#include "mamdanidefuzz.h"

namespace fuzzy
{
    template <class T>
    class CogDefuzz : public Mamdanidefuzz<T>
    {
        public:
            virtual ~CogDefuzz() {};        
            virtual T  evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
        template <class T>
    T CogDefuzz<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        /*TODO*/
    }
}

#endif	/* COGDEFUZZ_H */

