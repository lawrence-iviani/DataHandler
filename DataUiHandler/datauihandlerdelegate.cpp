#include "datauihandlerdelegate.h"

DataUiHandlerDelegate::DataUiHandlerDelegate(DataUiHandlerProperty * property, DataUiHandlerUI * ui , QObject *parent) :
    QObject(parent),
    DomHelper((QObject*)property),
    m_property(property),
    m_ui(ui),
    m_updateDataEnabled(true)
{
    initClass();
}

DataUiHandlerDelegate::DataUiHandlerDelegate(DataUiHandlerProperty * property,
                                             DataUiHandlerUI * ui ,
                                             QString docType,
                                             QString rootTag,
                                             QObject *parent) :
    QObject(parent),
    DomHelper((QObject*)property,docType,rootTag),
    m_property(property),
    m_ui(ui),
    m_updateDataEnabled(true)
{
    initClass();
}

DataUiHandlerDelegate::DataUiHandlerDelegate(DataUiHandlerProperty * property,
                                             DataUiHandlerUI * ui ,
                                             QString docType,
                                             QString rootTag,
                                             QString fileExtension,
                                             QObject *parent) :
    QObject(parent),
    DomHelper((QObject*)property,docType,rootTag,fileExtension),
    m_property(property),
    m_ui(ui),
    m_updateDataEnabled(true)
{
    initClass();
}

void DataUiHandlerDelegate::initClass() {
    PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,"\t--------- Connecting signal ---------"));
    connectSignal();
    PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,"\t--------- Creating DOM ---------"));
    this->selfObjectData();
    PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,"\t--------- Emit ALL Prop Signal ---------"));
    this->setEnableDataUpdate(false);
    m_property->sendAllPropertiesSignal();
    this->setEnableDataUpdate(true);
}

void DataUiHandlerDelegate::connectSignal() {

    if (m_property==NULL || m_ui==NULL) {
        PRINT_WARNING( ErrorMessage::WARNING(Q_FUNC_INFO,
                     QString("trying to connect unreferenced data, property@%1, UI@%2").arg((qlonglong)m_property).arg((qlonglong)m_ui)));
        return;
    }

    const QMetaObject* _propMetaObject = m_property->metaObject();
    const QMetaObject* _uiMetaObject = m_ui->metaObject();

    //Collecting all the method from property and ui
    QStringList _propMethod=extractMethodSignatureList(_propMetaObject);
    QStringList _uiMethod=extractMethodSignatureList(_uiMetaObject);

//    PRINT_DEBUG( ErrorMessage::DEBUG(Q_FUNC_INFO,"Connecting PROPERTY to UI"));
//----------- 1. Connect the property class signal to the UI ---------------
    for(int i = 0; i < _propMetaObject->propertyCount(); i++) {
        //Looking if the property has slot&connection
        QMetaProperty _prop=_propMetaObject->property(i);//Getting property i
        QString _propName=_prop.name();//Getting properties name

        //Looking
        QString _signalSignature="";
        if (_prop.hasNotifySignal()) {
            _signalSignature=_prop.notifySignal().signature();
        }
        if (_signalSignature=="") continue;

        //looking if the corrispondent UI slot exists!
        QString _slotName=QString("%1%2").arg(_propName).arg(POSTPEND_UPDATE_UI_SLOT);
        QString _uiMethodSignature=findMethodSignature(&_uiMethod,_slotName);
        if (_uiMethodSignature=="") {
            PRINT_WARNING( ErrorMessage::WARNING(Q_FUNC_INFO,
                         QString("found signal %1 but candidate method %2 can't be find").arg(_signalSignature).arg(_slotName)
                        ));
            continue;
        }
        QString _slotSignature=findSlotSignature(_uiMetaObject,_uiMethodSignature);
        if (_slotSignature=="") {
            PRINT_WARNING( ErrorMessage::WARNING(Q_FUNC_INFO,
                         QString("found signal %1 but method %2 is not a slot").arg(_signalSignature).arg(_uiMethodSignature)
                        ));
            continue;
        }

        //Connect property SIGNAL to ui SLOT
        _signalSignature.prepend("2");//2 is in front because in qobjectdefs.h the macro SIGNAL introduce this number
        _slotSignature.prepend("1");//1 is in front because in qobjectdefs.h the macro SLOT introduce this number
        if (!connect(m_property,_signalSignature.toAscii().constData(),m_ui,_slotSignature.toAscii().data())) {
            PRINT_WARNING( ErrorMessage::WARNING(Q_FUNC_INFO,
                         QString("fail to connect signal %1 to signal %2").arg(_signalSignature).arg(_slotSignature)
                        ));
        } else {
            //Every time a property is changed this method is called
            Q_ASSERT(connect(m_property,_signalSignature.toAscii().constData(),this,SLOT(dataChanged())));
            PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,
                         QString("connected signal %1 to signal %2").arg(_signalSignature).arg(_slotSignature)
                        ));
        }
    }

   // PRINT_DEBUG( ErrorMessage::DEBUG(Q_FUNC_INFO,"Connecting UI to PORPERTY"));
 //----------- 2. Connect the UI class signal to the property class ---------------
        for(int n = 0; n < _propMetaObject->propertyCount(); n++) {
            //Looking if the property has slot&connection
            QMetaProperty _prop=_propMetaObject->property(n);//Getting property i
            QString _propName=_prop.name();//Getting properties name

            //Looking for the signal name from UI
            QString _signalName=QString("%1%2").arg(_propName).arg(POSTPEND_UI_CHANGED_SIGNAL);
            QString _uiMethodSignature=findMethodSignature(&_uiMethod,_signalName);
            QString _signalSignature=findSignalSignature(_uiMetaObject,_uiMethodSignature);
            if (_signalSignature=="") continue;

            //looking if the corrispondent property slot exists!
            QString _slotName=QString("%1%2").arg(PREPEND_UPDATE_PROPERTY_SLOT).arg(_propName);
            _slotName.replace(PREPEND_UPDATE_PROPERTY_SLOT.length(),1,_slotName.at(PREPEND_UPDATE_PROPERTY_SLOT.length()).toUpper());//Uppercase

            QString _propMethodSignature=findMethodSignature(&_propMethod,_slotName);
            if (_propMethodSignature=="") {
                PRINT_WARNING( ErrorMessage::DEBUG(Q_FUNC_INFO,
                             QString("found signal %1 but candidate method %2 can't be find").arg(_signalSignature).arg(_slotName)
                            ));
                continue;
            }
            QString _slotSignature=findSlotSignature(_propMetaObject,_propMethodSignature);
            if (_slotSignature=="") {
                PRINT_WARNING( ErrorMessage::WARNING(Q_FUNC_INFO,
                             QString("found signal %1 but method %2 is not a slot").arg(_signalSignature).arg(_propMethodSignature)
                            ));
                continue;
            }

            //Connect property SIGNAL to ui SLOT
            _signalSignature.prepend("2");//2 is in front because in qobjectdefs.h the macro SIGNAL introduce this number
            _slotSignature.prepend("1");//1 is in front because in qobjectdefs.h the macro SLOT introduce this number
            if (!connect(m_ui,_signalSignature.toAscii().constData(),m_property,_slotSignature.toAscii().data())) {
                PRINT_WARNING( ErrorMessage::WARNING(Q_FUNC_INFO,
                             QString("fail to connect signal %1 to signal %2").arg(_signalSignature).arg(_slotSignature)
                            ));
            } else {
                PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT,ErrorMessage::DEBUG(Q_FUNC_INFO,
                             QString("connected signal %1 to signal %2").arg(_signalSignature).arg(_slotSignature)
                            ));
            }
        }
}

const QString DataUiHandlerDelegate::findMethodSignature(const QStringList* methodList, QString& methodName) {
    QStringList nameList=methodList->filter(methodName);
    if (nameList.length() > 1) {
        QString _methods="";
        for (int i=0; i < nameList.length() ; i++)
            _methods.append(QString("\n\t%1").arg(nameList.at(i)));
        PRINT_WARNING(ErrorMessage::WARNING(Q_FUNC_INFO,
                                            QString("Found too many (%1) methods %2: %3").arg(nameList.length()).arg(methodName).arg(_methods)
                                         ));
        return "";
    }
    if (nameList.length()==0) return "";
    return (const QString) nameList.at(0);
}

const QString DataUiHandlerDelegate::findSignalSignature(const QMetaObject * metaObj, QString& methodSignature) {
    if (methodSignature=="") return "";
    int _sigIndex=metaObj->indexOfSignal(methodSignature.toLocal8Bit().constData());
    if (_sigIndex<=-1) {
        PRINT_WARNING(ErrorMessage::WARNING(Q_FUNC_INFO,
                     QString("NOT FOUND signal |%1|").arg(methodSignature)
                    ));
        return "";
    } /*else {
        PRINT_DEBUG( ErrorMessage::DEBUG(Q_FUNC_INFO,
                     QString("Found signal %1 with index=%2").arg(methodSignature).arg(_sigIndex)
                    ));
    }*/
    QMetaMethod _signal=metaObj->method(_sigIndex);
    //qDebug() <<Q_FUNC_INFO<<"Property SIGNAL"<< _signal.signature() << _signal.parameterTypes() << _signal.parameterNames();
    return (const QString) _signal.signature();
}

const QString DataUiHandlerDelegate::findSlotSignature(const QMetaObject * metaObj, QString& methodSignature) {
    if (methodSignature=="") return "";
    int _slotIndex=metaObj->indexOfSlot(methodSignature.toLocal8Bit().constData());
    if (_slotIndex<=-1) {
        PRINT_WARNING(ErrorMessage::WARNING(Q_FUNC_INFO,
                     QString("NOT FOUND slot |%1|").arg(methodSignature)
                    ));
        return "";

    } /*else {
        PRINT_DEBUG( ErrorMessage::DEBUG(Q_FUNC_INFO,
                     QString("Found slot %1 with index=%2").arg(methodSignature).arg(_slotIndex)
                    ));
    }*/
    QMetaMethod _slot=metaObj->method(_slotIndex);
    //qDebug() <<Q_FUNC_INFO<<"Property SLOT"<< _slot.signature() << _slot.parameterTypes() << _slot.parameterNames();
    return (const QString) _slot.signature();
}

const QStringList DataUiHandlerDelegate::extractMethodSignatureList(const QMetaObject * metaObj) {
    QStringList retval;
    for (int n=0; n < metaObj->methodCount() ; n++)
        retval << metaObj->method(n).signature();
    return retval;
}

void DataUiHandlerDelegate::dataChanged() {
    PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT, ErrorMessage::DEBUG(Q_FUNC_INFO,"slot called!"));
    //updateDOM
    if (m_updateDataEnabled &&  !isImportingDomData()) {
        if (!this->selfObjectData()) {
            PRINT_WARNING(ErrorMessage::WARNING(Q_FUNC_INFO,"Something was wrong when try to generate the self objcet DOM data"));
        } else  {
            PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT, ErrorMessage::DEBUG(Q_FUNC_INFO,"doc is \n%1\n").arg(getDomDocument().toString(4)));
        }
    } else {
        PRINT_DEBUG_LEVEL (ErrorMessage::DEBUG_NOT_SO_IMPORTANT, ErrorMessage::DEBUG(Q_FUNC_INFO,"Do nothing!"));
    }
}

bool DataUiHandlerDelegate::setEnableDataUpdate(bool enable) {
    bool retval=m_updateDataEnabled;
    if (enable!=m_updateDataEnabled) {
        m_updateDataEnabled=enable;
        if (enable) dataChanged();
    }
    return retval;
}