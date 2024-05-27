// -----------------------------------------------------------------------------------
// Controller Service tile
#pragma once

#include "../htmlHeaders.h"
#include "../htmlMessages.h"
#include "../htmlScripts.h"

extern void serviceTile(String &data);
extern void serviceTileAjax(String &data);
extern void serviceTileGet();

const char html_ServiceSection[] PROGMEM = 
"You can reset command channels or whole SWS here<br/><br/>";

const char html_html_ServiceSectionrestart[] PROGMEM = "<button onpointerdown=\"s('srvc','rst')\" type='button'>Restart SWS</button> ";
#if COMMAND_SERVER == PERSISTENT || COMMAND_SERVER == BOTH
const char html_html_ServiceSectionrestartCC1[] PROGMEM = "<button onpointerdown=\"s('srvc','cc1_rst')\" type='button'>Restart CC1</button> ";
const char html_html_ServiceSectionrestartCC2[] PROGMEM = "<button onpointerdown=\"s('srvc','cc2_rst')\" type='button'>Restart CC2</button> ";
const char html_html_ServiceSectionrestartCC3[] PROGMEM = "<button onpointerdown=\"s('srvc','cc3_rst')\" type='button'>Restart CC3</button> ";
#endif