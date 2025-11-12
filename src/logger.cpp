#include "logger.h"
#include "config.h"
#include "sse.h"

void debugMsg(String msg, uint8_t pri)
{
  if(pri >= config.getUChar("debugLevel"))
  {
    if(config.getBool("debugSerial"))
    {
      Serial.println(msg);
    }
    if(config.getBool("debugWeb"))
    {
      sendSSEDebugMessage(msg);
      Serial.println(msg);
    }
  }
}