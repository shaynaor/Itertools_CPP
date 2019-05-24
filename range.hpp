/**
 * A template iterator-range class.
 * range represent a range of numbers.
 * for example range(a,b) for a,b natural numbers,
 * represent the natural numbers between a to b, [a,b).
 * 
 * @author - Shay Naor and Alex Vaisman.
 */

 #pragma once

namespace itertools{

   template<typename T> 
   class range { 

        private:
            /* Private data-members */
            T _begin;
            T _end;
        
        public:

            /* Constructor. */
            range(const T begin, const T end)
            : _begin (begin), _end(end) {}

            /* Inner iterator class */
            class iterator{

                private:
                    /* Private data-members.*/
                     T _it;

                public:
                    /* Constructor.  */
                    iterator(T item)
                    : _it(item){}

                    /* Operator * implementation. Returns a reference T */
		            T& operator*() {
			            return _it;
		            }

                    /* Operator -> implementation. */
		            T* operator->() const {
			            return &(_it);
		            }

		            /* Prefix operator ++ implementation.(++i)  */
		            iterator& operator++() {
                        _it += 1;
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
			            return _it == rhs._it;
		            }

                    /* Operator != implementation. Return true iff _it != rhs._it */
		            bool operator!=(const iterator& rhs) const {
			            return _it != rhs._it;
                    }


            }; // End iterator inner class.

            /* Returns iterator to range begin. */
            iterator begin() {
		        return iterator(_begin);
	        }

            /* Returns iterator to range end. */
	        iterator end() {
		        return iterator(_end);
            }

       
    }; // End range class.
}

    