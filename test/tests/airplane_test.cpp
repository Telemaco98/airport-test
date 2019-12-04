#include "CppUTest/TestHarness.h"
#include "Airplane.h"

TEST_GROUP(TestAirplane) { 
	TEST_SETUP(){
		Airplane__INITIALISATION();
	}
};

TEST(TestAirplane, testAddPlane) {
	Airport_ctx__AIRPLANE aa = 10;
	Airplane__add_plane(aa);

	bool bb;
	Airplane__has_airplane(aa, &bb);
	printf("%d\n", bb);

	CHECK_EQUAL(true, bb);
}

TEST(TestAirplane, testDeletePlane) {
	Airport_ctx__AIRPLANE aa = 30;
	Airplane__add_plane(aa);
	Airplane__remove(aa);

	bool bb;
	Airplane__has_airplane(aa, &bb);

	CHECK_EQUAL(false, bb);
}

TEST(TestAirplane, testHasNonexistentPlane){
	Airport_ctx__AIRPLANE aa = 30;
	
	bool bb;
	Airplane__has_airplane(aa, &bb);

	CHECK_EQUAL(false, bb);
}