// 100361d0 RwDestroyUserDraw [Global]
// programa: RWL21.DLL

undefined4 RwDestroyUserDraw(undefined4 *param_1)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
                    /* 0x361d0  69  RwDestroyUserDraw */
  if (param_1 == (undefined4 *)0x0) {
    FUN_1000cba0(1);
    return 0;
  }
  iVar1 = param_1[0xd];
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(iVar1 + 0xe4);
    if (param_1 == puVar2) {
      *(undefined4 *)(iVar1 + 0xe4) = puVar2[0xe];
    }
    else {
      iVar1 = puVar2[0xe];
      while (iVar1 != 0) {
        puVar3 = (undefined4 *)puVar2[0xe];
        if (param_1 == puVar3) goto LAB_10036219;
        puVar2 = puVar3;
        iVar1 = puVar3[0xe];
      }
      puVar3 = (undefined4 *)puVar2[0xe];
      if (param_1 != puVar3) goto LAB_10036226;
LAB_10036219:
      puVar2[0xe] = puVar3[0xe];
    }
    param_1[0xd] = 0;
  }
LAB_10036226:
  iVar1 = param_1[0xf];
  if (iVar1 != 0) {
    puVar2 = *(undefined4 **)(iVar1 + 0x110);
    if (param_1 == puVar2) {
      *(undefined4 *)(iVar1 + 0x110) = puVar2[0x10];
    }
    else {
      iVar1 = puVar2[0x10];
      while (iVar1 != 0) {
        puVar3 = (undefined4 *)puVar2[0x10];
        if (param_1 == puVar3) goto LAB_10036262;
        puVar2 = puVar3;
        iVar1 = puVar3[0x10];
      }
      puVar3 = (undefined4 *)puVar2[0x10];
      if (param_1 != puVar3) goto LAB_1003626f;
LAB_10036262:
      puVar2[0x10] = puVar3[0x10];
    }
    param_1[0xf] = 0;
  }
LAB_1003626f:
  FUN_10037010(DAT_1005b310,param_1);
  return 1;
}


