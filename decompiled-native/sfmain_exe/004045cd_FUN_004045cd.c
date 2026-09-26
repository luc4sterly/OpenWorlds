// 004045cd FUN_004045cd [Global]
// programa: sfmain.exe

void FUN_004045cd(void)

{
  short *in_EAX;
  int iVar1;
  short sVar2;
  
  iVar1 = 1;
  do {
    sVar2 = *in_EAX;
    if (sVar2 < 0) {
      if (sVar2 == -0x8000) {
        sVar2 = 0x7fff;
      }
      else {
        sVar2 = -sVar2;
      }
    }
    if (sVar2 < 0) {
      FUN_0042b978();
    }
    if (sVar2 < 0x5666) {
      sVar2 = sVar2 >> 1;
    }
    else if (sVar2 < 0x799a) {
      if (sVar2 < 0x2b33) {
        FUN_0042b978();
      }
      sVar2 = sVar2 + -0x2b33;
    }
    else {
      if (sVar2 < 0x6600) {
        FUN_0042b978();
      }
      sVar2 = (sVar2 + -0x6600) * 4;
    }
    if (*in_EAX < 0) {
      sVar2 = -sVar2;
    }
    *in_EAX = sVar2;
    if (sVar2 == -0x8000) {
      FUN_0042b978();
    }
    iVar1 = iVar1 + 1;
    in_EAX = in_EAX + 1;
  } while (iVar1 < 9);
  return;
}


