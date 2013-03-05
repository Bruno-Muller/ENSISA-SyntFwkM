/* 
 * File:   assertion.h
 * Author: bruno
 *
 * Created on 5 mars 2013, 17:59
 */

#ifndef ASSERTION_H
#define	ASSERTION_H

#ifndef ASSERT_ON
        #define ASSERT(x)
#else
        #define ASSERT(x) \
                if (!(x)) \
                { \
                        std::cout << std ::endl << "ASSERT ERROR "<< #x << " failed" << std::endl; \
                        std::cout << "on line " << __LINE__ << std::endl; \
                        std::cout << "in file " << __FILE__ << std::endl; \
                }
#endif

#endif
/* ASSERTION_H */

