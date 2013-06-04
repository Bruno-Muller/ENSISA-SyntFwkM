/* 
 * File:   naryexpressionmodel.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:22
 */

#ifndef NARYEXPRESSIONMODEL_H
#define	NARYEXPRESSIONMODEL_H

#include <exception>
#include "expression.h"
#include "naryexpression.h"

namespace core {

    template <class T>
    class NaryExpressionModel : public Expression<T>, public NaryExpression<T> {
    public:
        NaryExpressionModel(std::vector<const Expression<T>*> *operands, NaryExpression<T>* op);
        virtual ~NaryExpressionModel() {};
        
        virtual T evaluate() const;
        virtual T evaluate(std::vector<const Expression<T>*> *operands) const;

    private:
        NaryExpression<T>* m_operator;
        std::vector<const Expression<T>*> *m_operands;
    };
    
    template <class T>
    NaryExpressionModel<T>::NaryExpressionModel(std::vector<const Expression<T>*> *operands, NaryExpression<T>* op) : m_operands(operands), m_operator(op)
    {
    }

    template <class T>
    T NaryExpressionModel<T>::evaluate() const {
        if (m_operands != 0)
            return evaluate(m_operands);
        
        throw(std::exception());
    }

    template <class T>
    T NaryExpressionModel<T>::evaluate(std::vector<const Expression<T>*> *operands) const {
        if (m_operator != 0)
            return m_operator->evaluate(operands);
        
        throw(std::exception());
    }

}

#endif	/* NARYEXPRESSIONMODEL_H */

