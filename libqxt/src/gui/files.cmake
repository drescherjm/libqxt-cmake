set(qxt_headers 
     qxtbasespinbox.h
     qxtcheckcombobox.h
     qxtcheckcombobox_p.h
     qxtconfigdialog.h
     qxtconfigdialog_p.h
     qxtconfigwidget.h
     qxtconfigwidget_p.h
     qxtconfirmationmessage.h
     qxtcountrycombobox.h
     qxtcountrycombobox_p.h
     qxtcountrymodel.h
     qxtcountrymodel_p.h
     qxtcrumbview.h
     qxtcrumbview_p.h
     qxtflowview.h
     qxtflowview_p.h
     qxtgui.h
     qxtgroupbox.h
     qxtheaderview.h
     qxtitemdelegate.h
     qxtitemdelegate_p.h
     qxtitemeditorcreator.h
     qxtitemeditorcreatorbase.h
     qxtlabel.h
     qxtletterboxwidget.h
     qxtletterboxwidget_p.h
     qxtlineedit.h
     qxtlistwidget.h
     qxtlistwidget_p.h
     qxtlistwidgetitem.h
     qxtlanguagecombobox.h
     qxtlanguagecombobox_p.h
     qxtnativeeventfilter.h
     qxtprogresslabel.h
     qxtproxystyle.h
     qxtpushbutton.h
     qxtspanslider.h
     qxtspanslider_p.h
     qxtstandarditemeditorcreator.h
     qxtstars.h
     qxtstringspinbox.h
     qxtstringvalidator.h
     qxtstringvalidator_p.h
     qxttablewidget.h
     qxttablewidget_p.h
     qxttablewidgetitem.h
     qxttabwidget.h
     qxttabwidget_p.h
     qxttooltip.h
     qxttooltip_p.h
     qxttreewidget.h
     qxttreewidget_p.h
     qxttreewidgetitem.h

     qxtscheduleheaderwidget.h
     qxtscheduleitemdelegate.h
     qxtscheduleview.h
     qxtscheduleviewheadermodel_p.h
     qxtscheduleview_p.h
     qxtstyleoptionscheduleviewitem.h

     qxtsortfilterproxymodel.h
     qxtfilterdialog.h
     qxtfilterdialog_p.h
     qxtlookuplineedit.h
     qxtlookuplineedit_p.h        
)

set(qxt_sources
     qxtbasespinbox.cpp
     qxtcheckcombobox.cpp
     qxtconfigdialog.cpp
     qxtconfigwidget.cpp
     qxtconfirmationmessage.cpp
     qxtcountrymodel.cpp
     qxtcountrycombobox.cpp
     qxtcrumbview.cpp
     qxtflowview.cpp
     qxtflowview_p.cpp
     qxtgroupbox.cpp
     qxtheaderview.cpp
     qxtitemdelegate.cpp
     qxtlabel.cpp
     qxtletterboxwidget.cpp
     qxtlineedit.cpp
     qxtlistwidget.cpp
     qxtlistwidgetitem.cpp
     qxtlanguagecombobox.cpp
     qxtprogresslabel.cpp
     qxtproxystyle.cpp
     qxtpushbutton.cpp
     qxtspanslider.cpp
     qxtstars.cpp
     qxtstringspinbox.cpp
     qxtstringvalidator.cpp
     qxttablewidget.cpp
     qxttablewidgetitem.cpp
     qxttabwidget.cpp
     qxttooltip.cpp
     qxttreewidget.cpp
     qxttreewidgetitem.cpp

     qxtscheduleitemdelegate.cpp
     qxtscheduleview.cpp
     qxtscheduleview_p.cpp
     qxtscheduleviewheadermodel_p.cpp
     qxtstyleoptionscheduleviewitem.cpp
     qxtscheduleheaderwidget.cpp

     qxtsortfilterproxymodel.cpp
     qxtfilterdialog.cpp
     qxtlookuplineedit.cpp        
		)
		
		
		
		
if(WIN32)
	set(qxt_sources ${qxt_sources}
			
	)
endif(WIN32)

if(UNIX)
	set(qxt_headers ${qxt_headers}
		qxtserialdevice.h
		qxtserialdevice_p.h
	)
	
	set(qxt_sources ${qxt_sources}
		
	)
	
endif(UNIX)
