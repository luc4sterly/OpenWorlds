// 004029f7 FUN_004029f7 [Global]
// programa: sfmain.exe

void __fastcall FUN_004029f7(undefined4 param_1,undefined2 *param_2)

{
  short *in_EAX;
  short sVar1;
  int iVar2;
  
  iVar2 = *in_EAX + -0x20;
  if (0xffff < (int)*in_EAX + 0x7fe0U) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  sVar1 = (short)(iVar2 << 10);
  if (sVar1 < 0x7fff) {
    if (sVar1 < -0x7fff) {
      sVar1 = -0x8000;
    }
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = (short)(sVar1 * 0x3333 + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  *param_2 = (short)iVar2;
  iVar2 = in_EAX[1] + -0x20;
  if (0xffff < (int)in_EAX[1] + 0x7fe0U) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  sVar1 = (short)(iVar2 << 10);
  if (sVar1 < 0x7fff) {
    if (sVar1 < -0x7fff) {
      sVar1 = -0x8000;
    }
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = (short)(sVar1 * 0x3333 + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[1] = (short)iVar2;
  iVar2 = in_EAX[2] + -0x10;
  if (0xffff < (int)in_EAX[2] + 0x7ff0U) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar2 = (short)(iVar2 << 10) + -0x1000;
  if (iVar2 < 0x7fff) {
    if (iVar2 < -0x7fff) {
      iVar2 = -0x8000;
    }
    sVar1 = (short)iVar2;
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = (short)(sVar1 * 0x3333 + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[2] = (short)iVar2;
  iVar2 = in_EAX[3] + -0x10;
  if (0xffff < (int)in_EAX[3] + 0x7ff0U) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar2 = (short)(iVar2 << 10) + 0x1400;
  if (iVar2 < 0x7fff) {
    if (iVar2 < -0x7fff) {
      iVar2 = -0x8000;
    }
    sVar1 = (short)iVar2;
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = (short)(sVar1 * 0x3333 + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[3] = (short)iVar2;
  iVar2 = in_EAX[4] + -8;
  if (0xffff < (int)in_EAX[4] + 0x7ff8U) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar2 = (short)(iVar2 << 10) + -0xbc;
  if (iVar2 < 0x7fff) {
    if (iVar2 < -0x7fff) {
      iVar2 = -0x8000;
    }
  }
  else {
    iVar2 = 0x7fff;
  }
  iVar2 = (short)((short)iVar2 * 0x4b17 + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[4] = (short)iVar2;
  iVar2 = in_EAX[5] + -8;
  if (0xffff < (int)in_EAX[5] + 0x7ff8U) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar2 = (short)(iVar2 << 10) + 0xe00;
  if (iVar2 < 0x7fff) {
    if (iVar2 < -0x7fff) {
      iVar2 = -0x8000;
    }
  }
  else {
    iVar2 = 0x7fff;
  }
  iVar2 = (short)((short)iVar2 * 0x4444 + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[5] = (short)iVar2;
  iVar2 = in_EAX[6] + -4;
  if (0xffff < (int)in_EAX[6] + 0x7ffcU) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar2 = (short)(iVar2 << 10) + 0x2aa;
  if (iVar2 < 0x7fff) {
    if (iVar2 < -0x7fff) {
      iVar2 = -0x8000;
    }
  }
  else {
    iVar2 = 0x7fff;
  }
  iVar2 = (short)((short)iVar2 * 0x7ade + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[6] = (short)iVar2;
  iVar2 = in_EAX[7] + -4;
  if (0xffff < (int)in_EAX[7] + 0x7ffcU) {
    if (iVar2 < 1) {
      iVar2 = 0;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar2 = (short)(iVar2 << 10) + 0x8f0;
  if (iVar2 < 0x7fff) {
    if (iVar2 < -0x7fff) {
      iVar2 = -0x8000;
    }
  }
  else {
    iVar2 = 0x7fff;
  }
  iVar2 = (short)((short)iVar2 * 0x740c + 0x4000 >> 0xf) * 2;
  if (0xffff < iVar2 + 0x8000U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  param_2[7] = (short)iVar2;
  return;
}


