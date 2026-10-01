// 0040196c FUN_0040196c [Global]
// program: sfmain.exe

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined8 __fastcall FUN_0040196c(undefined4 param_1,undefined4 param_2)

{
  undefined4 extraout_ECX;
  undefined4 extraout_ECX_00;
  undefined4 extraout_ECX_01;
  uint extraout_ECX_02;
  int extraout_EDX;
  undefined4 extraout_EDX_00;
  int iVar1;
  float10 fVar2;
  float10 fVar3;
  float10 fVar4;
  float10 fVar5;
  float10 extraout_ST0;
  float10 extraout_ST0_00;
  float10 extraout_ST1;
  longlong lVar6;
  undefined4 local_18;
  
  iVar1 = 0;
  local_18 = 0;
  fVar2 = (float10)_DAT_00435040;
  fVar3 = (float10)_DAT_00435078;
  fVar4 = (float10)_DAT_00435038;
  do {
    fVar5 = (float10)FUN_0042b7e0();
    *(undefined4 *)(extraout_EDX + iVar1) = 0;
    local_18 = local_18 + 1;
    iVar1 = iVar1 + 4;
    *(float *)(extraout_EDX + 0x1f3c + iVar1) = (float)((fVar3 - fVar5 * fVar4) * fVar2);
  } while (local_18 < 0xf0);
  lVar6 = FUN_0042b860(extraout_ECX,extraout_EDX);
  _DAT_0043f014 = (float)-extraout_ST0;
  _DAT_0043f018 = (float)((float10)1 + -extraout_ST0);
  FUN_0042b860(extraout_ECX_00,(int)((ulonglong)lVar6 >> 0x20));
  fVar2 = (float10)FUN_0042b7e0();
  _DAT_0043f01c = (float)(fVar2 * extraout_ST1);
  lVar6 = FUN_0042b860(extraout_ECX_01,extraout_EDX_00);
  _DAT_0043f034 = 0;
  _DAT_0043f020 = (float)extraout_ST0_00;
  _DAT_0043f028 = 0;
  _DAT_0043f02c = (uint)((ulonglong)lVar6 >> 0x20) ^ extraout_ECX_02;
  _DAT_0043f024 = _DAT_0043f01c + 1.0 + _DAT_0043f020;
  DAT_004380fc = extraout_ECX_02;
  return CONCAT44(param_2,(int)lVar6);
}


