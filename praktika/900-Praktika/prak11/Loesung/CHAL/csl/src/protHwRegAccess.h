/*
 * protHwRegAccess.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PROTHWREGACCESS_H_
#define CSL_PROTHWREGACCESS_H_

/**
 * @brief Allows write access to protected C2000 register.
 */
static inline void protHwRegAccessAllow(void)
{
  __asm(" EALLOW");
}

/**
 * @brief Disallows write access to protected C2000 register.
 */
static inline void protHwRegAccessDisallow(void)
{
  __asm(" EDIS");
}

#endif /* CSL_PROTHWREGACCESS_H_ */
