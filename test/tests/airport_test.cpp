#include "CppUTest/TestHarness.h"
#include "Airport.h"

TEST_GROUP(TestAirport) { 
	TEST_SETUP(){
		Airport__INITIALISATION();
	    // MemoryLeakWarningPlugin::turnOnNewDeleteOverloads();
	}
};

TEST(TestAirport, testCanLandAiportEmpty) {
	int32_t track = 0;
	bool result;
	Airport__can_landing(track, &result);

	CHECK(result);
}

TEST(TestAirport, testCanOccupiedLand) {
	Airport_ctx__AIRPLANE plane = 66;
	Airport__add_airplane(plane);

	int32_t track = 4;	
	Airport__land(plane, track);

	bool result;
	Airport__can_landing(track, &result);

	CHECK(!result);
}

TEST(TestAirport, testGateResultAirplaneParked) {
	Airport_ctx__AIRPLANE plane = 77;
	Airport__add_airplane(plane);

	int32_t track = 3;	
	Airport__land(plane, track);

	int32_t gate = 4;
	Airport__park(plane, gate);


	int32_t gate_result;
	Airport__query_parked(plane, &gate_result);

	CHECK_EQUAL(gate, gate_result);
}


TEST(TestAirport, statusAirplaneOut) {
	Airport_ctx__AIRPLANE plane = 1;

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__out, status_result);
}

TEST(TestAirport, statusAirplaneAdded) {
	Airport_ctx__AIRPLANE plane = 2;
	Airport__add_airplane(plane);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__flighting, status_result);
}

TEST(TestAirport, statusAirplaneLanding) {
	Airport_ctx__AIRPLANE plane = 3;
	Airport__add_airplane(plane);

	int32_t track = 1;
	Airport__land(plane, track);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__alighting, status_result);
}

TEST(TestAirport, statusAirplaneParking) {
	Airport_ctx__AIRPLANE plane = 4;
	Airport__add_airplane(plane);

	int32_t track = 2;
	Airport__land(plane, track);

	int32_t gate = 1;
	Airport__park(plane, gate);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__parked, status_result);
}

TEST(TestAirport, statusAirplaneBoarding) {
	Airport_ctx__AIRPLANE plane = 5;
	Airport__add_airplane(plane);

	int32_t track = 2;
	Airport__land(plane, track);

	int32_t gate = 1;
	Airport__park(plane, gate);

	Airport__board(plane);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__boarding, status_result);
}

TEST(TestAirport, statusAirplaneTakingTrack) {
	Airport_ctx__AIRPLANE plane = 6;
	Airport__add_airplane(plane);

	int32_t track = 2;
	Airport__land(plane, track);

	int32_t gate = 1;
	Airport__park(plane, gate);

	Airport__board(plane);

	Airport__take_track(plane, track);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__departing, status_result);
}

TEST(TestAirport, statusAirplaneDeparting) {
	Airport_ctx__AIRPLANE plane = 7;
	Airport__add_airplane(plane);

	int32_t track = 2;
	Airport__land(plane, track);

	int32_t gate = 1;
	Airport__park(plane, gate);
	Airport__board(plane);
	Airport__take_track(plane, track);
	Airport__depart(plane);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__flighting, status_result);
}

TEST(TestAirport, statusExcludeAirplane) {
	Airport_ctx__AIRPLANE plane = 8;
	Airport__add_airplane(plane);
	Airport__exclude_airplane(plane);

	Airport_ctx__STATUS status_result;
	Airport__query_status(plane, &status_result);

	CHECK_EQUAL(Airport_ctx__out, status_result);
}