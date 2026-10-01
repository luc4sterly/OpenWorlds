// 10037240 RwSRandom [Global]
// program: RWL21.DLL

void RwSRandom(undefined4 param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  bool bVar4;
  
                    /* 0x37240  359  RwSRandom */
  bVar4 = DAT_1005b72c != 0;
  *(undefined4 *)PTR_DAT_1005b728 = param_1;
  if (bVar4) {
    iVar2 = 1;
    if (1 < DAT_1005b730) {
      iVar3 = 4;
      do {
        iVar2 = iVar2 + 1;
        piVar1 = (int *)(PTR_DAT_1005b728 + iVar3);
        iVar3 = iVar3 + 4;
        *piVar1 = piVar1[-1] * 0x41c64e6d + 0x3039;
      } while (iVar2 < DAT_1005b730);
    }
    PTR_DAT_1005b720 = PTR_DAT_1005b728 + DAT_1005b734 * 4;
    iVar2 = 0;
    PTR_DAT_1005b724 = PTR_DAT_1005b728;
    if (0 < DAT_1005b730 * 10) {
      do {
        if (DAT_1005b72c == 0) {
          *(uint *)PTR_DAT_1005b728 = *(int *)PTR_DAT_1005b728 * -0x3e39b193 + 0x3039U & 0x7fffffff;
        }
        else {
          *(int *)PTR_DAT_1005b720 = *(int *)PTR_DAT_1005b720 + *(int *)PTR_DAT_1005b724;
          PTR_DAT_1005b720 = PTR_DAT_1005b720 + 4;
          if (PTR_DAT_1005b720 < PTR_PTR_1005b738) {
            PTR_DAT_1005b724 = PTR_DAT_1005b724 + 4;
            if (PTR_PTR_1005b738 <= PTR_DAT_1005b724) {
              PTR_DAT_1005b724 = PTR_DAT_1005b728;
            }
          }
          else {
            PTR_DAT_1005b724 = PTR_DAT_1005b724 + 4;
            PTR_DAT_1005b720 = PTR_DAT_1005b728;
          }
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < DAT_1005b730 * 10);
    }
    return;
  }
  return;
}


