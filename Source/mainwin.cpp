/**
 * @file      mainwin.cpp
 * @brief     
 * @details   
 * @author    ranwei
 * @version     
 * @date      2019/1/22 15:35:30:353
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
 *         1.Date         -- 2019/1/22 15:35:30:353
 *           Author       -- ranwei
 *           Modification -- Created file
 *
 */

#define  MAINWIN_GLOBAL

/* includes-------------------------------------------------------------------*/
#include "mainwin.hh"
#include <QSpacerItem>
    
/** @defgroup MAINWIN                                            
  * @brief MAINWIN system modules                                
  * @{                                                                         
  */
    
/* Private typedef&macro&definde----------------------------------------------*/
#define MAINWIN_WIDTH 640
#define LAYOUT_SPACING 5
#define LAYOUT_MARGIN  5
#define COM_COMBABOX_WIDTH  128
#define COM_COMBABOX_HEIGHT  28

/* Private variables ---------------------------------------------------------*/
/* Private functions ---------------------------------------------------------*/
/* External functions --------------------------------------------------------*/
/* External variables --------------------------------------------------------*/
                                                                                
/** @defgroup MAINWIN_Private_Functions                          
  * @{                                                                         
  */                                                                            
                                                                                
/**                                                                             
  * @}                                                                         
  */	                                                                        
                                                                                
/** @defgroup MAINWIN_CLASS_Functions                          
  * @{                                                                         
  */                                                                            

CMainWin::CMainWin(QWidget *parent)
    : QMainWindow(parent)
{
    m_pCentralWidget = make_shared<QWidget>();
    setCentralWidget(m_pCentralWidget.get());
    m_pMainLayout = new QGridLayout();
    m_pMainLayout->setSpacing(LAYOUT_SPACING);
    m_pMainLayout->setMargin(LAYOUT_MARGIN);

    m_pBinFileLayout = new QHBoxLayout();
    m_pBinFileLayout->setSpacing(LAYOUT_SPACING);
    m_pBinFilePathLEdit = make_shared<QLineEdit>(this);
    m_pBinFilePathLEdit->setFixedSize(MAINWIN_WIDTH - 28 - 15, 28);
    m_pBinFileLayout->addWidget(m_pBinFilePathLEdit.get());

    QPixmap *pixmap = new QPixmap(24, 24);
    pixmap->load("://res/image/openbinfile-24x24.png");
    QIcon icon(*pixmap);
    m_pBinFileBtn = make_shared<QPushButton>(icon, "");
    m_pBinFileBtn->setFixedSize(28, 28);

    m_pBinFileLayout->addWidget(m_pBinFileBtn.get());

    m_pMainLayout->addLayout(m_pBinFileLayout, 0, 0, 1, 1);

    m_pUpdateBar = make_shared<QProgressBar>();
    m_pUpdateBar->setFixedHeight(28);
    m_pUpdateBar->setMinimum(0);
    m_pUpdateBar->setMaximum(100);
    m_pUpdateBar->setValue(0);
    m_pUpdateBar->setFormat("%p%");
    m_pMainLayout->addWidget(m_pUpdateBar.get(), 1, 0, 1, 1);

    m_pMsgWidget = make_shared<QPlainTextEdit>();
    m_pMainLayout->addWidget(m_pMsgWidget.get(), 2, 0);

    m_pComLayout = new QHBoxLayout();
    m_pComNameWidget = make_shared<CComNameWidget>();
    m_pComNameWidget->setFixedSize(COM_COMBABOX_WIDTH, COM_COMBABOX_HEIGHT);
    m_pComLayout->addWidget(m_pComNameWidget.get());
    m_pComBaudWidget = make_shared<QComboBox>();
    const auto baudsList = QSerialPortInfo::standardBaudRates();
    for(const qint32 &baud : baudsList)
    {
        m_pComBaudWidget->addItem(QString::number(baud));
    }
    m_pComBaudWidget->setEditable(true);
    m_pComBaudWidget->setCurrentText("115200");
    m_pComBaudWidget->setFixedSize(COM_COMBABOX_WIDTH, COM_COMBABOX_HEIGHT);
    m_pComLayout->addWidget(m_pComBaudWidget.get());
    m_pComLayout->addSpacerItem(new QSpacerItem(0,0, QSizePolicy::Expanding, QSizePolicy::Minimum));

    m_pMainLayout->addLayout(m_pComLayout, 3, 0);
    m_pCentralWidget->setLayout(m_pMainLayout);
}

CMainWin::~CMainWin()
{
    delete m_pBinFileLayout;
    delete m_pComLayout;
    delete m_pMainLayout;
}


                                                                                
/**                                                                             
  * @}                                                                         
  */	                                                                        
                                                                                
/**                                                                             
  * @}                                                                         
  */
                                                                                
/****************** (C) COPYRIGHT 2010-2018 R_W ******END OF FILE**************/

