// 1000553d FUN_1000553d [Global]
// program: rwdlmd21.dll

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined4 FUN_1000553d(void)

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
    iVar1 = (**(code **)(*DAT_1008717c + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    DAT_10087188 = 0;
    piStack_24 = (int *)&DAT_10087184;
    piStack_28 = (int *)0x0;
    piStack_2c = DAT_1008717c;
    piStack_30 = (int *)0x10005677;
    iVar1 = (**(code **)(*DAT_1008717c + 0x10))();
    if (iVar1 != 0) {
      piStack_30 = DAT_10087180;
      piStack_34 = (int *)0x10005686;
      (**(code **)(*DAT_10087180 + 8))();
      DAT_10087180 = (int *)0x0;
      return 0;
    }
    piStack_30 = DAT_10087184;
    piStack_34 = DAT_10087180;
    piStack_38 = (int *)0x100056a5;
    (**(code **)(*DAT_10087180 + 0x70))();
    piStack_38 = DAT_10087180;
    ppiStack_3c = (int **)0x100056b1;
    (**(code **)(*DAT_10087180 + 0x6c))();
    ppiStack_3c = (int **)DAT_10087184;
    piStack_40 = DAT_10087180;
    iVar1 = (**(code **)(*DAT_10087180 + 0x70))();
    if (iVar1 != 0) {
      piStack_24 = (int *)0x100056d9;
      (**(code **)(*DAT_10087184 + 8))();
      DAT_10087184 = (int *)0x0;
      piStack_24 = DAT_10087180;
      piStack_28 = (int *)0x100056ea;
      (**(code **)(*DAT_10087180 + 8))();
      DAT_10087180 = (int *)0x0;
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
    iVar1 = (**(code **)(*DAT_1008717c + 0x18))();
    if (iVar1 != 0) {
      return 0;
    }
    DAT_10087188 = 1;
    DAT_10087184 = (int *)0x0;
  }
  puVar2 = (undefined4 *)register0x00000010;
  for (iVar1 = 0x1b; iVar1 != 0; iVar1 = iVar1 + -1) {
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  }
  piStack_24 = DAT_10087180;
  piStack_28 = (int *)0x100055ca;
  (**(code **)(*DAT_10087180 + 0x58))();
  piStack_28 = DAT_10087180;
  piStack_2c = (int *)0x100055d6;
  (**(code **)(*DAT_10087180 + 0x6c))();
  piStack_2c = (int *)&stack0xfffffff4;
  piStack_30 = DAT_10087180;
  piStack_34 = (int *)0x100055e7;
  iVar1 = (**(code **)(*DAT_10087180 + 0x58))();
  if (iVar1 == 0) {
    puVar2 = (undefined4 *)&stack0x00000034;
    puVar3 = &DAT_1008a310;
    for (iVar1 = 8; _DAT_1008718c = unaff_ESI, _DAT_10087190 = unaff_EDI, iVar1 != 0;
        iVar1 = iVar1 + -1) {
      *puVar3 = *puVar2;
      puVar2 = puVar2 + 1;
      puVar3 = puVar3 + 1;
    }
  }
  else {
    _DAT_1008a320 = 0xf800;
    _DAT_1008a324 = 0x7e0;
    _DAT_1008a328 = 0x1f;
    _DAT_1008a32c = 0;
    _DAT_1008a31c = 0x10;
  }
  if (DAT_10087188 != 0) {
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
    iVar1 = (**(code **)(*DAT_10087180 + 0x14))(DAT_10087180,&piStack_24);
    if (iVar1 == -0x7789fe3e) {
      (**(code **)(*DAT_10087180 + 0x6c))(DAT_10087180);
      (**(code **)(*DAT_10087180 + 0x14))
                (DAT_10087180,&piStack_40,0,&piStack_40,0x1000400,&stack0x0000003c);
    }
  }
  return 1;
}


