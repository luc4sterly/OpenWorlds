// 00425bc0 _Java_NET_worlds_scape_Transform_makeIdentity@8 [Global]
// program: gamma.dll

undefined4 _Java_NET_worlds_scape_Transform_makeIdentity_8(int *param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  undefined4 *puVar4;
  undefined4 *puVar5;
  undefined4 local_50 [16];
  
                    /* 0x25bc0  325  _Java_NET_worlds_scape_Transform_makeIdentity@8 */
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d250,DAT_00471bf4);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d254,DAT_00471bf4);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d258,DAT_00471bf4);
  iVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  if (iVar1 == 0) {
    uVar2 = FUN_00419040();
    (**(code **)(*param_1 + 0x1b4))(param_1,param_2,DAT_0049d24c,uVar2);
    return param_2;
  }
  puVar4 = &DAT_00471c3c;
  puVar5 = local_50;
  for (iVar3 = 0x10; iVar3 != 0; iVar3 = iVar3 + -1) {
    *puVar5 = *puVar4;
    puVar4 = puVar4 + 1;
    puVar5 = puVar5 + 1;
  }
  FUN_00419f90(iVar1,local_50);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


