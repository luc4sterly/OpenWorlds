// 00426820 FUN_00426820 [Global]
// programa: gamma.dll

void __cdecl FUN_00426820(char *param_1,int param_2,int *param_3,undefined1 *param_4)

{
  int iVar1;
  char cVar2;
  int iVar3;
  byte bVar4;
  int iVar5;
  undefined1 uVar6;
  int iVar7;
  int iVar8;
  char *local_18;
  int *local_14;
  
  if (param_2 < 2) {
    iVar7 = 0;
    do {
      if (*param_1 != '\0') {
        *param_1 = '\0';
        iVar3 = 0x100;
        do {
          iVar3 = iVar3 + -1;
          *param_4 = (char)iVar7;
          param_4 = param_4 + 1;
        } while (iVar3 != 0);
        return;
      }
      iVar7 = iVar7 + 1;
      param_1 = param_1 + 1;
    } while (iVar7 < 0x100);
    FUN_00402800(s_huffdcod_00471cb0,0x93);
  }
  else {
    local_18 = param_1;
    iVar7 = 0;
    local_14 = param_3;
    do {
      cVar2 = *local_18;
      local_18 = local_18 + 1;
      iVar3 = *local_14;
      local_14 = local_14 + 1;
      if (cVar2 != '\0') {
        bVar4 = 8 - cVar2;
        iVar8 = 1 << (bVar4 & 0x1f);
        iVar3 = iVar3 << (bVar4 & 0x1f);
        iVar5 = 0;
        if (0 < iVar8) {
          uVar6 = (undefined1)iVar7;
          if (8 < iVar8) {
            do {
              param_4[iVar3] = uVar6;
              iVar5 = iVar5 + 8;
              param_4[iVar3 + 1] = uVar6;
              param_4[iVar3 + 2] = uVar6;
              param_4[iVar3 + 3] = uVar6;
              param_4[iVar3 + 4] = uVar6;
              param_4[iVar3 + 5] = uVar6;
              param_4[iVar3 + 6] = uVar6;
              iVar1 = iVar3 + 7;
              iVar3 = iVar3 + 8;
              param_4[iVar1] = uVar6;
            } while (iVar5 < iVar8 + -8);
          }
          for (; iVar5 < iVar8; iVar5 = iVar5 + 1) {
            param_4[iVar3] = uVar6;
            iVar3 = iVar3 + 1;
          }
        }
      }
      iVar7 = iVar7 + 1;
    } while (iVar7 < 0x100);
  }
  return;
}


