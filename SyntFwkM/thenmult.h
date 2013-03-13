/* 
 * File:   thenmult.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 17:07
 */

#ifndef THENMULT_H
#define	THENMULT_H


#include "binaryexpression.h"
#include "then.h"

namespace fuzzy
{
    template <class T>
    class ThenMult : public Then<T>
    {
        public:
            virtual ~ThenMult() {};
            virtual T  evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T ThenMult<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        T l = left->evaluate();
        T r = right->evaluate();
        return l*r;
    }
}



#endif	/* THENMULT_H */

