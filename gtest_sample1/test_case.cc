#include <iostream>

#include "gtest/gtest.h"

using namespace std;

TEST(test_case1, true_test)
{
/*
	int aaa = 100;

	Stu* stu = new Stu(aaa);
	int bbb = stu->GetA();

	EXPECT_TRUE( bbb == (aaa+10) );
*/
	int i = 0;

	EXPECT_TRUE( i == 0 );
}

TEST(test_case2, false_test)
{
	int i = 0;

	EXPECT_TRUE( i == 2 );
}
