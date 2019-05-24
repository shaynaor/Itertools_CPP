/**
 * A template iterator-product class.
 * product represent a product of two psudo-containers.
 * for example ‫))product(range(1,4), string("helo")) represent
 * 1,h  1,e  1,l  1,l  1,o  2,h  2,e  2,l  2,l  2,o  3,h  3,e  3,l  3,l  3,o .
 * 
 * @author - Shay Naor and Alex Vaisman.
 */

#pragma once
#include <iostream>
#include "zip.hpp"


namespace itertools{

    template<typename T, typename U> 
    class product{
         private:
            /* Private data-members. */
            T _item1;
            U _item2;

        public:

            /* Constructor. */
            product(const T item1 , const U item2)
            : _item1(item1), _item2(item2) {}

            /* Iterator inner  class */
            class iterator{

                private:
                    /* Private data-members. */
                    typename T::iterator _it1;
                    typename T::iterator _it1End;
                    typename U::iterator _it2;
                    typename U::iterator _it2End;

                public:
                    /* Constructor. */
                    iterator(typename T::iterator item1,typename T::iterator item1End, 
                    typename U::iterator item2 ,typename U::iterator item2End )
                    : _it1(item1), _it1End(item1End), _it2(item2), _it2End(item2End) {}

                    /* Copy costructor. */
                    iterator(const iterator& other)
                    :_it1(other._it1), _it1End(other._it1End), _it2(other._it2), _it2End(other._it2End) {}

                    /* Operator * implementation. */
		            auto operator*()  {
                        return std::pair(*(_it1),*(_it2));
		            }

                    /* Operator -> implementation. */
		            auto operator->() const {
                       return std::pair(&(_it1),&(_it2));
		            }
                    
                    /* Prefix operator ++ implementation.(++i)  */
		            iterator& operator++() {
                        if(_it1 != _it1End && _it2 != _it2End){
                            _it1++;
                            _it2++;
                        }
                       
			            return *this;
		            }

                    /* Postfix operator ++ implementation.(i++)  */ 
		            const iterator operator++(int) {
                        iterator it = *this; 
                         ++*this; 
                        return it; 
		            }

                    /* Operator == implementation. Return true iff _it == rhs._it */
                    bool operator==(const iterator& rhs) const {
			            return (_it1 == rhs._it1) && (_it2 == rhs._it2);
		            }

                    /* Operator != implementation. Return true iff _it != rhs._it */
		            bool operator!=(const iterator& rhs) const {
			            return (_it1 != rhs._it1) && (_it2 != rhs._it2);
                    }
                

            }; // End itetator class.


            /* const_iterator inner  class */
            class const_iterator{

                private:
                    /* Private data-members. */
                    typename T::const_iterator _it1;
                    typename T::const_iterator _it1End;
                    typename U::const_iterator _it2;
                    typename U::const_iterator _it2End;

                public:
                    /* Constructor. */
                    const_iterator(typename T::const_iterator item1,typename T::const_iterator item1End, 
                    typename U::const_iterator item2 ,typename U::const_iterator item2End )
                    : _it1(item1), _it1End(item1End), _it2(item2), _it2End(item2End) {}

                    /* Copy costructor. */
                    const_iterator(const const_iterator& other)
                    :_it1(other._it1), _it1End(other._it1End), _it2(other._it2), _it2End(other._it2End) {}

                    /* Operator * implementation. */
		            const auto operator*() const {
                        return std::pair(*(_it1),*(_it2));
		            }

                    /* Operator -> implementation. */
		            auto operator->() const {
                       return std::pair(&(_it1),&(_it2));
		            }
                    
                    /* Prefix operator ++ implementation.(++i)  */
		            const_iterator& operator++() {
                        if(_it1 != _it1End && _it2 != _it2End){
                            _it1++;
                            _it2++;
                        }
                       
			            return *this;
		            }

                    /* Postfix operator ++ implementation.(i++)  */ 
		            const const_iterator operator++(int) {
                        const_iterator it = *this; 
                         ++*this; 
                        return it; 
		            }

                    /* Operator == implementation. Return true iff _it == rhs._it */
                    bool operator==(const const_iterator& rhs) const {
			            return (_it1 == rhs._it1) && (_it2 == rhs._it2);
		            }

                    /* Operator != implementation. Return true iff _it != rhs._it */
		            bool operator!=(const const_iterator& rhs) const {
			            return (_it1 != rhs._it1) && (_it2 != rhs._it2);
                    }
                

            }; // End const_iterator class.

       
            /* Returns iterator to range begin. */
            typename product::iterator begin() {
		        return product::iterator(_item1.begin(),_item1.end() ,_item2.begin(),_item2.end());
	        }
                   
            /* Returns const iterator to range begin. */
            const typename product::const_iterator begin() const {
		        return product::const_iterator(_item1.begin(),_item1.end() ,_item2.begin(),_item2.end());
	        }

            /* Returns iterator to range end. */
	        typename product::iterator end() {
		        return product::iterator(_item1.end(), _item1.end(), _item2.end(),_item2.end());
            }

            /* Returns const iterator to range end. */
	        const typename product::const_iterator end() const {
		        return product::const_iterator(_item1.end(), _item1.end(), _item2.end(),_item2.end());
            }

    }; // End product class.
    

}

