#include "pch.h"
#include "NetworkManager.h"
#include <shellapi.h>

NetworkManager::NetworkManager()
{
}

NetworkManager::~NetworkManager()
{
}


bool NetworkManager::Init()
{
	_acceptor = make_shared<boost::asio::ip::tcp::acceptor>(_context
		, tcp::endpoint(tcp::v4(), (boost::asio::ip::port_type)_mainServerPort), true);

	for (int i = 0; i < _backlogCnt; i++)
	{
		StartAccept();
	}

	return false;
}

void NetworkManager::StartAccept(shared_ptr<Connection> reuseConn)
{
	if (reuseConn)
	{
		reuseConn->Clean();
	}

	shared_ptr<Connection> conn = reuseConn
		? reuseConn
		: make_shared<Connection>();
	if (!reuseConn)
	{
		conn->Init(_context
			, bind(&NetworkManager::OnAccept, this, placeholders::_1)
			, bind(&NetworkManager::OnClosed, this, placeholders::_1)
			, bind(&NetworkManager::OnRecv, this, placeholders::_1, placeholders::_2));
		_backlogConn.insert(make_pair(conn.get(), conn));
	};

	_acceptor->async_accept(*conn->GetSocket()
		, [this, conn](const boost::system::error_code& error)
		{
			if (error)
			{
				LOG(Error, "accept error: " + error.message());

				// 실패시 기존 conn으로 accept
				StartAccept(conn);
				return;
			}

			_backlogConn.erase(conn.get());
			_pendingConn.insert(make_pair(conn.get(), conn));

			conn->OnAccept();

			// 성공시 새로운 conn으로 accept
			StartAccept();
		});
}

void NetworkManager::Update()
{
	boost::system::error_code errorCode;

	uint32 pollCnt = 0;
	while (uint32 n = _context.poll_one())
	{
		pollCnt += n;
		if (pollCnt > _maxPollCntPerTick)
		{
			break;
		}
	}
}

void NetworkManager::OnAccept(Connection* conn)
{
}

void NetworkManager::OnClosed(Connection* conn)
{
}

void NetworkManager::OnRecv(Connection* conn, PacketHeader* packetHeader)
{
}