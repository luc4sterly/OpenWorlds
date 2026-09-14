// 00426f40 FUN_00426f40 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00426f40(float *param_1)

{
  float fVar1;
  float fVar2;
  float fVar3;
  byte bVar5;
  LPVOID pvVar4;
  
  fVar1 = *param_1 * *param_1 +
          param_1[3] * param_1[3] + param_1[1] * param_1[1] + param_1[2] * param_1[2];
  fVar2 = fVar1;
  if ((byte)(fVar1 < (float)_DAT_00471d20 |
            (byte)((ushort)((ushort)(NAN(fVar1) || NAN((float)_DAT_00471d20)) << 10) >> 8)) == 1) {
    fVar2 = -fVar1;
  }
  fVar3 = (float)_DAT_00471d28;
  bVar5 = fVar2 < fVar3 | (byte)((ushort)((ushort)(NAN(fVar2) || NAN(fVar3)) << 10) >> 8) |
          (byte)((ushort)((ushort)(fVar2 == fVar3) << 0xe) >> 8);
  if ((bVar5 != 1) && (bVar5 != 0x40)) {
    if (fVar1 < (float)_DAT_00471d20) {
      pvVar4 = FUN_00453ed0();
      *(undefined4 *)((int)pvVar4 + 4) = 0x21;
      fVar1 = _DAT_004823b0;
    }
    else {
      fVar1 = SQRT(fVar1);
    }
    *param_1 = *param_1 / fVar1;
    param_1[1] = param_1[1] / fVar1;
    param_1[2] = param_1[2] / fVar1;
    param_1[3] = param_1[3] / fVar1;
  }
  return;
}


