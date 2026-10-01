// 00428a20 FUN_00428a20 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __fastcall FUN_00428a20(int param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  LPVOID pvVar6;
  
  fVar1 = *(float *)(param_1 + 0x34) * *(float *)(param_1 + 0x34) +
          *(float *)(param_1 + 0x20) * *(float *)(param_1 + 0x20) +
          *(float *)(param_1 + 0xc) * *(float *)(param_1 + 0xc) + _DAT_00473334;
  if (fVar1 < (float)_DAT_00473338) {
    pvVar6 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar6 + 4) = 0x21;
    fVar1 = _DAT_004823b0;
  }
  else {
    fVar1 = SQRT(fVar1);
  }
  fVar2 = *(float *)(param_1 + 0x3c) * *(float *)(param_1 + 0x3c) +
          *(float *)(param_1 + 0x28) * *(float *)(param_1 + 0x28) +
          *(float *)(param_1 + 0x14) * *(float *)(param_1 + 0x14) + _DAT_00473334;
  if (fVar2 < (float)_DAT_00473338) {
    pvVar6 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar6 + 4) = 0x21;
    fVar2 = _DAT_004823b0;
  }
  else {
    fVar2 = SQRT(fVar2);
  }
  fVar3 = (_DAT_00473320 * *(float *)(param_1 + 0x10) +
          (_DAT_00473324 * *(float *)(param_1 + 8) - *(float *)(param_1 + 0xc))) -
          *(float *)(param_1 + 0x14);
  fVar5 = (_DAT_00473320 * *(float *)(param_1 + 0x24) +
          (_DAT_00473324 * *(float *)(param_1 + 0x1c) - *(float *)(param_1 + 0x20))) -
          *(float *)(param_1 + 0x28);
  fVar4 = (_DAT_00473320 * *(float *)(param_1 + 0x38) +
          (_DAT_00473324 * *(float *)(param_1 + 0x30) - *(float *)(param_1 + 0x34))) -
          *(float *)(param_1 + 0x3c);
  fVar3 = fVar4 * fVar4 + fVar5 * fVar5 + fVar3 * fVar3;
  if (fVar3 < (float)_DAT_00473338) {
    pvVar6 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar6 + 4) = 0x21;
    fVar3 = _DAT_004823b0;
  }
  else {
    fVar3 = SQRT(fVar3);
  }
  return ((float10)fVar3 + (float10)fVar1 + (float10)fVar2) * (float10)_DAT_00473340;
}


