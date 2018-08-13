
#include "nil/NilRTOS.h"
#include "nil/NilRTOS.c"
#include "nil/board.c"
#include "nil/nilcore.c"
#include "nil/nilUtility.cpp"
#include "nil/nil.c"

#include <avr/wdt.h> // watch dog for automatic reboot in case of crash

#include "time/Time.cpp" // git clone https://github.com/PaulStoffregen/Time

#include "hack/NullStream.h"
#include "hack/params.h"
#include "hack/eeprom.h"
#include "hack/toHex.h"
#include "hack/Utility.h"
#include "hack/WireSlave.h"
#include "hack/WireMaster.h"
#include "hack/SerialUtilities.h"
#include "hack/Serial.h"
#include "hack/start.h"
