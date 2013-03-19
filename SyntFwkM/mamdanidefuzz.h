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
    class MamdaniDefuzz : public core::BinaryExpression<T>
    {
        public:
            virtual ~MamdaniDefuzz() {};
            virtual T  evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
        template <class T>
    T MamdaniDefuzz<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        /*TODO*/
    }
}



#endif	/* MAMDANIDEFUZZ_H */

