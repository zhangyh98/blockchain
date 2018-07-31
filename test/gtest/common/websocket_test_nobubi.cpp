#include <gtest/gtest.h>
#include "common/private_key.h"
//#include <openssl/ripemd.h>
//#include <utils/logger.h>
#include <utils/crypto.h>
#include <utils/strings.h>
#include "web_socket_server.h"


class WebsocketTestWithoutChain : public testing::Test {
protected:
	static void SetUpTestCase() {
		//init operation
//		websocket_server = new chain::WebSocketServer();
		//websocket_server->Initialize();
		
	}
	static void TearDownTestCase() {
		
		//end operation
		delete websocket_server1;
		websocket_server1 = NULL;
		
	}
	// Some expensive resource shared by all tests.
	static chain::WebSocketServer *websocket_server1;
	
};

chain::WebSocketServer* WebsocketTestWithoutChain::websocket_server1 = new chain::WebSocketServer();

//to test the monitoragent with normal response from websocket_server
TEST_F(WebsocketTestWithoutChain, NormalResponse)
{
	websocket_server1->NormalResponseTest();
}

TEST_F(WebsocketTestWithoutChain, Warning)
{
	websocket_server1->WarningTest();
}

//to test the monitoragent with a request "system"
TEST_F(WebsocketTestWithoutChain, RequestSystem)
{
	websocket_server1->RequestSystemTest();
}

//to test the monitoragent with a request "ledger"

TEST_F(WebsocketTestWithoutChain, RequestLedger)
{
	websocket_server1->RequestLedgerTest();
}

//to test the monitoragent with an undefined method,need fix monitor
TEST_F(WebsocketTestWithoutChain, RequestUndef)
{
	websocket_server1->RequestUndefTest();
}

//to test the monitoragent with an incomplete request, need fix monitor
TEST_F(WebsocketTestWithoutChain, RequestIncomplete)
{
	websocket_server1->RequestIncompleteTest();
}

TEST_F(WebsocketTestWithoutChain, RequestUpgrade)
{
	websocket_server1->RequestUpgradeTest();
}

//to test the monitoragent with a request "chain"
TEST_F(WebsocketTestWithoutChain, RequestChain)
{
	websocket_server1->RequestChainTest();
}



//to test the monitoragent with a request "error"
TEST_F(WebsocketTestWithoutChain, ResponseError)
{
	websocket_server1->ResponseErrorTest();
}

TEST_F(WebsocketTestWithoutChain, BadHelloResponse)
{
	websocket_server1->BadHelloResponseTest();
}


TEST_F(WebsocketTestWithoutChain, RequestSetConfig)
{
	websocket_server1->RequestSetConfigTest();
}

TEST_F(WebsocketTestWithoutChain, RequestGetConfig)
{
	websocket_server1->RequestGetConfigTest();
}


//to test the monitoragent with response including bad session id from websocket_server

TEST_F(WebsocketTestWithoutChain, BadSessionID)
{
	websocket_server1->BadSessionIDTest();
}

//to test the monitoragent with a request "account_exception"
TEST_F(WebsocketTestWithoutChain, RequestAccountException)
{
	websocket_server1->RequestAccountExceptionTest();
}
