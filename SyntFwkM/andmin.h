/* 
 * File:   andmin.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 11:17
 */

#ifndef ANDMIN_H
#define	ANDMIN_H

#include "binaryexpression.h"
#include "and.h"

namespace fuzzy
{
    template <class T>
    class AndMin : public And<T>
    {
        public:
            virtual ~AndMin() {};
            virtual T  evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
    };
    
    template <class T>
    T AndMin<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
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


#endif	/* ANDMIN_H */


