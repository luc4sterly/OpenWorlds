// 00405459 FUN_00405459 [Global]
// program: sfmain.exe

void __fastcall FUN_00405459(short *param_1,short param_2,undefined2 *param_3)

{
  short sVar1;
  int in_EAX;
  undefined2 *puVar2;
  int iVar4;
  short unaff_BX;
  int iVar5;
  undefined2 *puVar3;
  
  if ((param_2 < 0x28) || (0x78 < param_2)) {
    param_2 = *(short *)(in_EAX + 0x26e);
  }
  *(short *)(in_EAX + 0x26e) = param_2;
  if ((param_2 < 0x28) || (0x78 < param_2)) {
    FUN_0042b978();
  }
  sVar1 = *(short *)(&DAT_0043815c + unaff_BX * 2);
  if (sVar1 == -0x8000) {
    FUN_0042b978();
  }
  iVar5 = 0;
  puVar2 = param_3;
  do {
    iVar4 = (int)(short)((int)(short)param_3[iVar5 - param_2] * (int)sVar1 + 0x4000 >> 0xf) +
            (int)*param_1;
    if (0xffff < iVar4 + 0x8000U) {
      if (iVar4 < 1) {
        iVar4 = -0x8000;
      }
      else {
        iVar4 = 0x7fff;
      }
    }
    param_1 = param_1 + 1;
    iVar5 = iVar5 + 1;
    *puVar2 = (short)iVar4;
    puVar2 = puVar2 + 1;
  } while (iVar5 < 0x28);
  puVar2 = param_3;
  do {
    puVar3 = puVar2 + 1;
    puVar2[-0x78] = puVar2[-0x50];
    puVar2 = puVar3;
  } while (puVar3 != param_3 + 0x78);
  return;
}


