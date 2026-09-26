// 10003490 FUN_10003490 [Global]
// programa: RWDLDD21.DLL

undefined1 *
FUN_10003490(undefined4 param_1,undefined4 param_2,int param_3,int param_4,undefined4 *param_5)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *unaff_EBP;
  undefined4 *puVar5;
  undefined4 **ppuVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  undefined1 auStack_110 [4];
  undefined4 uStack_10c;
  undefined1 *puStack_108;
  undefined4 uStack_104;
  int *piStack_100;
  int *piStack_fc;
  undefined4 **ppuStack_f8;
  undefined1 *puStack_f4;
  undefined4 uStack_f0;
  undefined1 auStack_dc [4];
  undefined4 *apuStack_d8 [2];
  int iStack_d0;
  int iStack_cc;
  undefined4 auStack_98 [10];
  undefined4 uStack_70;
  undefined4 uStack_30;
  undefined4 uStack_28;
  undefined4 *puStack_20;
  int iStack_1c;
  int iStack_10;
  
  ppuVar6 = apuStack_d8;
  for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
    *ppuVar6 = (undefined4 *)0x0;
    ppuVar6 = ppuVar6 + 1;
  }
  iStack_cc = param_3;
  iStack_d0 = param_4;
  uStack_f0 = 0;
  apuStack_d8[0] = (undefined4 *)0x6c;
  apuStack_d8[1] = (undefined4 *)0x1007;
  uStack_70 = 0x840;
  puVar8 = auStack_98 + 2;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar8 = *param_5;
    param_5 = param_5 + 1;
    puVar8 = puVar8 + 1;
  }
  puStack_f4 = auStack_dc;
  ppuStack_f8 = apuStack_d8;
  piStack_fc = DAT_10036030;
  piStack_100 = (int *)0x10003502;
  iVar2 = (**(code **)(*DAT_10036030 + 0x18))();
  if (iVar2 == 0) {
    puVar8 = (undefined4 *)&stack0xffffff18;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar8 = 0;
      puVar8 = puVar8 + 1;
    }
    piStack_100 = (int *)0x0;
    puStack_108 = &stack0xffffff18;
    uStack_104 = 0x21;
    uStack_10c = 0;
    iVar2 = (**(code **)(*unaff_EBP + 100))();
    if (iVar2 == -0x7789fe3e) {
      puVar8 = auStack_98 + 2;
      for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar8 = 0;
        puVar8 = puVar8 + 1;
      }
      auStack_98[2] = 0x6c;
      auStack_98[3] = 1;
      uStack_28 = 0x4000;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_98 + 2,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      iVar2 = (**(code **)(*unaff_EBP + 100))(unaff_EBP,0,auStack_110,0x21,0);
    }
    piVar1 = piStack_100;
    if (iVar2 == 0) {
      if (*(int *)(iStack_10 + 0xc) == 0x20) {
        uVar4 = param_3 << 2;
      }
      else {
        uVar4 = param_3 * 2;
      }
      if ((puStack_20 != (undefined4 *)0x0) &&
         (puVar8 = apuStack_d8[0], apuStack_d8[0] != (undefined4 *)0x0)) {
        for (; param_4 != 0; param_4 = param_4 + -1) {
          puVar5 = puStack_20;
          puVar7 = puVar8;
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar5;
            puVar5 = puVar5 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar5;
            puVar5 = (undefined4 *)((int)puVar5 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          puStack_20 = (undefined4 *)((int)puStack_20 + iStack_1c);
          puVar8 = (undefined4 *)((int)puVar8 + (int)unaff_EBP);
        }
      }
      iVar2 = (**(code **)(*piStack_100 + 0x80))(piStack_100,0);
      if (iVar2 == -0x7789fe3e) {
        puVar8 = auStack_98;
        for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar8 = 0;
          puVar8 = puVar8 + 1;
        }
        auStack_98[0] = 0x6c;
        auStack_98[1] = 1;
        uStack_30 = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,auStack_98,0,&LAB_10001b40);
        if (DAT_10036038 != (int *)0x0) {
          (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
        }
        if (DAT_1003603c != DAT_10036038) {
          (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
        }
        (**(code **)(*piVar1 + 0x80))(piVar1,0);
      }
    }
    else {
      if (piStack_100 != (int *)0x0) {
        (**(code **)(*piStack_100 + 8))(piStack_100);
      }
      puStack_108 = (undefined1 *)0x0;
    }
  }
  else {
    puStack_108 = (undefined1 *)0x0;
  }
  return puStack_108;
}


