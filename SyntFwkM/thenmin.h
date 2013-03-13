/* 
 * File:   thenmin.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 17:04
 */

#ifndef THENMIN_H
#define	THENMIN_H

#include "binaryexpression.h"
#include "then.h"

namespace fuzzy
{
    template <class T>
    class ThenMin : public Then<T>
    {
        public:
            virtual ~ThenMin() {};
            virtual T  evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T ThenMin<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        T l = left->evaluate();
        T r = right->evaluate();
        if(l>r)
        {
            return r;
        }
        else if(l<r)
        {
            return l;
        }
        else
        {
            return l;
        }
    }
}

#endif	/* THENMIN_H */

