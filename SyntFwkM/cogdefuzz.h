/* 
 * File:   cogdefuzz.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 17 mars 2013, 21:59
 */

#ifndef COGDEFUZZ_H
#define	COGDEFUZZ_H

#include "expression.h"
#include "mamdanidefuzz.h"
#include "evaluator.h"

namespace fuzzy
{
    template <class T>
    class CogDefuzz : public MamdaniDefuzz<T>
    {
        public:
            CogDefuzz(const T& min, const T& max, const T& step);
            virtual ~CogDefuzz() {};        
            
            virtual T defuzz(const typename core::Evaluator<T>::Shape&) const;
    };
    
    template <class T>
    CogDefuzz<T>::CogDefuzz(const T& min, const T& max, const T& step) : MamdaniDefuzz<T>(min, max, step)
    {
    }
    
    
    template <class T>
    T CogDefuzz<T>::defuzz(const typename core::Evaluator<T>::Shape& s) const
    {
        T x, y, numerator=0, denominator=0;
        for (int i = 0; i<(s.first.size()-1); i++) {
            
            x = s.first.at(i);
            y = s.second.at(i);
            numerator += x * y;
            denominator += y;
        }
        
        return numerator / denominator;
    }
}

#endif	/* COGDEFUZZ_H */

