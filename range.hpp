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








            /* Inner const_iterator class */
            class const_iterator{

                private:
                    /* Private data-members.*/
                     T _it;

                public:
                    /* Constructor.  */
                    const_iterator(T item)
                    : _it(item){}
                    
                    /* Copy constructor. */
                    const_iterator(const_iterator& other){
                        this->_it = other->_it;
                    }

                    /* Operator * implementation. Returns a reference T */
		            const T& operator*() const {
			            return _it;
		            }

                    /* Operator -> implementation. */
		            T* operator->() const {
			            return &(_it);
		            }

		            /* Prefix operator ++ implementation.(++i)  */
		            const_iterator& operator++() {
                        _it += 1;
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
			            return _it == rhs._it;
		            }

                    /* Operator != implementation. Return true iff _it != rhs._it */
		            bool operator!=(const const_iterator& rhs) const {
			            return _it != rhs._it;
                    }


            }; // End const_iterator inner class.













            /* Returns iterator to range begin. */
            iterator begin() {
		        return iterator(_begin);
	        }

            /* Returns const iterator to range begin. */
            const const_iterator begin() const {
		        return const_iterator(_begin);
	        }

            /* Returns iterator to range end. */
	        iterator end() {
		        return iterator(_end);
            }

            /* Returns const iterator to range end. */
	        const const_iterator end() const{
		        return const_iterator(_end);
            }

       
    }; // End range class.
}

    