/**
 * An example of how to write unit tests.
 * Use this as a basis to build a more complete Test.cpp file.
 * 
 * IMPORTANT: Please write more tests - the tests here are only for example and are not complete.
 *
 * AUTHORS: Inon Sinn
 * 
 * Date: 2021-02
 */

#include "doctest.h"
#include "mat.hpp"
using namespace ariel;

#include <string>
#include <algorithm>
using namespace std;

/**
 * Returns the input string without the whitespace characters: space, newline and tab.
 * Requires std=c++2a.
 */
string nospaces(string input) {
	std::erase(input, ' ');
	std::erase(input, '\t');
	std::erase(input, '\n');
	std::erase(input, '\r');
	return input;
}


TEST_CASE("Good input") {
	CHECK(nospaces(mat(9, 7, '@', '-')) == nospaces("@@@@@@@@@\n"
													 "@-------@\n"
													 "@-@@@@@-@\n"
													 "@-@---@-@\n"
													 "@-@@@@@-@\n"
													 "@-------@\n"
													 "@@@@@@@@@"));
	/* Add more test here */


	// Test 1-3 small areas
	CHECK(nospaces(mat(1, 1, '@', '-')) == nospaces("@"));

	CHECK(nospaces(mat(1, 3, '@', '-')) == nospaces("@\n"
													"@\n"
													"@"));

	CHECK(nospaces(mat(3, 1, '@', '-')) == nospaces("@@@"));


	// Test 4-6 same symbols
	CHECK(nospaces(mat(1, 1, '*', '*')) == nospaces("*"));

	CHECK(nospaces(mat(3, 3, '*', '*')) == nospaces("***\n"
													"***\n"
													"***"));

	CHECK(nospaces(mat(5, 3, '*', '*')) == nospaces("*****\n"
													"*****\n"
													"*****"));


	// Test 7-10 Rectangles
	CHECK(nospaces(mat(7, 1, '&', '^')) == nospaces("&&&&&&&"));

	CHECK(nospaces(mat(1, 7, '&', '^')) == nospaces("&\n"
													"&\n"
													"&\n"
													"&\n"
													"&\n"
													"&\n"
													"&\n"));

	CHECK(nospaces(mat(3, 5, '&', '^')) == nospaces("&&&\n"
													"&^&\n"
													"&^&\n"
													"&^&\n"
													"&&&"));

	CHECK(nospaces(mat(5, 3, '&', '^')) == nospaces("&&&&&\n"
													"&^^^&\n"
													"&&&&&"));


	// Test 11-14 Big Tests
	CHECK(nospaces(mat(3, 3, '#', '-')) == nospaces("###\n"
													"#-#\n"
													"###"));	

	CHECK(nospaces(mat(5, 5, '#', '-')) == nospaces("#####\n"
													"#---#\n"
													"#-#-#\n"
													"#---#\n"
													"#####"));		

	CHECK(nospaces(mat(7, 7, '#', '-')) == nospaces("#######\n"
													"#-----#\n"
													"#-###-#\n"
													"#-#-#-#\n"
													"#-###-#\n"
													"#-----#\n"
													"#######"));	
													
	CHECK(nospaces(mat(9, 9, '#', '-')) == nospaces("#########\n"
													"#-------#\n"
													"#-#####-#\n"
													"#-#---#-#\n"
													"#-#-#-#-#\n"
													"#-#---#-#\n"
													"#-#####-#\n"
													"#-------#\n"
													"#########"));

}

TEST_CASE("Bad input") {

	// Test 1-3 - zero test
	CHECK_THROWS(mat(0, 0, '*', '-'));
	CHECK_THROWS(mat(5, 0, '*', '-'));
	CHECK_THROWS(mat(0, 5, '*', '-'));

	// Test 4-6 - negative tests
	CHECK_THROWS(mat(-1, -1, '~', '$'));
	CHECK_THROWS(mat(-5, 5, '~', '$'));
	CHECK_THROWS(mat(5, -5, '~', '$'));

	// Test 7-9 odd numbers tests
	CHECK_THROWS(mat(2, 2, '%', '#'));
	CHECK_THROWS(mat(2, 5, '%', '#'));
	CHECK_THROWS(mat(5, 2, '%', '#'));

	// Test 10-12 wrong Symbols - check if needed
	// CHECK_THROWS(mat(1, 1, ' ', '*'));
	// CHECK_THROWS(mat(1, 1, '\t', '*'));
	// CHECK_THROWS(mat(1, 1, '\n', '*'));
	// CHECK_THROWS(mat(1, 1, '\r', '*'));


}
