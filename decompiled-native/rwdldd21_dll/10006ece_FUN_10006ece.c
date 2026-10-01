// 10006ece FUN_10006ece [Global]
// program: RWDLDD21.DLL

void __thiscall FUN_10006ece(void *this)

{
  int *piVar1;
  undefined4 in_EAX;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  int iStack00000004;
  int iStack00000008;
  int iStack0000000c;
  undefined4 uStack00000010;
  undefined4 uStack0000005c;
  uint uStack00000060;
  undefined4 uStack000000c4;
  int in_stack_000000e4;
  int *in_stack_000000e8;
  undefined1 *puStack_2c;
  int *piStack_28;
  
  puVar3 = &stack0x00000010;
  for (; this != (void *)0x0; this = (void *)((int)this + -1)) {
    *puVar3 = in_EAX;
    puVar3 = puVar3 + 1;
  }
  uStack00000010 = 100;
  FUN_10002490(0x10038a60,0x10038b38);
  uStack00000060 = FUN_100027c0(*(uint *)(in_stack_000000e4 + 0x98));
  iStack00000008 = in_stack_000000e8[2] + *in_stack_000000e8 + DAT_10042034;
  iStack00000004 = in_stack_000000e8[1] + DAT_10042038;
  iStack0000000c = in_stack_000000e8[3] + iStack00000004;
  puVar3 = *(undefined4 **)(*(int *)(in_stack_000000e4 + 0x100) + 0x2c);
  piStack_28 = (int *)*puVar3;
  puStack_2c = (undefined1 *)0x10006f69;
  iVar2 = (**(code **)(*piStack_28 + 0x14))();
  if (iVar2 == -0x7789fe3e) {
    puStack_2c = &LAB_10001b40;
    puVar4 = &stack0x0000005c;
    for (iVar2 = 0x1b; iVar2 != 0; iVar2 = iVar2 + -1) {
      *puVar4 = 0;
      puVar4 = puVar4 + 1;
    }
    uStack0000005c = 0x6c;
    uStack00000060 = 1;
    uStack000000c4 = 0x4000;
    (**(code **)(*DAT_10036030 + 0x24))(DAT_10036030,0x10,&stack0x0000005c,0);
    if (DAT_10036038 != (int *)0x0) {
      (**(code **)(*DAT_10036038 + 0x6c))(DAT_10036038);
    }
    if (DAT_1003603c != DAT_10036038) {
      (**(code **)(*DAT_1003603c + 0x6c))(DAT_1003603c);
    }
    piVar1 = (int *)*puVar3;
    (**(code **)(*piVar1 + 0x14))(piVar1,&puStack_2c,0,&puStack_2c,0x1000400,&stack0xffffffe4);
  }
  return;
}


