// 00402fdd FUN_00402fdd [Global]
// programa: sfmain.exe

void FUN_00402fdd(void)

{
  int iVar1;
  short *in_EAX;
  short sVar2;
  int iVar3;
  
  iVar3 = 1;
  do {
    sVar2 = *in_EAX;
    if (sVar2 < 0) {
      if (sVar2 == -0x8000) {
        sVar2 = 0x7fff;
      }
      else {
        sVar2 = -sVar2;
      }
      if (sVar2 < 0x2b33) {
        sVar2 = sVar2 * 2;
      }
      else if (sVar2 < 0x4e66) {
        sVar2 = sVar2 + 0x2b33;
      }
      else {
        iVar1 = ((int)sVar2 >> 2) + 0x6600;
        if (((int)sVar2 >> 2) + 0xe600U < 0x10000) {
          sVar2 = (short)iVar1;
        }
        else if (iVar1 < 1) {
          sVar2 = -0x8000;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      *in_EAX = -sVar2;
    }
    else {
      if (sVar2 < 0x2b33) {
        sVar2 = sVar2 * 2;
      }
      else if (sVar2 < 0x4e66) {
        sVar2 = sVar2 + 0x2b33;
      }
      else {
        iVar1 = ((int)sVar2 >> 2) + 0x6600;
        if (((int)sVar2 >> 2) + 0xe600U < 0x10000) {
          sVar2 = (short)iVar1;
        }
        else if (iVar1 < 1) {
          sVar2 = -0x8000;
        }
        else {
          sVar2 = 0x7fff;
        }
      }
      *in_EAX = sVar2;
    }
    iVar3 = iVar3 + 1;
    in_EAX = in_EAX + 1;
  } while (iVar3 < 9);
  return;
}


