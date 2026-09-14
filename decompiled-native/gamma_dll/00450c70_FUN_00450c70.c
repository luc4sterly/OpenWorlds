// 00450c70 FUN_00450c70 [Global]
// programa: gamma.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void __cdecl FUN_00450c70(char *param_1,int *param_2)

{
  char *pcVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int *piVar9;
  int iVar10;
  undefined4 *puVar11;
  char *pcVar12;
  int local_18;
  
  if (DAT_0049e530 == '\0') {
    _DAT_0049e52c = 0;
    DAT_0049e530 = '\x01';
  }
  *param_2 = 0;
  param_2[2] = 0;
  for (piVar9 = DAT_0049e528; (piVar9 != (int *)0x0 && (param_1 < *(char **)*piVar9));
      piVar9 = (int *)piVar9[2]) {
  }
  if (piVar9 == (int *)0x0) {
    return;
  }
  iVar8 = *piVar9;
  iVar2 = (int)((piVar9[1] - iVar8) + (piVar9[1] - iVar8 >> 0x1f & 7U)) >> 3;
  iVar7 = 0;
  iVar5 = iVar2;
  if (iVar2 != 1) {
    do {
      iVar10 = iVar7 + iVar5 >> 1;
      iVar6 = iVar10;
      if (*(char **)(iVar8 + iVar10 * 8) <= param_1) {
        iVar6 = iVar5;
        iVar7 = iVar10;
      }
      iVar5 = iVar6;
    } while (iVar7 + 1 != iVar6);
  }
  if ((*(char **)(iVar8 + iVar7 * 8) <= param_1) &&
     ((iVar7 + 1 == iVar2 || (param_1 < *(char **)(iVar8 + 8 + iVar7 * 8))))) {
    iVar8 = *(int *)(iVar8 + 4 + iVar7 * 8);
    *param_2 = iVar8;
    if ((*(byte *)*param_2 & 1) == 0) {
      uVar3 = (uint)*(ushort *)((byte *)*param_2 + 5);
      puVar11 = (undefined4 *)(iVar8 + 7);
      local_18 = 0;
      if (uVar3 != 0) {
        do {
          pcVar1 = (char *)*puVar11;
          if (*pcVar1 == -0x18) {
            pcVar12 = pcVar1 + 5;
          }
          else if (*pcVar1 == -1) {
            iVar8 = (int)(uint)(byte)pcVar1[1] >> 6;
            uVar4 = (byte)pcVar1[1] & 7;
            pcVar12 = pcVar1 + 2;
            if (iVar8 != 3) {
              if (uVar4 == 4) {
                pcVar12 = pcVar1 + 3;
              }
              if ((iVar8 == 0) && (uVar4 == 5)) {
                pcVar12 = pcVar12 + 4;
              }
              else {
                switch(iVar8) {
                case 1:
                  pcVar12 = pcVar12 + 1;
                  break;
                case 2:
                  pcVar12 = pcVar12 + 4;
                }
              }
            }
          }
          else {
            FUN_00458ca0();
            pcVar12 = pcVar1;
          }
          if (pcVar12 == param_1) {
            param_2[2] = puVar11[1];
            return;
          }
          puVar11 = puVar11 + 2;
          local_18 = local_18 + 1;
        } while (local_18 < (int)uVar3);
      }
    }
    param_2[2] = 0;
  }
  return;
}


