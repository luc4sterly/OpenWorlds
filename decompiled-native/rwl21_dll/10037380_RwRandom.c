// 10037380 RwRandom [Global]
// programa: RWL21.DLL

uint RwRandom(void)

{
  uint uVar1;
  
                    /* 0x37380  318  RwRandom */
  if (DAT_1005b72c == 0) {
    *(uint *)PTR_DAT_1005b728 = *(int *)PTR_DAT_1005b728 * -0x3e39b193 + 0x3039U & 0x7fffffff;
    return *(uint *)PTR_DAT_1005b728;
  }
  *(int *)PTR_DAT_1005b720 = *(int *)PTR_DAT_1005b720 + *(int *)PTR_DAT_1005b724;
  uVar1 = *(uint *)PTR_DAT_1005b720;
  PTR_DAT_1005b720 = PTR_DAT_1005b720 + 4;
  if (PTR_PTR_1005b738 <= PTR_DAT_1005b720) {
    PTR_DAT_1005b720 = PTR_DAT_1005b728;
    PTR_DAT_1005b724 = PTR_DAT_1005b724 + 4;
    return uVar1 >> 1;
  }
  PTR_DAT_1005b724 = PTR_DAT_1005b724 + 4;
  if (PTR_PTR_1005b738 <= PTR_DAT_1005b724) {
    PTR_DAT_1005b724 = PTR_DAT_1005b728;
  }
  return uVar1 >> 1;
}


