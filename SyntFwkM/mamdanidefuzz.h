/* 
 * File:   mamdanidefuzz.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 13 mars 2013, 10:58
 */

#ifndef MAMDANIDEFUZZ_H
#define	MAMDANIDEFUZZ_H

#include "binaryexpression.h"
#include "evaluator.h"
#include "valuemodel.h"
#include "expression.h"

namespace fuzzy {

    template <class T>
    class MamdaniDefuzz : public core::BinaryExpression<T> {
    public:
        MamdaniDefuzz(const T& min, const T& max, const T& step);
        virtual ~MamdaniDefuzz() {};
        
        virtual T evaluate(const core::Expression<T>*, const core::Expression<T>*)const;
        virtual T defuzz(const typename core::Evaluator<T>::Shape&) const=0;

    private:
        T m_max, m_min, m_step;

    };

    template<class T>
    MamdaniDefuzz<T>::MamdaniDefuzz(const T& min, const T& max, const T& step) : m_min(min), m_max(max), m_step(step) {
    }

    template <class T>
    T MamdaniDefuzz<T>::evaluate(const core::Expression<T>* _a, const core::Expression<T>* b) const {
        
        
        return defuzz(core::Evaluator<T>::buildShape(m_min, m_max, m_step, const_cast<const core::Expression<T>*>(_a), (core::ValueModel<T>*) b));
                
        
    }
}



#endif	/* MAMDANIDEFUZZ_H */

