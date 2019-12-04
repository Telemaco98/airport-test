#include "CppUTest/TestHarness.h"
#include "Gate.h"

TEST_GROUP(TestGate) { 
	TEST_SETUP(){
		Gate__INITIALISATION();
	}
};

TEST(TestGate, testOccupyGate) {
	int32_t gate = 2;
	Airport_ctx__AIRPLANE plane = 1;
	Gate__occupy_gate(gate, plane);

	bool bb;
	Gate__is_gate_occupied(gate, &bb);
	
	Airport_ctx__AIRPLANE plane_result;
	Gate__gate_belongs_to(gate, &plane_result);

	CHECK_EQUAL(true, bb);
	CHECK_EQUAL(plane, plane_result);
}

TEST(TestGate, testVacateGate) {
	int32_t gate = 7;
	Airport_ctx__AIRPLANE plane = 56;
	
	Gate__occupy_gate(gate, plane);
	Gate__vacate_gate(gate);
	
	bool bb;
	Gate__is_gate_occupied(gate, &bb);

	CHECK_EQUAL(false, bb);
}

TEST(TestGate, testBelongsTo) {
	int32_t gate = 8;
	Airport_ctx__AIRPLANE plane = 65;

	Gate__occupy_gate(gate, plane);
	
	Airport_ctx__AIRPLANE plane_result;
	Gate__gate_belongs_to(gate, &plane_result);

	CHECK_EQUAL(plane, plane_result);
}