/**
 * @file      comnamewidget.hh
 * @brief     
 * @details   
 * @author    ranwei
 * @version     
 * @date      2019/1/23 17:34:15:813
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
 *         1.Date         -- 2019/1/23 17:34:15:813
 *           Author       -- ranwei
 *           Modification -- Created file
 *
 */
#ifndef __COMNAMEWIDGET_HH__
#define __COMNAMEWIDGET_HH__

#ifdef  COMNAMEWIDGET_GLOBAL
#define COMNAMEWIDGET_EXT
#else
#define COMNAMEWIDGET_EXT extern
#endif /* COMNAMEWIDGET_GLOBAL */

/*============================================================================*/
/*                                  @INCLUDES                                 */
/*============================================================================*/
#include <QComboBox>
#include <QListWidget>
#include <QListView>
#include <QStringListModel>
#include <QTimer>
#include <memory>
#include "comnameitem.hh"
 
/** @addtogroup COMNAMEWIDGET
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
class CComNameWidget : public QComboBox
{
    Q_OBJECT
public:
    explicit CComNameWidget(QWidget *parent = 0);
    ~CComNameWidget();

private slots:
    void __OnMonitorTimerTimeout();

private:
    shared_ptr<QListView> m_pComNameListWidget;
    shared_ptr<QStringListModel> m_pComNameModel;
    QStringList m_ComNameList;
    shared_ptr<QTimer> m_pMonitorTimer;
    const uint32_t MONITOR_PERIOD = 500;

};

/**
  * @}
  */ 
		
#endif /* __COMNAMEWIDGET_HH__ */
/****************** (C) COPYRIGHT 2010-2018 R_W ******END OF FILE**************/
