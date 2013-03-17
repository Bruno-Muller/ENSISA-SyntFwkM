/* 
 * File:   aggplus.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 14 mars 2013, 14:57
 */

#ifndef AGGPLUS_H
#define	AGGPLUS_H

#include "expression.h"
#include "agg.h"

namespace fuzzy
{
    template <class T>
    class AggPlus : public Or<T>
    {
        public:
            virtual ~AggPlus() {};
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T AggPlus<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        T l = left->evaluate();
        T r = right->evaluate();
        return l+r;
    }
}

#endif 	/* AGGPLUS_H */

