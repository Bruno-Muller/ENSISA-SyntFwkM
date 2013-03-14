/* 
 * File:   aggmax.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 14 mars 2013, 14:46
 */

#ifndef AGGMAX_H
#define	AGGMAX_H

#include "expression.h"
#include "agg.h"

namespace fuzzy
{
    template <class T>
    class AggMax : public Or<T>
    {
        public:
            virtual ~AggMax() {};
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T AggMax<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        T l = left->evaluate();
        T r = right->evaluate();
        if(l>r)
        {
            return l;
        }
        else if(l<r)
        {
            return r;
        }
        else
        {
            return l;
        }
    }
}

#endif	/* AGGMAX_H */

