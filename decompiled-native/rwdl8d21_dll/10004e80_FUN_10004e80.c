// 10004e80 FUN_10004e80 [Global]
// programa: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10004e80(uint param_1)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 unaff_EDI;
  undefined4 *puVar3;
  int *piStack_120;
  int **ppiStack_11c;
  int *piStack_118;
  int *piStack_114;
  int *piStack_110;
  int *piStack_10c;
  int *piStack_108;
  int *piStack_104;
  int *piStack_100;
  int *piStack_fc;
  undefined4 *puStack_f8;
  undefined4 *puStack_f4;
  undefined4 uStack_f0;
  undefined4 auStack_e0 [4];
  undefined4 auStack_d0 [9];
  undefined4 auStack_ac [2];
  undefined1 auStack_a4 [28];
  undefined4 auStack_88 [8];
  undefined4 uStack_68;
  undefined4 uStack_38;
  
  if ((param_1 & 0x10) == 0) {
    puVar2 = auStack_d0;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    auStack_d0[0] = 0x6c;
    uStack_f0 = 0;
    puStack_f8 = auStack_d0;
    puStack_f4 = &DAT_10075178;
    auStack_d0[1] = 1;
    uStack_68 = 0x200;
    piStack_fc = DAT_10075174;
    piStack_100 = (int *)0x10004fa2;
    iVar1 = (**(code **)(*DAT_10075174 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    piStack_100 = (int *)0x0;
    DAT_10075180 = 0;
    piStack_104 = (int *)&DAT_1007517c;
    piStack_108 = (int *)0x0;
    piStack_10c = DAT_10075174;
    piStack_110 = (int *)0x10004fc7;
    iVar1 = (**(code **)(*DAT_10075174 + 0x10))();
    if (iVar1 != 0) {
      piStack_110 = DAT_10075178;
      piStack_114 = (int *)0x10004fd6;
      (**(code **)(*DAT_10075178 + 8))();
      DAT_10075178 = (int *)0x0;
      return 0;
    }
    piStack_110 = DAT_1007517c;
    piStack_114 = DAT_10075178;
    piStack_118 = (int *)0x10004ff5;
    (**(code **)(*DAT_10075178 + 0x70))();
    piStack_118 = DAT_10075178;
    ppiStack_11c = (int **)0x10005001;
    (**(code **)(*DAT_10075178 + 0x6c))();
    ppiStack_11c = (int **)DAT_1007517c;
    piStack_120 = DAT_10075178;
    iVar1 = (**(code **)(*DAT_10075178 + 0x70))();
    if (iVar1 != 0) {
      piStack_100 = DAT_1007517c;
      piStack_104 = (int *)0x10005029;
      (**(code **)(*DAT_1007517c + 8))();
      DAT_1007517c = (int *)0x0;
      piStack_104 = DAT_10075178;
      piStack_108 = (int *)0x1000503a;
      (**(code **)(*DAT_10075178 + 8))();
      DAT_10075178 = (int *)0x0;
      return 0;
    }
  }
  else {
    puVar2 = auStack_d0;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    auStack_d0[0] = 0x6c;
    uStack_f0 = 0;
    puStack_f8 = auStack_d0;
    puStack_f4 = &DAT_10075178;
    auStack_d0[1] = 1;
    uStack_68 = 0x200;
    piStack_fc = DAT_10075174;
    piStack_100 = (int *)0x10004ed5;
    iVar1 = (**(code **)(*DAT_10075174 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    DAT_10075180 = 1;
    DAT_1007517c = (int *)0x0;
  }
  puVar2 = auStack_e0;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  piStack_100 = auStack_e0;
  auStack_e0[0] = 0x6c;
  piStack_104 = DAT_10075178;
  piStack_108 = (int *)0x10004f1a;
  (**(code **)(*DAT_10075178 + 0x58))();
  piStack_108 = DAT_10075178;
  piStack_10c = (int *)0x10004f26;
  (**(code **)(*DAT_10075178 + 0x6c))();
  piStack_10c = (int *)&stack0xffffff14;
  piStack_110 = DAT_10075178;
  piStack_114 = (int *)0x10004f37;
  iVar1 = (**(code **)(*DAT_10075178 + 0x58))();
  if (iVar1 == 0) {
    puVar2 = auStack_ac;
    puVar3 = &DAT_100782d0;
    for (iVar1 = 8; _DAT_10075184 = unaff_ESI, _DAT_10075188 = unaff_EDI, iVar1 != 0;
        iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    _DAT_100782e0 = 0xf800;
    _DAT_100782e4 = 0x7e0;
    _DAT_100782e8 = 0x1f;
    _DAT_100782ec = 0;
    _DAT_100782dc = 0x10;
  }
  if (DAT_10075180 != 0) {
    puVar2 = auStack_88;
    for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uStack_38 = 0;
    piStack_104 = (int *)0x0;
    piStack_114 = auStack_88;
    ppiStack_11c = &piStack_104;
    piStack_100 = (int *)0x0;
    piStack_118 = (int *)0x1000400;
    piStack_120 = (int *)0x0;
    auStack_88[0] = 100;
    iVar1 = (**(code **)(*DAT_10075178 + 0x14))(DAT_10075178,&piStack_104);
    if (iVar1 == -0x7789fe3e) {
      (**(code **)(*DAT_10075178 + 0x6c))(DAT_10075178);
      (**(code **)(*DAT_10075178 + 0x14))
                (DAT_10075178,&piStack_120,0,&piStack_120,0x1000400,auStack_a4);
    }
  }
  return 1;
}


