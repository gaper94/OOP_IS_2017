// enum generator
#include <iostream>  // std::cout

#define ENUM_NO_VALUE(ENUM_NAME, ... ) ENUM_NAME,
#define ENUM_WITH_VALUE(ENUM_NAME, ENUM_VALUE) ENUM_NAME = ENUM_VALUE,
#define ENUM_STRING(ENUM_NAME, ... ) case ENUM_NAME: return  #ENUM_NAME;

#define GENERATE_ENUM(ENUM_VALUES_LIST, ENUM_TYPE)  \
                                                    \
enum ENUM_TYPE                                      \
{                                                   \
   ENUM_VALUES_LIST(ENUM_NO_VALUE, ENUM_WITH_VALUE) \
};                                                  \
                                                    \
const char* GetEnumName(ENUM_TYPE eNumValue)        \
{                                                   \
   switch(eNumValue)                                \
   {                                                \
      ENUM_VALUES_LIST(ENUM_STRING, ENUM_STRING)    \
      default: return "??????";                     \
   }                                                \
}

#define FUEL_BONUS_TYPE_ENUM(DEFAULT, WITH_NUMBER)  \
     /* USAGE                                   */  \
     /* DEFAULT    ( ENUM_VALUE,)               */  \
     /* WITH_NUMBER( ENUM_VALUE, NUMBER)        */  \
                                                    \
     DEFAULT    (FUEL_BONUS_NONE,)                  \
     WITH_NUMBER(FUEL_BONUS_GENERIC, 1)             \
     WITH_NUMBER(FUEL_BONUS_PROMOTION, 2)

GENERATE_ENUM(FUEL_BONUS_TYPE_ENUM, FUEL_BONUS_TYPE)
     
int main() 
{
  FUEL_BONUS_TYPE eFuelBonusType;
  eFuelBonusType = FUEL_BONUS_GENERIC;
  std::cout << GetEnumName(FUEL_BONUS_GENERIC) << std::endl;
  std::cout << GetEnumName(FUEL_BONUS_NONE)    << std::endl;
  
  return 0;
}
