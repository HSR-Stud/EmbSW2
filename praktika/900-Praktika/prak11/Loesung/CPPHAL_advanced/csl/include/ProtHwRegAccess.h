/*
 * ProtHwRegAccess.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PROTHWREGACCESS_H_
#define CSL_PROTHWREGACCESS_H_

namespace csl
{

/**
 * @brief Abstracts C2000 protected register access handling.
 */
class ProtHwRegAccess
{
  public:
    /**
     * @brief Allows write access to protected register.
     */
    static void allow()
    {
      __asm(" EALLOW");
    }

    /**
     * @brief Disallows write access to protected register.
     */
    static void disallow()
    {
      __asm(" EDIS");
    }
};

} // namespace csl

#endif /* CSL_PROTHWREGACCESS_H_ */
