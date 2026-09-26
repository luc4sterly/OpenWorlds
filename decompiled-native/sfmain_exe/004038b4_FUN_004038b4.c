// 004038b4 FUN_004038b4 [Global]
// programa: sfmain.exe

void __fastcall FUN_004038b4(short *param_1,short *param_2,undefined2 *param_3)

{
  short sVar1;
  bool bVar2;
  short sVar3;
  short *in_EAX;
  undefined4 extraout_ECX;
  short *unaff_EBX;
  short sVar4;
  short *psVar5;
  int iVar6;
  short local_20;
  undefined2 local_1c;
  short local_18;
  byte local_14;
  short local_10 [2];
  
  local_18 = 0;
  psVar5 = in_EAX;
  do {
    sVar4 = *psVar5;
    if (sVar4 < 0) {
      if (sVar4 == -0x8000) {
        sVar4 = 0x7fff;
      }
      else {
        sVar4 = -sVar4;
      }
    }
    if (local_18 < sVar4) {
      local_18 = sVar4;
    }
    psVar5 = psVar5 + 1;
  } while (psVar5 != in_EAX + 0xd);
  bVar2 = false;
  iVar6 = 0;
  local_10[0] = 0;
  local_18 = local_18 >> 9;
  do {
    bVar2 = (bool)(bVar2 | local_18 < 1);
    local_18 = local_18 >> 1;
    if (5 < local_10[0]) {
      FUN_0042b978();
    }
    if (!bVar2) {
      local_10[0] = local_10[0] + 1;
    }
    iVar6 = iVar6 + 1;
  } while (iVar6 < 6);
  if ((6 < local_10[0]) || (local_10[0] < 0)) {
    FUN_0042b978();
  }
  sVar4 = local_10[0] + 5;
  if ((0xb < sVar4) || (sVar4 < 0)) {
    FUN_0042b978();
  }
  iVar6 = FUN_00407d27((int)sVar4,local_10[0] << 3);
  local_1c = (undefined2)iVar6;
  FUN_00403825(extraout_ECX,local_10);
  if ((0x1000 < local_10[0]) || (local_10[0] < -0x1000)) {
    FUN_0042b978();
  }
  if ((local_20 < 0) || (7 < local_20)) {
    FUN_0042b978();
  }
  sVar3 = 6 - local_10[0];
  sVar4 = *(short *)(&DAT_0043817a + local_20 * 2);
  psVar5 = in_EAX + 0xd;
  do {
    local_14 = (byte)sVar3;
    if ((sVar3 < 0) || (0xf < sVar3)) {
      FUN_0042b978();
    }
    sVar1 = *in_EAX;
    in_EAX = in_EAX + 1;
    *param_2 = ((short)((int)(short)(sVar1 << (local_14 & 0x1f)) * (int)sVar4 >> 0xf) >> 0xc) + 4;
    param_2 = param_2 + 1;
  } while (in_EAX != psVar5);
  *unaff_EBX = local_20;
  *param_1 = local_10[0];
  *param_3 = local_1c;
  return;
}


