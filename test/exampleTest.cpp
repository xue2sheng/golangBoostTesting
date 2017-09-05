#define BOOST_TEST_MAIN
#define BOOST_TEST_MODULE exampleTest

#include <boost/test/included/unit_test.hpp>
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_CASE( test000 ) {	
   BOOST_TEST_MESSAGE( "\ntest000: example" );

   BOOST_CHECK( true );
}
