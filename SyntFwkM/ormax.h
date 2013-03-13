/* 
 * File:   ormax.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 16:16
 */

#ifndef ORMAX_H
#define	ORMAX_H

#include "expression.h"
#include "or.h"

namespace fuzzy
{
    template <class T>
    class OrMax : public Or<T>
    {
        public:
            virtual ~OrMax() {};
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T OrMax<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
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

#endif	/* ORMAX_H */

