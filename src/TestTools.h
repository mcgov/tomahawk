#pragma once

#include "Character.h"

static void testAttribute( Character * testCharacter, uint8_t *attribute, Character::STATUS check_status, 
                        int set_to ,  bool desired_result, const char* status_msg  );


static void testAttribute64( Character * testCharacter, int64_t *attribute, Character::STATUS check_status, 
                        int set_to ,  bool desired_result, const char* status_msg  );