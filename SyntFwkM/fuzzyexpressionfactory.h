/* 
 * File:   fuzzyexpressionfactory.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 04:28
 */

#ifndef FUZZYEXPRESSIONFACTORY_H
#define	FUZZYEXPRESSIONFACTORY_H

#include <vector>
#include "expression.h"
#include "expressionfactory.h"
#include "unaryshadowexpression.h"
#include "unaryexpressionmodel.h"
#include "binaryshadowExpression.h"
#include "binaryexpressionmodel.h"
#include "naryshadowexpression.h"
#include "naryexpressionmodel.h"
#include "and.h"
#include "or.h"
#include "then.h"
#include "agg.h"
#include "mamdanidefuzz.h"
#include "not.h"
#include "is.h"
#include "agg.h"
#include "naryexpression.h"

namespace fuzzy {

    template <class T>
    class FuzzyExpressionFactory : core::ExpressionFactory<T> {
    public:
        FuzzyExpressionFactory<T>(Not<T>*, And<T>*, Or<T>*, Then<T>*, Agg<T>*, Is<T>*, MamdaniDefuzz<T>*, SugenoDefuzz<T>*, SugenoConclusion<T>*);

        virtual core::Expression<T>* newAnd(core::Expression<T>* l, core::Expression<T>* r);
        virtual core::Expression<T>* newOr(core::Expression<T>* l, core::Expression<T>* r);
        virtual core::Expression<T>* newThen(core::Expression<T>* l, core::Expression<T>* r);
        virtual core::Expression<T>* newAgg(core::Expression<T>* l, core::Expression<T>* r);
        virtual core::Expression<T>* newMamdani(core::Expression<T>* l, core::Expression<T>* r);
        virtual core::Expression<T>* newSugeno(std::vector<const core::Expression<T>*> *o);
        virtual core::Expression<T>* newConclusion(std::vector<const core::Expression<T>*> *o);
        virtual core::Expression<T>* newNot(core::Expression<T>* o);
        virtual core::Expression<T>* newIs(fuzzy::Is<T>* is, core::Expression<T>* o);

        virtual void changeAnd(And<T>* o);
        virtual void changeOr(Or<T>* o);
        virtual void changeThen(Then<T>* o);
        virtual void changeAgg(Agg<T>* o);
        virtual void changeMamdani(MamdaniDefuzz<T>* o);
        virtual void changeSugeno(SugenoDefuzz<T>* o);
        virtual void changeConclusion(SugenoConclusion<T>* o);
        virtual void changeNot(Not<T>* o);
        virtual void changeIs(Is<T>* o);
    private:
        core::BinaryShadowExpression<T> *m_and, *m_or, *m_then, *m_agg, *m_mamdani;
        core::UnaryShadowExpression<T> *m_is, *m_not;
        core::NaryShadowExpression<T> *m_sugeno, *m_conclusion;

    };

    template <class T>
    FuzzyExpressionFactory<T>::FuzzyExpressionFactory(Not<T>* n, And<T>* a, Or<T>* o, Then<T>* t, Agg<T>* g, Is<T>* s, MamdaniDefuzz<T>* md, SugenoDefuzz<T>* sd, SugenoConclusion<T>* sc) :
    m_not(new core::UnaryShadowExpression<T>(n)),
    m_is(new core::UnaryShadowExpression<T>(s)),
    m_and(new core::BinaryShadowExpression<T>(a)),
    m_or(new core::BinaryShadowExpression<T>(o)),
    m_then(new core::BinaryShadowExpression<T>(t)),
    m_agg(new core::BinaryShadowExpression<T>(g)),
    m_mamdani(new core::BinaryShadowExpression<T>(md)),
    m_mamdani(new core::NaryShadowExpression<T>(sd)),
    m_mamdani(new core::NaryShadowExpression<T>(sc)) {
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newAnd(core::Expression<T>* l, core::Expression<T>* r) {
        return new core::BinaryExpressionModel(m_and, l, r);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newOr(core::Expression<T>* l, core::Expression<T>* r) {
        return new core::BinaryExpressionModel(m_or, l, r);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newThen(core::Expression<T>* l, core::Expression<T>* r) {
        return new core::BinaryExpressionModel(m_then, l, r);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newAgg(core::Expression<T>* l, core::Expression<T>* r) {
        return new core::BinaryExpressionModel(m_agg, l, r);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newMamdani(core::Expression<T>* l, core::Expression<T>* r) {
        return new core::BinaryExpressionModel(m_mamdani, l, r);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newNot(core::Expression<T>* o) {
        return new core::UnaryExpressionModel(m_not, o);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newIs(fuzzy::Is<T>* is, core::Expression<T>* o) {
        return new core::UnaryExpressionModel(m_is, o);
    }

    template <class T>
    core::Expression<T>* FuzzyExpressionFactory<T>::newSugeno(std::vector<const core::Expression<T>*> *o) {
        return new core::NaryExpressionModel(o, m_sugeno);
    }

    template <class T>
    virtual core::Expression<T>* FuzzyExpressionFactory<T>::newConclusion(std::vector<const core::Expression<T>*> *o) {
        return core::NaryExpressionModel(o, m_conclusion);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeAnd(And<T>* o) {
        this->m_and->setTarget(o);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeOr(Or<T>* o) {
        this->m_or->setTarget(o);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeThen(Then<T>* o) {
        this->m_then->setTarget(o);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeAgg(Agg<T>* o) {
        this->m_agg->setTarget(o);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeMamdani(MamdaniDefuzz<T>* o) {
        this->m_mamdani->setTarget(o);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeNot(Not<T>* o) {
        this->m_not->setTarget(o);
    }

    template <class T>
    void FuzzyExpressionFactory<T>::changeIs(Is<T>* o) {
        this->m_is->setTarget(o);
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::changeSugeno(SugenoDefuzz<T>* o) {
        this->m_sugeno->setTarget(o);
    }
    
    template <class T>
    void FuzzyExpressionFactory<T>::changeConclusion(SugenoConclusion<T>* o) {
        this->m_conclusion->setTarget(o);
    }
}

#endif	/* FUZZYEXPRESSIONFACTORY_H */

