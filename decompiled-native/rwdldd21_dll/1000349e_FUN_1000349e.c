// 1000349e FUN_1000349e [Global]
// programa: RWDLDD21.DLL

undefined1 * __thiscall FUN_1000349e(void *this)

{
  int *piVar1;
  undefined4 in_EAX;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int *unaff_EBP;
  undefined4 *puVar5;
  undefined4 *puVar6;
  undefined4 *puVar7;
  undefined4 *puStack00000004;
  undefined4 uStack00000008;
  int iStack0000000c;
  int iStack00000010;
  undefined4 uStack00000044;
  undefined4 uStack00000048;
  undefined4 in_stack_0000004c;
  undefined4 in_stack_00000050;
  undefined4 uStack0000006c;
  undefined4 uStack000000ac;
  undefined4 in_stack_000000b4;
  undefined4 *in_stack_000000bc;
  int in_stack_000000c0;
  int in_stack_000000cc;
  int in_stack_000000e8;
  int in_stack_000000ec;
  undefined4 *in_stack_000000f0;
  undefined1 auStack_34 [4];
  undefined4 uStack_30;
  undefined1 *puStack_2c;
  undefined4 uStack_28;
  int *piStack_24;
  int *piStack_20;
  undefined1 *puStack_1c;
  
  puVar5 = (undefined4 *)register0x00000010;
  for (; puVar5 = puVar5 + 1, this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar5 = in_EAX;
  }
  iStack00000010 = in_stack_000000e8;
  iStack0000000c = in_stack_000000ec;
  puStack00000004 = (undefined4 *)0x6c;
  uStack00000008 = 0x1007;
  uStack0000006c = 0x840;
  puVar5 = in_stack_000000f0;
  puVar6 = &stack0x0000004c;
  for (iVar2 = 8; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar6 = *puVar5;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  puStack_1c = (undefined1 *)&stack0x00000004;
  piStack_20 = DAT_10036030;
  piStack_24 = (int *)0x10003502;
  iVar2 = (**(code **)(*DAT_10036030 + 0x18))();
  if (iVar2 == 0) {
    puVar5 = (undefined4 *)&stack0xfffffff4;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar5 = 0;
      puVar5 = puVar5 + 1;
    }
    piStack_24 = (int *)0x0;
    puStack_2c = &stack0xfffffff4;
    uStack_28 = 0x21;
    uStack_30 = 0;
    iVar2 = (**(code **)(*unaff_EBP + 100))();
    if (iVar2 == -0x7789fe3e) {
      puVar5 = &stack0x0000004c;
      for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
        *puVar5 = 0;
        puVar5 = puVar5 + 1;
      }
      in_stack_0000004c = 0x6c;
      in_stack_00000050 = 1;
      in_stack_000000b4 = 0x4000;
      (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0x0000004c,0,&LAB_10001b40);
      if (DAT_10036038 != (int *)0x0) {
        (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
      }
      if (DAT_1003603c != DAT_10036038) {
        (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
      }
      iVar2 = (**(code **)(*unaff_EBP + 100))(unaff_EBP,0,auStack_34,0x21,0);
    }
    piVar1 = piStack_24;
    if (iVar2 == 0) {
      if (*(int *)(in_stack_000000cc + 0xc) == 0x20) {
        uVar4 = in_stack_000000e8 << 2;
      }
      else {
        uVar4 = in_stack_000000e8 * 2;
      }
      if ((in_stack_000000bc != (undefined4 *)0x0) &&
         (puVar5 = puStack00000004, puStack00000004 != (undefined4 *)0x0)) {
        for (; in_stack_000000ec != 0; in_stack_000000ec = in_stack_000000ec + -1) {
          puVar6 = in_stack_000000bc;
          puVar7 = puVar5;
          for (uVar3 = uVar4 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {
            *puVar7 = *puVar6;
            puVar6 = puVar6 + 1;
            puVar7 = puVar7 + 1;
          }
          for (uVar3 = uVar4 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {
            *(undefined1 *)puVar7 = *(undefined1 *)puVar6;
            puVar6 = (undefined4 *)((int)puVar6 + 1);
            puVar7 = (undefined4 *)((int)puVar7 + 1);
          }
          in_stack_000000bc = (undefined4 *)((int)in_stack_000000bc + in_stack_000000c0);
          puVar5 = (undefined4 *)((int)puVar5 + (int)unaff_EBP);
        }
      }
      iVar2 = (**(code **)(*piStack_24 + 0x80))(piStack_24,0);
      if (iVar2 == -0x7789fe3e) {
        puVar5 = &stack0x00000044;
        for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
          *puVar5 = 0;
          puVar5 = puVar5 + 1;
        }
        uStack00000044 = 0x6c;
        uStack00000048 = 1;
        uStack000000ac = 0x4000;
        (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0x00000044,0,&LAB_10001b40);
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
      if (piStack_24 != (int *)0x0) {
        (**(code **)(*piStack_24 + 8))(piStack_24);
      }
      puStack_2c = (undefined1 *)0x0;
    }
  }
  else {
    puStack_2c = (undefined1 *)0x0;
  }
  return puStack_2c;
}


