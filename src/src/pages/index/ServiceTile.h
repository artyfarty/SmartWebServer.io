// -----------------------------------------------------------------------------------
// Controller Service tile
#pragma once

#include "../htmlHeaders.h"
#include "../htmlMessages.h"
#include "../htmlScripts.h"

extern void serviceTile(String &data);
extern void serviceTileAjax(String &data);
extern void serviceTileGet();

#if DISPLAY_SERVICE == ON

const char html_html_ServiceSectionrestart[] PROGMEM = "<button onpointerdown=\"s('srvc','rst')\" type='button'>Restart SWS</button> ";
#if (COMMAND_SERVER == PERSISTENT || COMMAND_SERVER == BOTH) && DISPLAY_CS_RESTART == ON
const char html_html_ServiceSectionrestartCC1[] PROGMEM = "<button onpointerdown=\"s('srvc','cc1_rst')\" type='button'>Restart CC1</button> ";
const char html_html_ServiceSectionrestartCC2[] PROGMEM = "<button onpointerdown=\"s('srvc','cc2_rst')\" type='button'>Restart CC2</button> ";
const char html_html_ServiceSectionrestartCC3[] PROGMEM = "<button onpointerdown=\"s('srvc','cc3_rst')\" type='button'>Restart CC3</button> ";
#endif

#endif