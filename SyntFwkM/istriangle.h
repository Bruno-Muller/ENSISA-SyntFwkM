/* 
 * File:   istriangle.h
 * Author: bruno
 *
 * Created on 10 mars 2013, 02:09
 */

#ifndef ISTRIANGLE_H
#define	ISTRIANGLE_H

namespace fuzzy {

    template <class T>
    class IsTriangle : Is<T> {
    public:
        virtual T& evaluate(const core::Expression<T>& o) const;
    private:
        T& min, mid, max;

    };

    template <class T>
    T& IsTriangle<T>::evaluate(const core::Expression<T>& o) const {
        return 0;
    }

}


#endif	/* ISTRIANGLE_H */

