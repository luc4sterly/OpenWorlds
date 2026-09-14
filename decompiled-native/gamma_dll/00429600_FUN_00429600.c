// 00429600 FUN_00429600 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * __cdecl FUN_00429600(undefined4 *param_1,int param_2)

{
  float fVar1;
  LPVOID pvVar2;
  
  fVar1 = *(float *)(param_2 + 0xc) * *(float *)(param_2 + 0xc) +
          *(float *)(param_2 + 4) * *(float *)(param_2 + 4) +
          *(float *)(param_2 + 8) * *(float *)(param_2 + 8);
  if (fVar1 < (float)_DAT_00473850) {
    pvVar2 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar2 + 4) = 0x21;
    fVar1 = _DAT_004823b0;
  }
  else {
    fVar1 = SQRT(fVar1);
  }
  if ((byte)((byte)((ushort)((ushort)(NAN(_DAT_00473858) || NAN(fVar1)) << 10) >> 8) |
            (byte)((ushort)((ushort)(_DAT_00473858 == fVar1) << 0xe) >> 8)) != 0x40) {
    FUN_00429560(param_1,param_2,fVar1);
    return param_1;
  }
  *param_1 = &PTR_LAB_004732e8;
  param_1[1] = *(undefined4 *)(param_2 + 4);
  param_1[2] = *(undefined4 *)(param_2 + 8);
  param_1[3] = *(undefined4 *)(param_2 + 0xc);
  return param_1;
}


