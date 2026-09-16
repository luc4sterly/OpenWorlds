// 004518b0 FUN_004518b0 [Global]
// programa: gamma.dll

ushort * FUN_004518b0(ushort *param_1,ushort *param_2,int param_3)

{
  undefined4 uVar1;
  ushort *puVar2;
  
  for (puVar2 = param_1; puVar2 < param_2; puVar2 = puVar2 + 1) {
    uVar1 = FUN_00451aa0(*puVar2);
    *(char *)(param_3 +
             ((int)((((int)puVar2 - (int)param_1) + 1U) -
                   (uint)((uint)((int)puVar2 - (int)param_1) < 0x80000000)) >> 1)) = (char)uVar1;
  }
  return param_2;
}


