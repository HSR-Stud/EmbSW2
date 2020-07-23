/*
 * Pin.h
 *
 *  Created on: April 15, 2019
 *      Author: Gian Danuser
 */

#ifndef CSL_PIN_H_
#define CSL_PIN_H_

extern "C"
{
#include <stdint.h> // C2000 does not define <cstdint>
}

#include "./bits.h"
#include "./ProtHwRegAccess.h"
#include "./HwReg.h"
#include "./Port.h"

namespace csl
{

namespace pin
{

/**
 * @brief The pin ID.
 */
enum Id
{
  pin0 = 0, // must be 0
  pin1,
  pin2,
  pin3,
  pin4,
  pin5,
  pin6,
  pin7,
  pin8,
  pin9,
  pin10,
  pin11,
  pin12,
  pin13,
  pin14,
  pin15,
  pin16,
  pin17,
  pin18,
  pin19,
  pin20,
  pin21,
  pin22,
  pin23,
  pin24,
  pin25,
  pin26,
  pin27,
  pin28,
  pin29,
  pin30,
  pin31,
  pin32,
  pin33,
  pin34,
  pin35,
  pin36,
  pin37,
  pin38,
  pin39,
  pin40,
  pin41,
  pin42,
  pin43,
  pin44,
  pin45,
  pin46,
  pin47,
  pin48,
  pin49,
  pin50,
  pin51,
  pin52,
  pin53,
  pin54,
  pin55,
  pin56,
  pin57,
  pin58,
  pin59,
  pin60,
  pin61,
  pin62,
  pin63
};

/**
 * @brief The pin direction.
 */
enum Direction
{
  in,
  out
};

/**
 * @brief The pin mux.
 */
enum Mux
{
  fun1 = 0, ///< GIO
  fun2 = bit0,
  fun3 = bit1,
  fun4 = bit1|bit0
};

/**
 * @brief The pin sync selection.
 */
enum Sync
{
  syncToSysClk = 0 ///< sync to system clock
};

/**
 * @brief The C2000 pin base class.
 *
 * @tparam id port ID
 */
template<port::Id id>
class PinBase
{
public:
    /**
     * @brief Initializes the port if required.
     *
     * @param bitNr bit number
     * @param dir pin direction
     * @param mux pin mux
     * @param isPullupEn true if pull-up enabled
     * @param sync sync to specified clock
     */
    PinBase(unsigned int bitNr,
            Direction dir,
            Mux mux,
            bool isPullupEn,
            Sync sync);

    /**
     * @brief Sets the direction of the pin.
     *
     * @param bitNr bit number
     * @param dir pin direction
     */
    void setDirection(unsigned int bitNr, Direction dir);

private:
    enum
    {
      muxBitWidth = 2,  ///< bit width per mux setting
      syncBitWidth = 2, ///< bit width per sync setting
      pudBitWidth = 1   ///< bit width per pud setting
    };

    static bool initDonePort; ///< port initialized flag
};

/**
 * @brief Template meta programming to get the port ID derived from the pin ID.
 *
 * @tparam pinId pin ID
 */
template<Id pinId>
struct GetPort
{
  static const port::Id id = pinId < port::numPins ? port::a : port::b;
};

/**
 * @brief Abstracts C2000 pins.
 *
 * @tparam id pin ID
 */
template<Id id>
class Pin : public PinBase<GetPort<id>::id>
{

  public:

    /**
     * @brief Initializes the pin to the default configuration.
     *
     * @param dir pin direction (default: in)
     * @param mux pin mux (default: GIO)
     * @param isPullupEn true if pull-up enabled (default: enabled)
     * @param sync sync to specified clock (default: sync to system clock)
     */
    Pin(Direction dir = in,
        Mux mux = fun1,
        bool isPullupEn = true,
        Sync sync = syncToSysClk);

    /**
     * @brief Sets the direction of the pin.
     *
     * @param dir pin direction
     */
    void setDirection(Direction dir);

    /**
     * @brief Sets the pin.
     */
    void set();

    /**
     * @brief Clears the pin.
     */
    void clear();

    /**
     * @brief Toggles the pin.
     */
    void toggle();

    /**
     * @brief Returns the state of the pin.
     *
     * @return pin state
     */
    bool get() const;
};


//
// template meta programming
//

/**
 * @brief Template meta programming to get the bit number derived from the pin ID.
 *
 * @tparam id pin ID
 */
template<Id id>
struct GetBitNr
{
  static const unsigned int nr = id < port::numPins ? id : id - port::numPins;
};


//
// implementation
//

template<port::Id id>
bool PinBase<id>::initDonePort = false;

template<port::Id id>
PinBase<id>::PinBase(unsigned int bitNr,
                     Direction dir,
                     Mux mux,
                     bool isPullupEn,
                     Sync sync)
{
  // Ensures that each port is initialized only once.
  if(!initDonePort)
  {
    port::Port<id> port(true);
    initDonePort = true;
  }

  ProtHwRegAccess::allow();

  //configure sync
  if(bitNr >= (port::numPins/syncBitWidth))
    reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::sel2)->setSubValue<syncBitWidth>(
        sync, bitNr - port::numPins/syncBitWidth);
  else
    reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::sel1)->setSubValue<syncBitWidth>(
        sync, bitNr);

  //configure mux
  if(bitNr >= (port::numPins/muxBitWidth))
    reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::mux2)->setSubValue<syncBitWidth>(
        mux, bitNr - port::numPins/muxBitWidth);
  else
    reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::mux1)->setSubValue<syncBitWidth>(
        mux, bitNr);

  //configure pull-up
  reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::pud)->setSubValue<pudBitWidth>(
      isPullupEn, bitNr);

  ProtHwRegAccess::disallow();

  setDirection(bitNr, dir);
}

template<port::Id id>
void PinBase<id>::setDirection(unsigned int bitNr, Direction dir)
{
  ProtHwRegAccess::allow();

  if(dir == in)
    reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::dir)->clearBits(
        static_cast<uint32_t>(1) << bitNr);
  else
    reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<id>::dir)->setBits(
        static_cast<uint32_t>(1) << bitNr);

  ProtHwRegAccess::disallow();
}

template<Id id>
Pin<id>::Pin(Direction dir,
             Mux mux,
             bool isPullupEn,
             Sync sync) :
  PinBase<GetPort<id>::id>(GetBitNr<id>::nr, dir, mux, isPullupEn, sync)
{

}

template<Id id>
void Pin<id>::setDirection(Direction dir)
{
  PinBase<id>::setDirection(GetBitNr<id>::nr, dir);
}

template<Id id>
inline void Pin<id>::set()
{
  // reinterpret cast is used instead of placement new,
  // because C2000 compiler does not reduce the new operator to zero instructions
  reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<GetPort<id>::id>::set)->setBits(
      static_cast<uint32_t>(1) << GetBitNr<id>::nr);
}

template<Id id>
inline void Pin<id>::clear()
{
  // reinterpret cast is used instead of placement new,
  // because C2000 compiler does not reduce the new operator to zero instructions
  reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<GetPort<id>::id>::clr)->setBits(
      static_cast<uint32_t>(1) << GetBitNr<id>::nr);
}

template<Id id>
inline void Pin<id>::toggle()
{
  // reinterpret cast is used instead of placement new,
  // because C2000 compiler does not reduce the new operator to zero instructions
  reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<GetPort<id>::id>::toggle)->setBits(
      static_cast<uint32_t>(1) << GetBitNr<id>::nr);
}

template<Id id>
inline bool Pin<id>::get() const
{
  // reinterpret cast is used instead of placement new,
  // because C2000 compiler does not reduce the new operator to zero instructions
  return reinterpret_cast<HwReg<uint32_t>*>(port::GetAddrReg<GetPort<id>::id>::dat)->areBitsSet(
      static_cast<uint32_t>(1) << GetBitNr<id>::nr);
}

} // namespace pin

} // namespace csl

#endif /* CSL_PIN_H_ */
