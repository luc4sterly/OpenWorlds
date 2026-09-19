// 10038af0 RwClose [Global]
// programa: RWL21.DLL

void RwClose(void)

{
                    /* 0x38af0  27  RwClose */
  if (DAT_1005b750 != 0) {
    RwStopDisplayDevice(DAT_1005b750);
    RwCloseDisplayDevice(DAT_1005b750);
  }
  RwRelease();
  return;
}


