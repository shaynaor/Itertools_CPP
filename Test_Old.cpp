
#include <iostream>
using namespace std;

#include "badkan.hpp"
#include "range.hpp"
#include "chain.hpp"
#include "zip.hpp"
#include "product.hpp"
#include "powerset.hpp"

#define COMMA ,

using namespace itertools;

int main() {

	badkan::TestCase testcase;
	int grade=0;
	int signal = setjmp(badkan::longjmp_buffer);
	if (signal == 0) {
        //////////////-------range-------------/////////////
        testcase.setname("Testing range");
        string s = "";

        /* Checking numbers */
        for (auto i: range(5,9)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "5678");
        s = "";
        //----------------------------------------------------
                
        for (auto i: range(0,10)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "0123456789");
        s = "";
        //----------------------------------------------------
        
        for (auto i: range(0,1)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "0");
        s = "";
        //----------------------------------------------------
        for (auto i: range(8,9)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "8");
        s = "";
        //----------------------------------------------------
        for (auto i: range(3,8)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "34567");
        s = "";
        //----------------------------------------------------
        for (auto i: range(5.0,9.0)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "5.0000006.0000007.0000008.000000");
        s = "";
        //----------------------------------------------------
        for (auto i: range(0.0,1.0)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "0.000000");
        s = "";
         //----------------------------------------------------   
        for (auto i: range(0.0,5.0)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "0.0000001.0000002.0000003.0000004.000000");
        s = "";
         //----------------------------------------------------   
        for (auto i: range(3.0,4.0)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "3.000000");
        s = "";
         //----------------------------------------------------   
        for (auto i: range(7.0,9.0)){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "7.0000008.000000");
        s = "";

        /* checking letters */

         //----------------------------------------------------    
        for (auto i: range('a','e')){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "abcd");
        s = "";
         //----------------------------------------------------    
        for (auto i: range('x','z')){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "xy");
        s = "";
         //----------------------------------------------------    
        for (auto i: range('c','f')){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "cde");
        s = "";
         //----------------------------------------------------    
        for (auto i: range('g','k')){
            s+= i; 
        }   
        testcase.CHECK_OUTPUT(s, "ghij");
        s = "";
         //----------------------------------------------------    
        for (auto i: range('d','e')){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "d");
        s = "";

         //----------------------------------------------------    
        for (auto i: range('A','B')){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "A");
        s = "";
         //----------------------------------------------------    
        for (auto i: range('G','K')){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "GHIJ");
        s = "";

        //////////////-------chain-------------/////////////
        testcase.setname("Testing chain");
        //----------------------------------------------------
        for (auto i: chain(range(1,4), range(5,8))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "123567");
        s = "";
        //---------------------------------------------------- 
        for (auto i: chain(range(0,2), range(7,8))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "017");
        s = "";
         //----------------------------------------------------
        for (auto i: chain(range(2,4), range(0,4))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "230123");
        s = "";
         //----------------------------------------------------
        for (auto i: chain(range(10,14), range(0,5))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "1011121301234");
        s = "";
         //----------------------------------------------------
        for (auto i: chain(range(6,9), range(9,11))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "678910");
        s = "";
        //---------------------------------------------------- 
        for (auto i: chain(range(6.1,9.1), range(9.1,11.1))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "6.1111117.1111118.1111119.11111110.111111");
        s = "";
         //----------------------------------------------------
        for (auto i: chain(range(2.0,3.0), range(7.2,8.2))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "2.0000007.222222");
        s = "";
         //----------------------------------------------------
        for (auto i: chain(range(0.0,2.0), range(4.0,5.0))){
            s+=to_string(i) ; 
        }   
        testcase.CHECK_OUTPUT(s, "0.0000001.0000004.000000");
        s = "";
        
        /* Cheking letters */
         //---------------------------------------------------- 
        for (auto i: chain(range('a','b'), range('b','c'))){
            s+= i; 
        }   
        testcase.CHECK_OUTPUT(s, "ab");
        s = "";
         //---------------------------------------------------- 
        for (auto i: chain(range('d','f'), range('D','F'))){
            s+= i; 
        }   
        testcase.CHECK_OUTPUT(s, "deDE");
        s = "";
         //---------------------------------------------------- 
        for (auto i: chain(range('r','t'), range('n','p'))){
            s+= i; 
        }   
        testcase.CHECK_OUTPUT(s, "rjklmnopqrsno");
        s = "";
         //---------------------------------------------------- 
        for (auto i: chain(range('A','C'), string("hii"))){
            s+= i; 
        }   
        testcase.CHECK_OUTPUT(s, "ABhii");
        s = "";
        //----------------------------------------------------  
        for (auto i: chain(range('d','f'), string("shuki"))){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "deshuki");
        s = "";
         //---------------------------------------------------- 
        for (auto i: chain(string("hello"), string("world"))){
            s+= i ; 
        }   
        testcase.CHECK_OUTPUT(s, "helloworld");
        s = "";

        //////////////-------ZIP-------------/////////////
        testcase.setname("Testing zip");

        ostringstream str;
        //----------------------------------------------------
        for (auto pair: zip(range(1,6), string("hello"))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "1,h2,e3,l4,l5,o");
		str.str("");
        str.clear();
        s = "";
        //----------------------------------------------------
        for (auto pair: zip(range(1,10), string("abcdefghi"))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "1,a2,b3,c4,d5,e6,f7,g8,h9,i");
		str.str("");
        str.clear();
        s = "";
        //----------------------------------------------------
        for (auto pair: zip(string("hlool"), string("elwrd"))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "h,el,lo,wo,rl,d");
		str.str("");
        str.clear();
        s = "";
        //----------------------------------------------------
        for (auto pair: zip(range(6,11), range(1,6))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "6,17,28,39,410,5");
		str.str("");
        str.clear();
        s = "";
        //----------------------------------------------------
        for (auto pair: zip(range(2.2,5.5), range('a','d'))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "2.2,a3.2,b4.2,c");
		str.str("");
        str.clear();
        s = "";
        //----------------------------------------------------
        for (auto pair: zip(range(5.1,7.1), range(0.1,2.1))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "5.1,0.16.1,1.1");
		str.str("");
        str.clear();
        s = "";
         //----------------------------------------------------
        for (auto pair: zip(range(1,6), range('a','f'))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "1,a2,b3,c4,d5,e");
		str.str("");
        str.clear();
        s = "";
        //----------------------------------------------------
        for (auto pair: zip(zip(range(1,4), string("xyz")),zip(string("abc"),range(6,9)))){
            str << pair;
        }
        
        s = str.str();
        testcase.CHECK_OUTPUT(s, "1,x,a,6  2,y,b,7  3,z,c,8");
		str.str("");
        str.clear();
        s = "";
        

        
         //////////////-------product-------------/////////////
        testcase.setname("Testing product");

        //----------------------------------------------------
        for (auto pair: product(range(1,4), string("hello"))){
          str << pair;
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "1,h1,e1,l1,l1,o2,h2,e2,l2,l2,o3,h3,e3,l3,l3,o");
		str.str("");
        str.clear();
        s = "";

        //----------------------------------------------------
        for (auto pair: product(range(5,6), string("z"))){
          str << pair;
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "5,z");
		str.str("");
        str.clear();
        s = "";


        //----------------------------------------------------
        for (auto pair: product(range(5.0,6.0), string("z"))){
          str << pair;
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "5.0,z");
		str.str("");
        str.clear();
        s = "";


        //----------------------------------------------------
        for (auto pair: product(range('a','c'), string("ce"))){
          str << pair;
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "a,ca,eb,cb,e");
		str.str("");
        str.clear();
        s = "";

         //----------------------------------------------------
        for (auto pair: product(range('a','b'), range(1, 4))){
          str << pair;
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "a,1a,2a,3");
		str.str("");
        str.clear();
        s = "";

         //----------------------------------------------------
        for (auto pair: product(range(5,7), range(1, 4))){
          str << pair;
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "5,15,25,36,16,26,3");
		str.str("");
        str.clear();
        s = "";

    //////////////-------powerset-------------/////////////

    //----------------------------------------------------
	    for (auto subset: powerset(range(1,4))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{1}{2}{1,2}{3}{1,3}{2,3}{1,2,3}");
		str.str("");
        str.clear();
        s = "";

    //----------------------------------------------------
	    for (auto subset: powerset(chain(range('a','c'),range('x','z')))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{a}{b}{a,b}{x}{a,x}{b,x}{a,b,x}{y}{a,y}{b,y}{a,b,y}{x,y}{a,x,y}{b,x,y}{a,b,x,y}");
		str.str("");
        str.clear();
        s = "";

        //----------------------------------------------------
	    for (auto subset: powerset(chain(range(1,2),range(3,4)))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{1}{3}{1,3}");
		str.str("");
        str.clear();
        s = "";

        //----------------------------------------------------
	    for (auto subset: powerset(chain(range(1.1,2.1),range(3.1,4.1)))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{1.1}{3.1}{1.1,3.1}");
		str.str("");
        str.clear();
        s = "";


        //----------------------------------------------------
	    for (auto subset: powerset(chain(range('a','b'),range('c','d')))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{a}{c}{a,c}");
		str.str("");
        str.clear();
        s = "";


        //----------------------------------------------------
	    for (auto subset: powerset(chain(range('a','b'),range(1,2)))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{a}{1}{a,1}");
		str.str("");
        str.clear();
        s = "";


        //----------------------------------------------------
	    for (auto subset: powerset(chain(range(1,2),range('a','b')))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{1}{a}{1,a}");
		str.str("");
        str.clear();
        s = "";


        //----------------------------------------------------
	    for (auto subset: powerset(chain(range(1.2,2.2),range('a','b')))){
           str << subset; 
        }
		
        s = str.str();
        testcase.CHECK_OUTPUT(s, "{}{1.2}{a}{1.2,a}");
		str.str("");
        str.clear();
        s = "";









        
    grade = testcase.grade();
	} else {
		testcase.print_signal(signal);
		grade = 0;
	}
	cout << "Your grade is: "  << grade << endl;
	return 0;
}//End of main.




