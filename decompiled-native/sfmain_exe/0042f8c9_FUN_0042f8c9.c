// 0042f8c9 FUN_0042f8c9 [Global]
// programa: sfmain.exe

byte * __fastcall FUN_0042f8c9(undefined4 param_1,byte *param_2)

{
  byte bVar1;
  byte *in_EAX;
  uint uVar2;
  undefined4 uVar3;
  int extraout_ECX;
  int extraout_ECX_00;
  int extraout_ECX_01;
  int iVar4;
  int *unaff_EBX;
  byte *pbVar5;
  byte *pbVar6;
  int local_24;
  int local_20;
  int local_1c;
  uint local_18;
  byte *local_14;
  
  pbVar5 = in_EAX;
  if (*in_EAX == 0x3a) {
    in_EAX = in_EAX + 1;
    pbVar5 = in_EAX;
  }
  for (; ((((bVar1 = *in_EAX, bVar1 != 0 && (bVar1 != 0x2c)) && (bVar1 != 0x2d)) && (bVar1 != 0x2b))
         && ((bVar1 < 0x30 || (0x39 < bVar1)))); in_EAX = in_EAX + 1) {
  }
  local_18 = (int)in_EAX - (int)pbVar5;
  if (0x1e < (int)local_18) {
    local_18 = 0x1e;
  }
  pbVar6 = param_2;
  for (uVar2 = local_18 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(undefined4 *)pbVar6 = *(undefined4 *)pbVar5;
    pbVar5 = pbVar5 + 4;
    pbVar6 = pbVar6 + 4;
  }
  for (uVar2 = local_18 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *pbVar6 = *pbVar5;
    pbVar5 = pbVar5 + 1;
    pbVar6 = pbVar6 + 1;
  }
  param_2[local_18] = 0;
  uVar3 = 0;
  if (bVar1 == 0x2d) {
    uVar3 = 1;
  }
  else if (bVar1 != 0x2b) goto LAB_0042f963;
  in_EAX = in_EAX + 1;
LAB_0042f963:
  if ((0x2f < *in_EAX) && (*in_EAX < 0x3a)) {
    local_24 = 0;
    local_20 = 0;
    local_1c = 0;
    local_14 = param_2;
    in_EAX = (byte *)FUN_0042f8a5(uVar3,&local_1c);
    iVar4 = extraout_ECX;
    if ((*in_EAX == 0x3a) &&
       (in_EAX = (byte *)FUN_0042f8a5(extraout_ECX,&local_20), iVar4 = extraout_ECX_00,
       *in_EAX == 0x3a)) {
      in_EAX = (byte *)FUN_0042f8a5(extraout_ECX_00,&local_24);
      iVar4 = extraout_ECX_01;
    }
    local_24 = local_24 + (local_20 + local_1c * 0x3c) * 0x3c;
    *unaff_EBX = local_24;
    if (iVar4 != 0) {
      *unaff_EBX = -local_24;
    }
  }
  return in_EAX;
}


