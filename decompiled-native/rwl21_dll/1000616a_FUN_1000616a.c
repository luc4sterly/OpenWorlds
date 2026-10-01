// 1000616a FUN_1000616a [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

uint __fastcall FUN_1000616a(int param_1,uint param_2)

{
  int iVar1;
  float fVar2;
  float fVar3;
  int *piVar4;
  int iVar5;
  float fVar6;
  float fStack00000004;
  float fStack0000000c;
  float fStack00000010;
  float fStack00000014;
  float fStack00000018;
  float fStack0000001c;
  float fStack00000020;
  
  iVar5 = *(int *)(param_1 + 0x3c);
  fStack00000004 = *(float *)(iVar5 + 0x10);
  fStack0000000c = *(float *)(iVar5 + 0xc);
  fStack0000001c = *(float *)(iVar5 + 0x14);
  if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
    fStack0000000c = fStack0000000c / fStack0000001c;
    fStack00000004 = fStack00000004 / fStack0000001c;
  }
  fStack00000014 = fStack00000004;
  fStack00000018 = fStack00000004;
  fStack00000010 = fStack0000000c;
  fStack00000020 = fStack0000001c;
  if (1 < *(byte *)(param_1 + 0x3a)) {
    piVar4 = (int *)(param_1 + 0x40);
    iVar5 = *(byte *)(param_1 + 0x3a) - 1;
    do {
      iVar1 = *piVar4;
      fVar6 = *(float *)(iVar1 + 0xc);
      fStack00000004 = *(float *)(iVar1 + 0x10);
      fVar2 = *(float *)(iVar1 + 0x14);
      if (*(int *)(*(int *)(PTR_DAT_1005b69c + 0x10) + 0x218) == 1) {
        fVar6 = fVar6 / fVar2;
        fStack00000004 = fStack00000004 / fVar2;
      }
      fVar3 = fVar6;
      if ((fStack0000000c <= fVar6) && (fVar3 = fStack0000000c, fStack00000010 < fVar6)) {
        fStack00000010 = fVar6;
      }
      fStack0000000c = fVar3;
      if (fStack00000014 <= fStack00000004) {
        if (fStack00000018 < fStack00000004) {
          fStack00000018 = fStack00000004;
        }
      }
      else {
        fStack00000014 = fStack00000004;
      }
      fVar6 = fVar2;
      if ((fStack0000001c <= fVar2) && (fVar6 = fStack0000001c, fStack00000020 < fVar2)) {
        fStack00000020 = fVar2;
      }
      fStack0000001c = fVar6;
      piVar4 = piVar4 + 1;
      iVar5 = iVar5 + -1;
    } while (iVar5 != 0);
  }
  fVar6 = fStack0000000c;
  if (_DAT_1005ddb0 <= fStack0000000c) {
    fVar6 = _DAT_1005ddb0;
  }
  _DAT_1005ddb0 = fVar6;
  fVar6 = fStack00000010;
  if (fStack00000010 <= _DAT_1005ddb4) {
    fVar6 = _DAT_1005ddb4;
  }
  _DAT_1005ddb4 = fVar6;
  fVar6 = fStack00000014;
  if (_DAT_1005dda0 <= fStack00000014) {
    fVar6 = _DAT_1005dda0;
  }
  _DAT_1005dda0 = fVar6;
  fVar6 = fStack00000018;
  if (fStack00000018 <= _DAT_1005dda4) {
    fVar6 = _DAT_1005dda4;
  }
  _DAT_1005dda4 = fVar6;
  fVar6 = fStack0000001c;
  if (_DAT_1005dda8 <= fStack0000001c) {
    fVar6 = _DAT_1005dda8;
  }
  _DAT_1005dda8 = fVar6;
  fVar6 = fStack00000020;
  if (fStack00000020 <= _DAT_1005ddac) {
    fVar6 = _DAT_1005ddac;
  }
  _DAT_1005ddac = fVar6;
  if ((uint)fStack00000010 < 0x80000001) {
    if (0x80000000 < (uint)fStack0000000c) {
      param_2 = 1;
    }
  }
  else {
    param_2 = 0x100;
  }
  if ((int)fStack0000000c < 0x3f800001) {
    if (0x3f800000 < (int)fStack00000010) {
      param_2 = param_2 | 2;
    }
  }
  else {
    param_2 = param_2 | 0x200;
  }
  if ((uint)fStack00000018 < 0x80000001) {
    if (0x80000000 < (uint)fStack00000014) {
      param_2 = param_2 | 4;
    }
  }
  else {
    param_2 = param_2 | 0x400;
  }
  if ((int)fStack00000014 < 0x3f800001) {
    if (0x3f800000 < (int)fStack00000018) {
      param_2 = param_2 | 8;
    }
  }
  else {
    param_2 = param_2 | 0x800;
  }
  iVar5 = *(int *)(PTR_DAT_1005b69c + 0x10);
  if (fStack00000020 < *(float *)(iVar5 + 0x74)) {
    param_2 = param_2 | 0x1000;
  }
  if (fStack0000001c < *(float *)(iVar5 + 0x74)) {
    param_2 = param_2 | 0x10;
  }
  if (fStack0000001c <= *(float *)(iVar5 + 0x78)) {
    if (*(float *)(iVar5 + 0x78) < fStack00000020) {
      param_2 = param_2 | 0x20;
    }
  }
  else {
    param_2 = param_2 | 0x2000;
  }
  return param_2;
}


