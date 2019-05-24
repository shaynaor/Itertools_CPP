/**
 * A template iterator-zip class.
 * zip represent a zipping of two psudo-containers.
 * for example ‫))‪zip(range(1,6), string("hello")) represent
 * 1,h  2,e  3,l  4,l  5,o .
 * 
 * @author - Shay Naor and Alex Vaisman.
 */

#pragma once
#include <iostream>

namespace itertools{

    template<typename T, typename U> 
    class zip{
         private:
            /* Private data-members. */
            T _item1;
            U _item2;

        public:

            /* Constructor. */
            zip(const T item1 , const U item2)
            : _item1(item1), _item2(item2) {}

            /* Iterator inner  class */
            class iterator{

                private:
                    /* Private data-members. */
                    typename T::iterator _it1;
                    typename T::iterator _it1End;
                    typename U::iterator _it2;

                public:
                    /* Constructor. */
                    iterator(typename T::iterator item1,typename T::iterator item1End , typename U::iterator item2)
                    : _it1(item1), _it1End(item1End), _it2(item2) {}

                    /* Copy constructor */
                    iterator(const iterator &other)
                    : _it1(other._it1), _it1End(other._it1End), _it2(other._it2) {}
                    

                    /* Operator * implementation. */
		            auto operator*()  {
                        return pair(*(_it1),*(_it2));
		            }

                    /* Operator -> implementation. */
		            auto operator->() const {
                       return pair(&(_it1),&(_it2));
		            }
                    
                    /* Prefix operator ++ implementation.(++i)  */
		            iterator& operator++() {
                        _it1++;
                        _it2++;
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



            /* cont_Iterator inner  class */
            class const_iterator{

                private:
                    /* Private data-members. */
                    typename T::const_iterator _it1;
                    typename T::const_iterator _it1End;
                    typename U::const_iterator _it2;

                public:
                    /* Constructor. */
                    const_iterator(typename T::const_iterator item1,typename T::const_iterator item1End , typename U::const_iterator item2)
                    : _it1(item1), _it1End(item1End), _it2(item2) {}

                    /* Copy constructor */
                    const_iterator(const const_iterator &other)
                    :_it1(other._it1), _it1End(other._it1End), _it2(other._it2) {}

                    /* Operator * implementation. */
		            const auto operator*() const {
                        return pair(*(_it1),*(_it2));
		            }

                    /* Operator -> implementation. */
		            const auto operator->() const {
                       return pair(&(_it1),&(_it2));
		            }
                    
                    /* Prefix operator ++ implementation.(++i)  */
		            const_iterator& operator++() {
                        _it1++;
                        _it2++;
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

            }; // End const_itetator class.


            /* Returns iterator to range begin. */
            typename zip::iterator begin() {
		        return zip::iterator(_item1.begin(),_item1.end() ,_item2.begin());
	        }

            /* Returns const iterator to range begin. */
            const typename zip::const_iterator begin() const {
		        return zip::const_iterator(_item1.begin(),_item1.end() ,_item2.begin());
	        }

            /* Returns iterator to range end. */
	        typename zip::iterator end() {
		        return zip::iterator(_item1.end(), _item1.end(), _item2.end());
            }

            /* Returns const iterator to range end. */
	        const typename zip::const_iterator end() const {
		        return zip::const_iterator(_item1.end(), _item1.end(), _item2.end());
            }

    }; // End zip class.

/* Pair class */
template <typename T, typename U> 
class pair {
    private:
        /* Private data-members. */
	    T _first;
	    U _second;

    public:

        /* Constructor. */
        pair(const T first, const U second):
        _first(first), _second(second) {}



    template <typename T1, typename T2>
    friend std::ostream& operator <<(std::ostream& os, const pair<T1,T2> thepair);

}; // End pair class.



} // End namespace iteratortools


/* Operator << implementation. */
template <typename T1, typename T2> 
ostream& operator<< (ostream& out, 
const pair<T1,T2>& thepair) {
	out << thepair.first << "," << thepair.second;
	return out;
}