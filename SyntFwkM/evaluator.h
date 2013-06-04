/* 
 * File:   evaluator.h
 * Author: CHEVALIER Simon 2A-IR ENSISA <simon.cvr@gmail.com>
 *
 * Created on 18 mars 2013, 08:26
 */

#ifndef EVALUATOR_H
#define	EVALUATOR_H

#include <vector>
#include <iostream>

#include "valuemodel.h"


namespace core {

    template <class T>
    class Evaluator {
    public:
        typedef std::pair<std::vector<T>, std::vector<T> > Shape;

        static Shape buildShape(const T &min, const T &max, const T &step, const core::Expression<T> *e, core::ValueModel<T> *v);
        static std::ostream& printShape(const Shape &shape, std::ostream& os);
    };

    template <class T>
    typename Evaluator<T>::Shape Evaluator<T>::buildShape(const T &min, const T &max, const T &step, const core::Expression<T> *e, core::ValueModel<T> *v) {
        
        typename Evaluator<T>::Shape shape;
        
        for (T i = min; i <= max; i += step) {
            shape.first.push_back(i);
            v->setValue(i);
            shape.second.push_back(e->evaluate());
        }
        
        return shape;
    }

    template <class T>
    std::ostream& Evaluator<T>::printShape(const Evaluator<T>::Shape &shape, std::ostream& os) {
        
        typename std::vector<T>::const_iterator itFirst = shape.first.begin();
        typename std::vector<T>::const_iterator itSecond = shape.second.begin();
        
        for (; itFirst != shape.first.end(); itFirst++, itSecond++)
            os << "[" << *itFirst << ", " << *itSecond << "]" << std::endl;
        
        
        return os;
    }
}



#endif	/* EVALUATOR_H */

