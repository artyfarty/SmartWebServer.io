// wifi IP command server
#include "CmdServer.h"

#if OPERATIONAL_MODE == WIFI && COMMAND_SERVER != OFF

  #include "../../tasks/OnTask.h"
  #include "../../../libApp/cmd/Cmd.h"

  CmdServer::CmdServer(uint32_t port, long clientTimeoutMs, bool persist) {
    this->clientTimeoutMs = clientTimeoutMs;
    this->persist = persist;
    this->port = port;
  }

  void CmdServer::begin() {
    cmdSvr = new WiFiServer(port);
    cmdSvr->begin();
    cmdSvr->setNoDelay(true);
  }

  void CmdServer::handleClient() {
    // disconnect client
    if (cmdSvrClient && !cmdSvrClient.connected()) cmdSvrClient.COMMAND_SERVER_STOP_TYPE();
    if (cmdSvrClient && (long)(clientEndTimeMs - millis()) < 0) cmdSvrClient.COMMAND_SERVER_STOP_TYPE();

    // new client
    if (!cmdSvrClient && cmdSvr->hasClient()) {
      // find free/disconnected spot
      cmdSvrClient = cmdSvr->accept();
      clientEndTimeMs = millis() + (unsigned long)clientTimeoutMs;
    }

    // check clients for data, if found get the command, pass to OnStep and pickup the response, then return the response to client
    while (cmdSvrClient && cmdSvrClient.connected() && cmdSvrClient.available() > 0) {
      static char cmdBuffer[40] = "";
      static int cmdBufferPos = 0;

      // still active? push back disconnect
      if (persist) clientEndTimeMs = millis() + (unsigned long)clientTimeoutMs;

      // get the data
      byte b = cmdSvrClient.read();
      
      // insert into the command buffer
      cmdBuffer[cmdBufferPos] = b;
      cmdBufferPos++;
      if (cmdBufferPos > 39) cmdBufferPos = 39;
      cmdBuffer[cmdBufferPos] = 0;

      // send cmd and pickup the response
      if (b == '#' || (strlen(cmdBuffer) == 1 && b == (char)6)) {
        char result[40] = "";

        onStep.processCommand(cmdBuffer, result, cmdTimeout); 

        // pickup response
        if (strlen(result) > 0) {
          if (cmdSvrClient && cmdSvrClient.connected()) {
            cmdSvrClient.print(result);
            delay(2);
          }
        }

        // reset command buffer
        cmdBuffer[0] = 0;
        cmdBufferPos = 0;
      } else tasks.yield();
    }
  }

#endif
