/**
 * A template iterator-powerset class.
 * powerset represent all sub-sets of psudo-containers.
 * For example powerset(range(1,4)) represent:
 *  {}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}
 * 
 * @author - Shay Naor and Alex Vaisman.
 */

#pragma once

namespace itertools{
    template<typename T> 
    class powerset{
         private:
            /* Private data-members. */
            T _item;

        public:
            /* Constructor. */
            powerset(const T item)
            : _item(item) {}

            /* Iterator inner  class */
            class iterator{

                private:
                    /* Private data-members. */
                    typename T::iterator _it;
                
                public:

                    /* Constructor. */
                    iterator(typename T::iterator it)
                    : _it(it) {}

                    /* Operator * implementation. */
		            auto operator*()  {
                        std::string s = "{}";
                        return s;
		            }

                    /* Prefix operator ++ implementation.(++i)  */
		            iterator& operator++() {
                        _it++;
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
			            return (_it == rhs._it);
		            }

                    /* Operator != implementation. Return true iff _it != rhs._it */
		            bool operator!=(const iterator& rhs) const {
			            return (_it != rhs._it);
                    }


            }; // End class iterator

             /* Returns iterator to range begin. */
            typename powerset::iterator begin() {
		        return powerset::iterator(_item.begin());
	        }

            /* Returns iterator to range end. */
	        typename powerset::iterator end() {
		        return powerset::iterator(_item.end());
            }


    }; // End class powerset.

}//End namespace itertools