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

                    /* Copy constructor. */
                    iterator(const iterator& other)
                    : _it(other._it) {}

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








            /* const_iterator inner  class */
            class const_iterator{

                private:
                    /* Private data-members. */
                    typename T::const_iterator _it;
                
                public:

                    /* Constructor. */
                    const_iterator(typename T::const_iterator it)
                    : _it(it) {}

                    /* Copy constructor. */
                    const_iterator(const const_iterator& other)
                    : _it(other._it) {}

                    /* Operator * implementation. */
		            const auto operator*() const {
                        std::string s = "{}";
                        return s;
		            }

                    /* Prefix operator ++ implementation.(++i)  */
		            const_iterator& operator++() {
                        _it++;
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
			            return (_it == rhs._it);
		            }

                    /* Operator != implementation. Return true iff _it != rhs._it */
		            bool operator!=(const const_iterator& rhs) const {
			            return (_it != rhs._it);
                    }


            }; // End class const_iterator









             /* Returns iterator to range begin. */
            typename powerset::iterator begin() {
		        return powerset::iterator(_item.begin());
	        }

             /* Returns const iterator to range begin. */
            const typename powerset::const_iterator begin() const {
		        return powerset::const_iterator(_item.begin());
	        }

            /* Returns iterator to range end. */
	        typename powerset::iterator end() {
		        return powerset::iterator(_item.end());
            }

            /* Returns const iterator to range end. */
	        const typename powerset::const_iterator end() const {
		        return powerset::const_iterator(_item.end());
            }


    }; // End class powerset.

}//End namespace itertools