
set(qxt_headers 
        qxtabstractconnectionmanager.h
        qxtabstractfileloggerengine.h
        qxtabstractiologgerengine.h
        qxtabstractsignalserializer.h
        qxtalgorithms.h
        qxtbasicfileloggerengine.h
        qxtbasicstdloggerengine.h
        qxtboundcfunction.h
        qxtboundfunction.h
        qxtboundfunctionbase.h
        qxtcore.h
        qxtcommandoptions.h
        qxtcsvmodel.h
        qxtdaemon.h
        qxtdatastreamsignalserializer.h
        qxtdeplex.h
        qxtdeplex_p.h
        qxterror.h
        qxtfifo.h
        qxtglobal.h
        qxthmac.h
        qxtjson.h
        qxtjob.h
        qxtjob_p.h
        qxtlinesocket.h
        qxtlinesocket_p.h
        qxtlinkedtree.h
        qxtlocale.h
        qxtlocale_data_p.h
        qxtlogger.h
        qxtlogger_p.h
        qxtloggerengine.h
        qxtlogstream.h
        qxtlogstream_p.h
        qxtmetaobject.h
        qxtmetatype.h
        qxtmodelserializer.h
        qxtmultisignalwaiter.h
        qxtnamespace.h
        qxtnull.h
        qxtnullable.h
        qxtpairlist.h
        qxtpimpl.h
        qxtpipe.h
        qxtpipe_p.h
        qxtpointerlist.h
        qxtsharedprivate.h
        qxtsignalgroup.h
        qxtsignalwaiter.h
        qxtslotjob.h
        qxtslotjob_p.h
        qxtslotmapper.h
        qxtstdio.h
        qxtstdio_p.h
        qxtstdstreambufdevice.h
        qxttemporarydir.h
        qxttemporarydir_p.h
        qxttimer.h
        qxttypelist.h
        qxtrpcservice.h
        qxtrpcservice_p.h
        qxtxmlfileloggerengine.h
		
		
    qxtfilelock.h
    qxtfilelock_p.h	

	qxtglobalshortcut.h	
	qxtglobalshortcut_p.h
)

set(qxt_sources
        qxtabstractconnectionmanager.cpp
        qxtabstractfileloggerengine.cpp
        qxtabstractiologgerengine.cpp
        qxtbasicfileloggerengine.cpp
        qxtbasicstdloggerengine.cpp
        qxtcommandoptions.cpp
        qxtcsvmodel.cpp
        qxtdaemon.cpp
        qxtdatastreamsignalserializer.cpp
        qxtdeplex.cpp
        qxterror.cpp
        qxtfifo.cpp
        qxtglobal.cpp
        qxthmac.cpp
        qxtlocale.cpp
        qxtjson.cpp
        qxtjob.cpp
        qxtlinesocket.cpp
        qxtlinkedtree.cpp
        qxtlogger.cpp
        qxtloggerengine.cpp
        qxtlogstream.cpp
        qxtmetaobject.cpp
        qxtmodelserializer.cpp
        qxtmultisignalwaiter.cpp
        qxtnull.cpp
        qxtpipe.cpp
        qxtpointerlist.cpp
        qxtsignalgroup.cpp
        qxtsignalwaiter.cpp
        qxtslotjob.cpp
        qxtslotmapper.cpp
        qxtstdio.cpp
        qxtstdstreambufdevice.cpp
        qxttemporarydir.cpp
        qxttimer.cpp
        qxtrpcservice.cpp
        qxtxmlfileloggerengine.cpp
		
		qxtfilelock.cpp
		
		qxtglobalshortcut.cpp
		)
	
if(WIN32)
	set(qxt_sources ${qxt_sources}
			qxtfilelock_win.cpp
			qxttemporarydir_win.cpp
			
			# # qxtglobalshortcut source
			qxtglobalshortcut_win.cpp
	)
endif(WIN32)

if(UNIX)
	set(qxt_headers ${qxt_headers}
		qxtserialdevice.h
		qxtserialdevice_p.h
	)
	
	set(qxt_sources ${qxt_sources}
		qxtfilelock_unix.cpp
		qxtserialdevice.cpp
		qxtserialdevice_unix.cpp
		qxttemporarydir_unix.cpp
	)
	
	# # qxtglobalshortcut source
	if(APPLE)
		set(qxt_sources ${qxt_sources}
			qxtglobalshortcut_mac.cpp
		)
		# # It seems that we do not need the following flags, but be aware if compilation failed on mac
		# # QMAKE_LFLAGS += -framework Carbon -framework CoreFoundation
	else(APPLE)
		set(qxt_sources ${qxt_sources}
			qxtglobalshortcut_x11.cpp
		)
	endif(APPLE)
	
endif(UNIX)
