// 0043b5f0 FUN_0043b5f0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __thiscall FUN_0043b5f0(int param_1,undefined4 *param_2,float param_3)

{
  ushort uVar1;
  float10 fVar2;
  float10 fVar3;
  
  *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x18) + param_3;
  fVar2 = (float10)*(float *)(param_1 + 0x18);
  uVar1 = (ushort)(NAN(fVar2) || NAN((float10)_DAT_00476ec4));
  if ((byte)(fVar2 < (float10)_DAT_00476ec4 | (byte)((ushort)(uVar1 << 10) >> 8)) == 1) {
    fVar3 = ABS((float10)*(float *)(param_1 + 0x1c));
    do {
      fVar2 = fVar2 - (float10)(unkint10)(fVar2 / fVar3) * fVar3;
    } while (uVar1 != 0);
    *(float *)(param_1 + 0x18) =
         (float)((float10)(float)fVar2 + (float10)*(float *)(param_1 + 0x1c));
  }
  fVar2 = (float10)*(float *)(param_1 + 0x1c);
  fVar3 = (float10)*(float *)(param_1 + 0x18);
  if (fVar2 < fVar3) {
    if (*(int *)(param_1 + 0x10) == 2) {
      uVar1 = (ushort)(NAN((float10)_DAT_00476ec4) || NAN(fVar2));
      if ((byte)((byte)((ushort)(uVar1 << 10) >> 8) |
                (byte)((ushort)((ushort)((float10)_DAT_00476ec4 == fVar2) << 0xe) >> 8)) == 0x40) {
        *(undefined4 *)(param_1 + 0x18) = 0;
      }
      else {
        do {
          fVar3 = fVar3 - (float10)(unkint10)(fVar3 / ABS(fVar2)) * ABS(fVar2);
        } while (uVar1 != 0);
        *(float *)(param_1 + 0x18) = (float)fVar3;
      }
    }
    else {
      if (*(int *)(param_1 + 0x10) != 1) {
        *param_2 = &PTR_LAB_00474bac;
        *param_2 = &PTR_LAB_00475fac;
        param_2[1] = 0;
        if (param_2[1] != 0) {
          FUN_0042f330(param_2[1]);
        }
        return param_2;
      }
      *(float *)(param_1 + 0x18) = *(float *)(param_1 + 0x1c);
    }
  }
  *(short *)(param_1 + 0x14) = (short)(int)ROUND(*(float *)(param_1 + 0x18) * _DAT_00476ec8);
  *param_2 = &PTR_LAB_00474bac;
  *param_2 = &PTR_LAB_00475fac;
  param_2[1] = param_1;
  if (param_2[1] != 0) {
    FUN_0042f330(param_2[1]);
  }
  return param_2;
}


