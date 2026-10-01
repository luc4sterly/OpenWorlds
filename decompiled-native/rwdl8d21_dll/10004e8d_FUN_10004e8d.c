// 10004e8d FUN_10004e8d [Global]
// program: RWDL8D21.DLL

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_10004e8d(void)

{
  int iVar1;
  undefined4 unaff_ESI;
  undefined4 *puVar2;
  undefined4 unaff_EDI;
  undefined4 *puVar3;
  bool in_ZF;
  undefined4 uStack00000010;
  undefined4 uStack00000014;
  undefined4 uStack00000058;
  undefined4 uStack00000078;
  undefined4 uStack000000a8;
  int *piStack_40;
  int **ppiStack_3c;
  int *piStack_38;
  int *piStack_34;
  int *piStack_30;
  int *piStack_2c;
  int *piStack_28;
  int *piStack_24;
  
  if (in_ZF) {
    puVar2 = &stack0x00000010;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uStack00000010 = 0x6c;
    uStack00000014 = 1;
    uStack00000078 = 0x200;
    iVar1 = (**(code **)(*DAT_10075174 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    DAT_10075180 = 0;
    piStack_24 = (int *)&DAT_1007517c;
    piStack_28 = (int *)0x0;
    piStack_2c = DAT_10075174;
    piStack_30 = (int *)0x10004fc7;
    iVar1 = (**(code **)(*DAT_10075174 + 0x10))();
    if (iVar1 != 0) {
      piStack_30 = DAT_10075178;
      piStack_34 = (int *)0x10004fd6;
      (**(code **)(*DAT_10075178 + 8))();
      DAT_10075178 = (int *)0x0;
      return 0;
    }
    piStack_30 = DAT_1007517c;
    piStack_34 = DAT_10075178;
    piStack_38 = (int *)0x10004ff5;
    (**(code **)(*DAT_10075178 + 0x70))();
    piStack_38 = DAT_10075178;
    ppiStack_3c = (int **)0x10005001;
    (**(code **)(*DAT_10075178 + 0x6c))();
    ppiStack_3c = (int **)DAT_1007517c;
    piStack_40 = DAT_10075178;
    iVar1 = (**(code **)(*DAT_10075178 + 0x70))();
    if (iVar1 != 0) {
      piStack_24 = (int *)0x10005029;
      (**(code **)(*DAT_1007517c + 8))();
      DAT_1007517c = (int *)0x0;
      piStack_24 = DAT_10075178;
      piStack_28 = (int *)0x1000503a;
      (**(code **)(*DAT_10075178 + 8))();
      DAT_10075178 = (int *)0x0;
      return 0;
    }
  }
  else {
    puVar2 = &stack0x00000010;
    for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uStack00000010 = 0x6c;
    uStack00000014 = 1;
    uStack00000078 = 0x200;
    iVar1 = (**(code **)(*DAT_10075174 + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    DAT_10075180 = 1;
    DAT_1007517c = (int *)0x0;
  }
  puVar2 = (undefined4 *)register0x00000010;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  piStack_24 = DAT_10075178;
  piStack_28 = (int *)0x10004f1a;
  (**(code **)(*DAT_10075178 + 0x58))();
  piStack_28 = DAT_10075178;
  piStack_2c = (int *)0x10004f26;
  (**(code **)(*DAT_10075178 + 0x6c))();
  piStack_2c = (int *)&stack0xfffffff4;
  piStack_30 = DAT_10075178;
  piStack_34 = (int *)0x10004f37;
  iVar1 = (**(code **)(*DAT_10075178 + 0x58))();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)&stack0x00000034;
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
    puVar2 = &stack0x00000058;
    for (iVar1 = 0x19; iVar1 != 0; iVar1 = iVar1 + -1) {
      *puVar2 = 0;
      puVar2 = puVar2 + 1;
    }
    uStack000000a8 = 0;
    piStack_24 = (int *)0x0;
    piStack_34 = &stack0x00000058;
    ppiStack_3c = &piStack_24;
    piStack_38 = (int *)0x1000400;
    piStack_40 = (int *)0x0;
    uStack00000058 = 100;
    iVar1 = (**(code **)(*DAT_10075178 + 0x14))(DAT_10075178,&piStack_24);
    if (iVar1 == -0x7789fe3e) {
      (**(code **)(*DAT_10075178 + 0x6c))(DAT_10075178);
      (**(code **)(*DAT_10075178 + 0x14))
                (DAT_10075178,&piStack_40,0,&piStack_40,0x1000400,&stack0x0000003c);
    }
  }
  return 1;
}


