// 00403f6d FUN_00403f6d [Global]
// programa: sfmain.exe

void __fastcall FUN_00403f6d(undefined4 param_1,int *param_2)

{
  short sVar1;
  short *in_EAX;
  short *psVar2;
  int *piVar3;
  undefined4 extraout_ECX;
  short sVar4;
  int iVar5;
  int *extraout_EDX;
  int *piVar6;
  int iVar7;
  undefined8 uVar8;
  short local_1c;
  
  sVar1 = 0;
  psVar2 = in_EAX;
  do {
    sVar4 = *psVar2;
    param_1 = CONCAT22((short)((uint)param_1 >> 0x10),sVar4);
    if (sVar4 < 0) {
      if (sVar4 == -0x8000) {
        sVar4 = 0x7fff;
      }
      else {
        sVar4 = -sVar4;
      }
    }
    if (sVar1 < sVar4) {
      sVar1 = sVar4;
    }
    psVar2 = psVar2 + 1;
  } while (psVar2 != in_EAX + 0xa0);
  if (sVar1 == 0) {
    local_1c = 0;
  }
  else {
    if (sVar1 < 1) {
      FUN_0042b978();
      param_1 = extraout_ECX;
    }
    uVar8 = FUN_00407eb1(param_1,4);
    local_1c = (short)((ulonglong)uVar8 >> 0x20) - (short)uVar8;
  }
  if (0 < local_1c) {
    switch(local_1c) {
    case 1:
      psVar2 = in_EAX;
      do {
        *psVar2 = (short)(*psVar2 * 0x4000 + 0x4000 >> 0xf);
        psVar2 = psVar2 + 1;
      } while (psVar2 != in_EAX + 0xa0);
      break;
    case 2:
      psVar2 = in_EAX;
      do {
        *psVar2 = (short)(*psVar2 * 0x2000 + 0x4000 >> 0xf);
        psVar2 = psVar2 + 1;
      } while (psVar2 != in_EAX + 0xa0);
      break;
    case 3:
      psVar2 = in_EAX;
      do {
        *psVar2 = (short)(*psVar2 * 0x1000 + 0x4000 >> 0xf);
        psVar2 = psVar2 + 1;
      } while (psVar2 != in_EAX + 0xa0);
      break;
    case 4:
      psVar2 = in_EAX;
      do {
        *psVar2 = (short)(*psVar2 * 0x800 + 0x4000 >> 0xf);
        psVar2 = psVar2 + 1;
      } while (psVar2 != in_EAX + 0xa0);
    }
  }
  piVar3 = param_2 + 9;
  sVar1 = *in_EAX;
  while (piVar3 = piVar3 + -1, piVar3 != param_2 + -1) {
    *piVar3 = 0;
  }
  *param_2 = *param_2 + (int)sVar1 * (int)*in_EAX;
  iVar5 = (int)in_EAX[1];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + iVar5 * *in_EAX;
  iVar5 = (int)in_EAX[2];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + in_EAX[1] * iVar5;
  param_2[2] = param_2[2] + iVar5 * *in_EAX;
  iVar5 = (int)in_EAX[3];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + in_EAX[2] * iVar5;
  param_2[2] = param_2[2] + in_EAX[1] * iVar5;
  param_2[3] = param_2[3] + iVar5 * *in_EAX;
  iVar5 = (int)in_EAX[4];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + in_EAX[3] * iVar5;
  param_2[2] = param_2[2] + in_EAX[2] * iVar5;
  param_2[3] = param_2[3] + in_EAX[1] * iVar5;
  param_2[4] = param_2[4] + iVar5 * *in_EAX;
  iVar5 = (int)in_EAX[5];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + in_EAX[4] * iVar5;
  param_2[2] = param_2[2] + in_EAX[3] * iVar5;
  param_2[3] = param_2[3] + in_EAX[2] * iVar5;
  param_2[4] = param_2[4] + in_EAX[1] * iVar5;
  param_2[5] = param_2[5] + iVar5 * *in_EAX;
  iVar5 = (int)in_EAX[6];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + in_EAX[5] * iVar5;
  param_2[2] = param_2[2] + in_EAX[4] * iVar5;
  param_2[3] = param_2[3] + in_EAX[3] * iVar5;
  param_2[4] = param_2[4] + in_EAX[2] * iVar5;
  param_2[5] = param_2[5] + in_EAX[1] * iVar5;
  param_2[6] = param_2[6] + iVar5 * *in_EAX;
  iVar5 = (int)in_EAX[7];
  *param_2 = *param_2 + iVar5 * iVar5;
  param_2[1] = param_2[1] + in_EAX[6] * iVar5;
  param_2[2] = param_2[2] + in_EAX[5] * iVar5;
  param_2[3] = param_2[3] + in_EAX[4] * iVar5;
  param_2[4] = param_2[4] + in_EAX[3] * iVar5;
  param_2[5] = param_2[5] + in_EAX[2] * iVar5;
  param_2[6] = param_2[6] + in_EAX[1] * iVar5;
  iVar7 = 8;
  param_2[7] = param_2[7] + iVar5 * *in_EAX;
  psVar2 = in_EAX + 7;
  do {
    iVar5 = (int)psVar2[1];
    *param_2 = *param_2 + iVar5 * iVar5;
    param_2[1] = param_2[1] + *psVar2 * iVar5;
    param_2[2] = param_2[2] + psVar2[-1] * iVar5;
    param_2[3] = param_2[3] + psVar2[-2] * iVar5;
    param_2[4] = param_2[4] + psVar2[-3] * iVar5;
    param_2[5] = param_2[5] + psVar2[-4] * iVar5;
    param_2[6] = param_2[6] + psVar2[-5] * iVar5;
    param_2[7] = param_2[7] + psVar2[-6] * iVar5;
    iVar7 = iVar7 + 1;
    param_2[8] = param_2[8] + iVar5 * psVar2[-7];
    psVar2 = psVar2 + 1;
  } while (iVar7 < 0xa0);
  piVar3 = param_2 + 9;
  piVar6 = param_2 + -1;
  while (piVar3 = piVar3 + -1, piVar3 != piVar6) {
    *piVar3 = *piVar3 * 2;
  }
  if (0 < local_1c) {
    if (4 < local_1c) {
      FUN_0042b978();
      piVar6 = extraout_EDX;
    }
    iVar5 = 0xa0;
    while (iVar5 = iVar5 + -1, iVar5 != -1) {
      piVar6 = (int *)(CONCAT22((short)((uint)piVar6 >> 0x10),*in_EAX) << ((byte)local_1c & 0x1f));
      *in_EAX = (short)piVar6;
      in_EAX = in_EAX + 1;
    }
  }
  return;
}


