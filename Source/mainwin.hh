/**
 * @file      mainwin.hh
 * @brief     
 * @details   
 * @author    ranwei
 * @version     
 * @date      2019/1/22 15:34:58:653
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
 *         1.Date         -- 2019/1/22 15:34:58:653
 *           Author       -- ranwei
 *           Modification -- Created file
 *
 */
#ifndef __MAINWIN_HH__
#define __MAINWIN_HH__

#ifdef  MAINWIN_GLOBAL
#define MAINWIN_EXT
#else
#define MAINWIN_EXT extern
#endif /* MAINWIN_GLOBAL */

/*============================================================================*/
/*                                  @INCLUDES                                 */
/*============================================================================*/
#include <QMainWindow>
#include <QLineEdit>
#include <QPushButton>
#include <QProgressBar>
#include <QPlainTextEdit>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QWidget>
#include <QTimer>
#include <QSerialPortInfo>
#include <QMap>
#include <memory>
#include <stdint.h>
#include "comnamewidget.hh"



 
/** @addtogroup MAINWIN
  * @{
  */

using namespace std;
 
/*============================================================================*/
/*                             @MACROS & @TYPEDEFS                            */
/*============================================================================*/
                                                                                
/*============================================================================*/
/*                             @GLOBAL VIRIABLES                              */
/*============================================================================*/
                                                                                
/*============================================================================*/
/*                                   @FUNCS                                   */
/*============================================================================*/
                                                                                
/*============================================================================*/
/*                                   @CLASS                                   */
/*============================================================================*/
/*! @class CMainWin 
 *  @brief 主窗口类。 @anchor CMainWin_Details
 *  
 */ 		
class CMainWin : public QMainWindow
{
    Q_OBJECT

public:
    CMainWin(QWidget *parent = 0);
    ~CMainWin();

private slots:

private:
    shared_ptr<QWidget> m_pCentralWidget;
    shared_ptr<QLineEdit> m_pBinFilePathLEdit;
    shared_ptr<QPushButton> m_pBinFileBtn;
    shared_ptr<QProgressBar> m_pUpdateBar;
    shared_ptr<QPlainTextEdit> m_pMsgWidget;
    shared_ptr<CComNameWidget> m_pComNameWidget;
    shared_ptr<QComboBox> m_pComBaudWidget;
    QHBoxLayout* m_pBinFileLayout;
    QHBoxLayout* m_pComLayout;
    QGridLayout* m_pMainLayout;  
};                                                                                

/**
  * @}
  */ 
		
#endif /* __MAINWIN_HH__ */
/****************** (C) COPYRIGHT 2010-2018 R_W ******END OF FILE**************/

