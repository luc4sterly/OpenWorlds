// 00401724 FUN_00401724 [Global]
// programa: sfmain.exe

/* WARNING: Type propagation algorithm not settling */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00401724(undefined4 param_1,float *param_2)

{
  undefined4 *puVar1;
  undefined4 uVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  undefined4 *in_EAX;
  float *extraout_ECX;
  int iVar8;
  int iVar9;
  undefined4 local_410 [199];
  float afStack_f4 [6];
  float afStack_dc [28];
  float local_6c [13];
  float local_38 [8];
  int local_18;
  float local_14;
  
  puVar1 = in_EAX + 0xf0;
  iVar8 = 0;
  do {
    uVar2 = *in_EAX;
    in_EAX = in_EAX + 5;
    *(undefined4 *)((int)local_410 + iVar8) = uVar2;
    iVar8 = iVar8 + 4;
  } while (in_EAX != puVar1);
  FUN_004014d8(afStack_f4 + 1,0x30);
  FUN_00401541(local_38,4);
  FUN_0040169b(afStack_f4 + 1,local_6c);
  FUN_004014d8(extraout_ECX,0x30);
  iVar9 = 5;
  local_18 = 0;
  local_14 = 0.0;
  iVar8 = 0x14;
  do {
    if (local_14 < *(float *)((int)afStack_f4 + iVar8 + 4U)) {
      local_18 = iVar9;
      local_14 = *(float *)((int)afStack_f4 + iVar8 + 4U);
    }
    iVar9 = iVar9 + 1;
    iVar8 = iVar8 + 4;
  } while (iVar9 < 0x21);
  iVar8 = local_18 * local_18;
  fVar3 = afStack_f4[local_18] * (float)_DAT_00435004;
  fVar7 = afStack_f4[local_18 + 2] * (float)_DAT_00435004;
  fVar5 = (fVar3 - local_14) + fVar7;
  fVar4 = (float)local_18 * (float)_DAT_0043500c;
  fVar4 = (1.0 - fVar4) * fVar7 +
          fVar4 * local_14 + afStack_f4[local_18] * (float)_DAT_00435014 * (fVar4 + 1.0);
  fVar6 = -fVar4 / (fVar5 * (float)_DAT_0043500c);
  afStack_f4[1] =
       ((float)(iVar8 - local_18) * fVar7 +
        (1.0 - (float)iVar8) * local_14 + (float)(iVar8 + local_18) * fVar3 +
       fVar4 * fVar6 + fVar5 * fVar6 * fVar6) / afStack_f4[1];
  if (((float)_DAT_00435020 <= afStack_f4[1]) ||
     ((DAT_00438100 == 3 && ((float)_DAT_00435028 <= afStack_f4[1])))) {
    *param_2 = fVar6 * _DAT_0043501c;
    DAT_00438100 = (DAT_00438100 & 1) * 2 + 1;
  }
  else {
    DAT_00438100 = (DAT_00438100 & 1) * 2;
    *param_2 = 0.0;
  }
  return;
}


