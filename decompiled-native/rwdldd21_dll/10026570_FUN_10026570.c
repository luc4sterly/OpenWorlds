// 10026570 FUN_10026570 [Global]
// program: RWDLDD21.DLL

undefined4 * FUN_10026570(int param_1,undefined4 *param_2)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  int iVar6;
  undefined1 *puVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  int local_c;
  
  iVar8 = *(int *)(param_1 + 0x34);
  uVar2 = *(undefined4 *)(param_1 + 0x20);
  param_2[7] = *(undefined4 *)(param_1 + 0x1c);
  param_2[8] = uVar2;
  param_2[9] = 8;
  puVar4 = FUN_10024a80(param_2);
  if (puVar4 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  if (*(code **)(DAT_100394fc + 0x298) != (code *)0x0) {
    if (((*(uint *)(param_1 + 0x40) & 2) != 0) &&
       (iVar5 = (**(code **)(DAT_100394fc + 0x298))(param_1), iVar5 == 0)) {
      return (undefined4 *)0x0;
    }
    if (((puVar4[0x10] & 2) != 0) &&
       (iVar5 = (**(code **)(DAT_100394fc + 0x298))(puVar4), iVar5 == 0)) {
      if (((*(uint *)(param_1 + 0x40) & 2) != 0) &&
         (*(code **)(DAT_100394fc + 0x29c) != (code *)0x0)) {
        (**(code **)(DAT_100394fc + 0x29c))(param_1);
      }
      return (undefined4 *)0x0;
    }
  }
  iVar5 = *(int *)(param_1 + 0x18);
  iVar3 = puVar4[6];
  if (*(int *)(param_1 + 0x24) == 8) {
    local_c = 0;
    if (0 < *(int *)(param_1 + 0x20)) {
      do {
        iVar6 = 0;
        puVar7 = (undefined1 *)(iVar3 + puVar4[10] * local_c);
        pbVar9 = (byte *)(iVar5 + *(int *)(param_1 + 0x28) * local_c);
        if (0 < *(int *)(param_1 + 0x1c)) {
          do {
            iVar6 = iVar6 + 1;
            *puVar7 = *(undefined1 *)((uint)*pbVar9 * 3 + 2 + iVar8);
            puVar7 = puVar7 + 1;
            pbVar9 = pbVar9 + 1;
          } while (iVar6 < *(int *)(param_1 + 0x1c));
        }
        local_c = local_c + 1;
      } while (local_c < *(int *)(param_1 + 0x20));
    }
  }
  else {
    iVar8 = 0;
    if (0 < *(int *)(param_1 + 0x20)) {
      do {
        iVar10 = iVar5 + *(int *)(param_1 + 0x28) * iVar8;
        iVar6 = 0;
        puVar7 = (undefined1 *)(iVar3 + puVar4[10] * iVar8);
        if (0 < *(int *)(param_1 + 0x1c)) {
          do {
            puVar1 = (undefined1 *)(iVar10 + 2);
            iVar10 = iVar10 + 3;
            iVar6 = iVar6 + 1;
            *puVar7 = *puVar1;
            puVar7 = puVar7 + 1;
          } while (iVar6 < *(int *)(param_1 + 0x1c));
        }
        iVar8 = iVar8 + 1;
      } while (iVar8 < *(int *)(param_1 + 0x20));
    }
  }
  if (*(code **)(DAT_100394fc + 0x29c) != (code *)0x0) {
    if ((*(uint *)(param_1 + 0x40) & 2) != 0) {
      (**(code **)(DAT_100394fc + 0x29c))(param_1);
    }
    if ((puVar4[0x10] & 2) != 0) {
      (**(code **)(DAT_100394fc + 0x29c))(puVar4);
    }
  }
  return puVar4;
}


