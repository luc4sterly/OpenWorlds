// 00453d00 FUN_00453d00 [Global]
// programa: gamma.dll

ulonglong FUN_00453d00(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  ulonglong uVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  byte bVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  if (param_4 != 0) {
    bVar10 = (param_4 & 1) != 0;
    iVar2 = 0x1f;
    if (param_4 != 0) {
      for (; param_4 >> iVar2 == 0; iVar2 = iVar2 + -1) {
      }
    }
    bVar7 = (byte)iVar2;
    uVar3 = CONCAT44((param_2 >> 1) >> (bVar7 & 0x1f),
                     (uint)(CONCAT14((param_2 & 1) != 0,param_1) >> 1) >> (bVar7 & 0x1f) |
                     (param_2 >> 1) << 0x20 - (bVar7 & 0x1f)) /
            (ulonglong)
            ((uint)(CONCAT14(bVar10,param_3) >> 1) >> (bVar7 & 0x1f) |
            (param_4 >> 1 | (uint)bVar10 << 0x1f) << 0x20 - (bVar7 & 0x1f));
    lVar4 = (uVar3 & 0xffffffff) * (ulonglong)param_3;
    uVar5 = (uint)lVar4;
    uVar8 = (int)((ulonglong)lVar4 >> 0x20) + ((param_4 >> 1) << 1 | (uint)bVar10) * (int)uVar3;
    uVar9 = param_1 - uVar5;
    uVar5 = (uint)(param_1 < uVar5);
    uVar1 = param_2 - uVar8;
    uVar8 = -(uint)(param_2 < uVar8 || uVar1 < uVar5);
    uVar6 = param_3 & uVar8;
    return CONCAT44((uVar8 & param_4) + (uVar1 - uVar5) + (uint)CARRY4(uVar6,uVar9),uVar6 + uVar9);
  }
  if (param_2 < param_3) {
    return CONCAT44(param_2,param_1) % (ulonglong)param_3;
  }
  return ((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) % (ulonglong)param_3
  ;
}


