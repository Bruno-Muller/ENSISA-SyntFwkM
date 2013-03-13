/* 
 * File:   orplus.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 16:31
 */

#ifndef ORPLUS_H
#define	ORPLUS_H

#include "expression.h"
#include "or.h"

namespace fuzzy
{
    template <class T>
    class OrPlus : public Or<T>
    {
        public:
            virtual ~OrPlus(){};
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T OrPlus<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        T l = left->evaluate();
        T r = right->evaluate();
        return l+r;
    }
}


#endif	/* ORPLUS_H */

