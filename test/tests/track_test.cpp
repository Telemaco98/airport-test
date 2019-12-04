#include "CppUTest/TestHarness.h"
#include "Track.h"

TEST_GROUP(TestTrack) { 
	TEST_SETUP(){
		Track__INITIALISATION();
	}
};


TEST(TestTrack, testOccupyGate) {
	int32_t track = 4;
	Airport_ctx__AIRPLANE plane = 63;
	Track__occupy_track(track, plane);

	bool bb;
	Track__is_track_occupied(track, &bb);
	
	Airport_ctx__AIRPLANE plane_result;
	Track__track_belongs_to(track, &plane_result);

	CHECK_EQUAL(true, bb);
	CHECK_EQUAL(plane, plane_result);
}

TEST(TestTrack, testVacateGate) {
	int32_t track = 3;
	Airport_ctx__AIRPLANE plane = 55;
	Track__occupy_track(track, plane);

	bool bb;
	
	Track__is_track_occupied(track, &bb);
	CHECK_EQUAL(true, bb);
	
	Track__vacate_track(track);
	
	Track__is_track_occupied(track, &bb);
	CHECK_EQUAL(false, bb);
}

TEST(TestTrack, testBelongsTo) {
	int32_t track = 2;
	Airport_ctx__AIRPLANE plane = 73;

	Track__occupy_track(track, plane);
	
	Airport_ctx__AIRPLANE plane_result;
	Track__track_belongs_to(track, &plane_result);

	CHECK_EQUAL(plane, plane_result);
}

/**
 * Test para falhar
 */
TEST(TestTrack, testDontBelongsTo) {
	int32_t track_1 = 11;
	Airport_ctx__AIRPLANE plane_1 = 98;
	Track__occupy_track(track_1, plane_1);

	int32_t track_2 = 12;
	Airport_ctx__AIRPLANE plane_2 = 99;	
	Track__occupy_track(track_2, plane_2);

	Airport_ctx__AIRPLANE plane_result_1;
	Track__track_belongs_to(track_1, &plane_result_1);

	CHECK_EQUAL(plane_2, plane_result_1);
}