// 00425e80 _Java_NET_worlds_scape_Transform_scale@20 [Global]
// programa: gamma.dll

undefined4
_Java_NET_worlds_scape_Transform_scale_20
          (int *param_1,undefined4 param_2,float param_3,float param_4,float param_5)

{
  undefined4 uVar1;
  float10 fVar2;
  
                    /* 0x25e80  335  _Java_NET_worlds_scape_Transform_scale@20 */
  uVar1 = (**(code **)(*param_1 + 400))(param_1,param_2,DAT_0049d24c);
  FUN_00418b10(uVar1,param_3,param_4,param_5);
  fVar2 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d250);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d250,param_3 * (float)fVar2);
  fVar2 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d254);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d254,param_4 * (float)fVar2);
  fVar2 = (float10)(**(code **)(*param_1 + 0x198))(param_1,param_2,DAT_0049d258);
  (**(code **)(*param_1 + 0x1bc))(param_1,param_2,DAT_0049d258,param_5 * (float)fVar2);
  FUN_00412800(param_1,param_2,DAT_0049d25c);
  return param_2;
}


