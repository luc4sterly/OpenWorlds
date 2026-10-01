// 00401a6a FUN_00401a6a [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __fastcall FUN_00401a6a(undefined4 param_1,undefined2 *param_2)

{
  float *pfVar1;
  float *pfVar2;
  float fVar3;
  int iVar4;
  float fVar5;
  float fVar6;
  undefined2 uVar7;
  byte *in_EAX;
  int extraout_EAX;
  int iVar8;
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  int iVar9;
  int iVar10;
  float10 fVar11;
  float local_48 [11];
  float local_1c;
  float local_18;
  uint local_14;
  
  fVar5 = _DAT_0043f01c;
  iVar9 = 0;
  iVar10 = 0x140;
  fVar3 = _DAT_0043f02c;
  fVar6 = _DAT_0043f028;
  do {
    _DAT_0043f02c = fVar6;
    iVar4 = DAT_004380fc;
    *(float *)(iVar10 + DAT_004380fc) =
         (float)*(short *)(&DAT_00426f92 + (uint)*in_EAX * 2) * (float)_DAT_00435080 *
         (float)_DAT_00435088;
    _DAT_0043f030 = _DAT_0043f018 * *(float *)(iVar10 + iVar4) - _DAT_0043f014 * _DAT_0043f034;
    iVar9 = iVar9 + 1;
    iVar8 = iVar10 + 4;
    in_EAX = in_EAX + 1;
    *(float *)(iVar10 + 4000 + iVar4) =
         (_DAT_0043f024 * _DAT_0043f034 - fVar5 * _DAT_0043f02c) - _DAT_0043f020 * fVar3;
    _DAT_0043f028 = *(float *)(iVar10 + 4000 + iVar4);
    iVar10 = iVar8;
    _DAT_0043f034 = _DAT_0043f030;
    fVar3 = _DAT_0043f02c;
    fVar6 = _DAT_0043f028;
  } while (iVar9 < 0xa0);
  iVar10 = 0;
  FUN_00401724(iVar8,&local_18);
  do {
    pfVar1 = (float *)(DAT_004380fc + iVar10);
    pfVar2 = (float *)(DAT_004380fc + 8000 + iVar10);
    iVar10 = iVar10 + 4;
    *(float *)(DAT_004380fc + 0x2edc + iVar10) = *pfVar1 * *pfVar2;
  } while (iVar10 != 0x3c0);
  FUN_004014d8(local_48,0xf0);
  FUN_00401541(&local_1c,10);
  fVar11 = FUN_0042b8ce();
  local_14 = (uint)ROUND(fVar11);
  uVar7 = Ordinal_9(local_14 & 0xffff);
  *param_2 = uVar7;
  fVar11 = FUN_0042b8ce();
  local_18 = (float)(int)ROUND(fVar11);
  *(undefined1 *)(param_2 + 1) = local_18._0_1_;
  do {
    fVar11 = FUN_0042b8ce();
    local_18 = (float)(int)ROUND(fVar11);
    *(undefined1 *)(param_2 + 2) = local_18._0_1_;
    param_2 = (undefined2 *)((int)param_2 + 1);
  } while (extraout_EAX != 0x24);
  FUN_0042b8eb(extraout_ECX,(undefined4 *)(DAT_004380fc + 0x280));
  FUN_0042b8eb(extraout_ECX_00,(undefined4 *)(DAT_004380fc + 0x1220));
  return;
}


