/* 
 * File:   sugenoconclusion.h
 * Author: bruno
 *
 * Created on 3 juin 2013, 20:37
 */

#ifndef SUGENOCONCLUSION_H
#define	SUGENOCONCLUSION_H

#include <exception>

#include "naryexpression.h"

namespace fuzzy {

    template<class T>
    class SugenoConclusion : public core::NaryExpression<T> {
    public:
        SugenoConclusion(const std::vector<T> *coef);
        virtual T evaluate(std::vector<const core::Expression<T>*> *operands) const;
    private:
        const std::vector<T> *m_coef;
    };
    
    template<class T>
    SugenoConclusion <T>::SugenoConclusion(const std::vector<T>* coef) : m_coef(coef)
    {
    }
    
    template<class T>
    T SugenoConclusion <T>::evaluate(std::vector<const core::Expression<T>*>* operands) const
    {
        typename std::vector<T>::const_iterator iteratorCoef = this->m_coef->begin();
        typename std::vector<const core::Expression<T>*>::const_iterator iteratorExpr = operands->begin();
        T result = 0;
        
        for(iteratorCoef = this->m_coef->begin(), iteratorExpr = operands->begin(); iteratorExpr != operands->end() && iteratorCoef != this->m_coef->end(); iteratorExpr++, iteratorCoef++) {
            T eval = (*iteratorExpr)->evaluate();
            result += *iteratorCoef * eval;
        }
        
        if (iteratorExpr != operands->end()) 
            throw(std::exception());
        
        return result;
    }
}

#endif	/* SUGENOCONCLUSION_H */

