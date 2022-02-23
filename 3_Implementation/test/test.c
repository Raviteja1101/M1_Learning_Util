#include "unity.h"
#include <employee_records.h>

#include <emplyee_record.h>
#define PROJECT_NAME    "employee record system"
void add( void );
void delete( void );
void modify(void);
void list(void);
/* Required by the unity test framework */
void setUp(){}
/* Required by the unity test framework */
void tearDown(){}

/* Start of the application test */
int main()
{
/* Initiate the Unity Test Framework */
  UNITY_BEGIN();

/* Run Test functions */
  RUN_TEST(add);
  RUN_TEST(delete);
  RUN_TEST(modify);
  RUN_TEST(list);
  

  /* Close the Unity Test Framework */
  return UNITY_END();
}

/* Write all the test functions */ 
void add( void ) {
  TEST_ASSERT_EQUAL('*', add( void ));
  
}

void delete( void ) {
  TEST_ASSERT_EQUAL('B', delete( void ));

}
void modify( void ) {
  TEST_ASSERT_EQUAL('*', modify( void ));
  
}
void list( void ) {
  TEST_ASSERT_EQUAL('*', list( void ));
  
}