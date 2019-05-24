/**
 * A template iterator-chain class.
 * chain represent a Chaining of two psudo-containers.
 * for example ‫))‪chain(range(1,4),range(5,9‬)) represent
 * the numbers 1,2,3,5,6,7,8.
 * 
 * @author - Shay Naor and Alex Vaisman.
 */

 #pragma once

namespace itertools{

    template<typename T, typename U> 
    class chain{

        private:
            /* Private data-members. */
            T _item1;
            U _item2;

        public:

            /* Constructor. */
            chain(const T item1 , const U item2)
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
                    iterator(iterator& other)
                    : _it1(other._it1), _it1End(other._it1End), _it2(other._it2) {}

                    /* Operator * implementation. */
		            auto operator*()  {
                        if(_it1 != _it1End){
                            return *(_it1);
                        }
			            return *(_it2);
		            }

                    /* Operator -> implementation. */
		            auto operator->() const {
                        if(_it1 != _it1End){
                            return &(_it1);
                        }
			            return &(_it2);
		            }

		            /* Prefix operator ++ implementation.(++i)  */
		            iterator& operator++() {
                        if(_it1 != _it1End){
                            (_it1)++;
			                return *this;
                        }
                        (_it2)++;
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



            }; // End Iterator inner class.

             /* Iterator inner  class */
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
                    const_iterator(const_iterator& other)
                    : _it1(other._it1), _it1End(other._it1End), _it2(other._it2) {}

                    /* Operator * implementation. */
		            const auto operator*() const {
                        if(_it1 != _it1End){
                            return *(_it1);
                        }
			            return *(_it2);
		            }

                    /* Operator -> implementation. */
		            const auto operator->() const {
                        if(_it1 != _it1End){
                            return &(_it1);
                        }
			            return &(_it2);
		            }

		            /* Prefix operator ++ implementation.(++i)  */
		            const const_iterator& operator++() {
                        if(_it1 != _it1End){
                            (_it1)++;
			                return *this;
                        }
                        (_it2)++;
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



            }; // End Iterator inner class.


            /* Returns iterator to range begin. */
            typename chain::iterator begin() {
		        return chain::iterator(_item1.begin(),_item1.end() ,_item2.begin());
	        }

            /* Returns const iterator to range begin. */
            const typename chain::const_iterator begin() const {
		        return chain::const_iterator(_item1.begin(),_item1.end() ,_item2.begin());
	        }

            /* Returns iterator to range end. */
	        typename chain::iterator end() {
		        return chain::iterator(_item1.end(), _item1.end(), _item2.end());
            }

            /* Returns const iterator to range end. */
	        const typename chain::const_iterator end() const {
		        return chain::const_iterator(_item1.end(), _item1.end(), _item2.end());
            }
    }; //End chain class
}