// 004046ba FUN_004046ba [Global]
// programa: sfmain.exe

void FUN_004046ba(void)

{
  short *in_EAX;
  short sVar1;
  int iVar2;
  int iVar3;
  
  sVar1 = (short)(*in_EAX * 0x5000 >> 0xf);
  if (0xffff < (int)sVar1 + 0x8000U) {
    if (sVar1 < 1) {
      sVar1 = -0x8000;
    }
    else {
      sVar1 = 0x7fff;
    }
  }
  iVar2 = sVar1 + 0x100;
  if ((int)sVar1 + 0x8100U < 0x10000) {
    sVar1 = (short)iVar2;
  }
  else if (iVar2 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  sVar1 = sVar1 >> 9;
  if (sVar1 < 0x20) {
    if (sVar1 < -0x20) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 0x20;
    }
  }
  else {
    sVar1 = 0x3f;
  }
  *in_EAX = sVar1;
  sVar1 = (short)(in_EAX[1] * 0x5000 >> 0xf);
  if (0xffff < (int)sVar1 + 0x8000U) {
    if (sVar1 < 1) {
      sVar1 = -0x8000;
    }
    else {
      sVar1 = 0x7fff;
    }
  }
  iVar2 = sVar1 + 0x100;
  if (0xffff < (int)sVar1 + 0x8100U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  sVar1 = (short)iVar2 >> 9;
  if (sVar1 < 0x20) {
    if (sVar1 < -0x20) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 0x20;
    }
  }
  else {
    sVar1 = 0x3f;
  }
  in_EAX[1] = sVar1;
  iVar3 = (int)(short)(in_EAX[2] * 0x5000 >> 0xf);
  iVar2 = iVar3 + 0x800;
  if (0xffff < iVar3 + 0x8800U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar3 = (short)iVar2 + 0x100;
  if (0xffff < (int)(short)iVar2 + 0x8100U) {
    if (iVar3 < 1) {
      iVar3 = -0x8000;
    }
    else {
      iVar3 = 0x7fff;
    }
  }
  sVar1 = (short)iVar3 >> 9;
  if (sVar1 < 0x10) {
    if (sVar1 < -0x10) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 0x10;
    }
  }
  else {
    sVar1 = 0x1f;
  }
  in_EAX[2] = sVar1;
  iVar3 = (int)(short)(in_EAX[3] * 0x5000 >> 0xf);
  iVar2 = iVar3 + -0xa00;
  if (iVar3 + 0x7600U < 0x10000) {
    sVar1 = (short)iVar2;
  }
  else if (iVar2 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = sVar1 + 0x100;
  if ((int)sVar1 + 0x8100U < 0x10000) {
    sVar1 = (short)iVar2;
  }
  else if (iVar2 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  sVar1 = sVar1 >> 9;
  if (sVar1 < 0x10) {
    if (sVar1 < -0x10) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 0x10;
    }
  }
  else {
    sVar1 = 0x1f;
  }
  in_EAX[3] = sVar1;
  iVar3 = (int)(short)(in_EAX[4] * 0x368c >> 0xf);
  iVar2 = iVar3 + 0x5e;
  if (iVar3 + 0x805eU < 0x10000) {
    sVar1 = (short)iVar2;
  }
  else if (iVar2 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = sVar1 + 0x100;
  if (0xffff < (int)sVar1 + 0x8100U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  sVar1 = (short)iVar2 >> 9;
  if (sVar1 < 8) {
    if (sVar1 < -8) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 8;
    }
  }
  else {
    sVar1 = 0xf;
  }
  in_EAX[4] = sVar1;
  iVar3 = (int)(short)(in_EAX[5] * 0x3c00 >> 0xf);
  iVar2 = iVar3 + -0x700;
  if (iVar3 + 0x7900U < 0x10000) {
    sVar1 = (short)iVar2;
  }
  else if (iVar2 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  iVar2 = sVar1 + 0x100;
  if ((int)sVar1 + 0x8100U < 0x10000) {
    sVar1 = (short)iVar2;
  }
  else if (iVar2 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  sVar1 = sVar1 >> 9;
  if (sVar1 < 8) {
    if (sVar1 < -8) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 8;
    }
  }
  else {
    sVar1 = 0xf;
  }
  in_EAX[5] = sVar1;
  iVar3 = (int)(short)(in_EAX[6] * 0x2156 >> 0xf);
  iVar2 = iVar3 + -0x155;
  if (0xffff < iVar3 + 0x7eabU) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar3 = (short)iVar2 + 0x100;
  if (0xffff < (int)(short)iVar2 + 0x8100U) {
    if (iVar3 < 1) {
      iVar3 = -0x8000;
    }
    else {
      iVar3 = 0x7fff;
    }
  }
  sVar1 = (short)iVar3 >> 9;
  if (sVar1 < 4) {
    if (sVar1 < -4) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 4;
    }
  }
  else {
    sVar1 = 7;
  }
  in_EAX[6] = sVar1;
  iVar3 = (int)(short)(in_EAX[7] * 0x234c >> 0xf);
  iVar2 = iVar3 + -0x478;
  if (0xffff < iVar3 + 0x7b88U) {
    if (iVar2 < 1) {
      iVar2 = -0x8000;
    }
    else {
      iVar2 = 0x7fff;
    }
  }
  iVar3 = (short)iVar2 + 0x100;
  if ((int)(short)iVar2 + 0x8100U < 0x10000) {
    sVar1 = (short)iVar3;
  }
  else if (iVar3 < 1) {
    sVar1 = -0x8000;
  }
  else {
    sVar1 = 0x7fff;
  }
  sVar1 = sVar1 >> 9;
  if (sVar1 < 4) {
    if (sVar1 < -4) {
      sVar1 = 0;
    }
    else {
      sVar1 = sVar1 + 4;
    }
  }
  else {
    sVar1 = 7;
  }
  in_EAX[7] = sVar1;
  return;
}


