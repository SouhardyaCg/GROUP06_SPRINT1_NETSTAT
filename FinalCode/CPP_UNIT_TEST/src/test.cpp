#include<test.h>
#include<cppunit/config/SourcePrefix.h>
#include<string>
#include<algorithm>
#include<netstat_r.h>
#include<netstat_tcp.h>
#include<netstat_udp.h>
#include<netstat_listen.h>
#include<netstat_firefox.h>



// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( testNetstat );

void testNetstat :: setUp()
{
	

	routing = storeRoutingTable();


	tcp = storeTCP_Table();



	udp = storeUDP_Table();



	listen = storeListen();



	firefox = storeFIREFOX_Table();
}

void testNetstat :: testConnection_UT_sunny()
{
	cout<<"Client-Server connection successful"<<endl;
}

void testNetstat :: testConnection_UT_rainy()
{
	cout<<"CLient-Server Connection Failed"<<endl;
}
void testNetstat :: testRouting_UT_sunny()
{
	
	string routing1 = storeRoutingTable();
	CPPUNIT_ASSERT_EQUAL(routing,routing1);
	
}
void testNetstat :: testRouting_UT_rainy()
{
	string routing = "rt";
	string routing1 = getRouting();
	CPPUNIT_ASSERT_EQUAL(routing,routing1);
}

void testNetstat :: testTCP_UT_sunny()
{
	
	string tcp1 = storeTCP_Table();
	CPPUNIT_ASSERT_EQUAL(tcp,tcp1);
}
void testNetstat :: testTCP_UT_rainy()
{
	string tcp = "tcpip";
	string tcp1 = getTCP();
	CPPUNIT_ASSERT_EQUAL(tcp,tcp1);
}
void testNetstat :: testUDP_UT_sunny()
{
	
	string udp1 = storeUDP_Table();
	CPPUNIT_ASSERT_EQUAL(udp,udp1);
}
void testNetstat :: testUDP_UT_rainy()
{
	string udp = "udpip";
	string udp1 = getUDP();
	CPPUNIT_ASSERT_EQUAL(udp,udp1);
}

void testNetstat :: testLISTEN_UT_sunny()
{
	
	string listen1 = storeListen();
	CPPUNIT_ASSERT_EQUAL(listen, listen1);
}
void testNetstat :: testLISTEN_UT_rainy()
{
	string listen = "Listenclient";
	string listen1 = getLISTEN();
	CPPUNIT_ASSERT_EQUAL(listen, listen1);
}

void testNetstat :: testFirefox_UT_sunny()
{
	
	string firefox1 = storeFIREFOX_Table();
	CPPUNIT_ASSERT_EQUAL(firefox, firefox1);
}

void testNetstat :: testFirefox_UT_rainy()
{
	string firefox = "Firefox open";
	string firefox1 = getFirefox();
	CPPUNIT_ASSERT_EQUAL(firefox, firefox1);}
