/* 
 * File:   expressionfactory.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:31
 */

#ifndef EXPRESSIONFACTORY_H
#define	EXPRESSIONFACTORY_H

#include <set>
#include "expression.h"
#include "unaryexpression.h"
#include "is.h"

namespace core {

    template <class T>
    class ExpressionFactory {
    public:
        ExpressionFactory();
        virtual ~ExpressionFactory();
        
        Expression<T>* hold(Expression<T>* e);
        ValueModel<T>* newValue(fuzzy::Is<T>*);
        UnaryExpressionModel<T>* newUnary(UnaryExpression<T>* ope, Expression<T>* o);
        BinaryExpressionModel<T>* newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r);
        NaryExpressionModel<T>* newNary(NaryExpression<T>* ope, std::vector<Expression<T>*> operands);

    private:
        std::set<Expression<T>*> *m_memory;
    };

    template <class T>
    ExpressionFactory<T>::ExpressionFactory() : m_memory(new std::set<Expression<T>*>) {
    }
    
    template <class T>
    ExpressionFactory<T>::~ExpressionFactory() {
        delete m_memory;
    }

    template <class T>
    Expression<T>* ExpressionFactory<T>::hold(Expression<T> *e) {
        m_memory->insert(e);
        return e;
    }

    template <class T>
    ValueModel<T>* ExpressionFactory<T>::newValue(fuzzy::Is<T>* v) {
        return new ValueModel<T>(v);
    }
    
    template <class T>
    UnaryExpressionModel<T>* ExpressionFactory<T>::newUnary(UnaryExpression<T>* ope, Expression<T>* o) {
        return new UnaryExpressionModel<T>(ope, o);
    }

    template <class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::newBinary(BinaryExpression<T>* ope, Expression<T>* l, Expression<T>* r) {
        return new BinaryExpressionModel<T>(ope, l, r);
    }
    
    template <class T>
    BinaryExpressionModel<T>* ExpressionFactory<T>::newNary(NaryExpression<T>* ope, std::vector<Expression<T>*> o) {
        return new NaryExpressionModel<T>(ope, o);
    }
}


#endif	/* EXPRESSIONFACTORY_H */

