/**
 * Unit Tests for Password class
**/

#include <gtest/gtest.h>
#include "Password.h"

class PracticeTest : public ::testing::Test
{
	protected:
		PracticeTest(){} //constructor runs before each test
		virtual ~PracticeTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor)
};

TEST(PasswordTest, single_letter_password)
{
	Password my_password;
	int actual = my_password.count_leading_characters("Z");
	ASSERT_EQ(1, actual);
}

TEST(PasswordTest, MixedCaseTrue) {
    Password password;
    ASSERT_TRUE(password.has_mixed_case("Abc"));
}

TEST(PasswordTest, CaseEmpty) {
    Password password;
    ASSERT_EQ(0, password.count_leading_characters(""));
}

TEST(PasswordTest, CaseSingleCharacter) {
    Password password;
    ASSERT_EQ(1, password.count_leading_characters("A"));
}

TEST(PasswordTest, MixedCaseWithNumbers) {
    Password password;
    ASSERT_TRUE(password.has_mixed_case("a1B2c3"));
}

TEST(PasswordTest, AllLowercase) {
    Password password;
    ASSERT_FALSE(password.has_mixed_case("aaaa"));
}

TEST(PasswordTest, AllUppercase) {
    Password password;
    ASSERT_FALSE(password.has_mixed_case("AAAA"));
}

TEST(PasswordTest, AllIdenticalCharacters) {
    Password password;
    ASSERT_EQ(5, password.count_leading_characters("AAAAA"));
}

TEST(PasswordTest, WithWhitespaceAndSpecialChars) {
    Password password;
    ASSERT_FALSE(password.has_mixed_case("   @#$"));
}
