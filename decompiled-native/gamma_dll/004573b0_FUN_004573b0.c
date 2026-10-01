// 004573b0 FUN_004573b0 [Global]
// program: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

float10 __cdecl FUN_004573b0(int param_1,int *param_2)

{
  double dVar1;
  double dVar2;
  LPVOID pvVar3;
  float10 fVar4;
  int local_20;
  int local_1c;
  int local_18 [3];
  
  local_18[0] = param_1;
  local_18[1] = 0;
  fVar4 = FUN_004565d0(0x7fffffff,&LAB_00459020,local_18,&local_20,&local_1c);
  dVar1 = (double)fVar4;
  if (param_2 != (int *)0x0) {
    *param_2 = param_1 + local_20;
  }
  dVar2 = ABS(dVar1);
  if ((local_1c != 0) ||
     (((byte)((byte)((ushort)((ushort)(NAN(_DAT_00482710) || NAN(dVar1)) << 10) >> 8) |
             (byte)((ushort)((ushort)(_DAT_00482710 == dVar1) << 0xe) >> 8)) != 0x40 &&
      (((byte)(dVar2 < _DAT_004823b8 |
              (byte)((ushort)((ushort)(NAN(dVar2) || NAN(_DAT_004823b8)) << 10) >> 8)) == 1 ||
       (_DAT_004823c0 < dVar2)))))) {
    pvVar3 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar3 + 4) = 0x22;
  }
  return (float10)dVar1;
}


