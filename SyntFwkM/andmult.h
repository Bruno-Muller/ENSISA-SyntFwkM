/* 
 * File:   andmult.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 11:38
 */

#ifndef ANDMULT_H
#define	ANDMULT_H

#include "and.h"
#include "binaryexpression.h"

namespace fuzzy
{
    template <class T>
    class AndMult : public And<T>
    {
        public:
            virtual ~AndMult() {};
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;          
    };
    
    template <class T>
    T AndMult<T>::evaluate(const core::Expression<T>* left,const core::Expression<T>* right) const
    {
        T l = left->evaluate();
        T r = right->evaluate();
        return l*r;
    }
}

#endif	/* ANDMULT_H */

