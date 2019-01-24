/**
 * @file      updatethread.hh
 * @brief     
 * @details   
 * @author    ranwei
 * @version     
 * @date      2019/1/24 18:3:7:230
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
 *         1.Date         -- 2019/1/24 18:3:7:230
 *           Author       -- ranwei
 *           Modification -- Created file
 *
 */
#ifndef __UPDATETHREAD_HH__
#define __UPDATETHREAD_HH__

#ifdef  UPDATETHREAD_GLOBAL
#define UPDATETHREAD_EXT
#else
#define UPDATETHREAD_EXT extern
#endif /* UPDATETHREAD_GLOBAL */

/*============================================================================*/
/*                                  @INCLUDES                                 */
/*============================================================================*/
#include <QThread>


/** @addtogroup UPDATETHREAD
  * @{
  */
 
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
class CUpdateThread : public QThread
{
    Q_OBJECT
public:
    explicit CUpdateThread();
    ~CUpdateThread();
    virtual void run() Q_DECL_OVERRIDE;
};

/**
  * @}
  */ 
		
#endif /* __UPDATETHREAD_HH__ */
/****************** (C) COPYRIGHT 2010-2018 R_W ******END OF FILE**************/
