#include "ServiceTile.h"

#include "../KeyValue.h"
#include "../Pages.common.h"

#if (COMMAND_SERVER == PERSISTENT || COMMAND_SERVER == BOTH) && DISPLAY_CS_RESTART == ON
    #include "src/lib/wifi/cmdServer/CmdServer.h"
    #include "src/lib/ethernet/cmdServer/CmdServer.h"

    extern CmdServer persistentCmdSvr1;
    extern CmdServer persistentCmdSvr2;
    extern CmdServer persistentCmdSvr3;
#endif

void serviceTile(String &data)
{
    char temp[240] = "";

    sprintf_P(temp, html_tile_text_beg, "28em", "15em", "Service");
    data.concat(temp);
    data.concat(F("<br /><hr>"));
    www.sendContentAndClear(data);

    data.concat(html_html_ServiceSectionrestart);

    #if (COMMAND_SERVER == PERSISTENT || COMMAND_SERVER == BOTH) && DISPLAY_CS_RESTART == ON
    data.concat(html_html_ServiceSectionrestartCC1);
    data.concat(html_html_ServiceSectionrestartCC2);
    data.concat(html_html_ServiceSectionrestartCC3);
    #endif

    data.concat(FPSTR(html_tile_end));
    www.sendContentAndClear(data);
}

void serviceTileAjax(String &data)
{
    UNUSED(data);
}

void serviceTileGet()
{
    String get = www.arg("srvc");
    if (!get.equals(EmptyStr))
    {
        if (get.equals("rst")) { ESP.restart(); }
        #if (COMMAND_SERVER == PERSISTENT || COMMAND_SERVER == BOTH) && DISPLAY_CS_RESTART == ON
        if (get.equals("cc1_rst")) { persistentCmdSvr1.restart(); }
        if (get.equals("cc2_rst")) { persistentCmdSvr2.restart(); }
        if (get.equals("cc3_rst")) { persistentCmdSvr3.restart(); }
        #endif
    }
}
