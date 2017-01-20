
set(qxt_headers
     qxtjsonrpccall.h
     qxtjsonrpcclient.h
     qxtnetwork.h
     qxtmail_p.h
     qxtsmtp.h
     qxtsmtp_p.h
     qxtmailattachment.h
     qxtmailmessage.h
     qxtrpcpeer.h
     qxttcpconnectionmanager.h
     qxttcpconnectionmanager_p.h
     qxtxmlrpccall.h
     qxtxmlrpcclient.h
     qxtxmlrpc_p.h
     qxtpop3.h
     qxtpop3_p.h
     qxtpop3reply.h
     qxtpop3reply_p.h
     qxtpop3statreply.h
     qxtpop3listreply.h
     qxtpop3retrreply.h
     qxtsslserver.h
     qxtsslconnectionmanager.h
	 
	 # # DEFINES,HAVE_OPENSSL
	  # qxtsshchannel.h
      # qxtsshchannel_p.h
      # qxtsshclient.h
      # qxtsshclient_p.h
      # qxtsshprocess.h
      # qxtsshtcpsocket.h


)

set(qxt_sources
     qxtjsonrpccall.cpp
     qxtjsonrpcclient.cpp
     qxtmailattachment.cpp
     qxtmailmessage.cpp
     qxtrpcpeer.cpp
     qxtsmtp.cpp
     qxttcpconnectionmanager.cpp
     qxtxmlrpccall.cpp
     qxtxmlrpcclient.cpp
     qxtxmlrpc_p.cpp
     qxtpop3.cpp
     qxtpop3reply.cpp
     qxtsslserver.cpp
     qxtsslconnectionmanager.cpp
	 
	# # DEFINES,HAVE_OPENSSL
      # qxtsshchannel.cpp
      # qxtsshclient.cpp
      # qxtsshprocess.cpp
      # qxtsshtcpsocket.cpp		 
)