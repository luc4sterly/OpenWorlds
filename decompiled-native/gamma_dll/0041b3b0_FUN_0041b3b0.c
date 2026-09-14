// 0041b3b0 FUN_0041b3b0 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 __cdecl FUN_0041b3b0(undefined4 param_1,undefined4 param_2)

{
  double dVar1;
  float fVar2;
  float fVar3;
  float fVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  float fVar8;
  float fVar9;
  byte bVar12;
  undefined4 uVar10;
  LPVOID pvVar11;
  float local_3c;
  float local_38;
  float local_34;
  float local_30;
  float local_2c;
  float local_28;
  float local_24;
  float local_20;
  float local_1c;
  float local_18;
  float local_14;
  float local_10;
  
  FUN_004195e0(param_2,1,&local_3c);
  FUN_004195e0(param_2,2,&local_30);
  FUN_004195e0(param_2,4,&local_24);
  uVar10 = FUN_00419950();
  FUN_004193c0(param_2,uVar10);
  FUN_0041a080(&local_3c,uVar10);
  FUN_0041a080(&local_30,uVar10);
  FUN_0041a080(&local_24,uVar10);
  FUN_004198f0();
  FUN_00419260(param_1,&local_18);
  fVar6 = local_30 - local_3c;
  fVar2 = local_2c - local_38;
  fVar4 = local_28 - local_34;
  fVar7 = local_24 - local_3c;
  fVar3 = local_20 - local_38;
  fVar5 = local_1c - local_34;
  fVar8 = fVar4 * fVar4 + fVar6 * fVar6 + fVar2 * fVar2;
  if (fVar8 < (float)_DAT_004708b0) {
    pvVar11 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar11 + 4) = 0x21;
    fVar8 = _DAT_004823b0;
  }
  else {
    fVar8 = SQRT(fVar8);
  }
  dVar1 = (double)fVar8;
  fVar9 = fVar5 * fVar5 + fVar7 * fVar7 + fVar3 * fVar3;
  if (fVar9 < (float)_DAT_004708b0) {
    pvVar11 = FUN_00453ed0();
    *(undefined4 *)((int)pvVar11 + 4) = 0x21;
    fVar9 = _DAT_004823b0;
  }
  else {
    fVar9 = SQRT(fVar9);
  }
  bVar12 = dVar1 < _DAT_004708b8 |
           (byte)((ushort)((ushort)(NAN(dVar1) || NAN(_DAT_004708b8)) << 10) >> 8) |
           (byte)((ushort)((ushort)(dVar1 == _DAT_004708b8) << 0xe) >> 8);
  if (((bVar12 != 1) && (bVar12 != 0x40)) && ((float)_DAT_004708b8 < fVar9)) {
    fVar8 = (float)_DAT_004708c0 / fVar8;
    fVar9 = (float)_DAT_004708c0 / fVar9;
    return (uint)(((local_18 - local_3c) * fVar2 * fVar8 - (local_14 - local_38) * fVar6 * fVar8) *
                  fVar5 * fVar9 +
                  ((local_14 - local_38) * fVar4 * fVar8 - (local_10 - local_34) * fVar2 * fVar8) *
                  fVar7 * fVar9 +
                  ((local_10 - local_34) * fVar6 * fVar8 - (local_18 - local_3c) * fVar4 * fVar8) *
                  fVar3 * fVar9 <= (float)_DAT_004708b8);
  }
  return 1;
}


