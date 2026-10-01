// 00426350 _Java_NET_worlds_scape_Transform_invert@8 [Global]
// program: gamma.dll

undefined4 _Java_NET_worlds_scape_Transform_invert_8(int *param_1,undefined4 param_2)

{
  undefined4 uVar1;
  undefined4 uVar2;
  float10 fVar3;
  
                    /* 0x26350  323  _Java_NET_worlds_scape_Transform_invert@8 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  uVar2 = FUN_00419950();
  FUN_00418f00(uVar1,uVar2);
  FUN_00419860(uVar2,uVar1);
  FUN_004198f0();
  fVar3 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d250,DAT_00471bf4 / (float)fVar3);
  fVar3 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d254,DAT_00471bf4 / (float)fVar3);
  fVar3 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d258,DAT_00471bf4 / (float)fVar3);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


