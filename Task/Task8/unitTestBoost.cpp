#define BOOST_TEST_MODULE example
#include <boost/test/included/unit_test.hpp>
#include "singletone.h"

BOOST_AUTO_TEST_SUITE( test_suite )

BOOST_AUTO_TEST_CASE( test_case1 )
{
  //create an instance of SingletonDatabaseCar
  SingletonDatabaseCar &database = SingletonDatabaseCar::get();

  //check the number of cars for a certain brand
  //check if the number for a brand in database is correct  
  BOOST_CHECK_EQUAL(database.get_nbCar("Aston Martin"), 2);
  BOOST_TEST_MESSAGE( "The number of brand ASton Martin in the database is correct" );

  BOOST_CHECK_EQUAL(database.get_nbCar("Toyota"), 1789);
  BOOST_TEST_MESSAGE( "The number of brand Toyota in the database is correct" );  
}

BOOST_AUTO_TEST_CASE( test_case2 )
{
  //create an instance of SingletonDatabaseCar
  SingletonDatabaseCar &database = SingletonDatabaseCar::get();
 
  //check if the car brand is not in the database will return 0 
  BOOST_CHECK_EQUAL(database.get_nbCar("BMW"), 0);
  BOOST_TEST_MESSAGE( "The BMW brand car doesn't exist in the database and it returns 0" );  
}

BOOST_AUTO_TEST_CASE( test_case3 )
{
  //create an instance of SingletonDatabaseCar
  SingletonDatabaseCar &database = SingletonDatabaseCar::get();
  
  //check if the car brand is in the database but with the incorrect number of cars will give an error
  BOOST_CHECK_EQUAL(database.get_nbCar("Mercedes"), 3);   
}

BOOST_AUTO_TEST_CASE( test_case4 )
{
  //create an instance of SingletonDatabaseCar
  SingletonDatabaseCar &database1 = SingletonDatabaseCar::get();
  //create a second instance of SingletonDatabaseCar
  SingletonDatabaseCar &database2 = SingletonDatabaseCar::get();

  //test if both instances point to the same object
  BOOST_CHECK_EQUAL(&database1, &database2);
  BOOST_TEST_MESSAGE( "the 2 instances point to the same SingletonDatabaseCar object" );  
}

BOOST_AUTO_TEST_SUITE_END()

