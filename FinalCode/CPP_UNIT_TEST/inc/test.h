#pragma once

#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<arpa/inet.h>
#include<vector>
#include<algorithm>
#include<cppunit/extensions/HelperMacros.h>

using namespace std;

class testNetstat : public CPPUNIT_NS::TestFixture
{
	CPPUNIT_TEST_SUITE( testNetstat );  
	CPPUNIT_TEST( testConnection_UT_sunny );
	CPPUNIT_TEST( testConnection_UT_rainy );
	CPPUNIT_TEST( testRouting_UT_sunny );
	CPPUNIT_TEST( testRouting_UT_rainy );
	CPPUNIT_TEST( testTCP_UT_sunny );
	CPPUNIT_TEST( testTCP_UT_rainy );
	CPPUNIT_TEST( testUDP_UT_sunny );
	CPPUNIT_TEST( testUDP_UT_rainy );
	CPPUNIT_TEST( testLISTEN_UT_sunny );
	CPPUNIT_TEST( testLISTEN_UT_rainy );
	CPPUNIT_TEST( testFirefox_UT_sunny );
	CPPUNIT_TEST( testFirefox_UT_rainy );
	CPPUNIT_TEST_SUITE_END();


	public:
		void setUp();
	        void setConnection(){}
		string getConnection(){}
		void setRouting(string name){string routing = name;}
		string getRouting(){return routing;}
		void setTCP(string name){string tcp = name;}
		string getTCP(){return tcp;}
		void setUDP(string name){string udp = name;}
		string getUDP(){return udp;}
		void setLISTEN(string name){string listen = name;}
		string getLISTEN(){return listen;}
		void setFirefox(string name){string firefox = name;}
		string getFirefox(){return firefox;}

	private:
		string routing;
		string tcp;
		string udp;
		string listen;
		string firefox;


			

	protected:
		void testConnection_UT_sunny();
		void testConnection_UT_rainy();
		void testRouting_UT_sunny();
		void testRouting_UT_rainy();
		void testTCP_UT_sunny();
		void testTCP_UT_rainy();
		void testUDP_UT_sunny();
		void testUDP_UT_rainy();
		void testLISTEN_UT_sunny();
		void testLISTEN_UT_rainy();
		void testFirefox_UT_sunny();
		void testFirefox_UT_rainy();
};

