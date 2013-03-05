/* 
 * File:   expression.h
 * Author: bruno
 *
 * Created on 5 mars 2013, 17:49
 */

#ifndef EXPRESSION_H
#define	EXPRESSION_H

namespace core {
    
    template<class T>
    class Expression {
        public:
            virtual T evalutate() const=0;
    };
}


#endif	/* EXPRESSION_H */

