// 1000ea70 FUN_1000ea70 [Global]
// program: RWL21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 * FUN_1000ea70(void)

{
  bool bVar1;
  float fVar2;
  float fVar3;
  int iVar4;
  int iVar5;
  
  DAT_1005a0b4 = (**(code **)(PTR_DAT_1005b69c + 0x350))(4,0x102);
  if (DAT_1005a0b4 == 0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  iVar4 = 0;
  iVar5 = 0;
  fVar2 = 0.0;
  do {
    fVar3 = fVar2 * fVar2 * fVar2 * fVar2;
    fVar3 = fVar3 * fVar3;
    fVar3 = fVar3 * fVar3;
    fVar2 = fVar2 + _DAT_1005210c;
    bVar1 = fVar2 < _DAT_100520d0;
    *(float *)(DAT_1005a0b4 + iVar5) = fVar3;
    iVar5 = iVar5 + 4;
    iVar4 = iVar4 + 1;
  } while (bVar1);
  *(float *)(DAT_1005a0b4 + iVar4 * 4) = fVar3;
  *(float *)(DAT_1005a0b4 + 4 + iVar4 * 4) = fVar3;
  DAT_1005a0ac = 999999;
  DAT_1005a0a8 = FUN_100371c0(s_lightlist_1005a0c0,0x90);
  return DAT_1005a0a8;
}


