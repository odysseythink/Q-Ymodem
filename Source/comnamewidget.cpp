/**
 * @file      comnamewidget.cpp
 * @brief     
 * @details   
 * @author    ranwei
 * @version     
 * @date      2019/1/23 17:33:58:241
 * @copyright R_W
 * @par         (c) COPYRIGHT 2010-2018 by R_W Systems, Inc.    
 *                        All rights reserved.
 *                                                                    
 *       This software is confidential and proprietary to R_W 
 *     Systems, Inc.  No part of this software may be reproduced,    
 *     stored, transmitted, disclosed or used in any form or by any means
 *     other than as expressly provided by the written license agreement    
 *     between R_W Systems and its licensee.
 * @par History      
 *         1.Date         -- 2019/1/23 17:33:58:241
 *           Author       -- ranwei
 *           Modification -- Created file
 *
 */

#define  COMNAMEWIDGET_GLOBAL

/* includes-------------------------------------------------------------------*/
#include <QSerialPortInfo>
#include <QDebug>
#include "comnamewidget.hh"
    
/** @defgroup COMNAMEWIDGET                                            
  * @brief COMNAMEWIDGET system modules                                
  * @{                                                                         
  */
    
/* Private typedef&macro&definde----------------------------------------------*/

/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* External functions --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
                                                                                
/** @defgroup COMNAMEWIDGET_Private_Functions                          
  * @{                                                                         
  */                                                                            
                                                                                
/**                                                                             
  * @}                                                                         
  */	                                                                        
                                                                                
/** @defgroup COMNAMEWIDGET_CLASS_Functions                          
  * @{                                                                         
  */                                                                            
CComNameWidget::CComNameWidget(QWidget *parent)
    : QComboBox(parent)
{
    setStyleSheet("QComboBox QAbstractItemView::item{height:30px;}");

    m_pComNameListWidget = make_shared<QListView>();
    m_pComNameModel = make_shared<QStringListModel>();
    m_pComNameListWidget->setModel(m_pComNameModel.get());
    setModel(m_pComNameListWidget->model());
    setView(m_pComNameListWidget.get());
    auto maxComNameSize = 0;
    auto infos = QSerialPortInfo::availablePorts();
    for(QSerialPortInfo &info : infos)
    {
        auto despstring = info.portName() + ": " + info.description();
        maxComNameSize = despstring.size() > maxComNameSize ? despstring.size():maxComNameSize;
        m_ComNameList << despstring;
    }
    m_pComNameModel->setStringList(m_ComNameList);
    m_pComNameListWidget->setFixedWidth(maxComNameSize*6.65);
    setCurrentText(m_ComNameList.first());

    m_pMonitorTimer = make_shared<QTimer>();
    connect(m_pMonitorTimer.get(), SIGNAL(timeout()), this, SLOT(__OnMonitorTimerTimeout()));
    m_pMonitorTimer->start(MONITOR_PERIOD);
}

CComNameWidget::~CComNameWidget()
{

}

void CComNameWidget::__OnMonitorTimerTimeout()
{
    auto maxComNameSize = 0;
    bool bComListChanged = false;
    auto infos = QSerialPortInfo::availablePorts();
    auto curText = currentText();
    for(QSerialPortInfo &info : infos)
    {
        auto despstring = info.portName() + ": " + info.description();
        if(!m_ComNameList.contains(despstring))
        {
            m_ComNameList << despstring;
            bComListChanged = true;
        }
    }

    QStringList::iterator iterator = m_ComNameList.begin();
    while(iterator != m_ComNameList.end())
    {
        bool bComAvailable = false;
        for(QSerialPortInfo &info : infos)
        {
            auto despstring = info.portName() + ": " + info.description();
            if(*iterator == despstring)
            {
                bComAvailable = true;
                break;
            }
        }
        if(!bComAvailable)
        {
            iterator = m_ComNameList.erase(iterator);
            bComListChanged = true;
        }
        else
        {
            maxComNameSize = (*iterator).size() > maxComNameSize ? (*iterator).size():maxComNameSize;
            ++iterator;
        }
    }
    if(bComListChanged)
    {
        m_pComNameModel->setStringList(m_ComNameList);
        m_pComNameListWidget->setFixedWidth(maxComNameSize*6.65);
        if(m_ComNameList.contains(curText))
        {
            setCurrentText(curText);
        }
    }
}



/**                                                                             
  * @}                                                                         
  */	                                                                        
                                                                                
/**                                                                             
  * @}                                                                         
  */
                                                                                
/****************** (C) COPYRIGHT 2010-2018 R_W ******END OF FILE**************/
