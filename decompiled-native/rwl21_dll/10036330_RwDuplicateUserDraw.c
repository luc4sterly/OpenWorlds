// 10036330 RwDuplicateUserDraw [Global]
// programa: RWL21.DLL

undefined4 * RwDuplicateUserDraw(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  int iVar6;
  
                    /* 0x36330  80  RwDuplicateUserDraw */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return (undefined4 *)0x0;
  }
  puVar4 = FUN_10037030(DAT_1005b310);
  if (puVar4 == (undefined4 *)0x0) {
    FUN_1000cba0(3);
    return (undefined4 *)0x0;
  }
  *puVar4 = *param_1;
  puVar4[2] = param_1[2];
  puVar4[3] = param_1[3];
  puVar4[4] = param_1[4];
  puVar4[5] = param_1[5];
  puVar4[10] = param_1[10];
  puVar4[0xb] = param_1[0xb];
  puVar4[0xc] = param_1[0xc];
  puVar4[1] = param_1[1];
  puVar4[0xd] = 0;
  puVar4[0xe] = 0;
  puVar4[0xf] = 0;
  puVar4[0x10] = 0;
  iVar6 = param_1[0xd];
  if (iVar6 == 0) {
    return puVar4;
  }
  if (puVar4 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    iVar6 = 0;
    goto LAB_10036415;
  }
  iVar1 = puVar4[0xd];
  if (iVar1 != 0) {
    if (iVar6 == iVar1) goto LAB_10036415;
    if (iVar1 != 0) {
      puVar2 = *(undefined4 **)(iVar1 + 0xe4);
      iVar3 = puVar2[0xe];
      if (puVar4 == puVar2) {
        *(int *)(iVar1 + 0xe4) = iVar3;
      }
      else {
        while (iVar3 != 0) {
          puVar5 = (undefined4 *)puVar2[0xe];
          if (puVar4 == puVar5) goto LAB_100363e8;
          puVar2 = puVar5;
          iVar3 = puVar5[0xe];
        }
        puVar5 = (undefined4 *)puVar2[0xe];
        if (puVar4 != puVar5) goto LAB_100363f5;
LAB_100363e8:
        puVar2[0xe] = puVar5[0xe];
      }
      puVar4[0xd] = 0;
    }
  }
LAB_100363f5:
  puVar4[0xd] = iVar6;
  puVar4[0xe] = *(undefined4 *)(iVar6 + 0xe4);
  *(undefined4 **)(iVar6 + 0xe4) = puVar4;
LAB_10036415:
  if (iVar6 != 0) {
    return puVar4;
  }
  return (undefined4 *)0x0;
}


