/* 
 * File:   sugenothen.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 17:11
 */

#ifndef SUGENOTHEN_H
#define	SUGENOTHEN_H

#include "binaryexpression.h"
#include "then.h"

namespace fuzzy
{
    template <class T>
    class SugenoThen : public Then<T>
    {
        public:
            SugenoThen();
            virtual ~SugenoThen();
            virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
            virtual T premiseValue();
        private:
            const T premiseValue; 
                
    };
    
    template <class T>
    SugenoThen<T>::SugenoThen() : premiseValue(0)
    {
    }
    
    template <class T>
    T SugenoThen<T>::evaluate(const core::Expression<T>* left, const core::Expression<T>* right) const
    {
        this->premiseValue = left->evaluate();
        return this->premiseValue * right->evaluate();
    }
    
    template <class T>
    T SugenoThen<T>::premiseValue()
    {
        return this->premiseValue;
    }
}


#endif	/* SUGENOTHEN_H */

