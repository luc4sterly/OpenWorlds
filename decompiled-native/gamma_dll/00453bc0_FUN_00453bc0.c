// 00453bc0 FUN_00453bc0 [Global]
// program: gamma.dll

ulonglong FUN_00453bc0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  ulonglong uVar1;
  longlong lVar2;
  int iVar3;
  byte bVar4;
  uint uVar5;
  bool bVar6;
  
  if (param_4 != 0) {
    bVar6 = (param_4 & 1) != 0;
    iVar3 = 0x1f;
    if (param_4 != 0) {
      for (; param_4 >> iVar3 == 0; iVar3 = iVar3 + -1) {
      }
    }
    bVar4 = (byte)iVar3;
    uVar1 = CONCAT44((param_2 >> 1) >> (bVar4 & 0x1f),
                     (uint)(CONCAT14((param_2 & 1) != 0,param_1) >> 1) >> (bVar4 & 0x1f) |
                     (param_2 >> 1) << 0x20 - (bVar4 & 0x1f)) /
            (ulonglong)
            ((uint)(CONCAT14(bVar6,param_3) >> 1) >> (bVar4 & 0x1f) |
            (param_4 >> 1 | (uint)bVar6 << 0x1f) << 0x20 - (bVar4 & 0x1f));
    iVar3 = (int)uVar1;
    lVar2 = (uVar1 & 0xffffffff) * (ulonglong)param_3;
    uVar5 = (int)((ulonglong)lVar2 >> 0x20) + ((param_4 >> 1) << 1 | (uint)bVar6) * iVar3;
    return (ulonglong)
           (iVar3 - (uint)(param_2 < uVar5 || param_2 - uVar5 < (uint)(param_1 < (uint)lVar2)));
  }
  if (param_2 < param_3) {
    return CONCAT44(param_2,param_1) / (ulonglong)param_3 & 0xffffffff;
  }
  return CONCAT44(param_2 / param_3,
                  (int)(((ulonglong)param_2 % (ulonglong)param_3 << 0x20 | (ulonglong)param_1) /
                       (ulonglong)param_3));
}


