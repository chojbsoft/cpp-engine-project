#pragma once

#include "Connection.h"

class NetworkManager
{
	SINGLE(NetworkManager)

public:
	virtual bool Init();

protected:
	void StartAccept(shared_ptr<Connection> reuseConn = nullptr);

public:
	virtual void Update();

private:
	virtual void OnAccept(Connection* conn);
	virtual void OnClosed(Connection* conn);
	virtual void OnRecv(Connection* conn, PacketHeader* packetHeader);


private:
	boost::asio::io_context _context;
	shared_ptr<tcp::acceptor> _acceptor;
	unordered_map<Connection*, shared_ptr<Connection>> _backlogConn;
	unordered_map<Connection*, shared_ptr<Connection>> _pendingConn;

private:
	uint8 _backlogCnt = 5;
	uint32 _maxPollCntPerTick = 1000;

private:
	uint16 _mainServerPort = 6122;
	UINT _dediServerPort = 7122;
};

