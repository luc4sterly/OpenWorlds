// 00403825 FUN_00403825 [Global]
// programa: sfmain.exe

void __fastcall FUN_00403825(undefined4 param_1,short *param_2)

{
  short in_AX;
  ushort uVar1;
  short *unaff_EBX;
  short sVar2;
  short sVar3;
  int iVar4;
  
  iVar4 = 0;
  if (0xf < in_AX) {
    iVar4 = ((int)in_AX >> 3) + -1;
  }
  uVar1 = in_AX - (short)(iVar4 << 3);
  if (uVar1 == 0) {
    sVar3 = -4;
    sVar2 = 7;
  }
  else {
    for (; sVar3 = (short)iVar4, (short)uVar1 < 8; uVar1 = uVar1 * 2 | 1) {
      iVar4 = iVar4 + -1;
    }
    sVar2 = uVar1 - 8;
  }
  if ((sVar3 < -4) || (6 < sVar3)) {
    FUN_0042b978();
  }
  if ((sVar2 < 0) || (7 < sVar2)) {
    FUN_0042b978();
  }
  *param_2 = sVar3;
  *unaff_EBX = sVar2;
  return;
}


