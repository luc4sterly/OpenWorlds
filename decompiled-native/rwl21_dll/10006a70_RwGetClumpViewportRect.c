// 10006a70 RwGetClumpViewportRect [Global]
// program: RWL21.DLL

float * RwGetClumpViewportRect
                  (float *param_1,int param_2,int *param_3,undefined4 *param_4,undefined4 *param_5,
                  undefined4 *param_6)

{
  float *pfVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  undefined4 extraout_EDX;
  undefined4 uVar5;
  undefined4 extraout_EDX_00;
  undefined4 extraout_EDX_01;
  undefined4 uVar6;
  float *pfVar8;
  float local_5c [2];
  int local_54;
  undefined4 local_50;
  undefined4 local_4c;
  undefined4 local_48;
  undefined1 auStack_44 [68];
  undefined3 uVar7;
  
                    /* 0x6a70  172  RwGetClumpViewportRect */
  pfVar8 = (float *)0x0;
  if (((((param_1 != (float *)0x0) && (param_2 != 0)) && (param_3 != (int *)0x0)) &&
      ((param_4 != (undefined4 *)0x0 && (param_5 != (undefined4 *)0x0)))) &&
     (param_6 != (undefined4 *)0x0)) {
    rwupdateViewMatrix(param_2);
    uVar5 = extraout_EDX;
    for (pfVar1 = param_1; pfVar1 != (float *)0x0; pfVar1 = (float *)pfVar1[0x5d]) {
      uVar7 = (undefined3)((uint)uVar5 >> 8);
      uVar5 = CONCAT31(uVar7,*(char *)((int)pfVar1 + 0x12d));
      if ((*(char *)((int)pfVar1 + 0x12d) != '\0') ||
         (uVar5 = CONCAT31(uVar7,*(char *)((int)pfVar1 + 0x171)),
         *(char *)((int)pfVar1 + 0x171) != '\0')) {
        pfVar8 = pfVar1;
      }
    }
    if (pfVar8 != (float *)0x0) {
      FUN_10004700(0,uVar5,pfVar8);
    }
    uVar5 = *(undefined4 *)(param_2 + 0x80);
    uVar2 = *(undefined4 *)(param_2 + 0x84);
    uVar3 = *(undefined4 *)(param_2 + 0x88);
    local_5c[0] = 0.015;
    local_5c[1] = 2.1474836e+09;
    iVar4 = FUN_10041c30();
    uVar6 = extraout_EDX_00;
    if (iVar4 == 0) {
      FUN_10041b80(param_2,local_5c);
      uVar6 = extraout_EDX_01;
    }
    FUN_10006be0(auStack_44,uVar6,param_1,(float *)auStack_44,param_2,&local_54,(float *)0x0);
    *(undefined4 *)(param_2 + 0x80) = uVar5;
    *(undefined4 *)(param_2 + 0x84) = uVar2;
    *(undefined4 *)(param_2 + 0x88) = uVar3;
    *param_3 = local_54;
    *param_4 = local_50;
    *param_5 = local_4c;
    *param_6 = local_48;
    if (param_1[99] != 1.4013e-45) {
      FUN_10030b70(param_1);
    }
    return param_1;
  }
  FUN_1000cba0(1);
  return (float *)0x0;
}


